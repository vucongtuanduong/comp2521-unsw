
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: goodCustomer badCustomer

goodCustomer: goodCustomer.c Account.c
badCustomer: badCustomer.c Account.c

.PHONY: clean
clean:
	rm -f goodCustomer badCustomer
