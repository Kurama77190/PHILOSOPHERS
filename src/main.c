/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:36:12 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/13 19:16:50 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


# define NC "\e[0m"
# define YELLOW "\e[1;33m"

long int	get_ms(void);

static	void wait_for_everyone(t_data *param)
{
	bool start;

	start = 0;
	while (!start)
	{
		pthread_mutex_lock(param->start);
		if (param->rtg)
			start = 1;
		pthread_mutex_unlock(param->start);
		usleep(20);
	}
}
void	*routine(void *param1)
{
	t_data	*param;
	
	param = (t_data *) param1;
	wait_for_everyone(&param)
	printf("%sTest from threads[%ld].%s\n", YELLOW, get_ms(), NC);
	return (NULL);
}

long int	get_ms(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("Error timeval");
		return (-1);
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int main(int ac, char **av)
{
	t_data	param;

	ft_memset(&param, 0, sizeof(t_data));// a ajouter
	if (parsing(ac, av, &param) == ERROR)
	{
		end_prog(&param, EXIT_FAILURE);
	}
	// algo philosophers
	end_prog(&param, EXIT_SUCCESS);
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
