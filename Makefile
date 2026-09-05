# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenich <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/03 17:00:34 by abenich           #+#    #+#              #
#    Updated: 2026/09/05 19:45:00 by abenich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_SRCS = $(LIBFT_DIR)/ft_putchar_fd.c $(LIBFT_DIR)/ft_putnbr_fd.c \
		$(LIBFT_DIR)/ft_putstr_fd.c $(LIBFT_DIR)/ft_strcmp.c \
		$(LIBFT_DIR)/ft_split.c

FILES = parsing/parse_numbers.c bench/get_strat_output.c \
		bench/strategy_parser.c bench/bench_display.c operations/sa.c \
		operations/sb.c operations/pb.c operations/pa.c operations/ra.c \
		operations/rra.c operations/rb.c operations/rrb.c operations/ss.c \
		operations/rr.c operations/rrr.c sort/chunk_sort.c sort/small_sort.c \
		src/main.c parsing/check.c sort/sort_moves.c sort/sort_strategies.c \
		src/sort_dispatch.c src/sort_runner.c parsing/parse_utils.c \
		sort/linear_sort.c

OFILES = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)
	@echo "Done."

$(LIBFT): $(LIBFT_SRCS) $(LIBFT_DIR)/Makefile push_swap.h
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all


.PHONY: all clean fclean re
