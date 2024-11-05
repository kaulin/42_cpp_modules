# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 10:46:35 by jajuntti          #+#    #+#              #
#    Updated: 2024/11/05 14:26:27 by jajuntti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= XNAME
CXX			:= c++
CXX_FLAGS	:= -Wall -Wextra -Werror

# Sources
SRC_DIR		:= sources/
SRC			:= main.cpp X.cpp
VPATH		+= $(SRC_DIR)

# Objects
OBJ_DIR		:= objects/
OBJ			:= ${SRC:.cpp=.o}
OBJS		:= $(addprefix $(OBJ_DIR), $(OBJ))

# Includes
INC_DIR		:= includes/
INC			:= X.hpp
INCS		:= $(addprefix $(INC_DIR), $(INC))
INC_FLAG	:= -I includes/

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(INCS) Makefile
	@echo "Linking executable $(NAME)..."
	@$(CXX) $(CXX_FLAGS) $(INCFLAG) $(OBJS) -o $(NAME)
	@echo "$(NAME) built with $(CXX) and flags $(CXX_FLAGS)!"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp $(INCS) Makefile 
	@echo "Compiling $<"
	@$(CXX) $(CXX_FLAGS) $(INCFLAG) -c $< -o $(OBJ_DIR)$(<:.cpp=.o)

clean:
	@echo "Removing object files"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Removing executable"
	@rm -f $(NAME)

re: fclean all

debug: CXX_FLAGS += -g
debug: fclean $(NAME)

sanitize: CXX_FLAGS += -g -fsanitize=address
sanitize: fclean $(NAME)

.PHONY: all clean fclean re debug sanitize