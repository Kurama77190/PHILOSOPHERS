/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:22:17 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/22 05:10:10 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_take_fork_a(t_philo *philo)
{
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (ERROR);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(philo->right);
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(&philo->sync->dead_lock);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		return (ERROR);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	return (SUCCESS);
}

int	philo_take_fork_b(t_philo *philo)
{
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (ERROR);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	pthread_mutex_lock(philo->right);
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(&philo->sync->dead_lock);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		return (ERROR);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	return (SUCCESS);
}

int	philo_eat_a(t_philo *philo)
{
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (ERROR);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	pthread_mutex_lock(&philo->sync->write_lock);
	printf("[%lu]Philosophe %lu mange (gaucher)...\n", get_ms(), philo->id);
	pthread_mutex_unlock(&philo->sync->write_lock);
	pthread_mutex_lock(&philo->sync->dead_lock);
	philo->last_meal_time = get_ms();
	usleep(philo->time->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->sync->dead_lock);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	return (SUCCESS);
}

int	philo_eat_b(t_philo *philo)
{
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (ERROR);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	pthread_mutex_lock(&philo->sync->write_lock);
	printf("[%lu]Philosophe %lu mange (droitier)...\n", get_ms(), philo->id);
	pthread_mutex_unlock(&philo->sync->write_lock);
	pthread_mutex_lock(&philo->sync->dead_lock);
	philo->last_meal_time = get_ms();
	usleep(philo->time->time_to_eat);
	pthread_mutex_unlock(&philo->sync->dead_lock);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	return (SUCCESS);
}

int	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (ERROR);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	pthread_mutex_lock(&philo->sync->write_lock);
	printf("[%lu]Philosophe %lu mange (droitier)...\n", get_ms(), philo->id);
	pthread_mutex_unlock(&philo->sync->write_lock);
	pthread_mutex_lock(&philo->sync->dead_lock);
	philo->last_meal_time = get_ms();
	usleep(philo->time->time_to_eat);
	pthread_mutex_unlock(&philo->sync->dead_lock);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	return (SUCCESS);
}
