NAME			:= libft.a

SRC_DIR			:= ./src
OBJ_DIR			:= ./obj

INCLUDE_DIRS	:= ./include

SRCS			:= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c \
				ft_strlen.c	ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcat.c ft_strlcpy.c ft_toupper.c \
				ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				ft_isspace.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
				ft_split.c ft_strsep.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

VPATH			:= $(SRC_DIR)/ctype $(SRC_DIR)/linked_list $(SRC_DIR)/stdio $(SRC_DIR)/stdlib $(SRC_DIR)/string

OBJS			:= $(SRCS:%.c=%.o)

CC				:= cc

ALL_CFLAGS		:= -Wall -Wextra -Werror -pedantic -std=c89

DEBUG_FLAGS		:= -g3 -Og -fsanitize=address
DEBUG_DEFINES	:= -DLIBFT_DEBUG

RELEASE_FLAGS	:= -g -O2 -fsanitize=address
RELEASE_DEFINES	:= -DLIBFT_RELEASE

DISTR_FLAGS		:= -Ofast -g0
DISTR_DEFINES	:= -DPS_DISTRIBUTION

.PHONY: clean fclean re bonus all debug release distribution
.PRECIOUS: $(BONUOBJ)

all: distribution

debug: ALL_CFLAGS += $(DEBUG_FLAGS)
debug: ALL_LINKFLAGS += -fsanitize=address
debug: DEFINES += $(DEBUG_DEFINES)
debug: $(NAME)

release: ALL_CFLAGS += $(RELEASE_FLAGS)
release: ALL_LINKFLAGS += -fsanitize=addresss
release: DEFINES += $(RELEASE_DEFINES)
release: $(NAME)

distribution: ALL_CFLAGS += $(DISTR_FLAGS)
distribution: ALL_CFLAGS += $(DISTR_DEFINES)
distribution: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME)(%.o): %.o
	ar rcs $(NAME) $<

$(NAME): $(DEPEND) $(LIBSRC) $(LIBOBJ)
	ar rcs $(NAME) $(LIBOBJ)

clean:
	rm -f $(BONUOBJ)
	rm -f $(LIBOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)


