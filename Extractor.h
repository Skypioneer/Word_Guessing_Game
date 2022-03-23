/**
 * @author: Jason Wang
 * File: Extractor.h
 * Reference: none
 * @version: 123.0
 * Description: create a extractor and return it
 * Dependencies: a child Class inheriting Sequence Class
 * State: Any state changes observed in the DerivedClass.
 * Assumption: none
 */
#ifndef HW7_EXTRACTOR_H
#define HW7_EXTRACTOR_H
#include "Sequence.h"
#include <vector>

class Extractor: public Sequence{
private:
    string otherHalfSubSeq;     // other half of subsequence
public:
    // Precondition: take in string
    // Postconditon: inherit Sequence Class
    explicit Extractor(const string &);

    // Precondition: take in state
    // Postconditon: return extracted word
    string getExecutedWord(State) override;

    // Precondition: take in a string
    // Postconditon: check if user input is a subsequence of the word
    bool validSubSeq(const string&);

    // Precondition: none
    // Postconditon: return other half of subsequence
    string getOtherHalfSubSeq();
};

#endif //HW7_EXTRACTOR_H
