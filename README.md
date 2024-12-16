# **Simple Shell Project**  

Welcome to the **Simple Shell** project! This is a basic Unix-like shell built using **C**. The shell supports essential features such as command execution, built-in commands (`cd`, `pwd`, `exit`), and process management. This README file explains the project structure, modules implemented, and guides future contributors for improvements.  

---

## **Project Overview**  

The Simple Shell mimics the functionality of a basic command-line interface. It processes user input, executes commands, and manages processes efficiently. It demonstrates core concepts of system-level programming, including process control, file handling, and custom command parsing.

---

## **Project Structure**  

```
Simple_Shell/
├── include/
│   └── shell.h            # Function declarations
├── src/
│   ├── main.c             # Main entry point for the shell
│   ├── shell.c            # Core implementation of the shell
├── Makefile               # Build automation file
└── README.md              # Project documentation
```

---

## **Modules Implemented**  

### 1. **Core Shell Framework**  
- **Description:** The shell’s main execution loop and user input processing.  
- **Key Functions:**  
  - `read_input()` - Reads user input from the command line.  
  - `parse_input()` - Tokenizes the input into command and arguments.  
  - Main loop runs continuously until terminated.

---

### 2. **Command Execution**  
- **Description:** Executes external system commands using process management functions.  
- **Key Functions:**  
  - **Forking:** Creates a child process using `fork()`.  
  - **Execution:** Replaces the child process with the new command using `execvp()`.  
  - **Error Handling:** Manages errors during execution using `perror()`.  
  - **Process Management:** Waits for child processes using `waitpid()`.

---

### 3. **Built-in Commands**  
- **Description:** Implements essential built-in commands.  

#### Supported Commands:  
1. **`cd [directory]`**  
   - Changes the current working directory using `chdir()`.  
   - Example: `cd /home/user`  

2. **`pwd`**  
   - Prints the current working directory using `getcwd()`.  
   - Example: `pwd`  

3. **`exit`**  
   - Exits the shell gracefully using `exit(EXIT_SUCCESS)`.  
   - Example: `exit`  

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

To contribute, follow these steps:  

1. **Fork** the repository.  
2. **Create a branch** for your feature or bug fix:  
   ```bash
   git checkout -b feature-name
   ```  
3. **Make improvements** based on these suggestions:  

### **Suggested Features:**  
- Add more built-in commands like `echo`, `history`, or `clear`.  
- Implement I/O redirection (`>`, `<`, `>>`).  
- Add piping support (`|`).  
- Add environment variable management.  
- Implement auto-completion and command history.

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

---