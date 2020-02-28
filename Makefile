# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/10 12:58:25 by aholster       #+#    #+#                 #
#    Updated: 2020/02/28 16:15:30 by aholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ARGUMENT_SRC := arg_lexer retrieve_arguments argument_creationkit

BUILTIN_SRC := builtin_exit builtin_echo builtin_env builtin_setenv\
 builtin_unsetenv builtin_cd

ENV_SRC := env_set env_search_key env_add_kvp env_del_kvp env_is_envkey_char

FILES := main shell_loop puterr hunt_exec

FILEC := $(FILES:%=ft_%.c) $(ENV_SRC:%=env_internals/%.c)\
 $(BUILTIN_SRC:%=builtins/%.c) $(ARGUMENT_SRC:%=./argument_generation/ft_%.c)

OBJ := $(FILEC:%.c=%.o)

DEPS := ./libft ./ft_printf

HEAD := minishell.h ./env_internals/ft_env.h ./builtins/builtin.h\
 ./argument_generation/ft_argument.h

NAME := minishell

CFLAGS := -Wall -Werror -Wextra -g

all: $(NAME)

make_deps:
	@for dir in $(DEPS); do \
		make -C $$dir ; \
	done

$(NAME): $(OBJ)
	@$(MAKE) make_deps
	@$(CC) $(CFLAGS) -o $@ $^ -L ./libft -lft -L ./ft_printf -lftprintf
	@echo "\033[0;32m$(NAME) compiled\033[0;00m"

%.o: %.c $(HEAD)
	@$(CC) -c $(CFLAGS) -o $@ $<

clean_deps:
	@for dir in $(DEPS); do \
		make fclean -C $$dir ; \
	done

clean: clean_deps
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

norm:
	@echo "\033[0;33m"
	@norminette $(FILEC) $(HEAD) | grep -e "Error"  -e "Warning" -B 1 || TRUE
	@echo "\033[0;00m"

add: norm
	@git add $(FILEC) $(HEAD) Makefile author
	@git status
