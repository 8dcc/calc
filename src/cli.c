
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h> /* PRId32, PRId64, etc. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/color.h"
#include "include/cli.h"
#include "include/stack.h"
#include "include/cmds.h"

#define LENGTH(arr) (uint32_t)(sizeof(arr) / sizeof((arr)[0]))

static Command stack_cmds[] = {
    { "d", cmd_del },
    { "pop", cmd_del },
    { "swap", cmd_swp },
};

static Command math_cmds[] = {
    { "+", cmd_add }, /* Addition */
    { "-", cmd_sub }, /* Subtraction */
    { "*", cmd_mul }, /* Multiplication */
    { "/", cmd_div }, /* Division */
    { "^", cmd_pow }, /* Power */
};

/*----------------------------------------------------------------------------*/

static inline void stack_print(void) {
    /* For COL_* defines, see include/color.h, for PRI* defines, see
     * <inttypes.h> */
    uint32_t i;
    for (i = 0; i < stk_top; i++)
        printf(COL_STK_PRE "[stk+%02" PRIu32 "]" COL_STK_NUM
                           " %" PRId64 COL_NORM "\n",
               i, stk[i]);

    /* Only print spacing if stack was not empty */
    if (i > 0)
        putchar('\n');
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
            /* Encountered a dot while reading an integer, number is float. */
            ret = INPUT_READ_FLOAT;
        else if (c < '0' || c > '9')
            /* Not a digit at all, string. Will be parsed in input_parse_str */
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

    /* Stack commands. Functions defined in src/cmds.c */
    for (size_t i = 0; i < LENGTH(stack_cmds); i++)
        if (!strcmp(s, stack_cmds[i].cmd))
            return stack_cmds[i].func();

    /* Math commands. Functions defined in src/cmds.c */
    for (size_t i = 0; i < LENGTH(math_cmds); i++)
        if (!strcmp(s, math_cmds[i].cmd))
            return math_cmds[i].func();

    warn_msg("input_parse_str: Unknown command \"%s\"", s);
    return INPUT_PARSE_UNK;
}

/*----------------------------------------------------------------------------*/

int cli_main(void) {
    /* Input buffer */
    char input_buf[INPUT_BUF_SZ] = { '\0' };

    /* Main loop */
    while (true) {
        printf(COL_PROMPT "[calc]: " COL_NORM);
        uint32_t input_read_code = input_read(input_buf, INPUT_BUF_SZ);
        bool print_stack         = true;

        switch (input_read_code) {
            case INPUT_READ_STR:
                /* We just read a string, parse it */
                uint32_t input_parse_code = input_parse_str(input_buf);
                switch (input_parse_code) {
                    case INPUT_PARSE_ERR:
                    case INPUT_PARSE_OK:
                        /* Should not reach here */
                        err_msg("cli_main: Reached unused input parse code "
                                "(0x%X)\n",
                                input_parse_code);
                        print_stack = false;
                        break;
                    case INPUT_PARSE_UNK:
                    case CMD_EXIT_ERR:
                        /* Don't print stack if unknown input or cmd failed */
                        print_stack = false;
                        break;
                    case INPUT_PARSE_QUIT:
                        /* "q" or "quit" commands */
                        return 0;
                    case CMD_EXIT_OK:
                    default:
                        /* Executed command and it exited fine. Just continue */
                        break;
                }

                break;
            case INPUT_READ_INT:
                /* Input was integer, just push to stack */
                stack_push(atoi(input_buf));
                break;
            case INPUT_READ_FLOAT:
                /* TODO: Float support */
                err_msg("Floats are not supported yet");
                print_stack = false;
                break;
            case INPUT_READ_EMPTY:
                /* No command, dupplicate top of stack */
                cmd_dup();
                break;
            default:
                break;
        }

        /* After executing a valid command, print new stack state */
        if (print_stack)
            stack_print();
    }

    return 0;
}
