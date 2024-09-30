/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:48:46 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/30 16:58:53 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(t_philo *param, unsigned int time_in_ms)
{
	long long	current_time;

	current_time = get_ms(param);
	while (check_dead(param) != DIED)
	{
		if (get_ms(param) - current_time >= time_in_ms)
			break ;
		usleep(1000);
	}
}
