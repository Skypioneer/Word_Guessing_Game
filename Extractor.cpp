/**
 * @author: Jason Wang
 * File: Extractor.cpp
 * Reference: none
 * @version: 123.0
 * Description: implement Extractor.h
 * Dependencies: a child Class inheriting Sequence Class
 * State: Any state changes observed in the DerivedClass.
 * Assumption: none
 */

#include "Extractor.h"

Extractor::Extractor(const string & word) : Sequence(word) {}

string Extractor::getExecutedWord(State wordState) {
    // check if the word's state is active
    if (wordState == State::ACTIVE){
        srand(time(nullptr));
        do {
            extractedWord = wordInSeq;
            int index = rand() % wordSize;
            int length = rand() % (wordSize - index) + 1;

            extractedWord = extractedWord.substr(index, length);
        } while (extractedWord == wordInSeq);

        return extractedWord;
    }else
        return wordInSeq;
}

bool Extractor::validSubSeq(const string& subSeqWord) {
    // make sure the subSeqWord is not equal to wordInSeq
    if (subSeqWord != wordInSeq) {
        otherHalfSubSeq = wordInSeq;
        unsigned subSeqWordSize = subSeqWord.size();
        int k = 0;
        int beginIndex;

        // check if subSeqWord is a part of subInSeq
        for (int i = 0; i < wordSize; i++) {
            if (otherHalfSubSeq[i] == subSeqWord[k]) {
                k++;
                if (k == 1) {
                    beginIndex = i;
                    if (k == subSeqWordSize) {
                        otherHalfSubSeq.erase(beginIndex, subSeqWordSize);
                        return true;
                    }
                } else if (k == subSeqWordSize) {
                    otherHalfSubSeq.erase(beginIndex, subSeqWordSize);
                    return true;
                }
            } else {
                k = 0;
            }
        }
    }
    return false;
}

string Extractor::getOtherHalfSubSeq() {
    return otherHalfSubSeq;
}
