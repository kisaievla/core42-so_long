NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -g
LIBMLX	:= ./lib/MLX42
OS	:= $(shell uname -s)

HEADERS	:= -I ./ -I $(LIBMLX)/include

ifeq ($(OS), Linux)
	LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
else
	LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L"/opt/homebrew/Cellar/glfw/3.4/lib/" -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit
endif

SRCS	:= ft_printf.c so_long.c bfs.c ft_printf_helpers.c \
			queue_methods.c ft_utils.c get_next_line_utils.c \
			get_next_line.c map_func.c so_long_utils.c put_img_utils.c \
			so_long_moves.c bfs_utils.c ft_split.c
OBJS	:= ${SRCS:%.c=%.o}

all: libmlx $(NAME)

libmlx:
	git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX);
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
	@rm -rf $(LIBMLX)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
























