/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 05:34:33 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/19 17:48:47 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	end_prog(t_data *param, char *stderr, int exit_code)
{
	free_s_philo(&param->thread);
	free_s_fork(&param->mutex);
	ft_putstr_fd(stderr, 2);
	exit(exit_code);
}
