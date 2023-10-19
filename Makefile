# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npremont <npremont@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 11:13:51 by npremont          #+#    #+#              #
#    Updated: 2023/10/19 18:24:09 by npremont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

SOURCES = ft_printf.c chars.c numbers.c ft_itoa_base.c ft_utoa.c ft_litoa_base.c

OBJECTS = $(SOURCES:.c=.o)

HEADER = ft_printf.h

GCC_FLAGS = -Wall -Wextra -Werror -fsanitize=address -g

LIB = libft/libft.a

LIB_PATH = libft

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB)
	gcc $(GCC_FLAGS) -o $(NAME) $(OBJECTS) $(LIB)
	make clean

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
