/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:25:53 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/29 19:36:18 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*new_philo(int id, t_data *param)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->tid = -1;
	new->id = id;
	new->next = NULL;
	new->prev = NULL;
	new->right = NULL;
	new->left = NULL;
	new->last_meal_time = 0;
	new->count_eat = 0;
	new->limit_meal = (param->time.n_of_time_eat);
	new->time_to_die = (param->time.time_to_die);
	new->time_to_eat = (param->time.time_to_eat);
	new->time_to_sleep = (param->time.time_to_sleep);
	new->optionnal = param->sync.optionnal;
	new->only_one = param->sync.only_one;
	new->sync = &param->sync;
	return (new);
}
