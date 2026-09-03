# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenich <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/03 17:00:34 by abenich           #+#    #+#              #
#    Updated: 2026/09/02 17:45:19 by efresnil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FILES = bench/get_stg_output.c bench/get_stg_output2.c \
		operations/sa.c operations/sb.c operations/pb.c operations/pa.c \
		operations/ra.c operations/rra.c operations/rb.c operations/rrb.c \
		operations/ss.c operations/rr.c operations/rrr.c operations/op_helper.c \
		sort/strategy.c src/main.c parsing/check.c sort/find_move.c \
		sort/Adaptive.c sort/linear_sort.c src/main_helper.c parsing/free.c sort/helper.c

OFILES = $(FILES:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)
	@echo "Done."

clean:
	rm -f $(OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.SECONDARY: $(OFILES)

.PHONY: all clean fclean re
