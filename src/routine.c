/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:59:05 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/20 03:41:44 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

# define NC "\e[0m"
# define YELLOW "\e[1;33m"

void	*routine(void	*param)
{
	t_philo *data = param;

	while(!data->sync->start_signal)
	{
		pthread_mutex_lock(&data->sync->routines_fork);
		usleep(100);
		pthread_mutex_unlock(&data->sync->routines_fork);
	}
	while(1)
	{
		pthread_mutex_lock(&data->sync->routines_fork);
		printf("%sTest from threads[%ld].%s\n", YELLOW, get_ms(), NC);
		pthread_mutex_unlock(&data->sync->routines_fork);
		if (!data->sync->start_signal)
		{
			break ;
		}
	}
	return (NULL);
}
