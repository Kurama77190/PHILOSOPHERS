/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:05:44 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/23 06:16:27 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parsing(int ac, char **av, t_data *param)
{
	if (ac > 6 || ac < 5)
		return (ft_putstr_fd("Error numbers arguments.\n", 2), ERROR);
	if (!av[1][0] || !av[2][0] || !av[3][0] || !av[4][0])
		return (ft_putstr_fd("empty argument(s).\n", 2), ERROR);
	if (check_digit(ac, av) == ERROR)
		return (ERROR);
	if (check_overflow(ac, av) == ERROR)
		return (ERROR);
	if (setup_arg(ac, av, param) == ERROR)
		return (ERROR);
	if (setup_threads(param) == ERROR)
		return (ERROR);
	if (setup_mutex(param) == ERROR)
		return (ERROR);
	if (create_philo(param) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
