/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:05:44 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/20 04:28:26 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	return (SUCCESS);
}

