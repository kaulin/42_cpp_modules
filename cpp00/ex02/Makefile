# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 10:46:35 by jajuntti          #+#    #+#              #
#    Updated: 2024/11/01 15:48:29 by jajuntti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= BanksterPro
CC			:= c++
CFLAGS		:= -Wall -Wextra -Werror -std=c++98 -g

# SOURCES
#SRC_DIR	:= sources/
SRCS		:= Account.cpp tests.cpp
#VPATH		+= $(SRC_DIR)

# OBJECTS
BUILD_DIR	:= build/
OBJ			:= ${SRCS:.cpp=.o}
OBJS		:= $(addprefix $(BUILD_DIR), $(OBJ))

# HEADERS
HEADERS		:= Account.hpp
#INC		:= -I includes/

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJS)
	@echo "Linking executable $(NAME)"
	@$(CC) $(CFLAGS) $(OPTS) $(OBJS) -o $(NAME)

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

$(BUILD_DIR)%.o: %.cpp
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)$(<:.cpp=.o)

clean:
	@echo "Removing object files"
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo "Removing executable"
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re