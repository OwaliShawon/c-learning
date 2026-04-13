# Lesson 4: Control Flow

Up until now, our code executed strictly top-to-bottom, line-by-line. **Control Flow** allows you to break this pattern! You can tell the program to skip code, repeat code, or make decisions.

## 1. Conditional Statements
Allow you to run code *only* if a certain condition is true.

- **`if` and `else`**: The bread and butter of decision-making.
  ```c
  if (age >= 18) {
      // Runs if the boolean condition is true (1)
  } else if (age > 12) {
      // Runs if the previous if was false, but this is true
  } else {
      // Catch-all if everything above was false (0)
  }
  ```

- **`switch`**: A cleaner way to write multiple `if` conditions when you are checking exactly equal values (usually against integers or characters).
  ```c
  switch (grade) {
      case 'A': 
          // Do something
          break; // Without break, it "falls through" to the next case!
      case 'B':
          // Do something else
          break;
      default:
          // Like 'else', runs if no cases match
  }
  ```

## 2. Loops (Iteration Statements)
Allow you to run a block of code multiple times.

- **`while` Loop**: Runs **as long as** the condition is true. Might execute zero times if the condition is false to begin with.
  ```c
  while (count < 5) {
      // Do something
      count++;
  }
  ```

- **`do-while` Loop**: Similar to `while`, but guarantees the code block runs **at least once** before checking the condition.
  ```c
  do {
      // Do something
  } while (false_condition);
  ```

- **`for` Loop**: The most compact loop. You declare the initialization, condition, and increment all on line one. Best used when you know exactly how many loops you want.
  ```c
  for (int i = 0; i < 5; i++) {
      // Do something 5 times
  }
  ```

Check out `main.c` to see how we write branching logic and loops!
