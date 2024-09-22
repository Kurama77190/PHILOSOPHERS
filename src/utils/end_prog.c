/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 05:34:33 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/22 04:55:52 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_s_monitor(t_monitor *param);
void	free_s_sync(t_sync *param);


void	end_prog(t_data *param, char *stderr, int exit_code)
{
	while (!param->sync.stop_monitor && !param->sync.stop_routine)
	{
		sleep(100);
	}
	free_s_sync(&param->sync);
	free_s_monitor(&param->monitor);
	free_s_philo(&param->thread);
	free_s_fork(&param->mutex);
	ft_putstr_fd(stderr, 2);
	exit(exit_code);
}

void	free_s_monitor(t_monitor *param)
{
	if (param->monitor_thread != 0)
		return ;
	if (pthread_join(param->monitor_thread, NULL) != 0)
	{
		perror("Error joining thread");
	}
	return ;
}

void	free_s_sync(t_sync *param)
{
	if (pthread_mutex_destroy(&param->dead_lock) != 0)
	{
		perror("Error destroying sync mutex dead_lock");
	}
	if (pthread_mutex_destroy(&param->write_lock) != 0)
	{
		perror("Error destroying sync mutex write_lock");
	}
	if (pthread_mutex_destroy(&param->meal_lock) != 0)
	{
		perror("Error destroying sync mutex meal_lock");
	}
	return ;
}
