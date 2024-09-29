/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:53:16 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/29 19:29:19 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_fork(t_philo *philo)
{
	unsigned long timestamp;

	if (check_dead(philo) == DIED)
		return (DIED);
	timestamp = get_ms(philo);
	pthread_mutex_lock(&philo->sync->write_lock);
	printf("%lu %u has taken a fork\n", timestamp, philo->id);
	pthread_mutex_unlock(&philo->sync->write_lock);
	if (check_dead(philo) == DIED)
		return (DIED);
	return (SUCCESS);
}

int	print_eat(t_philo *philo)
{
	unsigned long	timestamp;

	if (check_dead(philo) == DIED)
		return (DIED);
	timestamp = get_ms(philo);
	pthread_mutex_lock(&philo->sync->write_lock);
	printf("%lu %u is eating\n", timestamp, philo->id);
	pthread_mutex_unlock(&philo->sync->write_lock);
	pthread_mutex_lock(&philo->sync->meal_lock);
	philo->last_meal_time = timestamp;
	philo->count_eat++;
	philo->sync->count_all_meal++;
	pthread_mutex_unlock(&philo->sync->meal_lock);
	ft_usleep(philo, philo->time_to_eat);
	return (SUCCESS);
}

int	print_sleep(t_philo *philo)
{
	unsigned long	timestamp;

	if (check_dead(philo) == DIED)
		return (DIED);
	timestamp = get_ms(philo);
	pthread_mutex_lock(&philo->sync->write_lock);
	printf("%lu %u is sleeping\n", timestamp, philo->id);
	pthread_mutex_unlock(&philo->sync->write_lock);
	ft_usleep(philo, philo->time_to_sleep);
	return (SUCCESS);
}

int	print_think(t_philo *philo)
{
	unsigned long	timestamp;

	if (check_dead(philo) == DIED)
		return (DIED);
	timestamp = get_ms(philo);
	pthread_mutex_lock(&philo->sync->write_lock);
	printf("%lu %u is thinking\n", timestamp, philo->id);
	pthread_mutex_unlock(&philo->sync->write_lock);
	usleep(1000);
	return (SUCCESS);
}

int	print_die(t_philo *philo)
{
	unsigned long	timestamp;

	
	timestamp = get_ms(philo);
	pthread_mutex_lock(&philo->sync->write_lock);
	// printf("last time to eat = %u\n", philo->last_meal_time);
	// printf("time to die = %u\n", philo->time_to_die);
	printf("%lu %u died\n", timestamp, philo->id);
	pthread_mutex_unlock(&philo->sync->write_lock);
	return (SUCCESS);
}
