/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:02:07 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/23 07:15:07 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_monitor(t_data *param);
int	check_global_satiate(t_data *param);

void	*monitor(void *arg)
{
	t_data	*param;

	param = (t_data *)arg;
	usleep(param->time.time_to_die - 10);
	while (1)
	{
		if (check_global_death(param) == ERROR)
		{
			exit_monitor(param);
			return (NULL);
		}
		if (monitor_philosophers(param) == ERROR)
		{
            exit_monitor(param);
			return (NULL);
		}
		if (check_global_satiate(param) == SATIATE)
		{
			exit_monitor(param);
			return (NULL);
		}
		usleep(8000);
	}
	return (NULL);
}

void	exit_monitor(t_data *param)
{
	pthread_mutex_lock(&param->sync.dead_lock);
	param->sync.stop_monitor = true;
	pthread_mutex_unlock(&param->sync.dead_lock);
	return ;
}

int	check_global_satiate(t_data *param)
{
	while (1)
	{
		pthread_mutex_lock(&param->sync.dead_lock);
		if (param->time.n_of_time_eat == param->sync.count_all_eat)
		{
			pthread_mutex_unlock(&param->sync.dead_lock);
			return (SATIATE);
		}
		usleep(1000);
	}
	return (SUCCESS);
}
