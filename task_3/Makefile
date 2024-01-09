PROJECT_NAME = task_3
CFLAGS = -Wall -Wextra -Werror -std=c11

$(PROJECT_NAME)_1: clean
	gcc $(CFLAGS) $(PROJECT_NAME)_1.c -o $(PROJECT_NAME)_1.out -lncurses
	./$(PROJECT_NAME)_1.out

$(PROJECT_NAME)_2: clean
	gcc $(PROJECT_NAME)_2.c -o $(PROJECT_NAME)_2.out
	./$(PROJECT_NAME)_2.out 192.168.1.1 255.255.255.0 100

clean:
	rm -rf *.out *.o *.s *.out