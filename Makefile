NAME	:= libft
ODIR	:= obj
LIBSRC	:= src/string/ft_isalnum.c src/string/ft_isalpha.c src/string/ft_isascii.c src/string/ft_isdigit.c src/string/ft_isprint.c src/string/ft_memset.c src/string/ft_strlen.c \
			src/string/ft_bzero.c src/string/ft_memcpy.c src/string/ft_memmove.c src/string/ft_strlcat.c src/string/ft_strlcpy.c src/string/ft_toupper.c src/string/ft_tolower.c \
			src/string/ft_strchr.c src/string/ft_strrchr.c src/string/ft_strncmp.c src/string/ft_memchr.c
LIBOBJ	:= $(patsubst %.c,$(ODIR)/%.o,$(LIBSRC))
TESTSRC := $(wildcard src/tests/*tests.c)
TESTOBJ := $(patsubst %.c,$(ODIR)/%.o,$(TESTSRC))
CFLAGS	:= -Wall -Wextra -Werror

$(NAME):
	gcc $(CFLAGS) -c $(LIBSRC)

test: $(NAME)
	gcc $(CFLAGS) $(LIBSRC) $(TESTSRC)

ntest: $(NAME)
	gcc $(LIBSRC) $(TESTSRC)