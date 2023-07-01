//
// Created by lenovo on 6/8/2023.
//

#ifndef REGEX_EQUIVALENCE_NFA_H
#define REGEX_EQUIVALENCE_NFA_H
#include <iostream>
#include "State.h"
#include <list>


using namespace std;

class NFA {
private:
    char* alphabet;
    int alphabet_number;
    int state_number;
    list <int>** transition_matrix;



public:
    static NFA regexToNFA(const string & regex, int p, int q);
    NFA operator+ (const NFA & other);
    NFA operator* (const NFA & other);
    void addTransitoin(int state, char word, int destination);

};


#endif //REGEX_EQUIVALENCE_NFA_H
