# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npremont <npremont@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 11:13:51 by npremont          #+#    #+#              #
#    Updated: 2023/10/20 12:50:17 by npremont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c chars.c numbers.c ft_utoa_base.c ft_utoa.c ft_lutoa_base.c ft_itoa.c

OBJECTS = $(SOURCES:.c=.o)

HEADER = ft_printf.h

GCC_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar src $(NAME) $(OBJECTS)

$(OBJECTS):
	gcc $(GCC_FLAGS) -c -I $(HEADER) ${@:.o=.c} -o $@

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(NAME) $(OBJECTS)

re: fclean all

.PHONY: all clean fclean re
