

# Polynomial Arithmetic

[Phạm Thanh Phong](https://www.facebook.com/profile.php?id=100058046165384) 
[Nguyễn Ngô Thùy Trinh](https://www.facebook.com/profile.php?id=100086016403901)
[Vũ Thiên Vinh](https://www.facebook.com/vinhvuuuuu)
[Nguyễn Võ Yến Trang](https://www.facebook.com/nguyenvoyentrang15)
[Trần Ngọc Toàn Thắng](https://www.facebook.com/profile.php?id=100047881065625)
[Phan Lê Minh Thuận](https://www.facebook.com/thuanpl280104)
[Lương Tiểu Tuệ](https://www.facebook.com/luongtieutue2017)
[Phan Quốc Việt Anh](https://www.facebook.com/profile.php?id=100058046165384)


<img alt="Static Badge" src="https://img.shields.io/badge/codeforces-gray?style=plastic&logo=codeforces&label=2424&labelColor=%23de0a26&link=https%3A%2F%2Fcodeforces.com%2Fprofile%2Fneraxis"> 
<h3 align="left">Connect with me:</h3>
<p align="left">
<a href="https://linkedin.com/in/neraxis1210" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="neraxis1210" height="30" width="40" /></a>
<a href="https://codeforces.com/profile/neraxis" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/codeforces.svg" alt="neraxis" height="30" width="40" /></a>
</p>


<h3 align="left">Languages and Tools:</h3>
<p align="left"> <a href="https://www.cprogramming.com/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="40" height="40"/> </a> <a href="https://git-scm.com/" target="_blank" rel="noreferrer"> <img src="https://www.vectorlogo.zone/logos/git-scm/git-scm-icon.svg" alt="git" width="40" height="40"/> </a> <a href="https://www.linux.org/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/linux/linux-original.svg" alt="linux" width="40" height="40"/> </a> <a href="https://www.mathworks.com/" target="_blank" rel="noreferrer"> <img src="https://upload.wikimedia.org/wikipedia/commons/2/21/Matlab_Logo.png" alt="matlab" width="40" height="40"/> </a> </p>

This C++ program performs arithmetic operations on polynomials, including addition, subtraction, multiplication, and division. It also optimizes equations and provides a structured approach to polynomial operations using classes.

## 🚀 Features

- **Arithmetic Operations**: Perform addition, subtraction, multiplication, and division on polynomials.
- **Optimization**: Handles redundant parentheses and formats equations for better readability.
- **Loading Animation**: Displays a loading animation during calculations.
- **Platform Compatibility**: Clears the console based on the operating system for a better user experience.

# ⚙ Explanation 

### `solution_equation` Function

The `solution_equation` function parses a character array representing an equation, splitting it into individual components such as coefficients and exponents. Here's a breakdown of its functionality:

- **Inputs**: 
  - `equation`: A character array representing the equation to be processed.

- **Variables**:
  - `index`: An integer variable used as an index for storing components.
  - `base`, `exponent`: Integer variables to store the base and exponent of each term.
  - `str_number_equation`: An array of strings to store the components of the equation.
  - `pointer`, `number_equation`: Pointers used for parsing the equation.

![1](https://github.com/Phong12HexDockwork/Polynomial-Equation-Calculator/assets/99865968/14627066-625a-485e-bf20-cb2ac2762c1b)

- **Process**:
  1. The function initializes `index` to 0 and sets up variables for storing the base and exponent of each term.
  2. It defines an array `str_number_equation` to store the individual components of the equation.
  3. Using `strtok`, the function parses the input equation and stores each component in `str_number_equation`.
  4. It then iterates over the stored components and calls the `split_coefficient_exponent` function for each component.
  5. The loop continues until all components are processed.

- **Output**: 
  - The function does not return any value; instead, it populates global arrays with the coefficients and exponents of the equation.

### `process_string(char equation[])`:
- This function processes the input equation string to ensure correct handling of negative terms.
- It iterates through the string and checks for minus signs (`-`).
- If a minus sign is found, it checks if there's a space before it. If not, it inserts a space before the minus sign.
- Additionally, if there's a space after the minus sign, it removes that space.
- Finally, it returns the processed equation string.
  
![3](https://github.com/Phong12HexDockwork/Polynomial-Equation-Calculator/assets/99865968/7ebdf319-e6cf-424a-bd73-34adcfd0019c)

### `add_one(char equation[])`:
- This function adds a coefficient of 1 for terms where the coefficient is implicit.
- It iterates through the equation string and looks for specific characters (`)`, `(`, `+`, `-`, `*`, ` `) followed by `x`.
- When it finds such a pattern, it inserts a coefficient of 1 before the `x` term.
- This ensures that all terms have an explicit coefficient.
- It returns the modified equation string.

Both of these functions seem to prepare the equation strings for further processing or calculation.


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
  
![2](https://github.com/Phong12HexDockwork/Polynomial-Equation-Calculator/assets/99865968/852572e3-186c-4963-a697-c473f0fbaf56)

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
  
![image_2022_01_11T10_16_58_901Z-1024x463](https://github.com/Phong12HexDockwork/Polynomial-Equation-Calculator/assets/99865968/53d97474-0fe8-4c92-a7b5-5292c8f189d3)

- **Process**:
  1. The function dynamically allocates memory for the `productPolynomial` array, which will store the coefficients of the resulting polynomial. The size of this array is the sum of the sizes of the input polynomial arrays minus one, which is the maximum possible degree of the product polynomial.
  2. It initializes all elements of `productPolynomial` to zero.
  3. Using nested loops, the function multiplies each term of the first polynomial (`poly1`) with each term of the second polynomial (`poly2`) and adds the result to the corresponding index in `productPolynomial`.
  4. The outer loop iterates over the indices of `poly1`, and the inner loop iterates over the indices of `poly2`.
  5. For each pair of coefficients from `poly1` and `poly2`, their product is added to the corresponding index in `productPolynomial`, considering the correct degree.
  6. Once all multiplication operations are completed, the resulting `productPolynomial` array is returned.
 

### `Polynomial` Class

The `Polynomial` class represents a polynomial and provides various operations on polynomials, such as addition, subtraction, multiplication, division, and output. Let's break down the class and its methods:

- **Constructor Overloads**:
  - The class provides multiple constructors:
    1. `Polynomial(unsigned deg)`: Constructs a polynomial of a specified degree with all coefficients initialized to zero.
    2. `Polynomial(unsigned deg, initializer_list<double> cs)`: Constructs a polynomial with the specified degree and initializes coefficients using the provided initializer list.
    3. `Polynomial(initializer_list<double> cs)`: Constructs a polynomial using the provided initializer list, inferring the degree from the list size.
    4. `Polynomial(const vector<double>& cs)`: Constructs a polynomial using the provided vector of coefficients, inferring the degree from the vector size.

- **Member Functions**:
  - `degree()`: Returns the degree of the polynomial.
  - `coefficients()`: Returns a const reference to the vector of coefficients.
  - `operator+()`: Overloads the addition operator to perform polynomial addition.
  - `operator-()`: Overloads the subtraction operator to perform polynomial subtraction.
  - `operator*()`: Overloads the multiplication operator to perform polynomial multiplication.
  - `truncate()`: Truncates the polynomial by removing leading zero coefficients.
  - `operator/()`: Overloads the division operator to perform polynomial division, returning a pair of quotient and remainder.
  
- **Friend Function**:
  - `operator<<()`: Overloads the output stream operator to allow printing of polynomial objects. It formats the polynomial as a human-readable string, displaying each term with its coefficient and exponent.

- **Private Members**:
  - `m_deg`: An unsigned integer representing the degree of the polynomial.
  - `m_coeffs`: A vector of doubles representing the coefficients of the polynomial.

- **Explanation**:
  - The class encapsulates the behavior and properties of polynomials, allowing users to perform common operations and manipulate polynomials easily.
  - Overloaded operators enable intuitive usage of arithmetic operations on polynomial objects.
  - The `operator<<` function provides a convenient way to output polynomial objects for debugging or display purposes.

![Thiết kế chưa có tên](https://github.com/Phong12HexDockwork/Polynomial-Equation-Calculator/assets/99865968/c43f60f0-4fbf-4f06-ba59-30b96bc1ac46)

This class facilitates polynomial manipulation and computation in a clear and concise manner, making it easier to work with polynomials in various applications.

- **Output**:
  - The function returns a pointer to the `productPolynomial` array, which contains the coefficients of the product polynomial resulting from the multiplication of the two input polynomials.

This function efficiently calculates the product of two polynomials by performing the necessary multiplications and additions to obtain the coefficients of the resulting polynomial.

### `output_number` Function

The `output_number` function is responsible for printing a polynomial in a readable format. Let's analyze the function:

- **Input**:
  - `int saving_number[50]`: An array containing the coefficients of the polynomial.

- **Variables**:
  - `ping_check`: A boolean variable used to track whether 
any non-zero coefficients have been encountered.
  - `thread_check`: A boolean variable used to check if all coefficients are zero.

- **Functionality**:
  - The function iterates through the coefficients of the polynomial from the highest degree to the constant term.
  - It first checks if all coefficients are zero. If so, it prints "0" and exits.
  - Within the loop, it determines the appropriate representation for each coefficient based on its degree:
    - For the constant term (degree 0), it prints the absolute value of the coefficient.
    - For linear terms (degree 1), it prints the coefficient followed by "x".
    - For higher-degree terms, it prints the coefficient followed by "x^" and the degree.
  - If the coefficient of the next term is positive and `ping_check` is false (indicating that previous non-zero coefficients have been encountered), it prints "+" before the next term. If the coefficient is negative, it prints "-".
  - Finally, it checks if all coefficients are zero. If so, it prints "0" to ensure a valid polynomial representation.
  - It ends the output with a newline character.

- **Output**:
  - The function prints the polynomial representation based on the coefficients provided.

- **Explanation**:
  - This function ensures that the polynomial is displayed in a standard mathematical notation, making it easier for users to interpret.
  - It handles cases where certain terms may have zero coefficients, ensuring that the output is concise and accurate.
  - By printing terms in descending order of degree and handling sign placement appropriately, it provides a clear and readable representation of the polynomial.

Overall, this function plays a crucial role in visualizing polynomials, aiding users in understanding and working with polynomial expressions effectively.

## LISENCE 

```bash
© HCMUS - Physical and Engineering
@ University of Science - Vietnam National University
