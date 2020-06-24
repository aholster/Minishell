/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 16:02:34 by aholster      #+#    #+#                 */
/*   Updated: 2019/12/11 17:42:00 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memdup(const void *src, const size_t len)
{
	char		*ret;

	ret = (char *)malloc(sizeof(char) * len);
	if (ret == NULL)
	{
		return (NULL);
	}
	else
	{
		ft_memcpy(ret, src, len);
		return ((void *)ret);
	}
}
