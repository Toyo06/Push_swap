# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sroggens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 22:08:49 by sroggens          #+#    #+#              #
#    Updated: 2022/11/12 18:49:54 by sroggens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = Algo_by3.c Fill_list.c Algo_otherbis.c Algo_other1.c Algo_other2.c \
	   Move_ra.c Move_rra.c Move_sa.c Move_pa.c \
	   Parsing_check.c Parsing_check2.c Parsing_checkorder.c \
	   Tool_list.c Tool_printf.c Tool_printf2.c Tool_split.c Tool_utils.c \
	   Write_opti.c Write_opti2.c \
	   main.c \
	   Error_management.c \
	   Final_placement.c \
	   Parsing_pushswap1.c \

OBJECTS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
	rm -rf $(OBJECTS)

.PHONY: all clean fclean re
