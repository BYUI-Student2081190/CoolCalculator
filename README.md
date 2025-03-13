# Overview

This software is a calculator with a working memory using C++. This project makes use of classes, loops, functions, and it also makes use of memory managment through the new and delete functions. The program can do basic math with ease and the memory is stored and deleted manually. How this works is by every time a user does a problem and gets an answer, their problem and answer are then allowed a place in memory with the new function and the pointer to that spot in memory is stored inside a list. When the list reaches a length of five the program automatically removes the first object in the list, and then clears up that spot in memory by deleting it using the delete function. It then destroys the pointer to prevent memory leaking. Another thing this program does right before it is closed it makes sure to delete all the memory being used by the software and then clears the list to prevent memory leakage as well. This allows for dynamic object creation and memory managment.

The purpose behind writing this software was to show myself that I could learn a new language. I know Python, C#, JavaScript, HTML, and CSS; but I did not know anything about C++. I decided to spend two weeks learning all that I could on C++ and then make a basic program in that time displaying what I was learning. I also made sure to do a lot of things the long hand way just so I could deepen my understanding of how C++ worked. Because of this I feel like my purpose was completed, and I feel confident that I can write in C++ and even learn more about it with greater ease and comfort.


# Development Environment

Tools:
- VSCode.

Programming Languages: 
- C++.

Libraries:
- iostream: This allowed the program to use input and outputs into the terminal.
- string: Used to allow the use of strings in c++.
- cctype: Used for seeing if varibles are certain types.
- list: Allowed for the creation of lists in c++.

# Useful Websites
- [Visual Studio Code - Docs : Getting Started](https://code.visualstudio.com/docs/cpp/introvideos-cpp)
- [Visual Studio Code - Docs : Getting the C++ Compiler](https://code.visualstudio.com/docs/cpp/config-mingw)
- [W3Schools - C++ Variable Types](https://www.w3schools.com/cpp/cpp_variables.asp)
- [W3Schools - C++ Operators](https://www.w3schools.com/cpp/cpp_operators.asp)
- [W3Schools - C++ While Loops](https://www.w3schools.com/cpp/cpp_while_loop.asp)
- [W3Schools - C++ For Loops](https://www.w3schools.com/cpp/cpp_for_loop.asp)
- [W3Schools - C++ For Each Loops](https://www.w3schools.com/cpp/cpp_for_loop_foreach.asp)
- [W3Schools - C++ Classes](https://www.w3schools.com/cpp/cpp_classes.asp)
- [W3Schools - C++ Lists](https://www.w3schools.com/cpp/cpp_list.asp)
- [Youtube - Professor Hank Stalica: C++ Create Your Own Class Header Files](https://www.youtube.com/watch?v=Yr2LNtrRIUs)
- [Youtube - Portfolio Courses: new & delete Operators For Dynamic Memory Allocation | C++ Tutorial](https://www.youtube.com/watch?v=wopESdEVJs4)

# Future Work
- Add a way to let the user manage their own memory within the system.
- Allow different cool features like getting the sum, solving for exponents, and other complex math.
- Add a way to add, subtract, multiply, and divide decimals.