/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:05:44 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/13 05:53:20 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_digit(char **av);
static int	check_overflow(char **av);
static int	check_negatif(char **av);
static int	setup_threads(t_philoControl **param, char *arg_thread);

int	parsing(int ac, char **av, t_data *param)
{
	if (ac > 5 || ac < 5)
	{
		return (ft_putstr_fd("Error numbers arguments.\n", 2), ERROR);
	}
	if (!av[1][0] || !av[2][0] || !av[3][0] || !av[4][0])
	{
		return (ft_putstr_fd("empty argument(s).\n", 2), ERROR);
	}
	if (check_digit(av) == ERROR)
		return (ERROR);
	if (check_overflow(av) == ERROR)
		return (ERROR);
	if (check_negatif(av) == ERROR)
		return (ERROR);
	// setup_monitors;
	setup_threads(&param->thread, av[1]);
	param->time.time_to_die = (size_t)ft_atoi(av[2]);
	param->time.time_to_eat = (size_t)ft_atoi(av[3]);
	param->time.time_to_sleep = (size_t)ft_atoi(av[4]);
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

static int	check_negatif(char **av)
{
	int	nb_thread;
	int time_die;
	int time_eat;
	int time_sleep;

	nb_thread = ft_atoi(av[1]);
	time_die = ft_atoi(av[2]);
	time_eat = ft_atoi(av[3]);
	time_sleep = ft_atoi(av[4]);
	if (nb_thread < 0)
		return (ft_putstr_fd("number_philo is negatif.\n", 2), ERROR);
	if (time_die < 0)
	{
		return (ft_putstr_fd("time_to_die is negatif.\n", 2), ERROR);
	}
	if (time_eat < 0)
	{
		return (ft_putstr_fd("time_to_eat is negatif.\n", 2), ERROR);
	}
	if (time_sleep < 0)
	{
		return (ft_putstr_fd("time_to_sleep is negatif.\n", 2), ERROR);
	}
	return (SUCCESS);
}

static int	setup_threads(t_philoControl **param, char *arg_thread)
{
	int		i;
	int		nb_philo;
	t_philo	*new;

	i = 0;
	nb_philo = ft_atoi(arg_thread);
	while (i < nb_philo)
	{
		(*param)->n_thread = (i + 1);
		new = new_philo();
		if (!new)
			return (free_s_philo(&(*param)->head), ERROR);
		add_philo(&(*param)->head, new);
		i++;
	}
	(*param)->current = (*param)->head;
	return (SUCCESS);
}
