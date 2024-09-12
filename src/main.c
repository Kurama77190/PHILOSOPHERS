/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:36:12 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/09 02:12:42 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


# define NC "\e[0m"
# define YELLOW "\e[1;33m"

void	*routine()
{
	printf("%sTest from threads%s\n", YELLOW, NC);
	return (NULL);
}

int main(int ac, char **av)
{
	t_data	param;

	param = (t_data){};
	if (parsing(ac, av, &param) == ERROR)
		return (1);

	free_s_philo(&param.thread);
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
