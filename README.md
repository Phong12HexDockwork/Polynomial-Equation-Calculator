# Polynomial Arithmetic in C++

This C++ program performs arithmetic operations on polynomials, including addition, subtraction, multiplication, and division. It also optimizes equations and provides a structured approach to polynomial operations using classes.

## Features

- **Arithmetic Operations**: Perform addition, subtraction, multiplication, and division on polynomials.
- **Optimization**: Handles redundant parentheses and formats equations for better readability.
- **Loading Animation**: Displays a loading animation during calculations.
- **Platform Compatibility**: Clears the console based on the operating system for a better user experience.

# Explanation 

### `solution_equation` Function

The `solution_equation` function parses a character array representing an equation, splitting it into individual components such as coefficients and exponents. Here's a breakdown of its functionality:

- **Inputs**: 
  - `equation`: A character array representing the equation to be processed.

- **Variables**:
  - `index`: An integer variable used as an index for storing components.
  - `base`, `exponent`: Integer variables to store the base and exponent of each term.
  - `str_number_equation`: An array of strings to store the components of the equation.
  - `pointer`, `number_equation`: Pointers used for parsing the equation.

- **Process**:
  1. The function initializes `index` to 0 and sets up variables for storing the base and exponent of each term.
  2. It defines an array `str_number_equation` to store the individual components of the equation.
  3. Using `strtok`, the function parses the input equation and stores each component in `str_number_equation`.
  4. It then iterates over the stored components and calls the `split_coefficient_exponent` function for each component.
  5. The loop continues until all components are processed.

- **Output**: 
  - The function does not return any value; instead, it populates global arrays with the coefficients and exponents of the equation.

### `split_coefficient_exponent` Function

The `split_coefficient_exponent` function extracts the coefficient and exponent from a given term in the equation. Here's an explanation of its functionality:

- **Inputs**: 
  - `equation`: A string representing a term in the equation.
  - `base`, `exponent`: References to integer variables to store the extracted coefficient and exponent.

- **Variables**:
  - `x_pos`, `pow_pos`: Size_t variables storing the positions of 'x' and '^' characters in the term.

- **Process**:
  1. The function searches for the positions of 'x' and '^' characters in the term using the `find` method of the string class.
  2. Based on the positions found, it extracts the coefficient and exponent from the term.
  3. If 'x' or '^' characters are not found, default values are assigned to `base` and `exponent`.
  4. The extracted coefficient and exponent are then used to update global arrays storing polynomial information.

- **Output**: 
  - The function updates global arrays with the extracted coefficient and exponent information.

This pair of functions work together to break down the equation into its constituent parts and extract relevant information, facilitating further processing and manipulation of the polynomial equation.

### `multiplyTwoPolynomials` Function

The `multiplyTwoPolynomials` function calculates the product of two polynomial arrays representing coefficients of polynomials. Here's a detailed explanation:

- **Inputs**:
  - `poly1`: An array representing the coefficients of the first polynomial.
  - `poly2`: An array representing the coefficients of the second polynomial.
  - `size_poly1`: The size of the `poly1` array.
  - `size_poly2`: The size of the `poly2` array.

- **Variables**:
  - `productPolynomial`: A dynamically allocated integer array to store the coefficients of the resulting polynomial.

- **Process**:
  1. The function dynamically allocates memory for the `productPolynomial` array, which will store the coefficients of the resulting polynomial. The size of this array is the sum of the sizes of the input polynomial arrays minus one, which is the maximum possible degree of the product polynomial.
  2. It initializes all elements of `productPolynomial` to zero.
  3. Using nested loops, the function multiplies each term of the first polynomial (`poly1`) with each term of the second polynomial (`poly2`) and adds the result to the corresponding index in `productPolynomial`.
  4. The outer loop iterates over the indices of `poly1`, and the inner loop iterates over the indices of `poly2`.
  5. For each pair of coefficients from `poly1` and `poly2`, their product is added to the corresponding index in `productPolynomial`, considering the correct degree.
  6. Once all multiplication operations are completed, the resulting `productPolynomial` array is returned.

- **Output**:
  - The function returns a pointer to the `productPolynomial` array, which contains the coefficients of the product polynomial resulting from the multiplication of the two input polynomials.

This function efficiently calculates the product of two polynomials by performing the necessary multiplications and additions to obtain the coefficients of the resulting polynomial.
