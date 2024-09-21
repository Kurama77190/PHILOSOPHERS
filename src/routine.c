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

#define NC "\e[0m"
#define YELLOW "\e[1;33m"

void	*routine_a(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->sync->dead)
	{
		pthread_mutex_lock(philo->left);
		pthread_mutex_lock(philo->right);
		pthread_mutex_lock(&philo->sync->write_lock);
		printf("Philosophe %lu mange...\n", philo->id);
		philo->last_meal_time = get_ms();
		usleep(philo->time->time_to_eat * 100);
		pthread_mutex_unlock(&philo->sync->write_lock);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_lock(&philo->sync->write_lock);
		printf("Philosophe %lu dort...\n", philo->id);
		usleep(philo->time->time_to_sleep * 100);
		pthread_mutex_unlock(&philo->sync->write_lock);
		pthread_mutex_lock(&philo->sync->write_lock);
		printf("Philosophe %lu pense...\n", philo->id);
		pthread_mutex_unlock(&philo->sync->write_lock);
	}
	return (NULL);
}

void	*routine_b(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->sync->dead)
	{
		pthread_mutex_lock(philo->right);
		pthread_mutex_lock(philo->left);
		pthread_mutex_lock(&philo->sync->write_lock);
		printf("Philosophe %lu mange...\n", philo->id);
		philo->last_meal_time = get_ms();
		usleep(philo->time->time_to_eat);
		pthread_mutex_unlock(&philo->sync->write_lock);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_lock(&philo->sync->write_lock);
		printf("Philosophe %lu dort...\n", philo->id);
		usleep(philo->time->time_to_sleep);
		pthread_mutex_unlock(&philo->sync->write_lock);
		pthread_mutex_lock(&philo->sync->write_lock);
		printf("Philosophe %lu pense...\n", philo->id);
		pthread_mutex_unlock(&philo->sync->write_lock);
	}
	return (NULL);
}
