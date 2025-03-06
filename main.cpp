#include <iostream>
#include <string>
#include <cctype>
#include <chrono>
#include <thread>

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

// Main function being ran
int main()
{
    // Test if you can send a message.
    std::cout << "Hello World!" << std::endl;

    // Test if you can save variables.
    int number = 30;

    // Test to see if you can send a message and have a variable in it.
    std::cout << "My favorite number is " << number << "!" << std::endl;

    // Create a variable to loop the while loop until condition is met.
    bool loopBreak = false;

    // Create a while loop to keep asking for a number until they enter a proper number.
    while (loopBreak != true)
    {
        // Create a string variable to hold the response.
        std::string input;
        std::cout << "What is your favorite number? (Please Enter:) ";
        std::cin >> input;

        // Test the input to see if we can leave the loop.
        if (isNumb(input)) 
        {
            // Set the break condition.
            loopBreak = true;

            // Send message.
            std::cout << "Your favorite number is " << input << "! That is so cool!" << std::endl;
        } else {
            // Set the break condition.
            loopBreak = false;

            // Send message.
            std::cout << "Your input was not a number... Please input a number." << std::endl;
        }
    }

    // Test counting section.

    std::cout << "What to see me count?" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));

    for (int i = 1; i <= 10; ++i)
    {
        std::cout << i << "...";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Add a line end so the counting does not look weird.
    std::cout << endl;

    // Send message to see if we left the loop.
    std::cout << "Thank you for hanging out with me! Talk to you later! :)" << std::endl;

    // End function.
    return 0;
}