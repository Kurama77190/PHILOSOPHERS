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

void	*routine_a(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo_take_fork_a(philo) == DIED)
		{
			return (NULL);
		}
		if (philo_eat_a(philo) == DIED)
		{
			return (NULL);
		}
		if (philo_sleep(philo) == DIED)
		{
			return (NULL);
		}
	}
	return (NULL);
}

void	*routine_b(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo_take_fork_b(philo) == DIED)
		{
			return (NULL);
		}
		if (philo_eat_b(philo) == DIED)
		{
			return (NULL);
		}
		if (philo_sleep(philo) == DIED)
		{
			return (NULL);
		}
	}
	return (NULL);
}
