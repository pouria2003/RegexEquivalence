//
// Created by lenovo on 6/8/2023.
//

#ifndef REGEX_EQUIVALENCE_DFA_H
#define REGEX_EQUIVALENCE_DFA_H
#include "NFA.h"

class DFA : public NFA {
public:
   DFA(const std::vector<char>& alphabet, int state_number, const vector<int> &final_states)
   : NFA(alphabet, state_number, final_states) {}

public:
    static DFA NFAtoDFA(NFA);

};


ostream& operator<<(ostream& os, const DFA& dfa);



#endif //REGEX_EQUIVALENCE_DFA_H
