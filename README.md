# Polynomial Arithmetic in C++

This C++ program performs arithmetic operations on polynomials, including addition, subtraction, multiplication, and division. It also optimizes equations and provides a structured approach to polynomial operations using classes.

## Features

- **Arithmetic Operations**: Perform addition, subtraction, multiplication, and division on polynomials.
- **Optimization**: Handles redundant parentheses and formats equations for better readability.
- **Loading Animation**: Displays a loading animation during calculations.
- **Platform Compatibility**: Clears the console based on the operating system for a better user experience.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/your_username/polynomial-arithmetic.git
   
2. Compile the source code:
   ```bash
   g++ main.cpp -o polynomial

3. Run the executable:
   ```bash
   ./polynomial

$ ./polynomial

========================Polynomial Arithmetic Program========================
+ Enter the first polynomial equation: 2x^3 + 3x^2 - x + 5
+ Enter the second polynomial equation: -x^2 + 4x - 1

( Computer @ hostname ) Calculating... \     # Loading animation
( Computer @ hostname ) Calculation complete!         

================================================================================
+ Multiplication and Division:

     - Product of two polynomials:   2x^5 + 5x^4 - 7x^3 + 26x^2 - 2x + 5
     - Quotient of two polynomials:  2x + 1
     - Remainder of two polynomials: 9x^2 - 3x + 4

+ Addition and Subtraction:

     - Sum of two polynomials:       2x^3 + 2x^2 + 3x + 4
     - Difference of two polynomials:2x^3 + 4x^2 - 4
=====================================END========================================

