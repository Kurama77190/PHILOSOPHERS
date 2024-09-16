/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:25:53 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/16 19:28:45 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*new_philo(int id, t_data *param)
{
	t_philo			*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	if (pthread_create(&new->tid, NULL, &routine, NULL))
		return (NULL);
	if (pthread_join(new->tid, NULL))
		return (NULL);
	new->id = id;
	new->next = NULL;
	new->prev = NULL;
	if (param->mutex.index == 0)
		new->left = param->mutex.fork[param->mutex.size];
	new->left = param->mutex.fork[param->mutex.index++];
	if (param->mutex.index == param->mutex.size)
		param->mutex.index = 0;
	new->right = param->mutex.fork[param->mutex.index++];
	return (new);
}
