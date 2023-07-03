//
// Created by lenovo on 6/8/2023.
//

#ifndef REGEX_EQUIVALENCE_NFA_H
#define REGEX_EQUIVALENCE_NFA_H
#include <iostream>
#include "State.h"
#include <vector>
#include <list>


using namespace std;

class NFA {
public:
    NFA(const std::vector<char>& alphabet, int state_number, const vector<int> &final_states);
    ~NFA();
public:
    std::vector<char> alphabet;
    int state_number;
    list <int>** transition_matrix;
    int *final_states;



public:
    static NFA regexToNFA(const string & regex, int p, int q, const vector<char> &);
    NFA operator+ (const NFA & other);
    NFA operator* (const NFA & other);
    NFA starOperation();
    void addTransition(int state, char word, int destination);
    void addTransition(list <int>** transitions, int states, int start_ind);

};

ostream& operator<<(ostream& os, const NFA& nfa);

#endif //REGEX_EQUIVALENCE_NFA_H
