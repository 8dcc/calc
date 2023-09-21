
#include <stdint.h>
#include <math.h>
#include "include/cmds.h"
#include "include/stack.h"
#include "include/util.h"

/*----------------------------------------------------------------------------*/
/* Stack commands */

int cmd_del(void) {
    if (stk_top < 1)
        return CMD_EXIT_ERR;

    stack_pop();
    return CMD_EXIT_OK;
}

int cmd_dup(void) {
    if (stk_top < 1)
        return CMD_EXIT_ERR;

    const int64_t n = stack_pop();

    stack_push(n);
    stack_push(n);

    return CMD_EXIT_OK;
}

int cmd_swp(void) {
    if (stk_top < 2)
        return CMD_EXIT_ERR;

    const int64_t n2 = stack_pop();
    const int64_t n1 = stack_pop();

    stack_push(n2);
    stack_push(n1);

    return CMD_EXIT_OK;
}

/*----------------------------------------------------------------------------*/
/* Math commands */

int cmd_add(void) {
    if (stk_top < 2)
        return CMD_EXIT_ERR;

    const int64_t n2 = stack_pop();
    const int64_t n1 = stack_pop();

    stack_push(n1 + n2);
    return CMD_EXIT_OK;
}

int cmd_sub(void) {
    if (stk_top < 2)
        return CMD_EXIT_ERR;

    const int64_t n2 = stack_pop();
    const int64_t n1 = stack_pop();

    stack_push(n1 - n2);
    return CMD_EXIT_OK;
}

int cmd_mul(void) {
    if (stk_top < 2)
        return CMD_EXIT_ERR;

    const int64_t n2 = stack_pop();
    const int64_t n1 = stack_pop();

    stack_push(n1 * n2);
    return CMD_EXIT_OK;
}

int cmd_div(void) {
    if (stk_top < 2)
        return CMD_EXIT_ERR;

    const int64_t n2 = stack_pop();
    const int64_t n1 = stack_pop();

    if (n2 == 0) {
        err_msg("Error. Division by zero.");
        stack_push(n1);
        stack_push(n2);
        return CMD_EXIT_ERR;
    }

    stack_push(n1 / n2);
    return CMD_EXIT_OK;
}

int cmd_pow(void) {
    if (stk_top < 2)
        return CMD_EXIT_ERR;

    const int64_t n2 = stack_pop();
    const int64_t n1 = stack_pop();

    stack_push(pow(n1, n2));
    return CMD_EXIT_OK;
}
