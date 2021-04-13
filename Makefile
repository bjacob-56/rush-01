SRC_DIR	:= srcs/
INC_DIR	:= includes/

NAME	:= rush
SRC		:= $(SRC_DIR)algo.c \
$(SRC_DIR)ft_strdel_2d.c \
$(SRC_DIR)get_next_line.c \
$(SRC_DIR)main.c

OBJ		:= $(SRC:$(SRC_DIR)%.c=%.o)

INC	:= $(INC_DIR)rush01.h
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
INCLUDE	:= -Iincludes
# LDFLAGS	:=  -g3 -fsanitize=address

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):  $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: $(SRC_DIR)%.c $(INC)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) -rf $(OBJ)

fclean:
	$(RM) -rf $(OBJ)
	$(RM) -rf $(NAME)

re: fclean all