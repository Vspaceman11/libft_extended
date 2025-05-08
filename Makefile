# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 17:56:39 by vpushkar          #+#    #+#              #
#    Updated: 2025/05/08 18:11:43 by vpushkar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME = libft_extended.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj

# Source subdirectories
SUBDIRS = libft ft_printf get_next_line

# Include header files
INCLUDES = -I$(INC_DIR)

# Collect all .c source files from subdirectories
SRC = $(foreach dir,$(SUBDIRS),$(wildcard $(SRC_DIR)/$(dir)/*.c))

# Corresponding object files in obj/ directory
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Default target
all: $(NAME)

# Build the static library
$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo "Library created: $(NAME)"

# Compile .c files into .o object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Remove all object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files removed."

# Remove object files and the library
fclean: clean
	@rm -f $(NAME)
	@echo "Library removed."

# Clean and rebuild everything
re: fclean all

