#include <iostream>
#include <string>
#include <cctype>
// Include this library to use lists.
#include <list>
// Include the class into the main file.
#include "calc.cpp"

using namespace std;

// Create a global varible to hold the list of objects in the heap. (This list must be kept at at a max of 5 objects inside.)
std::list<Calc*> calc_list;

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

// Function that obtains an object from the heap and displays it for the user.
void viewMemory(int indexPlusOne)
{
    // Same idea as the deleteOnePointer except with a few changes.
    // First we need to convert the index into the proper one.
    int index = indexPlusOne - 1;

    // Now we loop to find the index of the matching memory object in the list.
    int count = 0;

    for(Calc *obj : calc_list) {
        // Look and see if we are at the index.
        if (count == index) {
            // Display the information to the user.
            std::cout << "------------------------------------------------" << std::endl;
            std::cout << "Memory No: " << indexPlusOne << std::endl;
            std::cout << "First Number: " << obj->getNumOne() << std::endl;
            std::cout << "Second Number: " << obj->getNumTwo() << std::endl;
            // Display the type of problem.
            if (obj->getProblemType() == 1) {
                std::cout << "Problem Type: Addition" << std::endl;
            } else if (obj->getProblemType() == 2) {
                std::cout << "Problem Type: Subtraction" << std::endl;
            } else if (obj->getProblemType() == 3) {
                std::cout << "Problem Type: Multiplication" << std::endl;
            } else {
                std::cout << "Problem Type: Division" << std::endl;
            }
            // Display the solution.
            std::cout << "Solution: " << obj->getSolution() << std::endl;
            // Display the full problem.
            if (obj->getProblemType() == 1) {
                std::cout << obj->getNumOne() << " + " << obj->getNumTwo() << " = " << obj->getSolution() << std::endl;
            } else if (obj->getProblemType() == 2) {
                std::cout << obj->getNumOne() << " - " << obj->getNumTwo() << " = " << obj->getSolution() << std::endl;
            } else if (obj->getProblemType() == 3) {
                std::cout << obj->getNumOne() << " * " << obj->getNumTwo() << " = " << obj->getSolution() << std::endl;
            } else {
                std::cout << obj->getNumOne() << " / " << obj->getNumTwo() << " = " << obj->getSolution() << std::endl;
            }
            std::cout << "------------------------------------------------" << std::endl;
            // Now break the loop.
            break;
        }

        // If it is not found, then we add one to count.
        count += 1;
    }

    // Tell them to press enter to continue.
    std::cout << "Press 'enter' to continue: ";
    // Call this to clear up the inputs being accepted into the std bin.(If this is not cleared this will just move on because we already accepted an input before.)
    std::cin.ignore();
    // Use this to pause to continue on.
    std::cin.get();

    // Return back to the original function.
    return;
}

// Function that dynamically deletes an object from the heap.
void deleteOnePointer(int index) 
{
    // Delete the obj at it's index.
    // To do this create a varible to count as we cycle through the list.
    int count = 0;

    // Now loop through the list.
    for (Calc *obj : calc_list) {
        // Look to see if we are at the index.
        if (count == index) {
            // Remove from the list.
            calc_list.remove(obj);
            // Delete the pointer.
            delete obj;
            obj = nullptr;
            // Now break out of the loop.
            break;
        }
        // Add one to our counter.
        count += 1;
    }
    // Return back to main function.
    return;
}

// Function that dynamically deletes all objects from the heap on close.
void deletePointers()
{
    // Check to see if it is empty.
    if (!calc_list.empty()) {
        // Loop through the list and delete all the pointers to free up memory.
        for (Calc *obj : calc_list) {
            // Delete the object to free up memory.
            delete obj;
            obj = nullptr; // Good practice to reset the pointer to avoid dangling pointers.
        }
        // Clear the list and return.
        calc_list.clear();
        // Return back to the previous function.
        return;
    } else {
        // Just return.
        return;
    }
}

