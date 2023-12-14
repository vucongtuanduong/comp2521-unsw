// runHashTable.c - a command-line interface to the HashTable ADT

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HashTable.h"

#define MAX 1024

static void processOptions(int argc, char *argv[]);
static void showUsage(char *progname);
static void showWelcomeMessage(void);
static int getCommand(char *buf);
static char **tokenize(char *s, int *ntokens);
static void freeTokens(char **tokens);
static void showHelp(void);

static void runInsert(HashTable ht, int argc, char *argv[]);
static void runDelete(HashTable ht, int argc, char *argv[]);
static void runContains(HashTable ht, int argc, char *argv[]);
static void runGet(HashTable ht, int argc, char *argv[]);
static void runGetOrDefault(HashTable ht, int argc, char *argv[]);
static void runSize(HashTable ht, int argc, char *argv[]);
static void runShow(HashTable ht, int argc, char *argv[]);
static void showCmdHelp(void);

////////////////////////////////////////////////////////////////////////

typedef struct command {
	char  *code;
	void (*fn)(HashTable, int, char **);
	char  *argHint;
	char  *helpMsg;
} Command;

static Command COMMANDS[] = {
	{"+", runInsert,       "<key> <value>",   "insert a key-value pair"},
	{"-", runDelete,       "<key>",           "delete a key-value pair"},
	{"c", runContains,     "<key>",           "checks if a key exists"},
	{"g", runGet,          "<key>",           "gets the value associated with a key"},
	{"f", runGetOrDefault, "<key> <default>", "same as 'g' but with default value"},
	{"s", runSize,         "",                "gets the number of keys"},
	{"p", runShow,         "",                "show the hash table"},
	{"?", NULL,            "",                "show this message"},
	{"q", NULL,            "",                "quit"},
};

////////////////////////////////////////////////////////////////////////

static bool ECHO = false;
static Command *currCommand = NULL;

int main(int argc, char *argv[]) {
	processOptions(argc, argv);
	showWelcomeMessage();

	HashTable ht = HashTableNew();
	bool done = false;
	char cmd[MAX + 1] = {0};

	while (!done && getCommand(cmd)) {
		if (ECHO) {
			printf("%s", cmd);
		}

		int ntokens = 0;
		char **tokens = tokenize(cmd, &ntokens);
		if (ntokens == 0) {
			free(tokens);
			continue;
		}

		char *cmdName = tokens[0];

		// Meta-commands
		if (strcmp(cmdName, "?") == 0) {
			showHelp();
		} else if (strcmp(cmdName, "q") == 0) {
			done = true;

		// Actual commands
		} else {
			bool validCommand = false;

			int numCommands = sizeof(COMMANDS) / sizeof(Command);
			for (int i = 0; i < numCommands; i++) {
				if (strcmp(cmdName, COMMANDS[i].code) == 0) {
					validCommand = true;
					currCommand = &COMMANDS[i];
					COMMANDS[i].fn(ht, ntokens, tokens);
				}
			}

			if (!validCommand) {
				printf("Unknown command '%s'\n", cmdName);
			}
		}
		freeTokens(tokens);
	}

	HashTableFree(ht);
}

static void processOptions(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-h") == 0) {
			showUsage(argv[0]);
			exit(EXIT_SUCCESS);
		} else if (strcmp(argv[i], "-e") == 0) {
			ECHO = true;
		}
	}
}

static void showUsage(char *progName) {
	printf("Usage: %s [options]...\n"
	       "Options:\n"
	       "    -h      show this help message\n"
	       "    -e      echo - echo all commands\n",
	       progName);
}

static void showWelcomeMessage(void) {
	printf("Interactive Hash Table Tester\n");
	printf("Enter ? to see the list of commands.\n");
}

static int getCommand(char *buf) {
	printf("> ");
	if (fgets(buf, MAX, stdin) != NULL) {
		int len = strlen(buf);
		if (len > 0 && buf[len - 1] != '\n') {
			buf[len] = '\n';
			buf[len + 1] = '\0';
		}
		return 1;
	} else {
		return 0;
	}
}

