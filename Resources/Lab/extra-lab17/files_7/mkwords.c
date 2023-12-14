// mkwords.c ... Generate random "words"
// Written by John Shepherd, October 2015

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void usage(char *progname);

int main(int argc, char *argv[]) {
	int nwords;    // # words to generate
	int seed;      // seed for rand # generator

	// set up parameters
	switch (argc) {
		case 2:
			nwords = atoi(argv[1]);
			seed = 42;
			break;
		case 3:
			nwords = atoi(argv[1]);
			seed = atoi(argv[2]);
			break;
		default:
			usage(argv[0]);
			return 1;
	}
	srand(seed);

	// array of letters, to simulate distribution of letters in English
	char *letters = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
	                "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	                "rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr"
	                "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii"
	                "ooooooooooooooooooooooooooooooooooooo"
	                "ttttttttttttttttttttttttttttttttttt"
	                "nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn"
	                "sssssssssssssssssssssssssssss"
	                "llllllllllllllllllllllllllll"
	                "ccccccccccccccccccccccc"
	                "uuuuuuuuuuuuuuuuuuu"
	                "ddddddddddddddddd"
	                "pppppppppppppppp"
	                "mmmmmmmmmmmmmmm"
	                "hhhhhhhhhhhhhhh"
	                "ggggggggggggg"
	                "bbbbbbbbbbb"
	                "fffffffff"
	                "yyyyyyyyy"
	                "wwwwwww"
	                "kkkkkk"
	                "vvvvv"
	                "x"
	                "z"
	                "j"
	                "q";
	
	int nletters = strlen(letters);

	// generate some words
	// each "word" consists of 2..15 random lower-case letters
	int i, j, len;
	char word[17];
	for (i = 0; i < nwords; i++) {
		len = rand() % 14 + 2;
		for (j = 0; j < len; j++) {
			word[j] = letters[rand() % nletters];
		}
		word[j] = '\n';
		word[j + 1] = '\0';
		fputs(word, stdout);
	}
}

static void usage(char *progname) {
	fprintf(stderr, "Usage: %s #words Seed\n", progname);
	exit(1);
}

