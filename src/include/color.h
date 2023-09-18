#ifndef COLOR_H_
#define COLOR_H_ 1

/* Bold colors */
#define TC_B_NRM "\x1B[1m"
#define TC_B_GRY "\x1B[1;30m"
#define TC_B_RED "\x1B[1;31m"
#define TC_B_GRN "\x1B[1;32m"
#define TC_B_YEL "\x1B[1;33m"
#define TC_B_BLU "\x1B[1;34m"
#define TC_B_MAG "\x1B[1;35m"
#define TC_B_CYN "\x1B[1;36m"
#define TC_B_WHT "\x1B[1;37m"

/* Normal colors */
#define TC_NRM "\x1B[0m"
#define TC_BLK "\x1B[0;31m"
#define TC_RED "\x1B[0;31m"
#define TC_GRN "\x1B[0;32m"
#define TC_YEL "\x1B[0;33m"
#define TC_BLU "\x1B[0;34m"
#define TC_MAG "\x1B[0;35m"
#define TC_CYN "\x1B[0;36m"
#define TC_WHT "\x1B[0;37m"

/* App colors, if enabled */
#ifdef USE_COLOR
#define COL_STK_NUM TC_B_WHT
#define COL_STK_PRE TC_CYN
#define COL_PROMPT  TC_GRN
#define COL_NORM    TC_NRM
#define COL_ERROR   TC_RED
#else
#define COL_STK_NUM ""
#define COL_STK_PRE ""
#define COL_PROMPT  ""
#define COL_NORM    ""
#define COL_ERROR   ""
#endif

#endif /* COLOR_H_ */
