// This is a header file for the calculator class.
// Add protectors for the compiler.
#ifndef CALC_H // Open the header.
#define CALC_H

// Class declarations.
class Calc {
public:
    // Constructor.
    Calc(int value);
    // Getters.
    int getValue() const;
    int getSolution() const;
    int getNumOne() const;
    int getNumTwo() const;
    int getProblemType() const;
    // Setters.
    void setProblem(int numOne, int numTwo, int problemType);
    // Member Functions.
    int runProblem() const;
private:
    // Attributes.
    int data; // This is it's place in memory.
    int numOne;
    int numTwo;
    int problemType;
    int solution;
};

// Close the header.
#endif