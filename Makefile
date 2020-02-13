# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/10 12:58:25 by aholster       #+#    #+#                 #
#    Updated: 2020/02/13 18:11:41 by aholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ARGUMENT_SRC := generate_all_arguments retrieve_arguments argument_creationkit

BUILTIN_SRC := builtin_exit builtin_echo builtin_env builtin_setenv\
 builtin_unsetenv builtin_cd

ENV_SRC := env_set env_search_key env_add_kvp env_del_kvp

FILES := main shell_loop puterr hunt_exec

FILEC := $(FILES:%=ft_%.c) $(ENV_SRC:%=env_internals/%.c)\
 $(BUILTIN_SRC:%=builtins/%.c) $(ARGUMENT_SRC:%=./argument_generation/ft_%.c)

OBJ := $(FILEC:%.c=%.o)

DEPS := ./libft

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
	@$(CC) $(CFLAGS) -o $@ $^ -L ./libft -lft

%.o: %.c $(HEAD)
	@$(CC) -c $(CFLAGS) -o $@ $<

clean_deps:
	@for dir in $(DEPS); do \
		make fclean -C $$dir ; \
	done

clean: clean_deps
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
