/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/08 21:42:09 by aholster      #+#    #+#                 */
/*   Updated: 2020/06/24 12:12:22 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incl/ft_utilities.h"

size_t			ft_printf_strnlen(char const *s, size_t maxlen)
{
	size_t index;

	index = 0;
	while (s[index] != '\0' && index < maxlen)
	{
		index++;
	}
	return (index);
}
