//
// Created by lenovo on 6/8/2023.
//

#ifndef REGEX_EQUIVALENCE_TRANSITION_H
#define REGEX_EQUIVALENCE_TRANSITION_H
<<<<<<< HEAD
#import "State.h"
=======
>>>>>>> db7b0c100650785b78cb7673a9bc39cd3a54b28b

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
