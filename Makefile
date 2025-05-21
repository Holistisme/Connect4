# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 04:30:36 by aheitz            #+#    #+#              #
#    Updated: 2025/05/21 20:20:09 by aheitz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = connect4
CC   = cc

INCLUDES = -I include
DEPFLAGS = -MMD -MP

SDL_CFLAGS = $(shell sdl2-config --cflags)
SDL_LIBS   = $(shell sdl2-config --libs)

CFLAGS   = -Wall -Wextra -Werror $(INCLUDES) $(DEPFLAGS) $(SDL_CFLAGS)

GAME      = src/game
INTERFACE = $(GAME)/interface
UTIL      = src/util

SRCS = src/main.c               \
       src/memory.c             \
       src/play.c               \
       $(UTIL)/getLength.c      \
       $(UTIL)/writeError.c     \
       $(UTIL)/atoui.c          \
       $(GAME)/ai.c             \
       $(GAME)/dropPiece.c      \
       $(GAME)/humanTurn.c      \
       $(GAME)/isDraw.c         \
       $(GAME)/victory.c        \
       $(INTERFACE)/graphical.c \
       $(INTERFACE)/grid.c      \
       $(INTERFACE)/term.c      \

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(SDL_LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)