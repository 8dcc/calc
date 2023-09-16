
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "include/args.h"

#define LENGTH(arr) (int)(sizeof(arr) / sizeof((arr)[0]))

typedef struct {
    const char* s;
    const char c;
    const char* desc;
    const enum arg_types code;
} ArgPair;

ArgPair arg_pairs[] = {
    /* str version, char version, description, code */
    { "help", 'h', "Show this help", ARG_HELP },
    { "cli", 'c', "Launch in CLI mode", ARG_MODE_CLI },
};

int args_parse(int argc, char** argv) {
    if (argc < 2)
        return ARG_MODE_CLI;

    /* Iterate argv */
    for (int i = 1; i < argc; i++) {
        /* All arguments must start with '-', both "-h" and "--help" */
        if (argv[i][0] != '-')
            continue;

        if (argv[i][1] == '-') {
            /* Check for long "--help" args */
            for (int j = 0; j < LENGTH(arg_pairs); j++)
                if (!strcmp(&argv[i][2], arg_pairs[j].s))
                    return arg_pairs[j].code;
        } else {
            /* Check for short "-h" args */
            for (int j = 0; j < LENGTH(arg_pairs); j++)
                if (argv[i][1] == arg_pairs[j].c)
                    return arg_pairs[j].code;
        }

        /* Not in arg_pairs */
        fprintf(stderr, "Unknown argument: \"%s\"\n", argv[i]);
        return ARG_ERROR;
    }

    return ARG_ERROR;
}

int args_print_usage(const char* s) {
    fprintf(stderr,
            "Usage:\n"
            "  %s         - Launch in CLI mode\n",
            s);

    for (int i = 0; i < LENGTH(arg_pairs); i++) {
        fprintf(stderr, "  %s --%-5s - %s\n", s, arg_pairs[i].s,
                arg_pairs[i].desc);
        fprintf(stderr, "  %s -%c      - Same as \"--%s\"\n", s, arg_pairs[i].c,
                arg_pairs[i].s);
    }

    return 1;
}
