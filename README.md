# Simple Shell

[![Contributors][contributors-shield]][contributors-url]

This is a simple implementation of the Shell command line. The Simple Shell interprets and executes the command line arguments read from the standard input. Read line by line from a file or the terminal line It then interprets the lines and executes them if the line is a valid command.

### File Index
|File           |Description    |
|:-:	          |---	          |
|[main.c](https://github.com/dany-eduard/simple_shell/blob/main/main.c)               |This file contains five functions, which are: The main function, as the main function, executes an infinite loop that in turn invoke the ```reading()``` function, this in turn obtains the line written in the standard input thanks to the getline function. Followed by these are ```sigint_handler()```, ```comparing()``` and ```executing()```. These are the 5 functions that allow reading signals and executing commands.               |
|[cases.c](https://github.com/dany-eduard/simple_shell/blob/main/cases.c)               |There are only two functions here. first ```errors()```, which is invoked to print error messages and ```semicolon()```, which allows handling of separators.               |
|[split.c](https://github.com/dany-eduard/simple_shell/blob/main/split.c)               |Here is only the ```split()``` function, it breaks the chain into segments or tokens depending on the delimiters that we impose on it, every time it finds one it will tokenize it.               |
|[string-handling.c](https://github.com/dany-eduard/simple_shell/blob/main/string-handling.c)               |It contains auxiliary functions that facilitate string manipulation.               |
|[builtin.c](https://github.com/dany-eduard/simple_shell/blob/main/builtin.c)               |               |
|               |               |


## Getting started
You only need a development environment for C. 

### Pre-requirements
* Compile with **gcc** v4.8.4
* Use the flags ```-Wall -Werror -Wextra and -pedantic```

### Installation

Follow these steps to test this project:
1) Clone this repo ```git clone https://github.com/dany-eduard/simple_shell.git```
2) Go to the project directory ```cd simple_shell```
3) Compile and test ```gcc -Wall -Werror -Wextra -pedantic *.c -o hsh```


### How it work
Simple Shell operates in both interactive and non-interactive mode. The user  may initiate simple shell and begin working or initate simple shell using commands meant to be run by the program. The first argument, argument 0 is understood to be the command to be  run by simple shell and arguments following as modifiers or options.

Simple shell may be invoked with the same functionality in interactive or non-interactive mode.  The user may quit the program  by  typing  "exit", "Ctrl + D", or "Ctrl + C" on the command line. When the program quits or a command has been executed, simple shell returns with a new prompt: "$ ". Look at the example:

![Example Simple_shell 2020-11-25 194147](https://raw.githubusercontent.com/dany-eduard/simple_shell/main/test/Example%20Simple_shell%202020-11-25%20194147.png)

## Testing
This simple Shell is expected to work in interactive mode:
```sh
linux@ubuntu $ ./hsh
$ /bin/ls
hsh main.c shell.c
$
$ exit
linux@ubuntu $
```
But also in non-interactive mode:
```c
linux@ubuntu $ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
linux@ubuntu $
linux@ubuntu $ cat test_ls_2
/bin/ls
/bin/ls
linux@ubuntu $
linux@ubuntu $ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
linux@ubuntu $
```


## Environment
* Language: C
* OS: Ubuntu 14.04 LTS
* Compiler: gcc 4.8.4
*  Style guidelines: [betty-style](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc-pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)  

## Authors ✒️
* **Kathe De Oro** - [Reina8540](https://github.com/Reina8540)
* **Daniel Eduardo** - [dany-eduard](https://github.com/dany-eduard)



[contributors-shield]: https://img.shields.io/github/contributors/dany-eduard/simple_shell?style=social&logo=appveyor
[contributors-url]: https://github.com/dany-eduard/simple_shell/graphs/contributors
