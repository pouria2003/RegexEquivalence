//
// Created by lenovo on 6/8/2023.
//

#include "NFA.h"
#include "functions.h"

NFA NFA::regexToNFA(const string & regex, int p, int q, const vector<char> & alphabet) {
    if(findMatchingRightParentheses(regex, p) == q)
        return regexToNFA(regex, p + 1, q - 1, alphabet);
    else if(p == q) {
        NFA nfa(alphabet, 2, vector<int>{1});
        nfa.addTransition(0, regex[p], 1);
        return nfa;
    }
    else if(regex[q] == '*') {
        return (regexToNFA(regex, p + 1, q - 2, alphabet)).starOperation();
    }
    else if(regex[findMatchingRightParentheses(regex, p) + 1] == '+')
        return regexToNFA(regex, p + 1, findMatchingRightParentheses(regex, p) - 1, alphabet) +
                regexToNFA(regex, findMatchingLeftParentheses(regex, q) + 1, q - 1, alphabet);
    else
        return regexToNFA(regex, p + 1, findMatchingRightParentheses(regex, p) - 1, alphabet) *
               regexToNFA(regex, findMatchingLeftParentheses(regex, q) + 1, q - 1, alphabet);
}

NFA NFA::operator+(const NFA &other) {
    NFA res(this->alphabet, state_number + other.state_number + 2,
            vector<int>{state_number + other.state_number + 1});
    res.addTransition(transition_matrix, state_number, 1);
    res.addTransition(other.transition_matrix, other.state_number , state_number + 1);
    res.addTransition(0, 'l', 1);
    res.addTransition(0, 'l', state_number + 1);
    res.addTransition(state_number, 'l', state_number + other.state_number + 1);
    res.addTransition(state_number + other.state_number, 'l', state_number + other.state_number + 1);

    return res;
}

NFA NFA::operator*(const NFA &other) {
    NFA res(this->alphabet, state_number + other.state_number + 1,
            vector<int>{state_number + other.state_number});
    res.addTransition(transition_matrix, state_number, 0);
    res.addTransition(other.transition_matrix, other.state_number , state_number);
    res.addTransition(state_number - 1, 'l', state_number);
    res.addTransition(state_number + other.state_number - 1 , 'l', state_number + other.state_number);

    return res;





}

NFA NFA::starOperation() {
    NFA res(this->alphabet, state_number + 2, vector<int>{state_number + 1});
    res.addTransition(transition_matrix, state_number, 1);
    res.addTransition(0, 'l', 1);
    res.addTransition(0, 'l', state_number + 1);
    res.addTransition(state_number, 'l', state_number + 1);
    res.addTransition(state_number + 1, 'l', 0);

    return res;
}

NFA::NFA(const vector<char> &alphabet, int state_number, const vector<int> & final_states) {
    this->alphabet = alphabet;
    this->state_number = state_number;
    transition_matrix = new list<int>*[state_number];
    for(int i = 0; i < state_number; ++i) {
        transition_matrix[i] = new list<int>[alphabet.size()];
    }
    this->final_states = new int[final_states.size()];
    for(int i = 0; i < final_states.size(); ++i)
        this->final_states[i] = final_states.at(i);
}

NFA::~NFA() {
    for(int i = 0; i < state_number; ++i) {
        delete [] transition_matrix[i];
    }
    delete [] transition_matrix;
    delete [] final_states;
}

void NFA::addTransition(int state, char word, int destination) {
    int i;
    for(i = 0; i < alphabet.size(); ++i) {
        if(alphabet[i] == word)
            break;
    }
    transition_matrix[state][i].push_back(destination);
    cout << "addTransition";
//    getTransition(state, word).push_back(destination);
}

void NFA::addTransition(list<int>** transitions, int states,int start_ind) {
    for(int i = 0; i < states; ++i) {
        for(int j = 0; j < alphabet.size(); ++j) {
            transition_matrix[i + start_ind][j].assign(transitions[i][j].begin(), transitions[i][j].end());
        }
    }
}

ostream& operator<<(ostream& os, const NFA& nfa)
{
    for(int i = 0; i < nfa.state_number; i++) {
        os << "[";
        for(int j = 0; j < nfa.alphabet.size(); ++j) {
            os << "(";
            for(int & it : nfa.transition_matrix[i][j])
                os << it << "_";
            os << ")\t";
        }
        os << "]\n";
    }
    return os;
}

list<int> NFA::getTransition(int state, char word) {
    int i;
    for(i = 0; i < alphabet.size(); ++i) {
        if(alphabet[i] == word)
            break;
    }
    return transition_matrix[state][i];
}
