/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_if.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 21:31:16 by aholster      #+#    #+#                 */
/*   Updated: 2019/12/11 17:41:25 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_if(char **tab, int (*f)(char*))
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (tab[i] != NULL)
	{
		if (((*f)(tab[i])) == 1)
			c++;
		i++;
	}
	return (c);
}
