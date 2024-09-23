/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:02:07 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/23 17:53:05 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_monitor(t_data *param);
int		check_global_satiate(t_data *param);

void	*monitor(void *arg)
{
	t_data	*param;

	param = (t_data *)arg;
	while (1)
	{
		if (check_global_death(param) == ERROR)
		{
			return (NULL);
		}
		if (monitor_philosophers(param) == ERROR)
		{
			return (NULL);
		}
		if (check_global_satiate(param) == SATIATE)
		{
			return (NULL);
		}
		usleep(8000);
	}
	return (NULL);
}
