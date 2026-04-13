# Lesson 3: Operators in C

Operators are symbols that tell the compiler to perform specific mathematical, relational, or logical operations. Let's break down the most commonly used operators in C.

## 1. Arithmetic Operators
These perform common mathematical operations.
- `+` (Addition)
- `-` (Subtraction)
- `*` (Multiplication)
- `/` (Division) -> Note: dividing two integers drops the remainder! (e.g., `5 / 2` equals `2`)
- `%` (Modulus) -> Returns the remainder of division (e.g., `5 % 2` equals `1`). *Only works with integers.*
- `++` (Increment) -> Increases by 1 (`x++` or `++x`)
- `--` (Decrement) -> Decreases by 1 (`x--` or `--x`)

## 2. Relational Operators
These compare two values and return `1` if true, or `0` if false.
- `==` (Equal to)
- `!=` (Not equal to)
- `>` (Greater than), `<` (Less than)
- `>=` (Greater than or equal to), `<=` (Less than or equal to)

## 3. Logical Operators
Used to combine multiple relational expressions. They also return `1` (true) or `0` (false).
- `&&` (Logical AND): True only if **both** sides are true.
- `||` (Logical OR): True if **at least one** side is true.
- `!` (Logical NOT): Reverses the logical state of its operand.

## 4. Assignment Operators
Used to assign values to variables.
- `=` (Simple assignment)
- `+=`, `-=`, `*=`, `/=`, `%=` (Compound assignments) -> e.g., `x += 5` is exactly the same as `x = x + 5`.

Explore `main.c` to see examples of arithmetic, relational, and logical operators in code!
