/**
 * @author: Jason Wang
 * File: Repeater.cpp
 * Reference: none
 * @version: 123.0
 * Description: implement Repeater.h
 * Dependencies: a child Class inheriting Sequence Class
 * State: Any state changes observed in the DerivedClass.
 * Assumption: none
 */

#include "Repeater.h"
#include <vector>

Repeater::Repeater(const string & word) : Sequence(word) {}

string Repeater::getExecutedWord(State wordState) {
    // check if the word's state is active
    if (wordState == State::ACTIVE) {
        unsigned size = wordSize;
        repeatedWord = wordInSeq;

        // decide how many characters need repeated
        srand(time(nullptr));
        int totalRepeatedChar = rand() % wordSize + 1;

        vector<int> wordIndex;          // collection of the word's index
        vector<int> repeatedIndex;      // collection of repeated index

        // populate wordIndex
        wordIndex.reserve(wordSize);
        for (int i = 0; i < wordSize; i++){
            wordIndex.push_back(i);
        }

        // find which character needs repeated
        while(totalRepeatedChar > 0) {
            bool indexExist = false;    // store if index exists
            int charIndex;              // the character needing repeated

            while(!indexExist) {
                charIndex = wordIndex[rand() % size];

                // check if repeatedIndex is empty
                if (repeatedIndex.empty()){
                    pushBackAndInsertCharacter(repeatedIndex,
                                               charIndex);
                    indexExist = false;
                }else{
                    // check if the index is repeated
                    for (int i = 0; i < (int)repeatedIndex.size(); i++){
                        if (charIndex == repeatedIndex[i]){
                            indexExist = true;
                            break;
                        }
                    }
                    if (!indexExist){
                        pushBackAndInsertCharacter(repeatedIndex, charIndex);
                    }
                }
            }
            totalRepeatedChar--;
        }
        return repeatedWord;
    } else
        return wordInSeq;
}

void Repeater::pushBackAndInsertCharacter(vector<int> &repeatedIndex,
                                          int charIndex) {
    char repeatedChar;          // repeated character

    repeatedIndex.push_back(charIndex);
    repeatedChar = wordInSeq[charIndex];
    repeatedWord.insert(charIndex,1,repeatedChar);
}




