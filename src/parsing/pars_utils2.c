/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:57:27 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/23 18:07:03 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_philo(t_data *param)
{
	t_philo	*current;

	current = param->thread.head;
	if (sequential_thread_launch(param, current) == ERROR)
		return (ERROR);
	if (pthread_create(&param->monitor.monitor_thread, NULL, &monitor,
			param) != 0)
		return (ERROR);
	return (SUCCESS);
}

int	sequential_thread_launch(t_data *param, t_philo *current)
{
	int	i;

	i = 0;
	while (i < param->thread.size)
	{
		if (i % 2 == 0)
		{
			if (pthread_create(&current->tid, NULL, &routine_a, current) != 0)
				return (ERROR);
		}
		else
		{
			if (pthread_create(&current->tid, NULL, &routine_b, current) != 0)
				return (ERROR);
		}
		if (current->next == current)
			return (SUCCESS);
		i++;
		current = current->next;
		usleep(1000);
	}
	return (SUCCESS);
}

int	init_mutex_thread(t_data *param, size_t nb_fork)
{
	size_t	i;

	i = 0;
	while (i < nb_fork)
	{
		if (pthread_mutex_init(&param->mutex.fork[i], NULL) != 0)
		{
			ft_putstr_fd("Error initializing mutex philo.\n", 2);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	init_mutex_routine(t_data *param)
{
	if (pthread_mutex_init(&param->sync.meal_lock, NULL) != 0)
	{
		ft_putstr_fd("Error initializing mutex meal.\n", 2);
		return (ERROR);
	}
	if (pthread_mutex_init(&param->sync.write_lock, NULL) != 0)
	{
		ft_putstr_fd("Error initializing mutex write.\n", 2);
		return (ERROR);
	}
	if (pthread_mutex_init(&param->sync.dead_lock, NULL) != 0)
	{
		ft_putstr_fd("Error initializing mutex write.\n", 2);
		return (ERROR);
	}
	return (SUCCESS);
}

int	setup_mutex(t_data *param)
{
	t_philo	*current;
	size_t	i;

	param->mutex.size = param->thread.size;
	param->mutex.fork = malloc(sizeof(pthread_mutex_t) * param->mutex.size);
	if (param->mutex.fork == NULL)
	{
		ft_putstr_fd("Error alocation fork.\n", 2);
		return (ERROR);
	}
	if (init_mutex_thread(param, param->mutex.size) == ERROR)
		return (ERROR);
	if (init_mutex_routine(param) == ERROR)
		return (ERROR);
	current = param->thread.head;
	i = 0;
	while (i < param->mutex.size)
	{
		current->left = &param->mutex.fork[i];
		current->right = &param->mutex.fork[(i + 1) % param->mutex.size];
		current = current->next;
		i++;
	}
	return (SUCCESS);
}
