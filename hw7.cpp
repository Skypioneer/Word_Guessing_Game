/**
 * @author: Jason Wang
 * File: hw7.cpp
 * Reference: none
 * @version: 123.0
 * Description: The program emits sequence variants and inversions. The program
 *              tests a class hierarchy of Sequence objects. The program allows
 *              a user guess word as many time as he / she wants until all words
 *              are guessed correctly or the user leaves the program.
 * Dependencies: none
 * State: Any state changes observed in the DerivedClass.
 * Assumption: none
 */

#include "Sequence.h"
#include "Repeater.h"
#include "Extractor.h"
#include "Variator.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Precondition: none
// Postconditon: return file size
int getFileSize(vector<string>&);

// Precondition: none
// Postconditon: display welcome message
void welcome();

// Precondition: none
// Postconditon: return if user wanna guess the word again
bool tryGuessAgain();

// Precondition: none
// Postconditon: return if user wanna test another word
bool testAnotherWord();

// Precondition: none
// Postconditon: return if the user wanna try another subsequence
bool tryOtherSubSeq();

// Precondition: none
// Postconditon: display goodbye message
void goodBye();

//Sequence** populateWord(int);

int main() {
    int fileSize;                       // file size
    int listSize;                       // size of sequence list
    int count = 0;                      // loop control variable
    int index = 0;                      // sequence pointer's index
    int wordIndex = 0;                  // loop control variable
    const int THREE = 3;                // loop control variable
    string wordInFile;                  // word' name
    ifstream inputFile;                 // input file stream
    srand(time(nullptr));               // initialized seed for random generator
    vector<string> wordCollection;

    fileSize = getFileSize(wordCollection);
    listSize = fileSize * 3;

    // declare Sequence pointer
    Sequence * sequenceList[listSize];

    while (index < listSize){
        wordInFile = wordCollection[wordIndex++];
        sequenceList[index++] = new Repeater(wordInFile);
        sequenceList[index++] = new Extractor(wordInFile);
        sequenceList[index++] = new Variator(wordInFile);
    }

    welcome();

    // Test first random three words
    while (count < 3) {
        bool guessAgain;        // the answer if the user wanna guess again
        int positionFirst;      // first position
        int positionSecond;     // second position
        int positionThird;      // third position
        int randNum;            // random number
        int remainder;          // remainder of calculation

        // get random position
        randNum = rand() % listSize;
        remainder = randNum / THREE;
        positionFirst = THREE * remainder;
        positionSecond = positionFirst + 1;
        positionThird = positionSecond + 1;

        // get a test word
        string word = sequenceList[positionFirst]->getWord();

        cout << "\n----------\n";
        printf("Testing word %d:\n", count + 1);

        // get the word's state
        State wordState = sequenceList[positionFirst]->getState();

        // get the word's repeater, extractor, and inverter
        printf("\nemit: %s\n", sequenceList[positionFirst]->
        getExecutedWord(wordState).c_str());
        printf("invert: %s\n", sequenceList[positionFirst]->
        getInvertedWord().c_str());

        printf("\nemit: %s\n", sequenceList[positionSecond]->
        getExecutedWord(wordState).c_str());
        printf("invert: %s\n", sequenceList[positionSecond]->
        getInvertedWord().c_str());

        printf("\nemit: %s\n", sequenceList[positionThird]->
        getExecutedWord(wordState).c_str());
        printf("invert: %s\n", sequenceList[positionThird]->
        getInvertedWord().c_str());

        // ask if the user wanna guess again
        do {
            string guess;   // the answer if user wanna guess again

            cout << "\nWhat is your guess? ";
            cin >> guess;

            // check if user input is same to the word
            if (guess == word) {

                // set word's state to inactive
                sequenceList[positionFirst]->setStateInactive();
                sequenceList[positionSecond]->setStateInactive();
                sequenceList[positionThird]->setStateInactive();
                cout << "That's correct!" << endl;
                guessAgain = false;
            } else {
                cout << "That is not correct." << endl;
                guessAgain = tryGuessAgain();
            }
        } while (guessAgain);

        // implement loop control variable
        count++;
    }

    cout << "\n----------\n"
            "Testing word 4 (additional functionality):\n";

    // ask if the user wanna test other words
    do{
        string userInput;           // user's input
        string otherHalfSubSeq;     // other half of subsequence
        bool guessAgain;            // answer if the user wanna guess again
        int randNum;                // random number
        int remainder;              // remainder of calculation
        int position;               // position index
        const int ONE = 1;          // constant control variable

        // get random position
        randNum = rand() % listSize;
        remainder = randNum / THREE;
        position = THREE * remainder + ONE;

        string word = sequenceList[position]->getWord();

        printf("\ninvert: %s\n", sequenceList[position]->
        getInvertedWord().c_str());

        // ask if user wanna try other subsequence
        do{
            // consume next line
            cin.ignore();

            cout << "\nprovide a subsequence: ";

            // cin.get() captures first character(index = 0) in a string to
            // check if it is '\n'.
            // Ex. once a user inputs qwert, cin.get() will capture q(index = 0)
            // to check if q is '\n' and leave wert for next operation.
            if (cin.get() == '\n')
                cout << "No Subsequence is provided.\n";
            else {
                // cin.unget() returns last captured character back to its
                // original index place in the original string
                // Ex. cin.unget() returns q back to wert and then the string
                // becomes its original string "qwert".
                cin.unget();
                cin >> userInput;

                // check if the user's input is a subsequence of the word
                if (dynamic_cast<Extractor *>(sequenceList[position])->
                validSubSeq(userInput)) {
                    // get other half of subsequence
                    otherHalfSubSeq = dynamic_cast<Extractor *>
                            (sequenceList[position])->
                            getOtherHalfSubSeq();
                    printf("emit: %s\n", otherHalfSubSeq.c_str());
                } else
                    cout << userInput << " is not a subsequence.\n";
            }
        } while(tryOtherSubSeq());


        // ask if the user wanna test another word
        do{
            string guess;       // the user's input
            cout << "\nWhat is your guess? ";
            cin >> guess;

            // check if the user's input is as same as the word
            if (guess == word) {

                // set word's state to inactive
                sequenceList[position]->setStateInactive();
                cout << "That's correct!" << endl;
                guessAgain = false;
            } else {
                cout << "That is not correct." << endl;

                // ask if the user wanna guess again
                guessAgain = tryGuessAgain();
            }
        } while (guessAgain);
    } while (testAnotherWord());

    goodBye();

    // free memory
    for (int i = 0; i < listSize; i++){
        delete sequenceList[i];
    }

    return 0;
}

