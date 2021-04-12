SRC_DIR	:= srcs/
INC_DIR	:= includes/
OBJ_DIR	:= obj/

NAME	:= rush
SRC		:= $(wildcard $(SRC_DIR)*.c) $(wildcard $(SRC_DIR)*/*.c)

OBJ		:= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

INC	:= $(INC_DIR)rush01.h
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
INCLUDE	:= -Iincludes
LDFLAGS	:=  -g3 -fsanitize=address


.PHONY: all clean fclean re

all: $(NAME)

$(NAME):  $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)| $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) -rf $(OBJ_DIR)

fclean:
	$(RM) -rf $(OBJ_DIR)
	$(RM) -rf $(NAME)

re: fclean all