/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putcaret_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:53:13 by aholster       #+#    #+#                */
/*   Updated: 2019/11/25 06:50:24 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putcaret_fd(int c, const int fd)
{
	char caret[2];

	if (c < ' ' && c >= 0)
	{
		caret[0] = '^';
		caret[1] = c + '@';
		write(fd, caret, 2);
	}
	else if (c == 127)
		write(fd, "^?", 2);
	else
		ft_putchar_fd(c, fd);
}
