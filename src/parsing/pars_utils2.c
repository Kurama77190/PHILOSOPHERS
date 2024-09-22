/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:57:27 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/21 14:48:27 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	return (SUCCESS);
}

int	create_philo(t_data *param)
{
	int i;
	t_philo *current;

	i = 0;
	current = param->thread.head;
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
		usleep(100);
		if (current->next == current)
			return (SUCCESS);
		current = current->next;
		i++;
	}
	if (pthread_create(&param->monitor.monitor_thread, NULL, &monitor,
		param) != 0)
		return (ERROR);
	return (SUCCESS);
}
