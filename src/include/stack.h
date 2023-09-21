#ifndef STACK_H_
#define STACK_H_ 1

#include "util.h"

/* Size of the stack in elements, not bytes */
#define STK_SZ 100

/* Defined in cli.c */
extern int64_t* stk;
extern uint32_t stk_top;

static inline void stack_push(int64_t n) {
    if (stk_top < STK_SZ)
        stk[stk_top++] = n;
    else
        err_msg("stack_push: Reached top of stack (%d)", STK_SZ);
}

static inline int64_t stack_pop(void) {
    if (stk_top > 0)
        return stk[--stk_top];

    err_msg("stack_pop: Trying to pop bottom of stack");
    return 0;
}

#endif /* STACK_H_ */
