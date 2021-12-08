# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dmeijer <dmeijer@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/08 10:23:31 by dmeijer       #+#    #+#                  #
#    Updated: 2021/12/08 10:30:08 by dmeijer       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			:= libft.a

SRC_DIR			:= ./src
OUT_DIR			:= ./out
INT_DIR			:= ./obj
TRGT_DIR		:= .

INCLUDE_DIRS	:= -I ./include

SRCS			:= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c \
				ft_strlen.c	ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcat.c ft_strlcpy.c ft_toupper.c \
				ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				ft_isspace.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
				ft_split.c ft_strsep.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

VPATH			:= $(SRC_DIR)/ctype $(SRC_DIR)/linked_list $(SRC_DIR)/stdio $(SRC_DIR)/stdlib $(SRC_DIR)/string

OBJS			:= $(addprefix $(INTDIR)/,$(SRCS:%.c=%.o))

CC				:= cc

ALL_CFLAGS		:= -Wall -Wextra -Werror -pedantic $(INCLUDE_DIRS)

DEBUG_FLAGS		:= -g3 -Og -fsanitize=address
DEBUG_DEFINES	:= -DLIBFT_DEBUG

RELEASE_FLAGS	:= -g -O2 -fsanitize=address
RELEASE_DEFINES	:= -DLIBFT_RELEASE

DISTR_FLAGS		:= -Ofast -g0
DISTR_DEFINES	:= -DPS_DISTRIBUTION

SILENT			:= @
ifdef VERBOSE
	SILENT		:=
endif

.PHONY: clean fclean re bonus all debug release distribution
.PRECIOUS: $(OBJS)

all: distribution
# Custom target paths voor elke target
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

$(NAME): $(NAME)($(notdir $(OBJS)))
	$(SILENT)echo Creating $(NAME)

$(NAME)(%.o): $(INT_DIR)/%.o
	ar rcs $(NAME) $<

$(INT_DIR)/%.o: %.c
	$(SILENT)mkdir -p $(INT_DIR)
	$(SILENT)echo $<
	$(SILENT)$(CC) $(ALL_CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
