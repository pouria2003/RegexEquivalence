//
// Created by lenovo on 6/8/2023.
//

#include <string>
#include <iostream>
#include <vector>
#include "functions.h"
#include "NFA.h"
#include "DFA.h"


using std::string;
using std::cout;
using std::endl;

int main() {
    string str = "b*(abb*)*(a+c)";

    std::vector<char> alphabet;
    bool new_word;
    for(int i = 0; str[i]; ++i){
        new_word = true;
        if((63 < str[i] && str[i] < 123) || (47 < str[i] && str[i] < 58)) {
            for(char & it : alphabet) {
                if(it == str[i]) {
                    new_word = false;
                    break;
                }
            }
            if(new_word)
                alphabet.push_back(str[i]);
        }
    }

    alphabet.push_back('l');

    addDotToRegex(str);
    putParentheses(str);
    std::cout << str << std::endl;

    cout << NFA::regexToNFA(str, 0, str.size() - 1, alphabet);
//    cout << DFA::NFAtoDFA(NFA::regexToNFA(str, 0, str.size() - 1, alphabet));
//
//
//
//
//    std::vector<char> alph;
//    alph.push_back('a');
//    alph.push_back('b');
//    alph.push_back('c');
//    alph.push_back('l');
//
//    NFA nfa(alph, 5, vector<int>{4});
//    NFA nfa_2(alph, 3, vector<int>{2});
//
//    list<int> **tr;
//
//    tr = new list<int>* [3];
//    for(int i = 0; i < 3; ++i)
//        tr[i] = new list<int>[4];
//
//    tr[0][0].push_back(1);
//    tr[0][0].push_back(2);
//    tr[1][1].push_back(0);
//    tr[1][2].push_back(1);
//    tr[2][0].push_back(2);
//    tr[2][1].push_back(1);
//    tr[2][2].push_back(0);
//
//    nfa.addTransition(tr,3,1);
//
//    nfa.addTransition(4, 'a',2);
//    nfa.addTransition(4, 'a',3);
//
//    nfa_2.addTransition(1, 'a', 2);
//    nfa_2.addTransition(1, 'c', 0);
//
//
//
//    cout << nfa << endl << endl << nfa_2 << endl << endl << nfa * nfa_2;
//
//
//
//
//
//    for(int i = 0; i < nfa.state_number; i++) {
//        cout << "[";
//        for(int j = 0; j < nfa.alphabet.size(); ++j) {
//            cout << "(";
//            for(int & it : nfa.transition_matrix[i][j])
//                cout << it;
//            cout << ")\t";
//        }
//        cout << "]\n";
//    }


}
