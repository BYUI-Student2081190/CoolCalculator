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
    // Setters.
    void setValue(int value);
    // Member Functions.
    // Attributes.

private:
    // Attributes.
    int data;
};

// Close the header.
#endif