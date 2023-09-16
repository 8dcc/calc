#ifndef ARGS_H_
#define ARGS_H_ 1

enum arg_types {
    ARG_ERROR    = 0x1,  /* 0000 0001 */
    ARG_HELP     = 0x2,  /* 0000 0010 */
    ARG_UNUSED0  = 0x4,  /* 0000 0100 */
    ARG_UNUSED1  = 0x8,  /* 0000 1000 */
    ARG_MODE_CLI = 0x10, /* 0001 0000 */
};

int args_parse(int argc, char** argv);
int args_print_usage(const char* argv0);

#endif /* ARGS_H_ */
