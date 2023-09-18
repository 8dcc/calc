#ifndef CLI_H_
#define CLI_H_ 1

#define INPUT_BUF_SZ 255

enum input_types {
    INPUT_EMPTY = 0,
    INPUT_STR   = 1,
    INPUT_INT   = 2,
    INPUT_FLOAT = 3,
};

int cli_main(void);

#endif /* CLI_H_ */
