PROJECT_NAME = task_4
FLAGS = -Wall -Wextra -Werror -std=c11

$(PROJECT_NAME)_1: clean
	gcc $(FLAGS) $(PROJECT_NAME)_1.c list.c -o $(PROJECT_NAME)_1.out -lncurses
	./$(PROJECT_NAME)_1.out

$(PROJECT_NAME)_2: clean
	gcc $(FLAGS) $(PROJECT_NAME)_2.c queue.c -o $(PROJECT_NAME)_2.out
	./$(PROJECT_NAME)_2.out

clean:
	rm -rf *.out *.o *.s $(PROJECT_NAME)_1.out $(PROJECT_NAME)_2.out $(PROJECT_NAME)_3.out