// Create secret menu to handle calculator memory using the heap.
void secretMenu() 
{
    // This menu does not return anything it just does stuff.
    // Check to see if the list is empty if it is display a message and return to the original function.
    if (calc_list.empty())
    {
        std::cout << "You currently have no memory. :(\nPlease go and do some problems and come back after you are done." << std::endl;
        std::cout << "" << std::endl;
        // Create a return to the past function on hit of enter.
        std::cout << "Press 'enter' to continue: ";
        // Call this to clear up the inputs being accepted into the std bin.(If this is not cleared this will just move on because we already accepted an input before.)
        std::cin.ignore();
        // Use this to pause to continue on.
        std::cin.get();
        // Return.
        return;
    } else {
        // Create a loop to make sure they select a response.
        bool loopStop = false;
        // Ask them to select one they would like to use.
        while (loopStop != true) {
            // Create a variable to display the position of each memory object.
            int mem = 0;
            // Welcome the user.
            std::cout << "Welcome to memory! Here are the last " << calc_list.size() << " problems you have done so far:" << std::endl;
            // Display all the objects here using a for each loop.
            for (Calc *obj : calc_list) {
                // Set mem plus 1 for each object in the list.
                mem += 1;
                // Now display the object by it's problem type.
                if (obj->getProblemType() == 1) {
                    // Display it.
                    std::cout << "[" << mem << "] Addition" << std::endl;
                } else if (obj->getProblemType() == 2) {
                    std::cout << "[" << mem << "] Subtraction" << std::endl; 
                } else if (obj->getProblemType() == 3) {
                    std::cout << "[" << mem << "] Multiplication" << std::endl;
                } else {
                    std::cout << "[" << mem << "] Division" << std::endl;
                }

            }

            // Create one more to allow them to go back if they would like.
            std::cout << "[6] Go Back" << std::endl;
        
        
            std::string userInput;
            std::cout << "" << std::endl;
            std::cout << "Please select which one you would like to view: ";
            std::cin >> userInput;

            // Check the input to move on.
            if (isNumb(userInput)) {
                // Go on to the next check.
                // Convert userInput for here.
                int userNum = std::stoi(userInput);
                if (userNum == 6) 
                {
                    // End the loop.
                    loopStop = true;
                } else if (inRange(userInput, 1, mem)) {
                    // Take the user where they need to go and allow them to view it.
                    viewMemory(userNum);
                    // Don't break the loop because we will only break when they say to go back.
                    loopStop = false;
                } else {
                    // Let the user know their mistake.
                    std::cout << "The number you chose was not an option. Please select an option." << std::endl;
                }
            } else {
                // Error message, and then set loopStop to false.
                std::cout << "Input is not a number please try again." << std::endl;
                loopStop = false;
            }
        }
        
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

    if (calc_list.empty()) {
    // Add the new pointer to the back of the list.
    // IT IS VERY IMPORTANT TO MAKE SURE THAT THIS IS TAKEN CARE OF WITH A DELETE TO PREVENT MEMORY LEAKS.
    calc_list.push_back(calc_pointer);
    } else {
        // Check to see if the list has 5 items in it already.
        if (calc_list.size() == 5) {
            // Delete the first index, and then move on.
            deleteOnePointer(0);
            // Now add the new pointer.
            calc_list.push_back(calc_pointer);
        } else {
            // Add the new pointer to the back of the list.
            // IT IS VERY IMPORTANT TO MAKE SURE THAT THIS IS TAKEN CARE OF WITH A DELETE TO PREVENT MEMORY LEAKS.
            calc_list.push_back(calc_pointer);
        }
    }

    // Return the solution to the main function.
    return solution;
}

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
        std::cout << "[5] Memory" << std::endl;
        std::cout << "[6] Quit" << std::endl;

        // Get the user input.
        std::string userInput;
        std::cout << "Please enter the number of the option you would like: ";
        std::cin >> userInput;
        // Check the input to see if it is 1.) a number, and 2.) in answer range.
        if (isNumb(userInput) && inRange(userInput, 1, 6))
        {
            // Convert the userInput to an int.
            int problemType = std::stoi(userInput);

            // Quit the program.
            if (problemType == 6)
            {
                // Break the loop because the user is quiting the program.
                mainEnd = true;
            } else if (problemType == 5) { // Check the memory and see what past problems have been done.
                // Call the secret menu function to take over.
                secretMenu();
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

    // Things to do before quit, delete the pointers.
    deletePointers();

    // Quiting message.
    std::cout << "Thank you for using the Cool Calculator!" << std::endl;
    std::cout << "Have a cool day! :)" << std::endl;

    // End Main Function.
    return 0;
}