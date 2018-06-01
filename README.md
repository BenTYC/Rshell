Assignment 4 - Redirection
===

Installation process
---

1. Get the code onto your local repo
	* `git clone https://github.com/cs100/cs100-assignment-2-nc-tc.git`
2. Get to the directory
	* `cd cs100-assignment-2-nc-tc`
	* `git checkout assn4`
3. make and run the file
	* `make`
	* `bin/rshell`


Overview of the assignment
---

Previously, we created a command shell known as Rshell as well the an expansion from assignment 3 that added the test command and the precedence operator. For assignment 4, the final update, we added redirection. Using the now added redirection, there is ease of use for redirecting standard input and output to where it is desired.

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


Task Distribution
---

BenTYC complete:
Task 2: Input redirection (For commands contain "<", 20%);
Task 3: output redirection (For commands contain ">" and ">>", 20%);
Task 4: Piping (25%)
total: 65%

noahchristensen complete:
Task 1: Github Setup (10%)
Task 5: construct test scripts (enough test cases, 15%)
Task 6: construct json and README files, and git commit (that means, all the works meaned from the part "Submission" to "Coding Conventions" in assignment 3 description)(10%) 
total: 35%
