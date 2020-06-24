/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_iswhitespace.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 20:00:49 by aholster      #+#    #+#                 */
/*   Updated: 2019/02/01 21:02:48 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_iswhitespace(int c)
{
	if (c == '\t' || c == '\r' || c == '\n' || c == '\f' || c == '\v'\
	|| c == ' ')
		return (1);
	return (0);
}
