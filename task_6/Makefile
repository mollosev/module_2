PROJECT_NAME = task_6
CFLAGS = -Wall -Wextra -Werror -std=c11

liblist.a: 
	gcc -c $(CFLAGS) list.c
	ar rcs liblist.a list.o 
	ranlib liblist.a

$(PROJECT_NAME)_1: clean liblist.a
	gcc $(CFLAGS) -c $(PROJECT_NAME)_1.c
	gcc $(CFLAGS) $(PROJECT_NAME)_1.o -o $(PROJECT_NAME)_1.out -L. -llist -lncurses
	./$(PROJECT_NAME)_1.out

$(PROJECT_NAME)_2: clean
	gcc $(CFLAGS) -fPIC -c list.c
	gcc $(CFLAGS) -shared list.o -o liblist.so
	gcc $(CFLAGS) -c $(PROJECT_NAME)_1.c -o $(PROJECT_NAME)_2.o
	gcc $(CFLAGS) $(PROJECT_NAME)_2.o -o $(PROJECT_NAME)_2.out -L. -llist -lncurses
	LD_LIBRARY_PATH = $(PWD):$(LD_LIBRARY_PATH) ./$(PROJECT_NAME)_2.out
	./$(PROJECT_NAME)_2.out

clean:
	rm -rf *.out *.o *.a *.so $(PROJECT_NAME)_1.out $(PROJECT_NAME)_2.out