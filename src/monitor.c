/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:02:07 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/21 04:05:20 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

# define NC "\e[0m"
# define YELLOW "\e[1;33m"

void	*monitor(void *arg)
{
    t_data *param;
    t_philo *current;
    long 	current_time;
	int		i;
	
	param = (t_data *)arg;
	pthread_mutex_lock(&param->sync.dead_lock);
    while (!param->sync.dead)
    {
		pthread_mutex_unlock(&param->sync.dead_lock);
        current = param->thread.head;
		i = 0;
		while (i < param->thread.size)
        {
            current_time = get_ms();
            pthread_mutex_lock(&param->sync.dead_lock);
            if (current_time - current->last_meal_time > param->time.time_to_die)
            {
                param->sync.dead = true;
                pthread_mutex_unlock(&param->sync.dead_lock);
                printf("Philosophe %lu est mort.\n", current->id);
                return (NULL);
            }
            pthread_mutex_unlock(&param->sync.dead_lock);
            current = current->next;
        }
		i++;
        usleep(100);
    }
    return NULL;
}
