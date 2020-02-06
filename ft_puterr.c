/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puterr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 23:22:45 by aholster       #+#    #+#                */
/*   Updated: 2020/02/05 17:30:05 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdarg.h>

#include "minishell.h"

void	ft_puterr(const char *const err, ...)
{
	va_list	ap;

	va_start(ap, err);
	vdprintf(2, err, ap);
	va_end(ap);
}
