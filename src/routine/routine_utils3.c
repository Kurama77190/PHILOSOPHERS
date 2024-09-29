/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:49:02 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/29 19:09:39 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_optionnal_satiate(t_philo *philo)
{
	if (philo->optionnal)
	{
		pthread_mutex_lock(&philo->sync->meal_lock);
		if (philo->count_eat == philo->limit_meal)
		{
			pthread_mutex_unlock(&philo->sync->meal_lock);
			return (SATIATE);
		}
		pthread_mutex_unlock(&philo->sync->meal_lock);
	}
	return (SUCCESS);
}

int	check_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->sync->dead_lock);
	if (philo->sync->dead)
	{
		pthread_mutex_unlock(&philo->sync->dead_lock);
		return (DIED);
	}
	pthread_mutex_unlock(&philo->sync->dead_lock);
	return (SUCCESS);
}
