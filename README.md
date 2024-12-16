# **Simple Shell Project**  

Welcome to the **Simple Shell** project! This is a Unix-like command-line shell built using **C**. It supports features like command execution, built-in commands (`cd`, `pwd`, `exit`), process management, I/O redirection, piping, and future GUI extensions. This README explains the project structure, implemented modules, and contribution guidelines.

---

## **Project Overview**  

The Simple Shell provides a basic CLI environment for executing system commands. It demonstrates core system-level programming concepts like process management, file handling, command parsing, I/O redirection, and inter-process communication.

---

## **Project Structure**  

```
Simple_Shell/
├── include/
│   └── shell.h               # Function declarations and constants
├── src/
│   ├── main.c                # Main entry point for the shell
│   ├── shell.c               # Core implementation of the shell
│   ├── redirection.c         # I/O redirection handling
│   ├── piping.c              # Piping feature implementation 
├── Makefile                  # Build automation file
└── README.md                 # Project documentation
```

---

## **Modules Implemented**  

### 1. **Core Shell Framework**  
- **Description:** Manages the shell's main execution loop and user input processing.  
- **Key Functions:**  
  - `read_input()` - Reads user input from the command line.  
  - `parse_input()` - Tokenizes the input into commands and arguments.  
  - Main loop runs continuously until terminated.

---

### 2. **Command Execution**  
- **Description:** Executes system commands using process management functions.  
- **Key Functions:**  
  - **Forking:** Creates child processes using `fork()`.  
  - **Execution:** Replaces the child process using `execvp()`.  
  - **Error Handling:** Displays errors using `perror()`.  
  - **Process Management:** Waits for child processes using `waitpid()`.

---

### 3. **Built-in Commands**  
- **Description:** Implements essential built-in commands.  

#### Supported Commands:  
1. **`cd [directory]`**  
   - Changes the current working directory using `chdir()`.  
   - Example: `cd /home/user`  

2. **`pwd`**  
   - Displays the current working directory using `getcwd()`.  
   - Example: `pwd`  

3. **`exit`**  
   - Exits the shell using `exit(EXIT_SUCCESS)`.  
   - Example: `exit`  

---

### 4. **I/O Redirection**  
- **Description:** Redirects input (`<`) and output (`>`) to/from files.  
- **Features:**  
  - **Output Redirection (`>`)**: Sends command output to a file.
    - Example: `echo "Hello" > output.txt`
  - **Input Redirection (`<`)**: Reads input for commands from a file.
    - Example: `cat < input.txt`
  - **Combined Redirection**: Supports simultaneous input and output redirection.
    - Example: `cat < input.txt > output.txt`

---

### 5. **Piping Support**  
- **Description:** Links the output of one command to the input of another using pipes (`|`).  
- **Key Functions:**  
  - Parses piped commands (`|`) into segments.  
  - Creates pipes using `pipe()`.  
  - Connects input/output streams using `dup2()`.

#### Example:  
```bash
ls -l | grep ".c" | wc -l
```

---

### 6. **Error Management**  
- **Description:** Centralized error handling for consistent user feedback.  
- **Key Functions:**  
  - Prints descriptive errors for command failures.  
  - Displays usage instructions for unsupported features.

---

### 7. **Utility Functions**  
- **Description:** Helper functions for tokenization, string processing, and memory management.  
- **Key Functions:**  
  - `tokenize_input()` - Splits input into tokens based on spaces or symbols.  
  - `trim_whitespace()` - Removes leading/trailing whitespace.

---

### 8. **Future Module: Graphical User Interface (GUI)**  
- **Description:** Planned implementation of a separate GUI using **C** libraries or a cross-platform GUI toolkit.  
- **Features Planned:**  
  - Custom command prompt themes with colorful output.  
  - Clickable command history.  
  - Real-time process monitoring with visual cues.

---

## **How to Build and Run**  

1. Clone the repository:  
   ```bash
   git clone https://github.com/Frank5ive/Simple_Shell.git
   cd Simple_Shell
   ```

2. Compile the project using `make`:  
   ```bash
   make
   ```

3. Run the shell:  
   ```bash
   ./simple_shell
   ```

---

## **How to Contribute**  

1. **Fork** the repository.  
2. **Create a branch** for your feature or bug fix:  
   ```bash
   git checkout -b feature-name
   ```  
3. **Make improvements** based on these suggestions:  

### **Suggested Features:**  
- Add new built-in commands like `echo`, `history`, or `clear`.  
- Implement environment variable management.  
- Add command history and auto-completion.  
- Enhance the GUI module with custom themes and animations.

4. **Commit your changes:**  
   ```bash
   git commit -m "Added new feature"
   ```  

5. **Push to your branch:**  
   ```bash
   git push origin feature-name
   ```  

6. Create a **Pull Request (PR)** with a detailed explanation.

---

## **License**  

This project is open-source and free to use under the MIT License.