# GNL

A simple function that allows you to read one line from a file and returns it. The goal is to learn how to use ***file descriptors***, ***malloc()***, ***read()***, ***open()***, ***close()*** functions, and our ***libft library***.

get_next_line() takes 2 parameters : 

- An integer that represent the file descriptor (fd)
- The address of a string
                    
The function returns 3 differents values :

- ``-1`` which is an Error signal
- ``0`` which means that you reached the end of file
- ``1`` which means that you read one line and didn't reach end of file

GNL ***allocates memory***, make sure you free it when needed.

[GNL Main page](https://github.com/Cerveaulent/GNL)
