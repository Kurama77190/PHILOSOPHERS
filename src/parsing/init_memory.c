/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 05:32:10 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/13 05:32:21 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_memory(t_data *param)
{
	param->time = (t_time){};
	param->thread = malloc(sizeof(t_philoControl));
	if (!param->thread)
	{
		ft_putstr_fd("Error initializing memory.\n", 2);
		return (ERROR);
	}
	param->thread->head = NULL;
	return (SUCCESS);
}
