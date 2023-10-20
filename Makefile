# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npremont <npremont@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 11:13:51 by npremont          #+#    #+#              #
#    Updated: 2023/10/20 11:34:23 by npremont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c chars.c numbers.c ft_utoa_base.c ft_utoa.c ft_lutoa_base.c ft_itoa.c

OBJECTS = $(SOURCES:.c=.o)

HEADER = ft_printf.h

GCC_FLAGS = -Wall -Wextra -Werror -fsanitize=address -g

LIB = libft/libft.a

LIB_PATH = libft

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB)
	ar src $(NAME) $(OBJECTS)

$(OBJECTS):
	gcc $(GCC_FLAGS) -c -I $(HEADER) ${@:.o=.c} -o $@

$(LIB):
	cd $(LIB_PATH) && make bonus

clean:
	rm -f $(OBJECTS)
	cd $(LIB_PATH) && make clean

fclean:
	rm -f $(NAME) $(OBJECTS)
	cd $(LIB_PATH) && make fclean

re: fclean all

.PHONY: all clean fclean re

# gcc $(GCC_FLAGS) -o $(NAME) $(OBJECTS) $(LIB)
