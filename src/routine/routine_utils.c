/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:22:17 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/23 23:39:00 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_take_fork_a(t_philo *philo)
{
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->optionnal)
	{
		if (philo->count_eat == philo->time->n_of_time_eat)
		{
			pthread_mutex_unlock(&philo->sync->dead_lock);
			return (DIED);
		}
	}
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (DIED);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(philo->right);
	if (print_fork(philo) == DIED)
	{
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		return (DIED);
	}
	return (SUCCESS);
}

int	philo_take_fork_b(t_philo *philo)
{
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->optionnal)
	{
		if (philo->count_eat == philo->time->n_of_time_eat)
		{
			pthread_mutex_unlock(&philo->sync->dead_lock);
			return (DIED);
		}
	}
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (DIED);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	pthread_mutex_lock(philo->right);
	pthread_mutex_lock(philo->left);
	if (print_fork(philo) == DIED)
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		return (DIED);
	}
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
		return (DIED);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	if (print_eat(philo) == DIED)
	{
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		return (DIED);
	}
	pthread_mutex_lock(&philo->sync->dead_lock);
	philo->last_meal_time = get_ms();
	pthread_mutex_unlock(&philo->sync->dead_lock);
	usleep(philo->time->time_to_eat * 1000);
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
		return (DIED);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	if (print_eat(philo) == DIED)
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		return (DIED);
	}
	pthread_mutex_lock(&philo->sync->dead_lock);
	philo->last_meal_time = get_ms();
	pthread_mutex_unlock(&philo->sync->dead_lock);
	usleep(philo->time->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	return (SUCCESS);
}

int	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (DIED);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	if (print_sleep(philo) == DIED)
	{
		return (DIED);
	}
	pthread_mutex_lock(&philo->sync->dead_lock);
	philo->last_meal_time = get_ms();
	pthread_mutex_unlock(&philo->sync->dead_lock);
	usleep(philo->time->time_to_sleep * 1000);
	if (print_think(philo) == DIED)
	{
		return (DIED);
	}
	return (SUCCESS);
}
