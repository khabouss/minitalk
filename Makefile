# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/30 12:16:54 by tkhabous          #+#    #+#              #
#    Updated: 2021/05/30 12:16:55 by tkhabous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
flags = -Wall -Wextra -Werror
SRCSC = client.c resources/*.c
SRCSB = bonus/client.c resources/*.c
SRCSS = server.c resources/*.c
NAME  = minitalk
NAME2 = minitalk2

all : $(NAME)

$(NAME):
	@$(CC) $(flags) $(SRCSC) -o client
	@$(CC) $(flags) $(SRCSS) -o server

bonus : $(NAME2)
	
$(NAME2):
	@$(CC) $(flags) $(SRCSB) -o client_bonus
	@$(CC) $(flags) $(SRCSS) -o server

clean:
	@rm -rf client server client_bonus

fclean: clean

re: fclean all
