#ifndef CLI_H_
#define CLI_H_ 1

#define INPUT_BUF_SZ 255

enum input_read_types {
    INPUT_READ_EMPTY = 0x0,
    INPUT_READ_STR   = 0x1,
    INPUT_READ_INT   = 0x2,
    INPUT_READ_FLOAT = 0x3,
};

enum input_parse_types {
    INPUT_PARSE_ERROR = 0x10,
    INPUT_PARSE_OK    = 0x11,
    INPUT_PARSE_QUIT  = 0x12,
};

/*----------------------------------------------------------------------------*/

int cli_main(void);

#endif /* CLI_H_ */
