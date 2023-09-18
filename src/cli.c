
#include <stdint.h>
#include <inttypes.h> /* PRId32, PRId64, etc. */
#include <stdio.h>
#include <stdlib.h>
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
    for (uint32_t i = 0; i < stk_top; i++)
        printf("[stk+%02" PRIu32 "] %" PRId64 "\n", i, stk[i]);
}

/*----------------------------------------------------------------------------*/

int cli_main(void) {
    /* Initialize stack and stack top */
    stk     = calloc(STK_SZ, sizeof(int64_t));
    stk_top = 0;

    /* Tests */
    stack_push(123);
    stack_push(555);
    stack_push(444);
    stack_print();

    printf("Popped: %ld\n", stack_pop());
    printf("Popped: %ld\n", stack_pop());
    stack_print();

    return 0;
}
