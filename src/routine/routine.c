/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:59:05 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/20 03:41:44 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	only_one(t_philo *philo);

void	*routine(void *arg)
{
	t_philo *philo;

	philo = arg;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->id % 2 != 0)
		{
			if (routine_right_handed(philo) == STOP)
				break ;
		}
		else
		{
			if (routine_left_handed(philo) == STOP)
				break ;
		}
	}
	return (NULL);
}

int	routine_left_handed(t_philo *philo)
{
	if (philo->only_one)
	{
		only_one(philo);
		return (STOP);
	}
	if (philo_take_fork_a(philo) == DIED)
		return (STOP);
	if (philo_eat_a(philo) == DIED)
		return (STOP);
	if (philo_sleep(philo) == DIED)
		return (STOP);
	pthread_mutex_lock(&philo->sync->start_lock);
	if (philo->sync->stop_routine)  // je stop le monitor quand ils sont satiate !
	{
		pthread_mutex_unlock(&philo->sync->start_lock);
		return (STOP);
	}
	pthread_mutex_unlock(&philo->sync->start_lock);
	// peut etre un usleep ici :).
	return (SUCCESS);
}

int	routine_right_handed(t_philo *philo)
{
	if (philo->only_one)
	{
		only_one(philo);
		return (STOP);
	}
	if (philo_take_fork_b(philo) == DIED)
		return (STOP);
	if (philo_eat_b(philo) == DIED)
		return (STOP);
	if (philo_sleep(philo) == DIED)
		return (STOP);
	pthread_mutex_lock(&philo->sync->start_lock);
	if (philo->sync->stop_routine)
	{
		pthread_mutex_unlock(&philo->sync->start_lock);
		return (STOP);
	}
	pthread_mutex_unlock(&philo->sync->start_lock);
	return (SUCCESS);
}

void	only_one(t_philo *philo)
{
	pthread_mutex_lock(&philo->sync->write_lock);
	printf("%lu %u has taken a fork\n", get_ms(philo), philo->id);
	pthread_mutex_unlock(&philo->sync->write_lock);
	usleep(philo->time_to_die * 1000);
	print_die(philo);
}
