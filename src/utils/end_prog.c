/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 05:34:33 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/13 05:49:12 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	end_prog(t_data *param, bool exit_code)
{
	free_s_philo(&param->thread->head);
	param->thread->head = NULL;
	free(param->thread);
	param->thread = NULL;
	exit(exit_code);
}
