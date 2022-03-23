/**
 * @author: Jason Wang
 * File: Variator.cpp
 * Reference: none
 * @version: 123.0
 * Description: implement Variator.h
 * Dependencies: a child Class inheriting Sequence Class
 * State: Any state changes observed in the DerivedClass.
 * Assumption: none
 */

#include "Variator.h"

Variator::Variator(const string & word) : Sequence(word) {}

string Variator::getExecutedWord(State wordState) {
    if (wordState == State::ACTIVE) {
        const int THREE = 3;        // loop control variable
        string tmp;                 // loop control variable

        extractedWord = wordInSeq;

        srand(time(nullptr));
        int index = rand() % wordSize;
        int length = rand() % (wordSize - index) + 1;
        extractedWord = extractedWord.substr(index, length);

        switch (rand() % THREE) {
            case 0:
                return extractedWord + wordInSeq;
            case 1:
                return wordInSeq + extractedWord;
            default:
                return extractedWord;
        }
    }
    else
        return wordInSeq;
}

