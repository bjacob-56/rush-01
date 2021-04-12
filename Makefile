SRC_DIR	:= srcs/
INC_DIR	:= includes/

NAME	:= rush
SRC		:= $(wildcard $(SRC_DIR)*.c) $(wildcard $(SRC_DIR)*/*.c)

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

%.o: $(SRC_DIR)%.c $(INC)| $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) -rf $(OBJ)

fclean:
	$(RM) -rf $(OBJ)
	$(RM) -rf $(NAME)

re: fclean all