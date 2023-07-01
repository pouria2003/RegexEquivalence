//
// Created by lenovo on 6/8/2023.
//

#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;

void addDotToRegex(string & regex)
{
    for(int i = 0; regex[i + 1]; ++i) {
        switch (regex[i]) {
            case '+':
                break;
            case '*':
                switch (regex[i + 1]) {
                    case '+':
                    case ')':
                        break;
                    case '(':
                    default:
                        regex.insert(++i, ".");
                        break;
                }
                break;
            case ')':
                switch (regex[i + 1]) {
                    case '*':
                    case '+':
                    case ')':
                        break;
                    case '(':
                    default:
                        regex.insert(++i, ".");
                        break;
                }
                break;
            case '(':
                switch (regex[i + 1]) {
                    case '(':
                    default:
                        break;
                }
                break;
            default:
                switch (regex[i + 1]) {
                    case '*':
                    case '+':
                    case ')':
                        break;
                    case '(':
                    default:
                        regex.insert(++i, ".");
                        break;
                }
                break;
        }
    }
}

int findMatchingLeftParentheses(const string & str, int index_of_right_prnts)
{
    int temp = 0;
    for(--index_of_right_prnts; index_of_right_prnts >= 0; index_of_right_prnts--) {
        if(str[index_of_right_prnts] == '(') {
            if(temp == 0)
                return index_of_right_prnts;
            else temp--;
        }
        else if(str[index_of_right_prnts] == ')')
            temp++;
    }
    return -1;
}

int findMatchingRightParentheses(const string & str, int index_of_left_prnts)
{
    int temp = 0;
    for(++index_of_left_prnts; str[index_of_left_prnts]; ++index_of_left_prnts) {
        if(str[index_of_left_prnts] == ')') {
            if(temp == 0)
                return index_of_left_prnts;
            else temp++;
        }
        else if(str[index_of_left_prnts] == '(')
            temp--;
    }
    return -1;
}

void putParentheses(string & regex)
{
    // characters
    for(int i = 0; regex[i]; ++i) {
        if((63 < regex[i] && regex[i] < 123) || (47 < regex[i] && regex[i] < 58)){
            regex.insert(i, "(");
            regex.insert(i + 2, ")");
            i += 2;
        }
    }

    // stars
    for(int i = 0; regex[i]; ++i) {
        if(regex[i] == '*') {
            regex.insert(i + 1, ")");
            regex.insert(findMatchingLeftParentheses(regex, i - 1), "(");
            i += 2;
        }
    }

    // dot operations
    for(int i = 0; regex[i]; ++i) {
        if(regex[i] == '.') {
            regex.insert(findMatchingRightParentheses(regex , i + 1), ")");
            regex.insert(findMatchingLeftParentheses(regex, i - 1), "(");
            i += 2;
        }
    }

    // add operations
    for(int i = 0; regex[i]; ++i) {
        if(regex[i] == '+') {
            regex.insert(findMatchingRightParentheses(regex , i + 1), ")");
            regex.insert(findMatchingLeftParentheses(regex, i - 1), "(");
            i += 2;
        }
    }

}

int main() {
    string str = "b*(abb*)*(a+c)";

    std::vector<char> alphabet;
    for(int i = 0; str[i]; ++i){
        if((63 < str[i] && str[i] < 123) || (47 < str[i] && str[i] < 58)) {
            for(auto it = alphabet.begin(); it != alphabet.end())
        }
    }

    addDotToRegex(str);
    putParentheses(str);
    std::cout << str;
}
