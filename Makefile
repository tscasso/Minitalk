CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

FT_PRINTF = ft_printf
NAME_CLIENT = client
NAME_SERVER = server

SRCS_CLIENT = client.c utils.c
SRCS_SERVER = server.c utils.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

all: $(FT_PRINTF) $(NAME_CLIENT) $(NAME_SERVER)

$(FT_PRINTF):
	make -sC $@ 

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $^ -o $@ -L$(FT_PRINTF) -lftprintf

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $^ -o $@ -L$(FT_PRINTF) -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

bonus: all

clean:
	make -sC $(FT_PRINTF) clean
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	make -sC $(FT_PRINTF) fclean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all
