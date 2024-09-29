/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:02:07 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/29 18:43:06 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor(void *arg)
{
	t_data	*param;
	t_philo	*current;

	param = (t_data *)arg;
	while (1)
	{
		current = param->thread.head;
		if (monitor_philosophers(current, param) == DIED)
		{
			break ;
		}
		if (check_optionnal_terminated(param) == SATIATE)
		{
			pthread_mutex_lock(&current->sync->start_lock);
			current->sync->stop_routine = true;
			pthread_mutex_unlock(&current->sync->start_lock);
			break ;
		}
		usleep(100);
	}
	return (NULL);
}
