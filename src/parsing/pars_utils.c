/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:07:54 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/20 04:40:42 by sben-tay         ###   ########.fr       */
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

int	init_fork(t_data *param, size_t nb_fork)
{
	size_t	i;

	i = 0;
	while (i < nb_fork)
	{
		if (pthread_mutex_init(&param->mutex.fork[i], NULL) != 0)
		{
			ft_putstr_fd("Error initializing fork mutex.\n", 2);
			return (ERROR);
		}
		i++;
	}
	if (pthread_mutex_init(&param->sync.routines_fork, NULL) != 0)
	{
		ft_putstr_fd("Error initializing fork mutex.\n", 2);
		return (ERROR);
	}
	pthread_mutex_lock(&param->sync.routines_fork);
	param->monitor.start_signal = true;
	param->sync.start_signal = true;
	pthread_mutex_unlock(&param->sync.routines_fork);
	return (SUCCESS);
}

int	setup_fork(t_data *param)
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
	current = param->thread.head;
	i = 0;
	while (i < param->mutex.size)
	{
		current->left = &param->mutex.fork[i];
		current->right = &param->mutex.fork[(i + 1) % param->mutex.size];
		current = current->next;
		i++;
	}
	if (init_fork(param, param->mutex.size) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	setup_threads(t_data *param)
{
	int		i;
	t_philo	*new;

	i = 0;
	while ((size_t)i < param->thread.n_thread)
	{
		new = new_philo(i + 1, param);
		if (!new)
			return (free_s_philo(&param->thread), ERROR);
		add_philo(&param->thread, new);
		i++;
	}
	param->thread.current = param->thread.head;
	pthread_create(&param->monitor.monitor_thread, NULL, &monitor, param);
	return (SUCCESS);
}
