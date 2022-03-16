# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 23:39:11 by ygbouri           #+#    #+#              #
#    Updated: 2022/03/04 05:00:31 by ygbouri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CLIENT	=	client
SERVER	=	server
CLIENTB	=	client_bonus
SERVERB	=	server_bonus

PRINTF		=	ft_printf/libftprintf.a
PRINTF_DIR	=	ft_printf/

SRC_C	=	client.c
SRC_S	=	server.c
SRCB_C	=	client_bonus.c
SRCB_S	=	server_bonus.c

CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -f

all: $(SERVER) $(CLIENT) $(SERVERB) $(CLIENTB)

$(SERVER): $(PRINTF) $(HEADER) $(SRC_S)
	@ $(CC) $(CFLAG) $(SRC_S) $(PRINTF) -o $(SERVER) 

$(CLIENT): $(PRINTF) $(HEADER) $(SRC_C)
	@ $(CC) $(CFLAG) $(SRC_C) $(PRINTF) -o $(CLIENT)

$(SERVERB): $(PRINTF) $(HEADER) $(SRCB_S)
	@ $(CC) $(CFLAG) $(SRCB_S) $(PRINTF) -o $(SERVERB)

$(CLIENTB): $(PRINTF) $(HEADER) $(SRCB_C)
	@ $(CC) $(CFLAG) $(SRCB_C) $(PRINTF) -o $(CLIENTB)

$(PRINTF):
	@ $(MAKE) -C $(PRINTF_DIR)

clean:
	@ $(RM) $(CLIENT) $(SERVER)
	@ $(RM) $(CLIENTB) $(SERVERB)

fclean:
	@ $(MAKE) fclean -C $(PRINTF_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@ $(RM) $(CLIENTB) $(SERVERB)
re: fclean all

mandatory:	$(CLIENT) $(SERVER)
bonus:		$(CLIENTB) $(SERVERB)

m : mandatory
b : bonus

.PHONY: all clean fclean re mandatory m bonus b
