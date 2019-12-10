# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/10 12:58:25 by aholster       #+#    #+#                 #
#    Updated: 2019/12/10 15:57:07 by aholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FILES := main

FILEC := $(FILES:%=ft_%.c)

OBJ := $(FILEC:%=ft_%.o)

HEAD := minishell.h

NAME := minishell

CFLAGS := -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEAD)
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -fv $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

norm:
	@echo "\033[0;33m"
	@norminette $(FILEC) $(HEAD) | grep -e "Error"  -e "Warning" -B 1 || TRUE
	@echo "\033[0;00m"

add: norm
	@git add $(FILEC) $(HEAD) Makefile author
	@git status
