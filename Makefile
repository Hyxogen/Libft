NAME		:= libft.a
LIBSRC	:= src/string/ft_isalnum.c src/string/ft_isalpha.c src/string/ft_isascii.c src/string/ft_isdigit.c src/string/ft_isprint.c src/string/ft_memset.c src/string/ft_strlen.c \
			src/string/ft_bzero.c src/string/ft_memcpy.c src/string/ft_memmove.c src/string/ft_strlcat.c src/string/ft_strlcpy.c src/string/ft_toupper.c src/string/ft_tolower.c \
			src/string/ft_strchr.c src/string/ft_strrchr.c src/string/ft_strncmp.c src/string/ft_memchr.c src/string/ft_memcmp.c src/string/ft_strnstr.c src/string/ft_isspace.c \
			src/string/ft_atoi.c src/string/ft_calloc.c src/string/ft_strdup.c src/string/ft_substr.c src/string/ft_strjoin.c src/string/ft_strtrim.c src/string/ft_split.c \
			src/string/ft_strsep.c src/string/ft_itoa.c src/string/ft_strmapi.c src/string/ft_striteri.c src/string/ft_putchar_fd.c src/string/ft_putstr_fd.c \
			src/string/ft_putendl_fd.c src/string/ft_putnbr_fd.c
OBJDIR	:= obj
SRCDIR	:= src/string
TESTDIR	:= src/tests
LIBOBJ	:= $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(LIBSRC)))
#LIBOBJ	:= $(LIBSRC:.c=.o)
TESTSRC := $(wildcard src/tests/*tests.c)
TESTOBJ := $(patsubst %.c,$(OBJDIR)/%.o,$(notdir TESTSRC)))
CFLAGS	:= -Wall -Wextra -Werror

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
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
