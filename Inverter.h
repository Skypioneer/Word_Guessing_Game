/**
 * @author: Jason Wang
 * File: Inverter.h
 * Reference: none
 * @version: 123.0
 * Description: an interface class being implemented in Sequence Class
 * Dependencies: a parent Class
 * State: Any state changes observed in the DerivedClass.
 * Assumption: none
 */

#ifndef HW7_INVERTER_H
#define HW7_INVERTER_H
#include "Sequence.h"
#include <string>
using namespace std;

class Inverter{
public:

    // pure virtual function
    virtual string getInvertedWord() = 0;
};

#endif //HW7_INVERTER_H
