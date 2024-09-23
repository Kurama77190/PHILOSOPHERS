/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:22:35 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/23 17:50:17 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_philosopher_dead(t_philo *philo, long current_time, t_data *param)
{
	pthread_mutex_lock(&param->sync.meal_lock);
	if (current_time - philo->last_meal_time > param->time.time_to_die)
	{
		pthread_mutex_lock(&param->sync.dead_lock);
		param->sync.dead = true;
		pthread_mutex_unlock(&param->sync.dead_lock);
		pthread_mutex_unlock(&param->sync.meal_lock);
		printf("%lu %lu died\n", get_ms(), philo->id);
		return (ERROR);
	}
	pthread_mutex_unlock(&param->sync.meal_lock);
	return (SUCCESS);
}

int	check_global_death(t_data *param)
{
	pthread_mutex_lock(&param->sync.dead_lock);
	if (param->sync.dead)
	{
		pthread_mutex_unlock(&param->sync.dead_lock);
		return (ERROR);
	}
	pthread_mutex_unlock(&param->sync.dead_lock);
	return (SUCCESS);
}

int	monitor_philosophers(t_data *param)
{
	t_philo	*current;
	long	current_time;

	current = param->thread.head;
	while (current != NULL)
	{
		current_time = get_ms();
		pthread_mutex_lock(&param->sync.dead_lock);
		if (current_time - current->last_meal_time > param->time.time_to_die)
		{
			param->sync.dead = true;
			pthread_mutex_unlock(&param->sync.dead_lock);
			printf("Philosophe %lu est mort.\n", current->id);
			return (ERROR);
		}
		pthread_mutex_unlock(&param->sync.dead_lock);
		current = current->next;
	}
	return (SUCCESS);
}

int	check_global_satiate(t_data *param)
{
	pthread_mutex_lock(&param->sync.dead_lock);
	if (param->time.n_of_time_eat == param->sync.count_all_eat)
	{
		pthread_mutex_unlock(&param->sync.dead_lock);
		return (SATIATE);
	}
	pthread_mutex_unlock(&param->sync.dead_lock);
	return (SUCCESS);
}
