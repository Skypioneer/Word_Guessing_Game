/**
 * @author: Jason Wang
 * File: Sequence.cpp
 * Reference: none
 * @version: 123.0
 * Description: implement Sequence.h
 * Dependencies: none
 * State: Any state changes observed in the DerivedClass.
 * Assumption: none
 */

#include "Sequence.h"
#include <utility>
#include <stdexcept>

using namespace std;

Sequence::Sequence(const string& word) {
    if (checkSize(word)) {
        this->wordInSeq = word;
        this->wordSize = word.size();
        this->state = State::ACTIVE;
    } else
        throw invalid_argument (" has invalid word size.");
}

bool Sequence::checkSize(const string& word) {
    return word.size() >= 3;
}

string Sequence::getInvertedWord() {
    return Sequence::getExecutedWord(ACTIVE);
}

string Sequence::getWord() {
    return wordInSeq;
}

void Sequence::swap(unsigned index) {
    char tmp;
    invertedWord = wordInSeq;

    tmp = invertedWord[index];
    invertedWord[index] = invertedWord[index + 1];
    invertedWord[index + 1] = tmp;
}

string Sequence::getExecutedWord(State wordState) {
    generateInvertedWord();
    return invertedWord;
}

void Sequence::generateInvertedWord() {
    if (iIndex == -1) {
        iIndex = (int) random() % (wordSize - 1);
    }
    swap(iIndex);
}

State Sequence::getState(){
    return state;
}

void Sequence::setStateInactive() {
    state = State::INACTIVE;
}