/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:36:12 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/18 02:40:33 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


# define NC "\e[0m"
# define YELLOW "\e[1;33m"

long int	get_ms(void);


void	*routine()
{
	printf("%sTest from threads[%ld].%s\n", YELLOW, get_ms(), NC);
	return (NULL);
}

long int get_ms(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("Error timeval");
		return (-1);
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void check_philosophers(t_philo *head, int num_philos)
{
    t_philo *current = head;
    int i = 0;

    if (current == NULL) {
        printf("La liste des philosophes est vide.\n");
        return;
    }

    // Parcourir la liste circulaire et afficher les informations
    do {
        printf("Philosophe %lu :\n", current->id);
        printf("  Adresse : %p\n", (void*)current);
        printf("  Fourchette gauche (left)  : %p\n", (void*)current->left);
        printf("  Fourchette droite (right) : %p\n", (void*)current->right);
        printf("  Next  : %p\n", (void*)current->next);
        printf("  Prev  : %p\n", (void*)current->prev);
        printf("\n");

        // Avancer vers le prochain philosophe
        current = current->next;
        i++;
    } while (current != head && i < num_philos); // S'arrêter si on boucle ou dépasse le nombre de philosophes
}

int main(int ac, char **av)
{
	t_data	param;

	ft_memset(&param, 0, sizeof(t_data));// a ajouter
	if (parsing(ac, av, &param) == ERROR)
	{
		end_prog(&param, NULL, EXIT_FAILURE);
	}
	check_philosophers(param.thread.head, param.thread.n_thread);
	printf("size = %u\n", param.thread.size);
	end_prog(&param, NULL, EXIT_SUCCESS);
}


// int main(void)
// {
// 	pthread_t t1;
// 	if (pthread_create(&t1, NULL, &routine, NULL))
// 		return (1);
// 	if (pthread_join(t1, NULL))
// 		return (2);
// 	return (0);
// }	
