// Implementation of the Maze ADT

// !!! DO NOT MODIFY THIS FILE !!!

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "cell.h"
#include "Maze.h"

#define CLEAR_SCREEN_ANSI "\e[1;1H\e[2J"

typedef enum {
    NONE,
    VISITED,
    PATH,
} State;

struct maze {
    int height;
    int width;
    struct cell start;
    bool **cells;

    State **state;
    bool firstPrint;
    struct cell prev;
    struct cell curr;
};

static int pauseMs = 200;

////////////////////////////////////////////////////////////////////////

static bool readDimensions(Maze m, FILE *fp);
static bool readStart(Maze m, FILE *fp);
static bool readExit(Maze m, FILE *fp);
static bool readCells(Maze m, FILE *fp);
static bool createState(Maze m);

static void freeCells(Maze m);
static void freeState(Maze m);

static void showState(Maze m, struct cell c);
static void showFullState(Maze m, struct cell c);
static void showUpdatedState(Maze m, struct cell c);
static void printCell(Maze m, int row, int col, struct cell c);

static bool validCell(Maze m, struct cell c);

////////////////////////////////////////////////////////////////////////

Maze MazeRead(FILE *fp) {
    Maze m = malloc(sizeof(*m));
    if (m == NULL) {
        fprintf(stderr, "error: out of memory\n");
        return NULL;
    }
    
    if (!(readDimensions(m, fp) && readCells(m, fp))) {
        free(m);
        return NULL;
    }

    if (!(readStart(m, fp) && readExit(m, fp) && createState(m))) {
        freeCells(m);
        free(m);
        return NULL;
    }
    
    m->firstPrint = true;
    m->prev = (struct cell){-1, -1};
    return m;
}

static bool readDimensions(Maze m, FILE *fp) {
    char *line = NULL;
    size_t n = 0;
    bool res;

    if (!(res = (getline(&line, &n, fp) > 0 &&
            sscanf(line, "%d %d", &m->height, &m->width) == 2))) {
        fprintf(stderr, "error: failed to read maze dimensions\n");
    } else if (!(res = (m->height > 0 && m->width > 0))) {
        fprintf(stderr, "error: invalid maze dimensions\n");
    }

    free(line);
    return res;
}

static bool readCells(Maze m, FILE *fp) {

    //////////////////////////////
    // allocate everything first

    char *line = malloc((m->width + 2) * sizeof(char));
    if (line == NULL) {
        fprintf(stderr, "error: out of memory\n");
        return false;
    }

    m->cells = calloc(m->height, sizeof(bool *));
    if (m->cells == NULL) {
        fprintf(stderr, "error: out of memory\n");
        free(line);
        return false;
    }

    for (int i = 0; i < m->height; i++) {
        m->cells[i] = malloc(m->width * sizeof(bool));
        if (m->cells[i] == NULL) {
            fprintf(stderr, "error: out of memory\n");
            freeCells(m);
            free(line);
            return false;
        }
    }

    //////////////////////////
    // now read in the cells

    size_t n = m->width + 2;
    for (int i = 0; i < m->height; i++) {
        if (getline(&line, &n, fp) < m->width) {
            fprintf(stderr, "error: not enough cells on row %d\n", i);
            freeCells(m);
            free(line);
            return false;
        }

        for (int j = 0; j < m->width; j++) {
            switch (line[j]) {
                case '#': m->cells[i][j] = true;  break;
                case ' ': m->cells[i][j] = false; break;
                default:
                    fprintf(stderr, "error: unknown cell character '%c'\n",
                            line[j]);
                    freeCells(m);
                    free(line);
                    return false;
            }
        }
    }

    free(line);
    return true;
}

static bool readStart(Maze m, FILE *fp) {
    char *line = NULL;
    size_t n = 0;
    bool res;

    if (!(res = (getline(&line, &n, fp) > 0 &&
            sscanf(line, "%d %d", &m->start.row, &m->start.col) == 2))) {
        fprintf(stderr, "error: failed to read starting cell\n");
    } else if (!(res = validCell(m, m->start))) {
        fprintf(stderr, "error: invalid starting cell\n");
    } else if (!(res = !MazeIsWall(m, m->start))) {
        fprintf(stderr, "error: starting cell is a wall cell\n");
    }

    free(line);
    return res;
}

static bool readExit(Maze m, FILE *fp) {
    // What the hell are you looking at? This is an ADT, you shouldn't
    // be looking at the implementation. Close this file right now or
    // the ADT police will come after you.

    char *line = NULL;
    size_t n = 0;
    bool res;

    if (!(res = (getline(&line, &n, fp) > 0 &&
            sscanf(line, "%d %d", &m->curr.row, &m->curr.col) == 2))) {
        
        fprintf(stderr, "error: failed to read exit cell\n");
    } else if (!(res = validCell(m, m->curr))) {
        fprintf(stderr, "error: invalid exit cell\n");
    } else if (!(res = !MazeIsWall(m, m->curr))) {
        fprintf(stderr, "error: exit cell is a wall cell\n");
    }

    free(line);
    return res;
}

