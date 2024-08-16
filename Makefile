NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= ../MLX42
OS	:= $(shell uname -o)

HEADERS	:= -I ./ -I $(LIBMLX)/include

ifeq ($(OS),GNU/Linux)
	LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
else
	LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L"/opt/homebrew/Cellar/glfw/3.4/lib/" -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit
endif
SRCS	:= $(shell find ./ -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
























