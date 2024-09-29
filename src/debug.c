/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:05:52 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/27 18:51:11 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_philosophers(t_philo *head, int num_philos)
{
	t_philo *current = head;
	int i = 0;

	if (current == NULL)
	{
		printf("La liste des philosophes est vide.\n");
		return ;
	}

	// Parcourir la liste circulaire et afficher les informations
	do
	{
		printf("Philosophe %u :\n", current->id);
		printf("  Adresse : %p\n", (void *)current);
		printf("  Fourchette gauche (left)  : %p\n", (void *)current->left);
		printf("  Fourchette droite (right) : %p\n", (void *)current->right);
		printf("  Next  : %p\n", (void *)current->next);
		printf("  Prev  : %p\n", (void *)current->prev);
		printf("\n");

		// Avancer vers le prochain philosophe
		current = current->next;
		i++;
	} while (current != head && i < num_philos);
		// S'arrêter si on boucle ou dépasse le nombre de philosophes
}