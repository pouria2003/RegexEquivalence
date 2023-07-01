//
// Created by lenovo on 6/8/2023.
//

#include "NFA.h"

NFA NFA::regexToNFA(const string & regex, int p, int q) {
    if(findMatchingRightParentheses(regex, p) == q)
        return regexToNFA(regex, p + 1, q - 1);
    else if() {

    }
}

NFA NFA::operator+(const NFA &other) {
    return NFA();
}
