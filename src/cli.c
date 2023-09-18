
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h> /* PRId32, PRId64, etc. */
#include <stdio.h>
#include <stdlib.h>

#define USE_COLOR
#include "include/color.h"
#include "include/cli.h"

/* Size of the stack in elements, not bytes */
#define STK_SZ 100

/* Stack and stack position of stack top (element on top of the last one) */
int64_t* stk;
uint32_t stk_top;

/*----------------------------------------------------------------------------*/

static inline void stack_push(int64_t n) {
    stk[stk_top++] = n;
}

static inline int64_t stack_pop(void) {
    return stk[--stk_top];
}

static inline void stack_print(void) {
    /* For COL_* defines, see include/color.h, for PRI* defines, see
     * <inttypes.h> */
    for (uint32_t i = 0; i < stk_top; i++)
        printf(COL_STK_PRE "[stk+%02" PRIu32 "]" COL_STK_NUM
                           " %" PRId64 COL_NORM "\n",
               i, stk[i]);
}

static uint32_t input_read(char* out, size_t bufsz) {
    uint32_t ret = INPUT_INT;

    uint32_t i;
    for (i = 0; i < bufsz - 1; i++) {
        char c = getchar();
        if (c == '\n' || c == EOF)
            break;

        /* Non-number char? */
        if (c == '.' && ret == INPUT_INT)
            ret = INPUT_FLOAT;
        else if (c < '0' || c > '9')
            ret = INPUT_STR;

        out[i] = c;
    }

    out[i] = '\0';
    return (i == 0) ? INPUT_EMPTY : ret;
}

/*----------------------------------------------------------------------------*/

int cli_main(void) {
    /* Initialize stack and stack top */
    stk     = calloc(STK_SZ, sizeof(int64_t));
    stk_top = 0;

    /* Input buffer */
    char input_buf[INPUT_BUF_SZ] = { '\0' };

    /* Main loop */
    while (true) {
        printf(COL_PROMPT "[calc]: " COL_NORM);
        uint32_t input_code = input_read(input_buf, INPUT_BUF_SZ);

        switch (input_code) {
            case INPUT_STR:
                /* TODO: Handle operations in separate func. */
                if (input_buf[0] == 'q')
                    return 0;

                break;
            case INPUT_INT:
                stack_push(atoi(input_buf));
                break;
            case INPUT_FLOAT:
                printf(COL_ERROR "Floats are not supported yet." COL_NORM "\n");
                input_code = INPUT_EMPTY;
                break;
            default:
                break;
        }

        if (input_code != INPUT_EMPTY)
            stack_print();
    }

    return 0;
}
