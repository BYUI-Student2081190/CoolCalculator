#include <iostream>
#include <string>
#include <cctype>
// Added these to use thread sleeping to create better UI.
#include <chrono>
#include <thread>
// Include the class into the main file.
#include "calc.cpp"

using namespace std;

// Test if number function.
bool isNumb(const string testNum)
{
    // Test if the input is empty.
    if (testNum.empty())
    {
        // Return false because this can't be empty.
        return false;
    }

    // Check to see what is a digit in the string.
    for (char c : testNum)
    {
        // Test to see if a character in the string is not a digit.
        if (!std::isdigit(c))
        {
            // If it is not a digit, then return false.
            return false;
        }
    }

    // If all these things check out, then return with an ok.
    return true;
}

// Test to see if input is in range. For menus and stuff.
bool inRange (const string testNum, const int minRange, const int maxRange)
{
    // Convert testNum to int.
    int conTestNum = std::stoi(testNum);

    // Test if it is in range.
    if (conTestNum >= minRange && conTestNum <= maxRange)
    {
        // Return true because this is good.
        return true;
    } else {
        // This is not in range.
        return false;
    }
}

// Test to see if number is 0.
bool isZero (const string textNum)
{
    // Convert to int.
    int num = std::stoi(textNum);

    // Check the value.
    if (num == 0)
    {
        return true;
    } else {
        return false;
    }
}

// Create the object and return the result.
int problemSolution(int numOne, int numTwo, int problemType) 
{
    // Create the object dynamically with new, giving it space on the heap.
    Calc *calc_pointer = new Calc(20);
    // Set the values of the object on the heap.
    (*calc_pointer).setProblem(numOne, numTwo, problemType);
    // Now run the problem, this will set the solution of the object on the heap.
    (*calc_pointer).runProblem();
    // Now save the solution to a variable to return to the main program.
    int solution = calc_pointer->getSolution(); // The arrow way to run these commands.

    // Now delete it to free space on the heep and prevent memory leaks.
    delete calc_pointer;
    calc_pointer = nullptr; // Good practice to reset the pointer to avoid dangling pointers.

    // Return the solution to the main function.
    return solution;
}

// Create secret menu.

// Main function being ran.
int main()
{
    // CURRENT MAIN.
    // Varible to break the loop.
    bool mainEnd = false;
    // Welcome the user to main and create a loop in main, until the user is done.
    std::cout << "Welcome to the Cool Calculator!" << std::endl;

    while (mainEnd != true) 
    {
        // Display options.
        std::cout << "What would you like to do today?" << std::endl;
        std::cout << "[1] Add" << std::endl;
        std::cout << "[2] Subtract" << std::endl;
        std::cout << "[3] Multiply" << std::endl;
        std::cout << "[4] Divide" << std::endl;
        std::cout << "[5] Quit" << std::endl;

        // Get the user input.
        std::string userInput;
        std::cout << "Please enter the number of the option you would like: ";
        std::cin >> userInput;
        // Check the input to see if it is 1.) a number, and 2.) in answer range.
        if (isNumb(userInput) && inRange(userInput, 1, 5))
        {
            // Convert the userInput to an int.
            int problemType = std::stoi(userInput);

            // Quit the program.
            if (problemType == 5)
            {
                // Break the loop because the user is quiting the program.
                mainEnd = true;
            } else { // Do everything else.
                // Create type of problem UI for user.
                std::string problemSelected;
                std::string symbol;

                // Addition.
                if (problemType == 1) 
                {
                    problemSelected = "Addition Selected:";
                    symbol = "+";
                } else if (problemType == 2) { // Subtraction.
                    problemSelected = "Subtraction Selected: ";
                    symbol = "-";
                } else if (problemType == 3){ // Multiplication.
                    problemSelected = "Multiplication Selected: ";
                    symbol = "*";
                } else { // Divison.
                    problemSelected = "Division Selected: ";
                    symbol = "/";
                }

                // Create a varible to break the loop.
                bool success = false;

                // Print the next part of UI.
                std::cout << problemSelected << std::endl;
                std::cout << "? " << symbol << " ? = ?" << std::endl;
                std::cout << "" << std::endl;
                // Create variable to hold input.
                std::string textNumOne;
                // First input check.
                while (success == false)
                {
                    std::cout << "Please enter the first number: ";
                    std::cin >> textNumOne;
                    // Preform checks on the input.
                    if (isNumb(textNumOne))
                    {
                        // Break the loop.
                        success = true;
                    } else {
                        // We don't leave until the input is good to go.
                        std::cout << "Input not a number." << std::endl;
                        success = false;
                    }
                }
                // Convert input one to a int.
                int numOne = std::stoi(textNumOne);
                // Display the current problem.
                std::cout << numOne << " " << symbol <<  " ? = ?" << std::endl;
                // Set success back to false for next check.
                success = false;
                // Create variable to hold second input.
                std::string textNumTwo;
                // Second input check.
                while (success == false)
                {
                    std::cout << "Please enter the second number: ";
                    std::cin >> textNumTwo;

                    // Create a check for division to prevent divison by 0.
                    if (problemType != 4) {
                        // Preform checks on the input.
                        if (isNumb(textNumTwo))
                        {
                            // Break the loop.
                            success = true;
                        } else {
                            // We don't leave until the input is good to go.
                            std::cout << "Input not a number." << std::endl;
                            success = false;
                        }
                    } else {
                        // Preform checks on the input.
                        if (isNumb(textNumTwo) && !isZero(textNumTwo))
                        {
                            // Break the loop.
                            success = true;
                        } else {
                            // We don't leave until the input is good to go.
                            std::cout << "Input not a number or cannot divide by 0." << std::endl;
                            success = false;
                        }
                    }
                }
                // Convert number two to a int.
                int numTwo = std::stoi(textNumTwo);

                // Let the user see their problem so far.
                std::cout << "Here is your problem: " << std::endl;
                std::cout << numOne << " " << symbol << " " << numTwo << " = ?" << std::endl;
                // Press enter to continue on to the next step.
                std::cout << "" << std::endl;
                std::cout << "Press 'enter' to continue: ";
                // Call this to clear up the inputs being accepted into the std bin.(If this is not cleared this will just move on because we already accepted an input before.)
                std::cin.ignore();
                // Use this to pause to continue on.
                std::cin.get();
                
                // Call the function to create an object and then display the result to the user.
                int result = problemSolution(numOne, numTwo, problemType);

                std::cout << "Here is the result:" << std::endl;
                std::cout << numOne << " " << symbol << " " << numTwo << " = " << result << std::endl;
                std::cout << "" << std::endl;
                std::cout << "The answer is: " << result << std::endl;
                std::cout << "" << std::endl;
                std::cout << "Press 'enter' to continue: ";
                std::cin.get();
            }
        } else {
            // Not in range and is not a number.
            std::cout << "Input not reconized... Please input a valid number." << std::endl;
            // Put an option to hit enter here to make it so you can continue back to selecting a better response.
            std::cout << "" << std::endl;
            std::cout << "Press 'enter' to continue: ";
            // Call this to clear up the inputs being accepted into the std bin.(If this is not cleared this will just move on because we already accepted an input before.)
            std::cin.ignore();
            // Use this to pause to continue on.
            std::cin.get();
        }
    }

    // Quiting message.
    std::cout << "Thank you for using the Cool Calculator!" << std::endl;
    std::cout << "Have a cool day! :)" << std::endl;

    // End Main Function.
    return 0;
}