/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:25:53 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/13 18:41:26 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*new_philo(int id)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	if (pthread_create(&new->tid, NULL, &routine, NULL))
	{
		return (NULL);
	}
	if (pthread_join(new->tid, NULL))
		return (NULL);
	new->id = id;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
