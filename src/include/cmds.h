#ifndef CMDS_H_
#define CMDS_H_ 1

#include <stdint.h>

enum cmd_exit_codes {
    CMD_EXIT_ERR = 0x100, /* Something went wrong whne executing cmd function */
    CMD_EXIT_OK  = 0x101, /* Command function executed successfully */
};

typedef int (*funcptr_t)(void);
typedef struct {
    const char* str;
    funcptr_t func;
    const char* desc;
} Command;

/* Stack commands */
int cmd_del(void);
int cmd_dup(void);
int cmd_swp(void);

/* Math commands */
int cmd_add(void);
int cmd_sub(void);
int cmd_mul(void);
int cmd_div(void);
int cmd_pow(void);

#endif /* CMDS_H_ */
