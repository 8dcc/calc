# Possible macros: USE_COLOR
SETTINGS?=-DUSE_COLOR

CC=gcc
CFLAGS=-Wall -Wextra
LDFLAGS=-lm

OBJ_FILES=main.c.o args.c.o cli.c.o cmds.c.o
OBJS=$(addprefix obj/, $(OBJ_FILES))

BIN=calc.out

.PHONY: clean all run

# -------------------------------------------

all: $(BIN)

run: $(BIN)
	./$<

clean:
	rm -f $(OBJS)
	rm -f $(BIN)

# -------------------------------------------

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

obj/%.c.o : src/%.c
	@mkdir -p obj/
	$(CC) $(CFLAGS) $(SETTINGS) -c -o $@ $<
