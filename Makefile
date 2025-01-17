# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/25 21:13:56 by tripham           #+#    #+#              #
#    Updated: 2025/01/16 22:23:45 by tripham          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./execution/mandatory/execute.c ./execution/mandatory/found_command_path.c \
       ./execution/mandatory/handle_error.c ./execution/mandatory/main.c \
       ./execution/mandatory/pipex.c ./execution/mandatory/split_command.c \
       ./execution/mandatory/utils.c 

# Source Object Files
OBJS = ${SRCS:.c=.o}

# Additional library directories
LIBFT_DIR = library/libft
FT_FRINTF_FD_DIR = library/ft_printf_fd

# Libraries
LIBFT = ${LIBFT_DIR}/libft.a
FT_PRINTF_FD = ${FT_FRINTF_FD_DIR}/libftprintf.a

# Execution name
NAME = pipex

# Default target
all: ${NAME}

# Rule to compile .o files from .c files
%.o: %.c
	cc -Wall -Werror -Wextra -c -I. $< -o $@

# Build libft.a
${LIBFT}:
	$(MAKE) -C ${LIBFT_DIR}

# Build ft_printf_fd.a
${FT_PRINTF_FD}:
	$(MAKE) -C ${FT_FRINTF_FD_DIR}

# Build the final executable
${NAME}: ${OBJS} ${LIBFT} ${FT_PRINTF_FD}
	cc ${OBJS} ${LIBFT} ${FT_PRINTF_FD} -o ${NAME}

# Clean object files
clean:
	rm -f ${OBJS}
	$(MAKE) -C ${LIBFT_DIR} clean
	$(MAKE) -C ${FT_FRINTF_FD_DIR} clean

# Full clean, including the executable
fclean: clean
	rm -rf ${NAME}
	$(MAKE) -C ${LIBFT_DIR} fclean
	$(MAKE) -C ${FT_FRINTF_FD_DIR} fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
