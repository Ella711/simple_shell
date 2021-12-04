#	Compliation Rules 
#	gcc -Wall -Werror -pedantic -Wextro -g -std=gnu89

CC = gcc 
CFLAG = -Wall -Werror -pedantic -Wextra -std=gnu89 -ggdb

shell:
	$(CC)$(CFLAG) *.c -o shell_alpha_V0.3
	valgrind --leak-check=full ./shell_alpha_V0.3

clean:
	rm -r shell_alpha_V0.3

