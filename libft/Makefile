NAME = libft.a

SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
			ft_tolower.c ft_toupper.c

SOURCES_BON = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c ft_lstdelone.c

OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BON = $(SOURCES_BON:.c=.o)

HEADER = libft.h

GCC_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -src $(NAME) $(OBJECTS)

$(OBJECTS):
	gcc $(GCC_FLAGS) -c -I $(HEADER) ${@:.o=.c} -o $@

$(OBJECTS_BON):
	gcc $(GCC_FLAGS) -c -I $(HEADER) ${@:.o=.c} -o $@

clean:
	rm -f $(OBJECTS) ${OBJECTS_BON}

fclean:
	rm -f $(NAME) $(OBJECTS) $(OBJECTS_BON)

bonus: ${OBJECTS} ${OBJECTS_BON}
	ar -src $(NAME) $(OBJECTS) ${OBJECTS_BON}


re: fclean all

.PHONY: all clean fclean re bonus
