NAME	:= libft
ODIR	:= obj
LIBSRC	:= src/string/ft_isalnum.c src/string/ft_isalpha.c src/string/ft_isascii.c src/string/ft_isdigit.c src/string/ft_isprint.c src/string/ft_memset.c src/string/ft_strlen.c
LIBOBJ	:= $(patsubst %.c,$(ODIR)/%.o,$(LIBSRC))
TESTSRC := src/tests/ft_isalpha_test.c src/tests/ft_memset_test.c src/tests/tests.c src/tests/ft_strlen_test.c src/tests/ft_isalnum_test.c
TESTOBJ := $(patsubst %.c,$(ODIR)/%.o,$(TESTSRC))
CFLAGS	:= -Wall -Wextra -Werror

$(NAME):
	gcc $(CFLAGS) -c $(LIBSRC)

test: $(NAME)
	gcc $(CFLAGS) $(LIBSRC) $(TESTSRC)