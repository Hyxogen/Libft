NAME		:= libft.a
LIBSRC	:= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c ft_strlen.c \
			ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcat.c ft_strlcpy.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_isspace.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_strsep.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c
TESTDIR	:= src/tests
LIBOBJ	:= $(patsubst %.c,%.o,$(notdir $(LIBSRC)))
#LIBOBJ	:= $(LIBSRC:.c=.o)
TESTSRC := $(wildcard src/tests/*tests.c)
TESTOBJ := $(patsubst %.c,$(OBJDIR)/%.o,$(notdir TESTSRC)))
CFLAGS	:= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	gcc $(CLFAGS) -c $< -o $@

$(NAME): $(LIBSRC) $(LIBOBJ)
	ar rcs $(NAME) $(LIBOBJ)

test: $(NAME)
	gcc $(CFLAGS) $(NAME) $(TESTSRC)

ntest:
	gcc $(LIBSRC) $(TESTSRC)

clean:
	rm -f $(LIBOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
