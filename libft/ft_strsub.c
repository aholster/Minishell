/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 19:18:45 by aholster       #+#    #+#                */
/*   Updated: 2020/02/14 17:03:03 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	total_len;

	total_len = ft_strlen(s);
	if (start > total_len)
	{
		ft_segdefault();
		return (NULL);
	}
	else
	{
		if (start + len <= total_len)
		{
			str = ft_memdup(s + start, len + 1);
			str[len] = '\0';
		}
		else
		{
			str = ft_memdup(s + start, (total_len + 1) - start);
			str[total_len] = '\0';
		}
		return (str);
	}
}
