/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:41:06 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/09 01:43:31 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	add_philo(t_philo **alst, t_philo *new)
{
	t_philo			*last;
	unsigned long	i;

	last = *alst;
	i = 1;
	if (new == NULL)
		return ;
	if (*alst == NULL)
	{
		new->id = i;
		*alst = new;
		return ;
	}
	while (last->next)
	{
		i++;
		last = last->next;
	}
	last->next = new;
	new->prev = last;
	new->id = i;
}
