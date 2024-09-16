/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 05:34:33 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/16 18:33:21 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	end_prog(t_data *param, char *stderr, int exit_code)
{
	free_s_philo(&param->thread);
	// free_s_fork
	free(param->mutex.fork);
	ft_putstr_fd(stderr, 2);
	exit(exit_code);
}
