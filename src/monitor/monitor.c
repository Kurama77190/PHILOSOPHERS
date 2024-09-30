/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:02:07 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/30 15:44:39 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor(void *arg)
{
	t_data	*param;
	t_philo	*current;

	param = (t_data *)arg;
	current = param->thread.head;
	while (1)
	{
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
		current = current->next;
	}
	return (NULL);
}
