Rshell
===

Overview 
---

Write a command shell called rshell in C++

Assignment 1: Design a simple UML diagram to represent components and their dependencies
Assignment 2: Implement basic command shell 
Assignment 3: Implement precedence operators and test command for Rshell
Assignment 4: Implement Redirect and Piping for Rshell

Assignment 1 
---

This assignment is to implement a command shell in C++. We use Composite Pattern and expression tree for our structure. For the expression tree, the nodes could be operations: “: || &&” and commands. So the node is our base structure. First, build the tree according to the rule of expression tree and return the root node. Then execute it from the leftmost child of the tree to the root. If a exit command execute, it breaks out the process.  
  
Our program includes /bin/ and /usr/bin/ to execute the commands. Besides, we implement function exit() to leave the process. Which are all implemented in the class CMD. The function execvp() can execute the command and return a boolean value for checking if it succeeds, which would be used for the operator: && and ||. As for the function execute(), for CMD is to execute the command, for operator is to combine the result of left child and right child.  


Assignment 2 
---



Assignment 3 
---

In assignment 3 we took took our previously created command shell known as Rshell and added more functionality. The assignment 2 rshell lacked two very needed commands. These were test and the precedence operators.

1. The Test Command
	* gives identity to any certain file or directory
	* prints (True) or (False) to screen
	* starts with either `test` or is surronded by `[` and `]`
	* uses the flags: `-e`, `-f`, `-d` or no flag at all
	* ex : `test -e directory` - determines whether directory exists
	* ex : `[ -f file ]` - determines whether "file" is actually a file

2. The Precedence Operators
	* can be used to give code within the operators precedence
	* works similarly to parentheses in math
	* defined by `(` and `)`
	* can be used in layers with parentheses in parentheses
	* ex : `(echo A && echo B) || (echo C && echo D)` - outputs A B

Assignment 4 
---

Previously, we created a command shell known as Rshell that have the test command and the precedence operator. There is ease of use for redirecting standard input and output to where it is desired.

1. Ouput Redirect
	* is denoted by `>`
	* takes the standard output of what's before `>`
	* then takes that standard output as input for what's after `>`
	* should be noted: replaces all previously existing contents
	* ex: `ls > list.out` - list.out contains result of ls

2. Append Redirect
	* is denoted by `>>`
	* takes the standard output of what's before `>>`
	* then takes that standard output as input for what's after `>>`
	* provides an alternative to `>` as it does not replace, it adds onto
	* ex: `ls >> list.out` - list.out contains result of ls after the end of what it previously held

3. Input Redirect
	* is denoted by `<`
	* takes the contents of what's after `<` as standard input
	* then takes the standard input to be used in what is before `<`
	* ex: `grep someVar < program.cpp` - prints to screen every line containing "someVar"

4. Piping
	* is denoted by `|`
	* links two commands and either side of `|` end to end
	* passes command output into the input of another command
	* ex: cat program.cpp | someVar` - prints to screen every line containing "someVar"


Bugs - Past and Current
---

* Test command with no flag gave a segmentation fault
	* now defaults the flag to `-e`
* Test command alone gave a segmentation fault
	* now outputs (False) automatically

* Redirection does not work for standard error (ie: 2>, &>)
* Not all functionalities are directly the same as the bash script
