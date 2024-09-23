/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:07:54 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/23 23:20:24 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_digit(int ac, char **av)
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
	if (ac == 6)
	{
		if (!ft_is_digit(av[5]))
			return (ft_putstr_fd("n_of_time_eat is not digit.\n", 2), ERROR);
	}
	return (SUCCESS);
}

int	check_overflow(int ac, char **av)
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
	if (ac == 6)
	{
		if (atoi_overflow(av[5]))
			return (ft_putstr_fd("n_of_time_eat overflow.\n", 2), ERROR);
	}
	return (SUCCESS);
}

int	check_none_args(int ac, t_data *param)
{
	if (param->thread.n_thread == 0)
	{
		ft_putstr_fd("number_philo is zero.\n", 2);
		return (ERROR);
	}
	if (param->time.time_to_die == 0)
	{
		ft_putstr_fd("time_to_die is zero.\n", 2);
		return (ERROR);
	}
	if (param->time.time_to_eat == 0)
	{
		ft_putstr_fd("time_to_eat is zero.\n", 2);
		return (ERROR);
	}
	if (param->time.time_to_sleep == 0)
	{
		return (ft_putstr_fd("time_to_sleep is zero.\n", 2), ERROR);
	}
	if (ac == 6)
	{
		if (param->time.n_of_time_eat == 0)
			return (ft_putstr_fd("n_of_time_eat is zero.\n", 2), ERROR);
	}
	return (SUCCESS);
}

int	setup_arg(int ac, char **av, t_data *param)
{
	param->thread.n_thread = ft_atoi(av[1]);
	param->time.time_to_die = (size_t)ft_atoi(av[2]);
	param->time.time_to_eat = (size_t)ft_atoi(av[3]);
	param->time.time_to_sleep = (size_t)ft_atoi(av[4]);
	if (ac == 6)
	{
		param->time.n_of_time_eat = (size_t)(ft_atoi(av[5]));
		param->sync.optionnal = true;
	}
	if (param->thread.n_thread > (size_t)200)
	{
		return (ft_putstr_fd("there are too many threads.\n", 2), ERROR);
	}
	if (check_none_args(ac, param) == ERROR)
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
			return (ERROR);
		add_philo(&param->thread, new);
		i++;
	}
	param->thread.current = param->thread.head;
	return (SUCCESS);
}
