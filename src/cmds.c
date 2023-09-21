
#include <stdint.h>
#include "include/cmds.h"
#include "include/stack.h"
#include "include/util.h"

int cmd_add(void) {
    const int64_t n2 = stack_pop();
    const int64_t n1 = stack_pop();

    stack_push(n1 + n2);
    return CMD_EXIT_OK;
}

int cmd_sub(void) {
    const int64_t n2 = stack_pop();
    const int64_t n1 = stack_pop();

    stack_push(n1 - n2);
    return CMD_EXIT_OK;
}

int cmd_mul(void) {
    const int64_t n2 = stack_pop();
    const int64_t n1 = stack_pop();

    stack_push(n1 * n2);
    return CMD_EXIT_OK;
}

int cmd_div(void) {
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
