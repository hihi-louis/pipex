NAME := libftprintf.a

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRC_DIR	:= src
SRCS := ft_base_check_fd.c	\
		ft_check_format_fd.c	\
		ft_printf_fd.c	\
		ft_putnbr_base_fd.c	\
		ft_putpointer_fd.c	\
		ft_putstr_fd.c	\
		ft_putchar_fd.c

OBJ := $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	ar	rcs	$(NAME)	$(OBJ)

%.o:	$(SRC_DIR)/%.c
	$(CC) $(CFLAGS)	-c	$<	-o	$@

clean:
	rm	-f	$(OBJ)

fclean: clean
	rm	-f	$(NAME)

re:	fclean	all

.PHONY:	all	clean	fclean	re
	
