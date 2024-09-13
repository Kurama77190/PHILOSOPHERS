/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:04:10 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/13 18:30:04 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	ft_is_digit(char *s)
{
	int	i;

	if (!s)
		return (false);
	i = 0;
	while (s[i])
	{
		if (s[i] == '+')
		{
			if (s[i + 1] && i != 0)
				return (false);
			else
				i++;
		}
		if (s[i] == '-')
			return (false);
		if (s[i] < '0' || s[i] > '9')
			return (false);
		i++;
	}
	return (true);
}
