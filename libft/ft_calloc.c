/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 06:37:27 by aholster       #+#    #+#                */
/*   Updated: 2019/12/11 10:36:46 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t const size, size_t const n)
{
	const size_t	bytes = (n * size);
	void *const		mem = malloc(bytes);

	if (mem != NULL)
	{
		ft_bzero(mem, bytes);
	}
	return (mem);
}
