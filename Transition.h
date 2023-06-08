//
// Created by lenovo on 6/8/2023.
//

#ifndef REGEX_EQUIVALENCE_TRANSITION_H
#define REGEX_EQUIVALENCE_TRANSITION_H
#import "State.h"

class Transition {
private:
    char  transition_char;
    State* destination;

public:
    char getTransitionChar() const;
    char setTransitionChar(char);

    State* getDestination() const;
    State* setDestination(State*);
};


#endif //REGEX_EQUIVALENCE_TRANSITION_H