int getFileSize(vector<string>& wordCollection){
    int fileSize = 0;       // initialize file size to 0
    ifstream inputFile;     // input file stream

    // open file
    inputFile.open("words.dat");

    // check if the file is open
    if (inputFile.is_open()){
        string str;                // loop control variable

        // populate words to wordCollection
        while(getline(inputFile,str)) {
            wordCollection.push_back(str);
            fileSize++;
        }

    } else {
        cout << "The file does not exist.\n";
        exit(0);
    }

    // close the file
    inputFile.close();

    return fileSize;
}

void welcome(){
    cout << "Welcome to the Sequence tester!\n";
}

bool testAnotherWord(){
    string ans;     // the answer if the user wanna test another word

    cout << "\nWould you like to test another word (y/n)? ";
    cin >> ans;

    return ans[0] != 'n' && ans[0] != 'N';
}

bool tryGuessAgain(){
    string ans;     // the answer if the user wanna guess another word

    cout << "Guess again (y/n)? ";
    cin >> ans;

    return ans[0] != 'n' && ans[0] != 'N';
}

bool tryOtherSubSeq(){
    string ans;     // the answer if the user wanna try another subsequence

    cout << "\nProvide another subsequence (y/n)? ";
    cin >> ans;

    return ans[0] != 'n' && ans[0] != 'N';
}

void goodBye(){
    cout << "\n----------\n"
            "Thanks for using the Sequence tester!\n";
}