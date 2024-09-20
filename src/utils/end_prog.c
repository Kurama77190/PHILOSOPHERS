/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 05:34:33 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/20 04:06:16 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_s_monitor(t_monitor *param);
void	free_s_sync(t_sync *param);


void	end_prog(t_data *param, char *stderr, int exit_code)
{
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
	param->start_signal = false;
	pthread_join(param->monitor_thread, NULL);
	param->monitor_thread = 0;
	if (pthread_mutex_destroy(&param->monitors_fork) != 0)
	{
		perror("Error destroying monitor mutex");
	}
	return ;
}

void	free_s_sync(t_sync *param)
{
	param->start_signal = false;
	if (pthread_mutex_destroy(&param->routines_fork) != 0)
	{
		perror("Error destroying sync mutex");
	}
	return ;
}
