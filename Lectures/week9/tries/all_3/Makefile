
CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: testTrie predict

testTrie: testTrie.c trie.c
	$(CC) $(CFLAGS) -o testTrie testTrie.c trie.c

predict: predict.c trie.c
	$(CC) $(CFLAGS) -o predict predict.c trie.c

.PHONY: clean
clean:
	rm -f testTrie predict

