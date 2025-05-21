# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 04:30:36 by aheitz            #+#    #+#              #
#    Updated: 2025/05/21 05:04:39 by aheitz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = connect4
CC   = cc

INCLUDES = -I include
DEPFLAGS = -MMD -MP
CFLAGS   = -Wall -Wextra -Werror $(INCLUDES) $(DEPFLAGS)

SRCS = src/main.c            \
       src/displayGrid.c     \
       src/gameMem.c         \
       src/connect_ai.c      \
       src/play.c            \
       src/victory.c         \
       src/util/getLength.c  \
       src/util/writeError.c \
       src/util/atoui.c      \

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)