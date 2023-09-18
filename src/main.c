
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/args.h"
#include "include/cli.h"
#include "include/stack.h"

/* Stack and stack position of stack top (element on top of the last one) */
int64_t* stk     = NULL;
uint32_t stk_top = 0;

/*----------------------------------------------------------------------------*/

int main(int argc, char** argv) {
    int args = args_parse(argc, argv);

    if (args & ARG_ERROR || args & ARG_HELP)
        return args_print_usage(argv[0]);

    /* Initialize stack and stack top */
    stk     = calloc(STK_SZ, sizeof(int64_t));
    stk_top = 0;

    int exit_code = 0;
    if (args & ARG_MODE_CLI)
        exit_code = cli_main();

    free(stk);

    /* Should not reach here */
    return exit_code;
}
