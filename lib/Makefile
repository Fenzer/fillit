# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fepinson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 18:43:04 by fepinson          #+#    #+#              #
#    Updated: 2019/01/25 14:25:10 by fepinson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=	$(realpath .)/src

INC_DIR		=	$(realpath .)

NAME		=	libft.a

CC			=	 gcc

RM			=	rm -f

SRCS		=	$(SRC_DIR)/ft_bzero.c			\
				$(SRC_DIR)/ft_itoa.c			\
				$(SRC_DIR)/ft_memalloc.c 		\
				$(SRC_DIR)/ft_memcpy.c			\
				$(SRC_DIR)/ft_memdel.c			\
				$(SRC_DIR)/ft_memset.c			\
				$(SRC_DIR)/ft_putchar.c			\
				$(SRC_DIR)/ft_putchar_fd.c		\
				$(SRC_DIR)/ft_putendl.c			\
				$(SRC_DIR)/ft_putendl_fd.c		\
				$(SRC_DIR)/ft_putnbr.c			\
				$(SRC_DIR)/ft_putnbr_fd.c		\
				$(SRC_DIR)/ft_putstr.c			\
				$(SRC_DIR)/ft_putstr_fd.c		\
				$(SRC_DIR)/ft_strchr.c			\
				$(SRC_DIR)/ft_strclr.c			\
				$(SRC_DIR)/ft_strdel.c			\
				$(SRC_DIR)/ft_strequ.c			\
				$(SRC_DIR)/ft_striter.c			\
				$(SRC_DIR)/ft_striteri.c		\
				$(SRC_DIR)/ft_strjoin.c			\
				$(SRC_DIR)/ft_strlen.c			\
				$(SRC_DIR)/ft_strmap.c			\
				$(SRC_DIR)/ft_strmapi.c			\
				$(SRC_DIR)/ft_strnequ.c			\
				$(SRC_DIR)/ft_strnew.c			\
				$(SRC_DIR)/ft_strrchr.c			\
				$(SRC_DIR)/ft_strsplit.c		\
				$(SRC_DIR)/ft_strsub.c			\
				$(SRC_DIR)/ft_strtrim.c			\
				$(SRC_DIR)/ft_strdup.c			\
				$(SRC_DIR)/ft_strlcat.c			\
				$(SRC_DIR)/ft_strcpy.c			\
				$(SRC_DIR)/ft_strncmp.c			\
				$(SRC_DIR)/ft_tolower.c			\
				$(SRC_DIR)/ft_toupper.c			\
				$(SRC_DIR)/ft_strncat.c			\
				$(SRC_DIR)/ft_strncpy.c			\
				$(SRC_DIR)/ft_strstr.c			\
				$(SRC_DIR)/ft_strnstr.c			\
				$(SRC_DIR)/ft_strdup.c			\
				$(SRC_DIR)/ft_strndup.c			\
				$(SRC_DIR)/ft_isascii.c			\
				$(SRC_DIR)/ft_isalpha.c 		\
				$(SRC_DIR)/ft_isdigit.c			\
				$(SRC_DIR)/ft_atoi.c			\
				$(SRC_DIR)/ft_strcmp.c			\
				$(SRC_DIR)/ft_strnstr.c			\
				$(SRC_DIR)/ft_strcat.c			\
				$(SRC_DIR)/ft_memccpy.c			\
				$(SRC_DIR)/ft_memchr.c			\
				$(SRC_DIR)/ft_memmove.c			\
				$(SRC_DIR)/ft_memcmp.c			\
				$(SRC_DIR)/ft_isalnum.c			\
				$(SRC_DIR)/ft_lstadd.c			\
				$(SRC_DIR)/ft_lstdel.c			\
				$(SRC_DIR)/ft_lstdelone.c		\
				$(SRC_DIR)/ft_lstiter.c			\
				$(SRC_DIR)/ft_lstmap.c			\
				$(SRC_DIR)/ft_lstnew.c			\
				$(SRC_DIR)/ft_isprint.c			\
				$(SRC_DIR)/ft_atoi_base.c		\
				$(SRC_DIR)/ft_atoi_cbase.c		\
				$(SRC_DIR)/ft_putnbr_base.c		\
				$(SRC_DIR)/ft_str_isalpha.c		\
				$(SRC_DIR)/ft_dyncat.c			\
				$(SRC_DIR)/ft_str_isalnum.c		\
				$(SRC_DIR)/ft_str_isdigit.c		\
				$(SRC_DIR)/ft_revstr.c			\
				$(SRC_DIR)/ft_swap.c			\
				$(SRC_DIR)/ft_xorswap.c			\
				$(SRC_DIR)/ft_freetab.c			\
				$(SRC_DIR)/ft_strssplit.c		\
				$(SRC_DIR)/ft_itoa_base.c		\
				$(SRC_DIR)/ft_itoa_cbase.c		\
				#$(SRC_DIR)/ft_get_next_line.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror

CPPFLAGS	=	-I$(INC_DIR)

all:			$(NAME)

$(NAME):		$(OBJS)
				@ ar -rcs $(NAME) $(OBJS)

clean:
				 $(RM) $(OBJS)

fclean:         clean
				 $(RM) $(NAME)

re:             fclean all

.PHONY:			all clean fclean re
