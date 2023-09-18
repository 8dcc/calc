#ifndef CLI_H_
#define CLI_H_ 1

#define INPUT_BUF_SZ 255

enum input_read_types {
    INPUT_READ_EMPTY = 0,
    INPUT_READ_STR   = 1,
    INPUT_READ_INT   = 2,
    INPUT_READ_FLOAT = 3,
};

enum input_parse_types {
    INPUT_PARSE_ERROR = 0,
    INPUT_PARSE_OK    = 1,
    INPUT_PARSE_QUIT  = 2,
};

int cli_main(void);

#endif /* CLI_H_ */
