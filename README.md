# Simple Shell

[![Contributors][contributors-shield]][contributors-url]

This is a simple implementation of the Shell command line. The Simple Shell interprets and executes the command line arguments read from the standard input. Read line by line from a file or the terminal line It then interprets the lines and executes them if the line is a valid command.

### File Index
|File           |Description    |
|:-:	          |---	          |
|               |               |
|               |               |
|               |               |
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
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

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
