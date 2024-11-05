# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 10:46:35 by jajuntti          #+#    #+#              #
#    Updated: 2024/11/05 15:13:03 by jajuntti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= Hi_this_is_brain
CXX			:= c++
CXX_FLAGS	:= -Wall -Wextra -Werror

# Sources
SRC			:= main.cpp

all: $(NAME)

$(NAME): $(SRC) Makefile
	@echo "Building executable $(NAME)..."
	@$(CXX) $(CXX_FLAGS) $(SRC) -o $(NAME)
	@echo "$(NAME) built! Compiler: $(CXX) Flags: $(CXX_FLAGS)!"

clean:

fclean:
	@echo "Removing executable"
	@rm -f $(NAME)

re: fclean all

debug: CXX_FLAGS += -g
debug: fclean $(NAME)

sanitize: CXX_FLAGS += -g -fsanitize=address
sanitize: fclean $(NAME)

.PHONY: all clean fclean re debug sanitize