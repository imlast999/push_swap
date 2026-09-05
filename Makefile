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

FILES = bench/bench_metrics.c bench/bench_report.c \
		operations/sa.c operations/sb.c operations/pb.c operations/pa.c \
		operations/ra.c operations/rra.c operations/rb.c operations/rrb.c \
		operations/ss.c operations/rr.c operations/rrr.c \
		sort/adaptive.c sort/linear_sort.c sort/chunk_sort.c sort/sort_small.c sort/sort_utils.c \
		parsing/validation.c parsing/parse_args.c parsing/parse_number.c parsing/cleanup.c \
		src/main.c src/dispatch.c

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
