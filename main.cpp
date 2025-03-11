#include <iostream>
#include <string>
#include <cctype>
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

// Main function being ran
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
            // Test this.
            std::cout << "That is in range" << std::endl;
            // Break loop for test.
            mainEnd = true;
        } else {
            // Not in range and is not a number.
            std::cout << "Input not reconized... Please input a valid number." << std::endl;
            // Put thread to sleep for better UI.
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }

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

    // End Main Function.
    return 0;
}