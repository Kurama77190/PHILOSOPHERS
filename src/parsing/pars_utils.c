/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:07:54 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/21 03:14:04 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_digit(char **av)
{
	if (!ft_is_digit(av[1]))
	{
		return (ft_putstr_fd("number_philo is not digit.\n", 2), ERROR);
	}
	if (!ft_is_digit(av[2]))
	{
		return (ft_putstr_fd("time_to_die is not digit.\n", 2), ERROR);
	}
	if (!ft_is_digit(av[3]))
	{
		return (ft_putstr_fd("time_to_eat is not digit.\n", 2), ERROR);
	}
	if (!ft_is_digit(av[4]))
	{
		return (ft_putstr_fd("time_to_sleep is not digit.\n", 2), ERROR);
	}
	return (SUCCESS);
}

int	check_overflow(char **av)
{
	if (atoi_overflow(av[1]))
	{
		return (ft_putstr_fd("number_philo overflow.\n", 2), ERROR);
	}
	if (atoi_overflow(av[2]))
	{
		return (ft_putstr_fd("time_to_die overflow.\n", 2), ERROR);
	}
	if (atoi_overflow(av[3]))
	{
		return (ft_putstr_fd("time_to_eat overflow.\n", 2), ERROR);
	}
	if (atoi_overflow(av[4]))
	{
		return (ft_putstr_fd("time_to_sleep overflow.\n", 2), ERROR);
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
