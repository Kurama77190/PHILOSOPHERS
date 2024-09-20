/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:02:07 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/20 18:49:10 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

# define NC "\e[0m"
# define YELLOW "\e[1;33m"

void	*monitor(void *param)
{
	t_data *data;
	t_philo	*current;
	int		test;

	data = (t_data *)param;
	current = data->thread.head;
	test = 0;
	while(!data->monitor.start_signal)
		usleep(100);
	while (current)
	{
		usleep(100);
		if (current->dead)
		{
			pthread_mutex_lock(&data->monitor.monitors_fork);
			printf("[%ld] Philosophers[%ld] is dead\n", get_ms(), current->id);
			pthread_mutex_unlock(&data->monitor.monitors_fork);
			end_prog(param, NULL, 0);
			return (NULL);
		}
		if (test >= 200)
		{
			break ;
		}
		pthread_mutex_lock(&data->monitor.monitors_fork);
		test++;
		pthread_mutex_unlock(&data->monitor.monitors_fork);
		if (!data->monitor.start_signal)
			break ;
	}
	return (NULL);
}
