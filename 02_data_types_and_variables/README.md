# Lesson 2: Data Types and Variables

In C, a **variable** is a storage location in the computer's memory, and its **data type** tells the computer what kind of information will be stored there.

## Basic Data Types
C requires you to explicitly declare what type of data your variable will hold. Here are the most common ones:

1. **`int` (Integer)**
   - Used for whole numbers (e.g., `10`, `-5`, `0`).
   - Format specifier for printing: `%d` (or `%i`)
   - Example: `int age = 25;`

2. **`float` (Floating Point)**
   - Used for decimal numbers with single precision (e.g., `3.14`, `-0.001`).
   - Format specifier for printing: `%f`
   - Example: `float pi = 3.14;`

3. **`double` (Double Floating Point)**
   - Like `float`, but has double the precision. Use this when you need highly accurate decimals.
   - Format specifier for printing: `%lf`
   - Example: `double exactPi = 3.14159265;`

4. **`char` (Character)**
   - Stores a single character enclosed in single quotes (e.g., `'A'`, `'z'`, `'?'`).
   - Format specifier for printing: `%c`
   - Example: `char grade = 'A';`

## Variable Declaration vs. Initialization
- **Declaration** is creating the variable: `int score;` (At this point, it holds a random "garbage" value from memory).
- **Initialization** is assigning it a value for the first time: `score = 100;`
- **Both at once:** `int score = 100;`

## Format Specifiers in `printf`
Unlike some modern languages, C doesn't let you just print objects smoothly into a string. You must use **format specifiers** (like `%d`, `%f`, `%c`) as placeholders in your `printf` text, and provide the variables as comma-separated arguments afterwards.

Let's look at `main.c` to see these types in action!
