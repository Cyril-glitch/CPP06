NAME = bin/converter

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

BIN_DIR = bin
OBJ_DIR = obj

SRC = src/main.cpp \
	  src/Serializer.cpp \

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))

VPATH = src

all : $(NAME)

$(NAME) : $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

it :
	./bin/converter

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(BIN_DIR)
	rm -rf $(NAME)

re: fclean all