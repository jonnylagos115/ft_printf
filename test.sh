make re
make clean
gcc -Wall -Wextra ./srcs/*.c ./srcs/handle_datatypes/*.c ./main.c ./libftprintf.a
./a.out