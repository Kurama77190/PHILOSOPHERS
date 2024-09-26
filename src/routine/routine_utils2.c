/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:53:16 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/26 19:58:58 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (DIED);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	pthread_mutex_lock(&philo->sync->write_lock);
	printf("%lu %lu has taken a fork\n", get_ms(), philo->id);
	pthread_mutex_unlock(&philo->sync->write_lock);
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (DIED);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	return (SUCCESS);
}

int	print_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (DIED);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	pthread_mutex_lock(&philo->sync->write_lock);
	printf("%lu %lu is eating\n", get_ms(), philo->id);
	pthread_mutex_lock(&philo->sync->meal_lock);
	philo->last_meal_time = get_ms();
	pthread_mutex_unlock(&philo->sync->meal_lock);
	pthread_mutex_unlock(&philo->sync->write_lock);
	philo->count_eat++;
	usleep(philo->time_to_die);
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (DIED);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	return (SUCCESS);
}

int	print_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (DIED);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	pthread_mutex_lock(&philo->sync->write_lock);
	printf("%lu %lu is sleeping\n", get_ms(), philo->id);
	pthread_mutex_unlock(&philo->sync->write_lock);
	usleep(philo->time_to_sleep);
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (DIED);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	return (SUCCESS);
}

int	print_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (DIED);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	pthread_mutex_lock(&philo->sync->write_lock);
	printf("%lu %lu is thinking\n", get_ms(), philo->id);
	pthread_mutex_unlock(&philo->sync->write_lock);
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (DIED);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	return (SUCCESS);
}

int	print_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->sync->write_lock);
	printf("%lu %lu died\n", get_ms(), philo->id);
	pthread_mutex_unlock(&philo->sync->write_lock);
	return (SUCCESS);
}
