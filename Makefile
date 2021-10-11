NAME	:= libft
ODIR	:= obj
LIBSRC	:= src/string/ft_isalnum.c src/string/ft_isalpha.c src/string/ft_isascii.c src/string/ft_isdigit.c src/string/ft_isprint.c src/string/ft_memset.c src/string/ft_strlen.c \
			src/string/ft_bzero.c src/string/ft_memcpy.c src/string/ft_memmove.c src/string/ft_strlcat.c src/string/ft_strlcpy.c src/string/ft_toupper.c src/string/ft_tolower.c \
			src/string/ft_strchr.c src/string/ft_strrchr.c src/string/ft_strncmp.c src/string/ft_memchr.c src/string/ft_memcmp.c src/string/ft_strnstr.c src/string/ft_isspace.c \
			src/string/ft_atoi.c src/string/ft_calloc.c src/string/ft_strdup.c src/string/ft_substr.c src/string/ft_strjoin.c src/string/ft_strtrim.c src/string/ft_split.c \
			src/string/ft_strsep.c src/string/ft_itoa.c src/string/ft_strmapi.c
LIBOBJ	:= $(patsubst %.c,$(ODIR)/%.o,$(LIBSRC))
TESTSRC := $(wildcard src/tests/*tests.c)
TESTOBJ := $(patsubst %.c,$(ODIR)/%.o,$(TESTSRC))
CFLAGS	:= -Wall -Wextra -Werror

$(NAME):
	gcc $(CFLAGS) -c $(LIBSRC)

test:
	gcc $(CFLAGS) $(LIBSRC) $(TESTSRC)

ntest:
	gcc $(LIBSRC) $(TESTSRC)
