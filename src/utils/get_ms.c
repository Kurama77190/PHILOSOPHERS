/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ms.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:00:23 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/30 16:59:09 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	get_ms(t_philo *param)
{
	struct timeval	tv;
	static long int	start_time = 0;
	long int		current_time;
	long int		result;

	(void)param;
	pthread_mutex_lock(&param->sync->time_lock);
	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("Error timeval");
		return (-1);
	}
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	if (start_time == 0)
		start_time = current_time;
	result = (current_time - start_time);
	pthread_mutex_unlock(&param->sync->time_lock);
	return (result);
}
