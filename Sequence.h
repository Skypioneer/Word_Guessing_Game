/**
 * @author: Jason Wang
 * File: Sequence.h
 * Reference: none
 * @version: 123.0
 * Description: The class implements Inverter Class, provides functions to be
 *              overridden by its child Class, and store words' information.
 * Dependencies: implement Inverter Class and be a parent class of Repeater,
 *               Extractor, and Variator Classes
 * State: Any state changes observed in the DerivedClass.
 * Assumption: none
 */

#ifndef HW7_SEQUENCE_H
#define HW7_SEQUENCE_H
#include <string>
#include "Inverter.h"
#include <vector>
using namespace std;

/**
 * The Class that describes the words' state.
 */
enum State {ACTIVE, INACTIVE};

class Sequence : public Inverter{
public:
    // Precondition: take in a string
    // Postconditon: initialize wordInSeq, wordSize, state, and generate an
    //               inverted word
    Sequence(const string&);

    // Precondition: take in a string
    // Postconditon: check if word is in valid size
    static bool checkSize(const string&);

    // Precondition: take in a string
    // Postconditon: being overridden by its child Class
    virtual string getExecutedWord(State);

    // Precondition: none
    // Postconditon: return wordInSeq
    string getWord();

    // Precondition: none
    // Postconditon: return invertedWord
    string getInvertedWord() override;

    // Precondition: none
    // Postconditon: return state
    State getState();

    // Precondition: none
    // Postconditon: set state to inactive
    void setStateInactive();

protected:
    string wordInSeq;           // word to be test
    string invertedWord;        // inverted word
    string extractedWord;       // extracted word
    State state;                // word's state
    unsigned wordSize;          // word's size
    unsigned iIndex = -1;       // control variable

private:
    // Precondition: none
    // Postconditon: inverted two characters in a string
    void swap(unsigned );

    // Precondition: none
    // Postconditon: generate inverted word
    void generateInvertedWord();
};

#endif //HW7_SEQUENCE_H