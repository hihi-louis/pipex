LIBFT	=	libft
PRINTF 	=	printf_fd

SDIR	=	./srcs
LIBFT_DIR	=	$(SDIR)/$(LIBFT)
PRINTF_DIR	=	$(SDIR)/$(PRINTF)


LIBFT_FILES :=     ft_isalpha.c		ft_isdigit.c		ft_isalnum.c	\
					ft_isascii.c		ft_isprint.c		ft_strlen.c		\
					ft_memset.c			ft_bzero.c			ft_memcpy.c 	\
					ft_memmove.c		ft_strlcpy.c		ft_strlcat.c	\
					ft_toupper.c		ft_tolower.c		ft_strchr.c		\
					ft_strrchr.c 		ft_strncmp.c		ft_strnstr.c	\
					ft_memchr.c			ft_memcmp.c 		ft_atoi.c		\
					ft_calloc.c			ft_strdup.c			ft_substr.c		\
					ft_strjoin.c		ft_strtrim.c		ft_split.c		\
					ft_itoa.c			ft_strmapi.c		ft_striteri.c	\
					ft_free_array.c		\
					ft_strjoin_free.c	ft_free_array.c

PRINTF_FILES	=	ft_printf_fd.c	ft_putchar_fd.c	\
					ft_puthex_fd.c	ft_putnbr_fd.c	\
					ft_putpointer_fd.c	ft_putstr_fd.c	ft_putui_fd.c	

LIBFT_SRCS	=	$(addprefix $(LIBFT_DIR)/, $(LIBFT_FILES))
PRINTF_SRCS		=	$(addprefix $(PRINTF_DIR)/, $(PRINTF_FILES))

ODIR	= ./objs
LIBFT_ODIR = $(ODIR)/$(LIBFT)
PRINTF_ODIR = $(ODIR)/$(PRINTF)

LIBFT_OBJS		= $(addprefix $(LIBFT_ODIR)/, $(notdir $(LIBFT_SRCS:.c=.o)))
PRINTF_OBJS 	= $(addprefix $(PRINTF_ODIR)/, $(notdir $(PRINTF_SRCS:.c=.o)))
OBJS			= $(LIBFT_OBJS) $(PRINTF_OBJS)


NAME			=	mylib.a
INCS			= 	./includes
LIBC			= 	ar rcs
RM				= 	rm -rf
CC				= 	cc -Wall -Wextra -Werror -I$(INCS)
MD				= 	mkdir -p

# Default target
all	:	${NAME}

# make dir:
$(LIBFT_ODIR) $(PRINTF_ODIR) $(GNL_ODIR):
	@$(MD) $@

# Rule to compile source files into object files
$(LIBFT_ODIR)%.o: $(LIBFT_DIR)%.c | $(LIBFT_ODIR)
	@$(CC) -c $< -o $@

$(PRINTF_ODIR)%.o: $(PRINTF_DIR)%.c | $(PRINTF_ODIR)
	@$(CC) -c $< -o $@

# Target to create the library
${NAME}	:	${OBJS}
	@${LIBC} $@ $^
	@echo "Created mylib.a"

# Target to clean object files
clean	:
	${RM} $(ODIR)

# Target to clean library and object files
fclean	: clean
	${RM} ${NAME}

# Target to rebuild (clean and build again)
re	: fclean all

# Ensure that 'clean', 'fclean', and 're' are not dependent on actual file names
.PHONY: all clean fclean re