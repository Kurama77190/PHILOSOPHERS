/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_s_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:49:55 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/13 19:06:35 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_s_philo(t_philoControl *lst)
{
	void			*next;

	while (lst->size > 1)
	{
		next = lst->head->next;
		free(lst->head);
		lst->head = next;
		lst->size--;
	}
	free(lst->head);
	lst->head = NULL;
}
