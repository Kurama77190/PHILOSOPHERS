/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:41:06 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/18 02:01:10 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	add_philo(t_philoControl *lst, t_philo *new)
{
	t_philo	*tmp;

	if (lst->size)
	{
		tmp = lst->head;
		tmp->prev->next = new;
		new->prev = tmp->prev;
		tmp->prev = new;
		new->next = tmp;
		lst->size++;
	}
	else
	{
		new->next = new;
		new->prev = new;
		lst->head = new;
		lst->size++;
	}
}
