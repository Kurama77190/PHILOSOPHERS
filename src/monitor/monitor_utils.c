/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:22:35 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/30 16:12:41 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_optionnal_terminated(t_data *param);

int	monitor_philosophers(t_philo *current, t_data *param)
{
	long	current_time;

	if (param->sync.only_one)
		return (DIED);
	current_time = get_ms(current);
	pthread_mutex_lock(&current->sync->meal_lock);
	if (current_time - current->last_meal_time > current->time_to_die)
	{
		pthread_mutex_unlock(&param->sync.meal_lock);
		pthread_mutex_lock(&param->sync.dead_lock);
		param->sync.dead = true;
		pthread_mutex_unlock(&param->sync.dead_lock);
		print_die(current);
		return (DIED);
	}
	pthread_mutex_unlock(&param->sync.meal_lock);
	usleep(100);
	return (SUCCESS);
}

int	check_optionnal_terminated(t_data *param)
{
	t_philo	*current;
	size_t	i;
	size_t	count;

	current = param->thread.head;
	i = 0;
	count = 0;
	while (i < param->thread.n_thread)
	{
		pthread_mutex_lock(&param->sync.meal_lock);
		if (current->count_eat == current->limit_meal)
		{
			pthread_mutex_unlock(&param->sync.meal_lock);
			count++;
		}
		else
			pthread_mutex_unlock(&param->sync.meal_lock);
		current = current->next;
		i++;
	}
	if (count == (size_t)param->thread.n_thread)
	{
		return (SATIATE);
	}
	return (SUCCESS);
}
