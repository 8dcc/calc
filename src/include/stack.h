#ifndef STACK_H_
#define STACK_H_ 1

/* Size of the stack in elements, not bytes */
#define STK_SZ 100

/* Defined in cli.c */
extern int64_t* stk;
extern uint32_t stk_top;

static inline void stack_push(int64_t n) {
    stk[stk_top++] = n;
}

static inline int64_t stack_pop(void) {
    return stk[--stk_top];
}

#endif /* STACK_H_ */
