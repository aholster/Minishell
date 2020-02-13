/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_argument.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:44:24 by aholster       #+#    #+#                */
/*   Updated: 2020/02/13 15:51:01 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGUMENT_H
# define FT_ARGUMENT_H

# include "../minishell.h"

void	argument_new(t_arg_object *const aargs);
void	argument_expand(t_arg_object *const aargs,
				char const *str,
				const size_t len);
void	argument_finish(t_arg_object *const aargs);

int		generate_all_arguments(char const *raw_arg,\
				char const *const arg_end,\
				t_arg_object *const aargs);

#endif
