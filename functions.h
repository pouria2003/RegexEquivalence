//
// Created by lenovo on 7/1/2023.
//

#include <string>

using std::string;

#ifndef REGEX_EQUIVALENCE_FUNCTIONS_H
#define REGEX_EQUIVALENCE_FUNCTIONS_H

void addDotToRegex(string & regex);
int findMatchingLeftParentheses(const string & str, int index_of_right_prnts);
int findMatchingRightParentheses(const string & str, int index_of_left_prnts);
void putParentheses(string & regex);

#endif //REGEX_EQUIVALENCE_FUNCTIONS_H
