/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_iscapital.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 16:47:03 by aholster       #+#    #+#                */
/*   Updated: 2019/04/18 16:48:02 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_iscapital(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
