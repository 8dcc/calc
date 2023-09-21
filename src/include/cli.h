#ifndef CLI_H_
#define CLI_H_ 1

#define INPUT_BUF_SZ 255

enum input_read_types {
    INPUT_READ_EMPTY = 0x0, /* No input, just newline */
    INPUT_READ_STR   = 0x1, /* Not a number, will parse string */
    INPUT_READ_INT   = 0x2, /* Integer number */
    INPUT_READ_FLOAT = 0x3, /* Float number */
};

enum input_parse_types {
    INPUT_PARSE_ERR  = 0x10, /* Unused */
    INPUT_PARSE_OK   = 0x11, /* Unused */
    INPUT_PARSE_UNK  = 0x12, /* Unknown string command */
    INPUT_PARSE_QUIT = 0x13, /* Quit command */
};

/*----------------------------------------------------------------------------*/

int cli_main(void);

#endif /* CLI_H_ */
