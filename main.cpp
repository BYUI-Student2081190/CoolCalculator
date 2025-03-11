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

// Create the object and return the result. (This will be nice for memory management.)

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
            int conUserInput = std::stoi(userInput);

            // Quit the program.
            if (conUserInput == 5)
            {
                // Break the loop because the user is quiting the program.
                mainEnd = true;
            } else { // Do everything else.
                // Create type of problem UI for user.
                std::string problemSelected;
                std::string symbol;

                // Addition.
                if (conUserInput == 1) 
                {
                    problemSelected = "Addition Selected:";
                    symbol = "+";
                } else if (conUserInput == 2) { // Subtraction.
                    problemSelected = "Subtraction Selected: ";
                    symbol = "-";
                } else if (conUserInput == 3){ // Multiplication.
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
                    if (conUserInput != 4) {
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
            }
        } else {
            // Not in range and is not a number.
            std::cout << "Input not reconized... Please input a valid number." << std::endl;
            // Put thread to sleep for better UI.
            // NOTE: Maybe use an empty user input to do this instead...
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }

    // Quiting message.
    std::cout << "Thank you for using the Cool Calculator!" << std::endl;
    std::cout << "Have a cool day! :)" << std::endl;

    // End Main Function.
    return 0;

    // OLD MAIN. (Delete after new main is finished.)
    // // Test if you can send a message.
    // std::cout << "Hello World!" << std::endl;

    // // Test if you can save variables.
    // int number = 30;

    // // Test to see if you can send a message and have a variable in it.
    // std::cout << "My favorite number is " << number << "!" << std::endl;

    // // Create a variable to loop the while loop until condition is met.
    // bool loopBreak = false;

    // // Create a while loop to keep asking for a number until they enter a proper number.
    // while (loopBreak != true)
    // {
    //     // Create a string variable to hold the response.
    //     std::string input;
    //     std::cout << "What is your favorite number? (Please Enter:) ";
    //     std::cin >> input;

    //     // Test the input to see if we can leave the loop.
    //     if (isNumb(input)) 
    //     {
    //         // Set the break condition.
    //         loopBreak = true;

    //         // Send message.
    //         std::cout << "Your favorite number is " << input << "! That is so cool!" << std::endl;
    //     } else {
    //         // Set the break condition.
    //         loopBreak = false;

    //         // Send message.
    //         std::cout << "Your input was not a number... Please input a number." << std::endl;
    //     }
    // }

    // // Test counting section.
    // std::cout << "What to see me count?" << std::endl;
    // std::this_thread::sleep_for(std::chrono::seconds(5));

    // for (int i = 1; i <= 10; ++i)
    // {
    //     std::cout << i << "...";
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    // }

    // // Add a line end so the counting does not look weird.
    // std::cout << endl;

    // // Send message to see if we left the loop.
    // std::cout << "Thank you for hanging out with me! Talk to you later! :)" << std::endl;


    // // Test creating an object.
    // Calc obj(20);
    // std::cout << "Value of Object: " << obj.getValue() << std::endl;
    // obj.setValue(15);
    // std::cout << "New Value of Object: " << obj.getValue() << std::endl;
}