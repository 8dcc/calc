
#include <stdio.h>
#include "include/args.h"
#include "include/cli.h"

int main(int argc, char** argv) {
    int args = args_parse(argc, argv);

    if (args & ARG_ERROR || args & ARG_HELP)
        return args_print_usage(argv[0]);

    if (args & ARG_MODE_CLI)
        return cli_main();

    /* Should not reach here */
    return 0;
}
