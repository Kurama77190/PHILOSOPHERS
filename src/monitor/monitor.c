/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:02:07 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/22 05:15:34 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_monitor(t_data *param);

void	*monitor(void *arg)
{
	t_data	*param;

	param = (t_data *)arg;
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
	}
	return (NULL);
}

void	exit_monitor(t_data *param)
{
	// pthread_mutex_lock(&param->sync.dead_lock);
	param->sync.stop_monitor = true;
	// pthread_mutex_unlock(&param->sync.dead_lock);
}
