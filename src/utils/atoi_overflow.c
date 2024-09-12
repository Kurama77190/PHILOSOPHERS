/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_overflow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:21:59 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/09 01:24:42 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	is_atoi_overflow(char *str);
bool	ft_check_overflow(char *str, long long nb, int sign, size_t len);

bool	atoi_overflow(char *strs)
{
    if (is_atoi_overflow(strs))
		return (true);
	return (false);
}

bool	is_atoi_overflow(char *str)
{
	size_t		len;
	long long	nb;
	int			sign;

	len = 0;
	nb = 0;
	sign = 1;
	while ((str[len] > 8 && str[len] < 14) || str[len] == 32)
		len++;
	if (str[len] == '-')
	{
		sign = -1;
		len++;
	}
	else if (str[len] == '+')
		len++;
	while (str[len] >= '0' && str[len] <= '9')
	{
		if (ft_check_overflow(str, nb, sign, len))
			return (true);
		nb = nb * 10 + (str[len] - '0');
		len++;
	}
	return (false);
}

bool	ft_check_overflow(char *str, long long nb, int sign, size_t len)
{
	int	digit;

	digit = str[len] - '0';
	if (sign == 1 && (nb > INT_MAX / 10 || \
	(nb == INT_MAX / 10 && digit > INT_MAX % 10)))
		return (true);
	else if (sign == -1 && (nb > -(long long)INT_MIN / 10 || (nb == \
	-(long long)INT_MIN / 10 && digit > -(long long)INT_MIN % 10)))
		return (true);
	else
		return (false);
}
