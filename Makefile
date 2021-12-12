NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar -rcs

INCLUDE = ft_printf.h

SRC = 	ft_printf_utils1.c	\
		ft_printf_utils2.c	\
		ft_printf.c			\
		ft_printf_flags.c	\
		
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :$(OBJ) $(INCLUDE) 

	$(AR) $(NAME) $(OBJ)

%.o : %.c

	$(CC) $(FLAGS) -o $@ -c $<

bonus: $(OBJ)

	$(AR) $(NAME) $^

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all
