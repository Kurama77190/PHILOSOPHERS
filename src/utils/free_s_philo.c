/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_s_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:49:55 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/13 05:49:59 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_s_philo(t_philo **lst)
{
	t_philo			*current;
	t_philo			*next;

	current = *lst;
	if (*lst == NULL)
		return ;
	while (current->next != *lst)
	{
		next = current->next;
		
		free(current);
		current = next;
	}
	free(current);
	*lst = NULL;
}
