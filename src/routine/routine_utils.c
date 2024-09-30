/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:22:17 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/30 16:17:24 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_take_fork_a(t_philo *philo)
{
	if (philo->optionnal)
		if (check_optionnal_satiate(philo) == SATIATE)
			return (SATIATE);
	if (check_dead(philo) == DIED)
		return (DIED);
	pthread_mutex_lock(philo->left);
	if (print_fork(philo) == DIED)
	{
		pthread_mutex_unlock(philo->left);
		return (DIED);
	}
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
	if (philo->optionnal)
		if (check_optionnal_satiate(philo) == SATIATE)
			return (SATIATE);
	if (check_dead(philo) == DIED)
		return (DIED);
	pthread_mutex_lock(philo->right);
	if (print_fork(philo) == DIED)
	{
		pthread_mutex_unlock(philo->right);
		return (DIED);
	}
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
	if (philo->optionnal)
	{
		if (philo->count_eat == philo->limit_meal)
			return (SATIATE);
	}
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
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	return (SUCCESS);
}

int	philo_eat_b(t_philo *philo)
{
	if (philo->optionnal)
	{
		if (philo->count_eat == philo->limit_meal)
			return (SATIATE);
	}
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
	if (print_think(philo) == DIED)
		return (DIED);
	return (SUCCESS);
}
