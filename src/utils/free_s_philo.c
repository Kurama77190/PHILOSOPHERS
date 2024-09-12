/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_s_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:49:55 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/08 19:26:59 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_s_philo(t_philo **lst)
{
	t_philo	*current;
	t_philo	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}
