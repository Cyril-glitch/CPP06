NAME = converter

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = obj

SRC = src/main.cpp \
	src/ScalarConverter.cpp \
	src/checktype.cpp \
	src/display.cpp


OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))

VPATH = src

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re: fclean all