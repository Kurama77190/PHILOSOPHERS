/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:05:44 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/18 02:38:28 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_digit(char **av);
static int	check_overflow(char **av);
static int	setup_threads(t_data *param);
static int	setup_fork(t_data *param);

int	parsing(int ac, char **av, t_data *param)
{
	if (ac > 5 || ac < 5)
		return (ft_putstr_fd("Error numbers arguments.\n", 2), ERROR);
	if (!av[1][0] || !av[2][0] || !av[3][0] || !av[4][0])
		return (ft_putstr_fd("empty argument(s).\n", 2), ERROR);
	if (check_digit(av) == ERROR)
		return (ERROR);
	if (check_overflow(av) == ERROR)
		return (ERROR);
	param->thread.n_thread = ft_atoi(av[1]);
	param->time.time_to_die = (size_t)ft_atoi(av[2]);
	param->time.time_to_eat = (size_t)ft_atoi(av[3]);
	param->time.time_to_sleep = (size_t)ft_atoi(av[4]);
	if (setup_threads(param) == ERROR)
		return (ERROR);
	if (setup_fork(param) == ERROR)
		return (ERROR);
	//timestamp
	return (SUCCESS);
}

static int	check_digit(char **av)
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

static int	check_overflow(char **av)
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

static int	setup_fork(t_data *param)
{
	t_philo	*current;
	size_t	num_philos;
	size_t	i;

	num_philos = param->thread.size;
	param->mutex.fork = malloc(sizeof(pthread_mutex_t) * num_philos);
	if (param->mutex.fork == NULL)
	{
		ft_putstr_fd("Error alocation fork.\n", 2);
		return (ERROR);
	}
	current = param->thread.head;
	i = 0;
	while (i < num_philos)
	{
		current->left = &param->mutex.fork[i];
		current->right = &param->mutex.fork[(i + 1) % num_philos];
		current = current->next;
		i++;
	}
	return (SUCCESS);
}

static int	setup_threads(t_data *param)
{
	int		i;
	t_philo	*new;

	i = 0;
	while ((size_t) i < param->thread.n_thread)
	{
		new = new_philo(i + 1);
		if (!new)
			return (free_s_philo(&param->thread), ERROR);
		add_philo(&param->thread, new);
		i++;
	}
	param->thread.current = param->thread.head;
	return (SUCCESS);
}
