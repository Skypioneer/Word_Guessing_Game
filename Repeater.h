/**
 * @author: Jason Wang
 * File: Repeater.h
 * Reference: none
 * @version: 123.0
 * Description: create a repeater and return it
 * Dependencies: a child Class inheriting Sequence Class
 * State: Any state changes observed in the DerivedClass.
 * Assumption: none
 */
#ifndef HW7_REPEATER_H
#define HW7_REPEATER_H
#include "Sequence.h"

class Repeater: public Sequence{
public:
    // Precondition: take in a string
    // Postconditon: inherit Sequence Class
    explicit Repeater(const string &);

    // Precondition: take in state
    // Postconditon: return repeated word
    string getExecutedWord(State) override;

protected:
    string repeatedWord;    // repeated word

private:
    // Precondition: take in a vector, a character, and int
    // Postconditon: push back character and insert it to the word
    void pushBackAndInsertCharacter(vector<int>&, int);
};

#endif //HW7_REPEATER_H
