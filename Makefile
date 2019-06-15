# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fepinson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/15 18:30:42 by fepinson          #+#    #+#              #
#    Updated: 2019/06/15 20:11:07 by fepinson         ###   ########.fr        #
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
	 $(MAKE) -C $(LIB_DIR)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	 $(MAKE) -C $(LIB_DIR) clean
	 $(RM) $(OBJS)

fclean: clean
	 $(MAKE) -C $(LIB_DIR) clean
	 $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
