/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:57:27 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/20 19:53:41 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_philo(t_data *param)
{
	int i;
	t_philo *current_;

	i = 0;
	current_ = param->thread.current;
	while (i < param->thread.size)
	{
		if (pthread_create(&current_->tid, NULL, &routine, &current_) != 0)
			return (ERROR);
		current_ = current_->next;
		i++;
	}
	if (pthread_create(&param->monitor.monitor_thread, NULL, &routine,
			&param->thread.head) != 0)
			return (ERROR);
	param->sync.start_signal = true;
	param->monitor.start_signal = true;
	return (SUCCESS);
}