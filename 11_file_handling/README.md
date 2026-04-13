# Lesson 11: File Handling

Everything we've done so far disappears the moment the program closes because variables only live in RAM. If we want permanent storage, we must write data to our Hard Drive using **File Handling**.

## The File Pointer
In C, we use a special pointer type called `FILE*` to interact with files. 

## 1. Opening a File
We use the `fopen` function which takes two arguments:
1. The **File Name** (or path).
2. The **Mode**.

### Common Modes:
- `"w"` (Write): Creates a new file. **WARNING:** If the file already exists, `"w"` deletes all its contents completely before writing!
- `"a"` (Append): Opens a file to add content to the *end* of it without deleting existing text.
- `"r"` (Read): Opens a file to read the data. Fails and returns `NULL` if the file doesn't exist.

## 2. Reading and Writing
- `fprintf()`: Behaves exactly like `printf()`, but instead of printing to the terminal screen, it prints text straight into your file!
- `fgets()`: Reads a line of text from the file until it hits a newline or the end of the file.

## 3. Closing a File
Just like dynamic memory, opening a file locks it in the Operating System. When you are done, you **MUST** call `fclose(filePointer)` to unlock and save the file properly!

Take a look at `main.c` where we will create a brand new file, write to it, and read it back!
