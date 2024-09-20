/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_s_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:46:33 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/20 04:02:27 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_s_fork(t_fork	*param)
{
	size_t	i;

	i = 0;
	while (i < param->size)
	{
		if (pthread_mutex_destroy(&param->fork[i]) != 0)
		{
			ft_putstr_fd("Error destroy fork's mutex.\n", 2);
		}
		i++;
	}
	free(param->fork);
	param->fork = NULL;
}
