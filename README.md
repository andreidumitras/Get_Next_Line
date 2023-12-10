# Get_Next_Line
 - (C) June 2017

Get_Next_Line is a function that reades only one line from a given file specified by a file-descriptor.
The function is able to read form multiple files, and still remembering where it left for each file.
Using this function inside a loop, one may read the whole file, line by line.
The function returns 1 for successful reading and still remaining to read, 0 when successful reading but it was the last line read, and -1 if an error occurs.

The project was made during Academy+Plus, and it was designed for Linux/MacOS.
