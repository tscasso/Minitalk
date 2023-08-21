NAME	=	libftprintf.a

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -f

SRCS	=	ft_printfn.c ft_printf.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
