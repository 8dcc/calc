
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h> /* PRId32, PRId64, etc. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USE_COLOR
#include "include/color.h"
#include "include/cli.h"
#include "include/stack.h"
#include "include/cmds.h"

#define LENGTH(arr) (int)(sizeof(arr) / sizeof((arr)[0]))

static Command cmds[] = {
    { "+", cmd_add },
    { "-", cmd_sub },
    { "*", cmd_mul },
    { "/", cmd_div },
};

/*----------------------------------------------------------------------------*/

static inline void stack_print(void) {
    /* For COL_* defines, see include/color.h, for PRI* defines, see
     * <inttypes.h> */
    for (uint32_t i = 0; i < stk_top; i++)
        printf(COL_STK_PRE "[stk+%02" PRIu32 "]" COL_STK_NUM
                           " %" PRId64 COL_NORM "\n",
               i, stk[i]);
}

static uint32_t input_read(char* out, size_t bufsz) {
    uint32_t ret = INPUT_READ_INT;

    uint32_t i;
    for (i = 0; i < bufsz - 1; i++) {
        char c = getchar();
        if (c == '\n' || c == EOF)
            break;

        /* Non-number char? */
        if (c == '.' && ret == INPUT_READ_INT)
            ret = INPUT_READ_FLOAT;
        else if (c < '0' || c > '9')
            ret = INPUT_READ_STR;

        out[i] = c;
    }

    out[i] = '\0';
    return (i == 0) ? INPUT_READ_EMPTY : ret;
}

static uint32_t input_parse_str(const char* s) {
    /* Special commands */
    if (!strcmp(s, "q") || !strcmp(s, "quit"))
        return INPUT_PARSE_QUIT;

    /* Stack commands */
    for (size_t i = 0; i < LENGTH(cmds); i++)
        if (!strcmp(s, cmds[i].cmd))
            cmds[i].func();

    return INPUT_PARSE_OK;
}

/*----------------------------------------------------------------------------*/

int cli_main(void) {
    /* Input buffer */
    char input_buf[INPUT_BUF_SZ] = { '\0' };

    /* Main loop */
    while (true) {
        printf(COL_PROMPT "[calc]: " COL_NORM);
        uint32_t input_read_code = input_read(input_buf, INPUT_BUF_SZ);

        switch (input_read_code) {
            case INPUT_READ_STR:
                uint32_t input_parse_code = input_parse_str(input_buf);
                if (input_parse_code == INPUT_PARSE_QUIT)
                    return 0;

                break;
            case INPUT_READ_INT:
                stack_push(atoi(input_buf));
                break;
            case INPUT_READ_FLOAT:
                printf(COL_ERROR "Floats are not supported yet." COL_NORM "\n");
                input_read_code = INPUT_READ_EMPTY;
                break;
            default:
                break;
        }

        if (input_read_code != INPUT_READ_EMPTY)
            stack_print();
    }

    return 0;
}
