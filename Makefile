# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fepinson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/15 18:30:42 by fepinson          #+#    #+#              #
#    Updated: 2019/06/15 19:25:39 by fepinson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

CC		=		gcc

RM		=		rm -f

INC_DIR	=	$(realpath .)

LIB_DIR	=	$(realpath ./lib)

SRC_DIR	=	$(realpath ./src)

SRCS	=	$(SRC_DIR)/main.c \
			$(SRC_DIR)/parsing.c \
			$(SRC_DIR)/solve.c \

OBJS	=	$(SRCS:.c=.o)

LDFLAGS	=	-I$(SRC_DIR) -L$(LIB_DIR) -lft

CFLAGS	+=	-Wall -Wextra -Werror -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
