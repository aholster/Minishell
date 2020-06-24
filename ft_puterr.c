/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puterr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 23:22:45 by aholster      #+#    #+#                 */
/*   Updated: 2020/02/18 12:04:46 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

#include <stdarg.h>

#include "minishell.h"

void	ft_puterr(const char *const err, ...)
{
	va_list	ap;

	va_start(ap, err);
	ft_vdprintf(2, err, ap);
	va_end(ap);
}
