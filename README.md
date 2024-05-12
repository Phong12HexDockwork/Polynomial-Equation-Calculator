# Polynomial Arithmetic in C++

This C++ program performs arithmetic operations on polynomials, including addition, subtraction, multiplication, and division. It also optimizes equations and provides a structured approach to polynomial operations using classes.

## Features

- **Arithmetic Operations**: Perform addition, subtraction, multiplication, and division on polynomials.
- **Optimization**: Handles redundant parentheses and formats equations for better readability.
- **Loading Animation**: Displays a loading animation during calculations.
- **Platform Compatibility**: Clears the console based on the operating system for a better user experience.

# Explanation 

## Polynomial Division Class Explanation

The `Polynomial` class in C++ represents a polynomial expression and provides functionalities for creating, manipulating, and performing arithmetic operations on polynomial objects.

## Constructors

The class has multiple constructors:

- `Polynomial(unsigned deg)`: Constructs a polynomial of degree `deg` with all coefficients initialized to zero.
- `Polynomial(unsigned deg, initializer_list <double> cs)`: Constructs a polynomial of degree `deg` with coefficients specified in the initializer list `cs`.
- `Polynomial(initializer_list <double> cs)`: Constructs a polynomial with coefficients specified in the initializer list `cs`.
- `Polynomial(const vector<double>& cs)`: Constructs a polynomial with coefficients specified in the vector `cs`.

## Member Functions

- `degree()`: Returns the degree of the polynomial.
- `coefficients()`: Returns a reference to the vector containing the coefficients of the polynomial.

## Arithmetic Operators

The class overloads arithmetic operators to perform operations between polynomial objects:

- `operator+`: Addition of polynomials.
- `operator-`: Subtraction of polynomials.
- `operator*`: Multiplication of polynomials.
- `operator/`: Division of polynomials, returning a pair consisting of the quotient and remainder.

## Other Functions

- `truncate()`: Removes leading zero coefficients from the polynomial.

## Private Members

- `m_deg`: Represents the degree of the polynomial.
- `m_coeffs`: Vector containing the coefficients of the polynomial.

## Friend Function

- `operator<<`: Friend function to overload the output stream operator for printing polynomial objects.

## Example Usage

```cpp
Polynomial p1{2, {1, 2, 3}}; // Polynomial: 2x^2 + 3x + 1
Polynomial p2{3, {4, 5, 6, 7}}; // Polynomial: 7x^3 + 6x^2 + 5x + 4

Polynomial sum = p1 + p2; // Addition
Polynomial difference = p1 - p2; // Subtraction
Polynomial product = p1 * p2; // Multiplication
auto division = p1 / p2; // Division, returns a pair (quotient, remainder)

cout << "Sum: " << sum << endl;
cout << "Difference: " << difference << endl;
cout << "Product: " << product << endl;
cout << "Quotient: " << division.first << ", Remainder: " << division.second << endl;
