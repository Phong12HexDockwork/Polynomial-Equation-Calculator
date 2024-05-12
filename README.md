# Polynomial Arithmetic in C++

This C++ program performs arithmetic operations on polynomials, including addition, subtraction, multiplication, and division. It also optimizes equations and provides a structured approach to polynomial operations using classes.

## Features

- **Arithmetic Operations**: Perform addition, subtraction, multiplication, and division on polynomials.
- **Optimization**: Handles redundant parentheses and formats equations for better readability.
- **Loading Animation**: Displays a loading animation during calculations.
- **Platform Compatibility**: Clears the console based on the operating system for a better user experience.

# Explanation 

# Polynomial Equation Processing Code Explanation

The provided code contains functions for processing, optimizing, and performing operations on polynomial equations. Let's break down each function:

## `process_string`

This function processes a string representing a polynomial equation. It mainly handles removing unnecessary spaces and ensuring proper formatting around negative signs.

## `add_one`

This function adds a coefficient of 1 to variables in the polynomial equation that don't have a coefficient specified. It also ensures proper spacing and formatting.

## `identify_parentheses`

This function identifies and optimizes parentheses in the equation. It extracts equations within parentheses, expands them if needed, and removes the parentheses. Additionally, it performs operations on the extracted equations and integrates them back into the main equation.

## `solution_equation`

This function splits the equation into individual components, such as coefficients and exponents, and stores them for further processing.

## `split_coefficient_exponent`

This function splits a coefficient and an exponent from a given equation string and saves them for later use.

## `multiplyTwoPolynomials`

This function multiplies two polynomial equations represented as arrays of coefficients and returns the resulting polynomial.

## `Polynomial` class

This class represents a polynomial equation and provides methods for addition, subtraction, multiplication, division, and truncation. It also overloads the output stream operator for printing polynomial objects.

Overall, these functions and the `Polynomial` class offer a comprehensive toolkit for processing, optimizing, and performing operations on polynomial equations.

