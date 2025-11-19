# C File CLI Utilities

A lightweight, terminal-based utility for performing common file operations in Linux. Built with C for performance and efficiency.

![C](https://img.shields.io/badge/Language-C-blue)
![Platform](https://img.shields.io/badge/Platform-Linux-green)

## 🚀 Overview
This project is a modular command-line interface (CLI) that allows users to manipulate text files directly from the terminal. It demonstrates low-level file handling, memory management, and stream processing in C.

I built this to deepen my understanding of:
* **File I/O Streams:** `fopen`, `fgets`, `fscanf`.
* **Memory Management:** Buffer handling and pointer manipulation.
* **Algorithm Design:** Efficient line-by-line comparison and searching.

## ⚡ Features
* **📄 File Reader:** Display content of any text file.
* **🔍 Word Counter:** Frequency analysis of specific terms within a file.
* **🔗 Concatenator:** Merge two separate files into a new output stream.
* **📊 Line Counter:** Rapidly calculate line counts for large text files.
* **⚖️ File Comparator:** Diff-checker that identifies the exact line number where two files diverge.

## 🛠️ Installation & Usage

### Prerequisites
* GCC Compiler (Standard on most Linux distros)
* Make (Optional, or compile manually)

### Quick Start
1.  **Clone the repository:**
    ```bash
    git clone https://github.com/0xYurii/c-file-handling-utils.git
    cd c-file-cli-utils
    ```

2.  **Compile the program:**
    ```bash
    gcc main_menu.c -o fileutil
    ```

3.  **Run the tool:**
    ```bash
    ./fileutil
    ```

## 🧠 Code Structure
The project follows a modular design pattern:
* `main_menu.c`: Handles the CLI loop and user input sanitization.
* `modules/`: (Optional: if you split files later) Contains specific logic for text processing.
