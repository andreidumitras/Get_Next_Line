# Get_Next_Line
 - June 2017
 - Individual project
 - (c) Academy+Plus

# Description
Get_Next_Line is a function that read only one line from a given file. The file is given by a file descriptor. The function is able to read form multiple files, and still remembering where it left for another read.

The program was written during the first year of Academy+Plus and it was the third algorithms project for me. The goal of this project was to learn the usage of the static variables in C.
The project was initially designed for Linux/macOS.

# Implementation
The project was implemented using some functions from the Libft library. All the logic is inside get_next_line.c/.h files. The main.c file is presented for test purposes.

# Usage
The function can be called inside a loop, to read an entire file, line by line.
```c
while (get_next_line(fd, &line) >= 0)
{
    // print line or something
}
```
A full test example is presented in the main.c file.