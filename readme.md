# File I/O Basics in C

This repository demonstrates basic file I/O operations in C, showcasing the use of functions such as `fopen`, `fclose`, `fprintf`, `fscanf`, `fread`, `fwrite`, and `fseek`. The implementation includes examples of reading and writing text and binary data to files, along with managing file pointers to control where data is read from or written to.

## Table of Contents
- [Overview](#overview)
- [Prerequisites](#prerequisites)
- [File I/O Operations](#file-io-operations)
- [How to Use](#how-to-use)
- [Examples](#examples)
- [License](#license)

## Overview
File I/O in C allows us to store, retrieve, and manage data from files on disk. This repository demonstrates basic operations like:
- **Opening** and **closing** files
- **Writing** and **reading** formatted text and binary data
- **Seeking** within a file to read or write data at specific positions

The examples include both reading from and writing to text files (with `fprintf` and `fscanf`) and binary files (with `fread` and `fwrite`). `fseek` is used to navigate to specific parts of the file for more advanced control over file data.

## Prerequisites
- A C compiler such as GCC
- Basic knowledge of C programming

## File I/O Operations

### 1. Opening and Closing Files
- **`fopen`**: Opens a file with a specific mode (read, write, append, etc.).
- **`fclose`**: Closes an open file to free resources.

### 2. Writing to and Reading from Files
- **Text I/O**:
  - **`fprintf`**: Writes formatted text data to a file.
  - **`fscanf`**: Reads formatted text data from a file.
- **Binary I/O**:
  - **`fwrite`**: Writes binary data to a file.
  - **`fread`**: Reads binary data from a file.

### 3. Navigating Files
- **`fseek`**: Moves the file pointer to a specified location within the file, allowing for non-sequential access.

## How to Use

1. **Clone the repository**:
   ```bash
   git clone https://github.com/your-username/file-io-basics.git
   cd file-io-basics
   ```

2. **Compile the code**:
   Use the following command to compile the code files:
   ```bash
   gcc main.c -o file_io_example
   ```

3. **Run the program**:
   Execute the compiled program:
   ```bash
   ./file_io_example
   ```

## Examples

### Opening and Writing to a File
```c
FILE *fptr = fopen("example.txt", "w");
if (fptr == NULL) {
    printf("Error opening file!\n");
    return 1;
}
fprintf(fptr, "Hello, world!\n");
fclose(fptr);
```

### Reading from a File
```c
FILE *fptr = fopen("example.txt", "r");
if (fptr == NULL) {
    printf("Error opening file!\n");
    return 1;
}
char buffer[100];
fscanf(fptr, "%s", buffer);
printf("Read from file: %s\n", buffer);
fclose(fptr);
```

### Using `fseek` to Move the File Pointer
```c
FILE *fptr = fopen("example.dat", "rb");
if (fptr == NULL) {
    printf("Error opening file!\n");
    return 1;
}
fseek(fptr, 10, SEEK_SET); // Move 10 bytes from the start
// Continue reading or writing from the new position
fclose(fptr);