static bool createState(Maze m) {
    m->state = calloc(m->height, sizeof(State *));
    if (m->state == NULL) {
        fprintf(stderr, "error: out of memory\n");
        return false;
    }

    for (int i = 0; i < m->height; i++) {
        m->state[i] = malloc(m->width * sizeof(State));
        if (m->state[i] == NULL) {
            fprintf(stderr, "error: out of memory\n");
            freeState(m);
            return false;
        }

        for (int j = 0; j < m->width; j++) {
            m->state[i][j] = NONE;
        }
    }

    return true;
}

////////////////////////////////////////////////////////////////////////

void MazeFree(Maze m) {
    freeState(m);
    freeCells(m);
    free(m);
}

static void freeCells(Maze m) {
    for (int i = 0; i < m->height; i++) {
        free(m->cells[i]);
    }
    free(m->cells);
}

static void freeState(Maze m) {
    for (int i = 0; i < m->height; i++) {
        free(m->state[i]);
    }
    free(m->state);
}

////////////////////////////////////////////////////////////////////////

int  MazeHeight(Maze m) {
    return m->height;
}

int  MazeWidth(Maze m) {
    return m->width;
}

struct cell MazeGetStart(Maze m) {
    return m->start;
}

bool MazeIsWall(Maze m, struct cell c) {
    if (!validCell(m, c)) {
        fprintf(stderr, "error: (%d, %d) is not a valid cell\n",
                c.row, c.col);
        exit(EXIT_FAILURE);
    }
    return m->cells[c.row][c.col];
}

bool MazeVisit(Maze m, struct cell c) {
    if (MazeIsWall(m, c)) {
        fprintf(stderr, "error: wall cells cannot be visited\n");
        exit(EXIT_FAILURE);
    }

    m->state[c.row][c.col] = VISITED;

    showState(m, c);

    m->prev = c;
    return (c.row == m->curr.row && c.col == m->curr.col);
}

void MazeMarkPath(Maze m, struct cell c) {
    if (MazeIsWall(m, c)) {
        fprintf(stderr, "error: wall cells cannot be marked\n");
        exit(EXIT_FAILURE);
    }

    m->state[c.row][c.col] = PATH;

    showState(m, c);
}

#define GOTO_POS(row, col) printf("\033[%d;%dH", row, col)

static void showState(Maze m, struct cell c) {
    if (m->firstPrint) {
        showFullState(m, c);
        m->firstPrint = false;
    } else {
        showUpdatedState(m, c);
    }

    struct timespec ts;
    ts.tv_sec = pauseMs / 1000;
    ts.tv_nsec = (pauseMs % 1000) * 1000000;
    nanosleep(&ts, NULL);
}

static void showFullState(Maze m, struct cell c) {
    int h = MazeHeight(m);
    int w = MazeWidth(m);
    
    printf(CLEAR_SCREEN_ANSI);
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            printCell(m, row, col, c);
        }
        printf("\n");
    }
}

static struct cell getInputCoords(int r, int c) {
    struct cell ret;
    ret.row = r + 1;
    ret.col = c * 2 + 1;
    return ret;
}

static void showUpdatedState(Maze m, struct cell c) {
    if (m->prev.row != -1) {    
        struct cell pos = getInputCoords(m->prev.row, m->prev.col);
        GOTO_POS(pos.row, pos.col);
        printCell(m, m->prev.row, m->prev.col, c);
    }

    struct cell pos = getInputCoords(c.row, c.col);
    GOTO_POS(pos.row, pos.col);
    printCell(m, c.row, c.col, c);

    GOTO_POS(MazeHeight(m) + 1, 0);

    fflush(stdout);
}

static void printCell(Maze m, int row, int col, struct cell c) {
    char *color;
    if (m->state[row][col] == PATH) {
        color = "\033[43m";
    } else if (row == c.row && col == c.col) {
        color = "\033[41m";
    } else if (m->state[row][col] == VISITED) {
        color = "\033[44m";
    } else if (MazeIsWall(m, (struct cell){row, col})) {
        color = "\033[47m";
    } else if (row == m->curr.row && col == m->curr.col) {
        color = "\033[42m";
    } else {
        color = "\033[40m";
    }
    printf("%s  \033[0m", color);
}

void MazeSetDisplayPause(int ms) {
    if (ms >= 0) {
        pauseMs = ms;
    }
}

////////////////////////////////////////////////////////////////////////

static bool validCell(Maze m, struct cell c) {
    return (
        c.row >= 0 && c.row < m->height && c.col >= 0 && c.col < m->width
    );
}

