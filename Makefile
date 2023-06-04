

all: chess

chess: 
	gcc -fsanitize=address *.c -o chess
# gcc *.c -o chess

re:
	rm chess
	make chess