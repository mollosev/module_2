PROJECT_NAME = task_2
FLAGS = -Wall -Wextra -Werror -std=c11

$(PROJECT_NAME)_1: clean
	gcc $(FLAGS) $(PROJECT_NAME)_1.c -o $(PROJECT_NAME)_1.out -lncurses
	./$(PROJECT_NAME)_1.out

$(PROJECT_NAME)_2: clean
	gcc $(FLAGS) $(PROJECT_NAME)_2.c -o $(PROJECT_NAME)_2.out -lncurses
	./$(PROJECT_NAME)_2.out

clean:
	rm -rf *.out *.o *.s $(PROJECT_NAME)_1.out $(PROJECT_NAME)_2.out