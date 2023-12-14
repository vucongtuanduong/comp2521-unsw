// runGraph.c - a command-line interface to the Graph ADT

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Graph.h"

#define MAX 1024

static void processOptions(int argc, char *argv[]);
static void showUsage(char *progname);
static void showWelcomeMessage(void);
static int getCommand(char *buf);
static char **tokenize(char *s, int *ntokens);
static void freeTokens(char **tokens);
static void showHelp(void);

static void runNumVertices(Graph g, int argc, char *argv[]);
static void runNumEdges(Graph g, int argc, char *argv[]);
static void runIsAdjacent(Graph g, int argc, char *argv[]);
static void runInsertEdge(Graph g, int argc, char *argv[]);
static void runRemoveEdge(Graph g, int argc, char *argv[]);
static void runDegree(Graph g, int argc, char *argv[]);
static void runShow(Graph g, int argc, char *argv[]);
static void showCmdHelp(void);

////////////////////////////////////////////////////////////////////////

typedef struct command {
	char  *code;
	void (*fn)(Graph, int, char **);
	char  *argHint;
	char  *helpMsg;
} Command;

static Command COMMANDS[] = {
	{"v", runNumVertices,  "",          "get the number of vertices"},
	{"e", runNumEdges,     "",          "get the number of edges"},
	{"a", runIsAdjacent,   "<v> <w>",   "check if an edge exists"},
	{"+", runInsertEdge,   "<v> <w>",   "insert an edge"},
	{"-", runRemoveEdge,   "<v> <w>",   "remove an edge"},
	{"d", runDegree,       "<v>",       "get the degree of a vertex"},
	{"p", runShow,         "",          "show the graph"},
	{"?", NULL,            "",          "show this message"},
	{"q", NULL,            "",          "quit"},
};

////////////////////////////////////////////////////////////////////////

static bool ECHO = false;
static Command *currCommand = NULL;

int main(int argc, char *argv[]) {
	processOptions(argc, argv);
	showWelcomeMessage();

	Graph g = GraphNew(7);
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
					COMMANDS[i].fn(g, ntokens, tokens);
				}
			}

			if (!validCommand) {
				printf("Unknown command '%s'\n", cmdName);
			}
		}
		freeTokens(tokens);
	}

	GraphFree(g);
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
	printf("Interactive Graph Tester\n");
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

static void runNumVertices(Graph g, int argc, char *argv[]) {
	if (argc != 1) {
		showCmdHelp();
		return;
	}

	printf("The graph has %d vertices\n", GraphNumVertices(g));
}

static void runNumEdges(Graph g, int argc, char *argv[]) {
	if (argc != 1) {
		showCmdHelp();
		return;
	}

	printf("The graph has %d edges\n", GraphNumEdges(g));
}

static void runIsAdjacent(Graph g, int argc, char *argv[]) {
	if (argc != 3) {
		showCmdHelp();
		return;
	}

	int v = 0;
	int w = 0;
	char c;
	if (sscanf(argv[1], "%d%c", &v, &c) != 1) {
		printf("Error: Invalid vertex '%s'\n", argv[1]);
		return;
	}

	if (sscanf(argv[2], "%d%c", &w, &c) != 1) {
		printf("Error: Invalid vertex '%s'\n", argv[2]);
		return;
	}

	if (GraphIsAdjacent(g, v, w)) {
		printf("There is an edge between %d and %d\n", v, w);
	} else {
		printf("There is no edge between %d and %d\n", v, w);
	}
}

static void runInsertEdge(Graph g, int argc, char *argv[]) {
	if (argc != 3) {
		showCmdHelp();
		return;
	}

	int v = 0;
	int w = 0;
	char c;
	if (sscanf(argv[1], "%d%c", &v, &c) != 1) {
		printf("Error: Invalid vertex '%s'\n", argv[1]);
		return;
	}

	if (sscanf(argv[2], "%d%c", &w, &c) != 1) {
		printf("Error: Invalid vertex '%s'\n", argv[2]);
		return;
	}

	GraphInsertEdge(g, v, w);
	printf("Inserted edge between %d and %d\n", v, w);
}

static void runRemoveEdge(Graph g, int argc, char *argv[]) {
	if (argc != 3) {
		showCmdHelp();
		return;
	}

	int v = 0;
	int w = 0;
	char c;
	if (sscanf(argv[1], "%d%c", &v, &c) != 1) {
		printf("Error: Invalid vertex '%s'\n", argv[1]);
		return;
	}

	if (sscanf(argv[2], "%d%c", &w, &c) != 1) {
		printf("Error: Invalid vertex '%s'\n", argv[2]);
		return;
	}

	GraphRemoveEdge(g, v, w);
	printf("Removed edge between %d and %d\n", v, w);
}

static void runDegree(Graph g, int argc, char *argv[]) {
	if (argc != 2) {
		showCmdHelp();
		return;
	}

	int v = 0;
	char c;
	if (sscanf(argv[1], "%d%c", &v, &c) != 1) {
		printf("Error: Invalid vertex '%s'\n", argv[1]);
		return;
	}

	printf("Degree of %d is %d\n", v, GraphDegree(g, v));
}

static void runShow(Graph g, int argc, char *argv[]) {
	if (argc != 1) {
		showCmdHelp();
		return;
	}

	GraphShow(g);
}

static void showCmdHelp(void) {
	printf("Usage: %s %s\n", currCommand->code, currCommand->argHint);
}

////////////////////////////////////////////////////////////////////////
