// Source file for the header file of the class.
// Inport the header file.
#include "calc.h"

// Create the class functions.
// The Constructor.
Calc::Calc(int value) : data(value) {} //Set the incoming object value as the spot in data.

// Getters.
int Calc::getValue() const {
    return data;
}

int Calc::getSolution() const {
    return solution;
}

int Calc::getNumOne() const {
    return numOne;
}

int Calc::getNumTwo() const {
    return numTwo;
}

int Calc::getProblemType() const {
    return problemType;
}

// Setters.
void Calc::setProblem(int numOne, int numTwo, int problemType) {
    Calc::numOne = numOne;
    Calc::numTwo = numTwo;
    Calc::problemType = problemType;
}

// Calculation Functions.
void Calc::runProblem() {
    // Run the different equations based on what attributes the object has.
    if (problemType == 1) {
        // Set the solution to the answer.
        solution = numOne + numTwo;
    } else if (problemType == 2) {
        solution = numOne - numTwo;
    } else if (problemType == 3) {
        solution = numOne * numTwo;
    } else {
        // Make this the base for right now.
        solution = numOne / numTwo;
    }
}