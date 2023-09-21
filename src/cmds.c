
#include <stdint.h>
#include "include/cmds.h"
#include "include/stack.h"
#include "include/util.h"

void cmd_add(void) {
    const int64_t n2 = stack_pop();
    const int64_t n1 = stack_pop();
    stack_push(n1 + n2);
}

void cmd_sub(void) {
    const int64_t n2 = stack_pop();
    const int64_t n1 = stack_pop();
    stack_push(n1 - n2);
}

void cmd_mul(void) {
    const int64_t n2 = stack_pop();
    const int64_t n1 = stack_pop();
    stack_push(n1 * n2);
}

void cmd_div(void) {
    const int64_t n2 = stack_pop();
    const int64_t n1 = stack_pop();

    if (n2 == 0)
        return err_msg("Error. Division by zero.");

    stack_push(n1 / n2);
}
