//
// Created by lenovo on 6/8/2023.
//

#include "DFA.h"

ostream& operator<<(ostream& os, const DFA& dfa)
{
    for(int i = 0; i < dfa.state_number; i++) {
        os << "[";
        for(int j = 0; j < dfa.alphabet.size(); ++j) {
            os << "(";
            for(int & it : dfa.transition_matrix[i][j])
                os << it << "_";
            os << ")\t";
        }
        os << "]\n";
    }
    return os;
}

DFA DFA::NFAtoDFA(NFA nfa) {
    cout << "1";
    vector<vector<int>> states;
    states.push_back(vector<int> {0});
    for(int i = 0; i < states[0].size(); ++i) {
        list<int> lambdas = nfa.getTransition(states[0][i], 'l');
        for(auto it = lambdas.begin(); it != lambdas.end(); ++it)
            states[0].push_back(*it);
    }
    for(int k = 0; k < states[0].size(); ++k)
        cout << states[0][k];
}