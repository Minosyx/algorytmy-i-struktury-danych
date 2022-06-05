CC = gcc
CFLAGS = -g -Wall -O0 -std=gnu99

num := $(strip $(word 2, $(MAKECMDGOALS)))

zadanie: 
	$(CC) $(CFLAGS) ./zadanie$(num)/*.c -o ./zadanie$(num)/zad$(num)
github-push:
	git add .
	git commit -m"$(num)"
	git push origin main
github-pull:
	git pull
%:
	@:
