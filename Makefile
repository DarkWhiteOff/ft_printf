# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zamgar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 18:27:37 by zamgar            #+#    #+#              #
#    Updated: 2024/06/12 18:28:29 by zamgar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_printf.c \
	ft_hex.c \
	ft_itoa.c \
	ft_unsigned_itoa.c \
	ft_ptr.c \
	ft_putcharstr.c \
	ft_strlen.c
	
BFILES =	ft_printf.o \
		ft_hex.o \
		ft_itoa.o \
		ft_unsigned_itoa.o \
		ft_ptr.o \
		ft_putcharstr.o \
		ft_strlen.o

MAIN =	 $(SRC) main.c
BMAIN =  $(BFILES) main.o

OBJS = ${SRC:.c=.o}
OBJSMAIN = ${MAIN:.c=.o}

NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Wextra -Werror -I ./

.c.o:
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

run: $(NAME) $(OBJSMAIN)
	$(CC) $(FLAGS) $(OBJSMAIN) -L. -lftprintf -o a.out &&./a.out

clean:
	rm -f $(OBJS) $(OBJSMAIN)

fclean: clean
	rm -f $(NAME)

re: fclean all