static char **tokenize(char *s, int *ntokens) {
	char *separators = " \t\n";
	*ntokens = 0;

	char **tokens = calloc((strlen(s) + 1), sizeof(*tokens));
	assert(tokens != NULL);

	while (*s != '\0') {
		s += strspn(s, separators);

		if (*s == '\0') {
			break;
		}

		size_t length = strcspn(s, separators);

		char *token = strndup(s, length);
		assert(token != NULL);
		s += length;

		tokens[*ntokens] = token;
		(*ntokens)++;
	}

	tokens[*ntokens] = NULL;

	tokens = realloc(tokens, (*ntokens + 1) * sizeof(*tokens));
	assert(tokens != NULL);

	return tokens;
}

static void freeTokens(char **tokens) {
	for (int i = 0; tokens[i] != NULL; i++) {
		free(tokens[i]);
	}
	free(tokens);
}

static void showHelp(void) {
	printf("Commands:\n");
	int numCommands = sizeof(COMMANDS) / sizeof(Command);
	for (int i = 0; i < numCommands; i++) {
		printf("%5s %-18s %s\n", COMMANDS[i].code, COMMANDS[i].argHint,
		                         COMMANDS[i].helpMsg);
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////
// Commands

static void runInsert(HashTable ht, int argc, char *argv[]) {
	if (argc != 3) {
		showCmdHelp();
		return;
	}

	int key = 0;
	int value = 0;
	char c;
	if (sscanf(argv[1], "%d%c", &key, &c) != 1) {
		printf("Error: Invalid key '%s'\n", argv[1]);
		return;
	}
	if (sscanf(argv[2], "%d%c", &value, &c) != 1) {
		printf("Error: Invalid value '%s'\n", argv[2]);
		return;
	}

	HashTableInsert(ht, key, value);
	printf("Inserted (%d, %d)\n", key, value);
}

static void runDelete(HashTable ht, int argc, char *argv[]) {
	if (argc != 2) {
		showCmdHelp();
		return;
	}

	int key = 0;
	char c;
	if (sscanf(argv[1], "%d%c", &key, &c) != 1) {
		printf("Error: Invalid key '%s'\n", argv[1]);
		return;
	}

	HashTableDelete(ht, key);
	printf("Deleted key %d\n", key);
}

static void runContains(HashTable ht, int argc, char *argv[]) {
	if (argc != 2) {
		showCmdHelp();
		return;
	}

	int key = 0;
	char c;
	if (sscanf(argv[1], "%d%c", &key, &c) != 1) {
		printf("Error: Invalid key '%s'\n", argv[1]);
		return;
	}

	bool result = HashTableContains(ht, key);
	printf("Hash table %s key %d\n",
	       result ? "contains" : "does not contain", key);
}

static void runGet(HashTable ht, int argc, char *argv[]) {
	if (argc != 2) {
		showCmdHelp();
		return;
	}

	int key = 0;
	char c;
	if (sscanf(argv[1], "%d%c", &key, &c) != 1) {
		printf("Error: Invalid key '%s'\n", argv[1]);
		return;
	}

	int value = HashTableGet(ht, key);
	printf("Value associated with key %d: %d\n", key, value);
}

static void runGetOrDefault(HashTable ht, int argc, char *argv[]) {
	if (argc != 3) {
		showCmdHelp();
		return;
	}

	int key = 0;
	int defaultValue = 0;
	char c;
	if (sscanf(argv[1], "%d%c", &key, &c) != 1) {
		printf("Error: Invalid key '%s'\n", argv[1]);
		return;
	}
	if (sscanf(argv[2], "%d%c", &defaultValue, &c) != 1) {
		printf("Error: Invalid default value '%s'\n", argv[2]);
		return;
	}

	int value = HashTableGetOrDefault(ht, key, defaultValue);
	printf("Value associated with key %d: %d\n", key, value);
}

static void runSize(HashTable ht, int argc, char *argv[]) {
	if (argc != 1) {
		showCmdHelp();
		return;
	}

	printf("Size: %d\n", HashTableSize(ht));
}

static void runShow(HashTable ht, int argc, char *argv[]) {
	if (argc != 1) {
		showCmdHelp();
		return;
	}

	HashTableShow(ht);
}

static void showCmdHelp(void) {
	printf("Usage: %s %s\n", currCommand->code, currCommand->argHint);
}

////////////////////////////////////////////////////////////////////////
