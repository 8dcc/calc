#ifndef CMDS_H_
#define CMDS_H_ 1

#include <stdint.h>

enum cmd_exit_codes {
    CMD_EXIT_ERR = 0x100, /* Something went wrong whne executing cmd function */
    CMD_EXIT_OK  = 0x101, /* Command function executed successfully */
};

typedef int (*funcptr_t)(void);
typedef struct {
    const char* cmd;
    funcptr_t func;
} Command;

int cmd_add(void);
int cmd_sub(void);
int cmd_mul(void);
int cmd_div(void);

#endif /* CMDS_H_ */
