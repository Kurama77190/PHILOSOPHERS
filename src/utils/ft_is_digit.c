/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:04:10 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/09 00:04:18 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	ft_is_digit(char *split)
{
	int	i;

	if (!split)
		return (false);
	i = 0;
	while (split[i])
	{
		if (split[i] == '+')
		{
			if (split[i + 1] && i != 0)
				return (false);
			else
				i++;
		}
		if (split[i] == '-')
			i++;
		if (split[i] < '0' || split[i] > '9')
			return (false);
		i++;
	}
	return (true);
}
