# Associative Matrix Using Binary Search Trees

This project implements an **associative matrix** in **C**, where entries are indexed by a unique **(string, integer)** key pair. The matrix is built using a **binary search tree (BST)** to efficiently store and retrieve data, demonstrating advanced data structures and memory management techniques in C.

---

## Features
- **Binary Search Tree (BST):**
  - Recursive insertion, traversal, and memory management.
  - Efficient indexing with string-integer pairs as keys.
- **Matrix Operations:**
  - Insert or update values indexed by keys.
  - Retrieve data for specific keys.
  - List all stored values in sorted order.
- **Dynamic Memory Management:**
  - Uses `malloc` and `free` to handle dynamic allocation safely.
- **Robust Input Handling:**
  - Reads input dynamically from the terminal or files.
  - Handles edge cases, such as duplicate keys and large datasets.

---

## Getting Started

### Prerequisites
- A **C compiler** like `gcc`.
- A terminal or IDE capable of running C programs (e.g., VSCode).

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/hzeesha/Associative-Matrix-Using-BSTs.git
   cd Associative-Matrix-Using-BSTs
2. Compile the program using the provided Makefile:
   ```bach
   make

## Usage

### Run the program interactively:
  ```bash
  ./mymatrix
```
  Enter a sequence of integer-string pairs, pressing Ctrl+D to terminate input. For example:
  70 Oxford Street
  10 Abbott Street
  101 Western Road
  10 Abbott Street

### Input from File
  You can also redirect input from a file:
  ```bash
  ./mymatrix < sampleInput.txt
``` 
  
### Example Output
  Number     Street                    Occurrence
  10         Abbott Street             2.000000
  70         Oxford Street             1.000000
  101        Western Road              1.000000

## File Structure
- datatype.c / datatype.h: Functions for managing keys and data types.
- bstree.c / bstree.h: Implementation of the binary search tree.
- matrix.c / matrix.h: Functions for managing the matrix structure.
- main.c: Entry point for the program.
- Makefile: Automates compilation and cleanup.
- sampleInput.txt: Sample input file for testing.

## Testing
1. Compile the program:
   ```bash
   make 
2. Run the program interactively or with input redirection:
   ```bash
   ./mymatrix < sampleInput.txt
3. make clean

## What You’ll Learn
- How to implement a binary search tree in C.
- Managing dynamic memory safely using malloc and free.
- Designing modular C programs with multiple files.
- Building efficient and scalable data structures.
