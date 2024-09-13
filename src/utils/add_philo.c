/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:41:06 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/13 05:48:36 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	add_philo(t_philo **head, t_philo *new)
{
	t_philo			*first;
	t_philo			*last;

	last = *head;
	if (new == NULL)
		return ;
	if (*head == NULL)
	{
		new->next = new;
		new->prev = new;
		new->id = 1;
		*head = new;
		return ;
	}
	first = *head;
	last = (*head)->prev;

	new->id = last->id + 1;
	new->next = first;
	new->prev = last;
	last->next = new;
	first->prev = new;
}
