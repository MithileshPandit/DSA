#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef unsigned char uint8_t;
typedef short int16_t;
enum js_var_type {JS_VAR_NULL, JS_VAR_UNDEFINED, JS_VAR_NAN, JS_VAR_BOOL, JS_VAR_INT16, JS_VAR_STRING, JS_VAR_ARRAY, JS_VAR_DICT};
struct js_var {
    enum js_var_type type;
    int16_t number;
    void *data;
};
struct js_var js_var_from(enum js_var_type type) {
    struct js_var v;
    v.type = type;
    v.data = NULL;
    return v;
}

struct word_t {
    void * length;
};
struct array_word_t {
    int16_t size;
    int16_t capacity;
    struct word_t ** data;
};

static uint8_t (*exist)(struct array_word_t *, struct word_t *);
uint8_t exist_func(struct array_word_t * board, struct word_t * word)
{
    int16_t r;
    void * c;
    int16_t dirs[2][4];
    uint8_t (*dfs)(int16_t, int16_t, int16_t);
    int16_t i;
    if (board->size == 0)
        return FALSE;
    r = board->size;
    c = board->data[0]->length;
    dirs[0][0] = -1;
    dirs[0][1] = 0;
    dirs[1][0] = 0;
    dirs[1][1] = 1;
    dirs[2][0] = 1;
    dirs[2][1] = 0;
    dirs[3][0] = 0;
    dirs[3][1] = -1;
    dfs = /* Unsupported node: (x, y, k) => { if (board[x][y] !== word[k]) { return false; } if (k === word.length - 1) { return true; } board[x][y] = '*'; for (const [dx, dy] of dirs) { const i = x + dx; const j = y + dy; if (i >= 0 && i < r && j >= 0 && j < c) { if (dfs(i, j, k + 1)) { return true; } } } board[x][y] = word[k]; return false; } */;
     ;
    i = 0;
    for (;i < r;i++)
    {
        int16_t j;
        j = 0;
        for (;j < js_var_from(JS_VAR_NAN);j++)
            if (dfs(i, j, 0))
            return TRUE;
    }
    return FALSE;

}

int main(void) {
    exist = exist_func;
    board[0][0] = "A";
    board[0][1] = "B";
    board[0][2] = "C";
    board[0][3] = "E";
    board[1][0] = "S";
    board[1][1] = "F";
    board[1][2] = "C";
    board[1][3] = "S";
    board[2][0] = "A";
    board[2][1] = "D";
    board[2][2] = "E";
    board[2][3] = "E";
    word = "ABCCED";
    printf("%s\n", exist(board, word) ? "true" : "false");

    return 0;
}
