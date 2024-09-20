/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_s_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:49:55 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/20 04:05:01 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_s_philo(t_philoControl *lst)
{
	void			*next;

	if (!lst->head)
	{
		return ;
	}
	while (lst->size > 1)
	{
		next = lst->head->next;
		if (pthread_join(lst->head->tid, NULL) != 0)
		{
			perror("Error joining thread");
		}
		free(lst->head);
		lst->head = next;
		lst->size--;
	}
	if (pthread_join(lst->head->tid, NULL) != 0)
	{
		perror("Error joining thread");
	}
	free(lst->head);
	lst->head = NULL;
}
