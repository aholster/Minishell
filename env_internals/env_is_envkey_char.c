/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_is_envkey_char.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/15 19:23:20 by aholster      #+#    #+#                 */
/*   Updated: 2020/02/15 19:24:08 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	is_envkey_char(const char character)
{
	if (ft_isalpha(character) || character == '_' || ft_isdigit(character))
	{
		return (1);
	}
	return (0);
}
