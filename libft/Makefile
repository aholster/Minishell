# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/10 12:58:25 by aholster      #+#    #+#                  #
#    Updated: 2020/06/24 11:00:45 by aholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

BONOR := lstnew lstdelone lstdel lstadd lstiter lstmap

ADVOR := memalloc memdel strnew strdel strclr striter striteri strmap\
 strmapi strequ strnequ strsub strjoin strtrim strsplit itoa putchar\
 putstr putendl putnbr putchar_fd putstr_fd putendl_fd putnbr_fd

BASICOR := memset bzero memcpy memccpy memmove memchr memcmp\
 strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr\
 strstr strnstr strcmp strncmp\
 atoi isalpha isdigit isalnum isascii isprint toupper tolower

CUSOR:= ll_len ull_len del lstaddend itoba iswhitespace isprime power\
 putstrarr\
 putstrarr_fd strarrdel strarrtolst lsttostrarr lstlen min max constrain\
 segdefault factorial count_if range sqrt absneg swap lsttardest memjoin \
 memdup strarrnew textangle stralloc bitprint putmem putmem_fd\
 putmemendl putmemendl_fd lstmemtomem lststrtostr iscapital islowercase\
 stock_read stock_write putcaret putcaret_fd strnlen\
 lst_stack_push lst_stack_pop lstqueue_push lstqueue_pop lstqueue_add\
 calloc

FILE := $(CUSOR) $(BONOR) $(ADVOR) $(BASICOR)

FILEC := $(FILE:%=ft_%.c)

OBJ := $(FILEC:%.c=%.o)

HEAD := libft.h

NAME := libft.a

CFLAGS := -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $@ $^
	@echo "\033[0;32m$(NAME) compiled\033[0;00m"

%.o: %.c $(HEAD)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
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
