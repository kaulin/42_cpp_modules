# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 10:46:35 by jajuntti          #+#    #+#              #
#    Updated: 2024/11/06 09:06:23 by jajuntti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= UnnecessaryViolence
CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror

# SOURCES
SRCS		:= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

# OBJECTS
BUILD_DIR	:= build/
OBJ			:= ${SRCS:.cpp=.o}
OBJS		:= $(addprefix $(BUILD_DIR), $(OBJ))

# HEADERS
HEADERS		:= HumanA.hpp HumanB.hpp Weapon.hpp

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJS) $(HEADERS) Makefile
	@echo "Linking executable $(NAME)..."
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) built with $(CXX) and flags $(CXXFLAGS)!"

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

$(BUILD_DIR)%.o: %.cpp $(HEADERS) Makefile 
	@echo "Compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $(BUILD_DIR)$(<:.cpp=.o)

clean:
	@echo "Removing object files"
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo "Removing executable"
	@rm -f $(NAME)

re: fclean all

debug: CXXFLAGS += -g
debug: fclean $(NAME)

sanitize: CXXFLAGS += -g -fsanitize=address
sanitize: fclean $(NAME)

.PHONY: all clean fclean re debug sanitize