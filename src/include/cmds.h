#ifndef CMDS_H_
#define CMDS_H_ 1

#include <stdint.h>

typedef void (*funcptr_t)(void);
typedef struct {
    const char* cmd;
    funcptr_t func;
} Command;

void cmd_add(void);
void cmd_sub(void);
void cmd_mul(void);
void cmd_div(void);

#endif /* CMDS_H_ */
