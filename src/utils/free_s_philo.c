/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_s_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:49:55 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/23 23:27:04 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_s_philo(t_philoControl *lst)
{
	void	*next;

	if (!lst->head)
	{
		return ;
	}
	while (lst->size > 0)
	{
		next = lst->head->next;
		if (lst->head->tid != 0)
		{
			if (pthread_join(lst->head->tid, NULL) != 0)
				perror("Error joining thread");
		}
		lst->head->tid = 0;
		free(lst->head);
		lst->head = next;
		lst->size--;
	}
	lst->head = NULL;
}
