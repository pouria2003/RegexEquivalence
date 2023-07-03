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

    }
}

NFA NFA::operator+(const NFA &other) {

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
}

void NFA::addTransition(int state, char word, int destination) {
    int i;
    for(i = 0; i < alphabet.size(); ++i) {
        if(alphabet[i] == word)
            break;
    }
    transition_matrix[state][i].push_back(destination);
}

void NFA::addTransition(list<int>** transitions, int states,int start_ind) {

    for(int i = 0; i < states; ++i) {
        for(int j = 0; j < alphabet.size(); ++j) {
            transition_matrix[i + start_ind][j].assign(transitions[i][j].begin(), transitions[i][j].end());
        }
    }
}

NFA NFA::starOperation() {
    NFA res(this->alphabet, state_number + 2, vector<int>{state_number + 1});
    res.addTransition(0, 'l', 1);
    res.addTransition(0, 'l', state_number + 1);
    res.addTransition(state_number, 'l', state_number + 1);
    res.addTransition(state_number + 1, 'l', 0);
    res.addTransition(transition_matrix, state_number, 1);

    return res;
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