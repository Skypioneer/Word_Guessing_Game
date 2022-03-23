/**
 * @author: Jason Wang
 * File: Variator.h
 * Reference: none
 * @version: 123.0
 * Description: create a variator and return it
 * Dependencies: a child Class inheriting Sequence Class
 * State: Any state changes observed in the DerivedClass.
 * Assumption: none
 */

#ifndef HW7_VARIATOR_H
#define HW7_VARIATOR_H
#include "Sequence.h"


class Variator: public Sequence{
public:
    // Precondition: take in string
    // Postconditon: inherit Sequence Class
    explicit Variator(const string &word);

    // Precondition: take in state
    // Postconditon: return variator
    string getExecutedWord(State wordState) override;
};

#endif //HW7_VARIATOR_H
