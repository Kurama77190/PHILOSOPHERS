/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:36:12 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/20 19:55:40 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


int main(int ac, char **av)
{
	t_data	param;

	ft_memset(&param, 0, sizeof(t_data));
	if (parsing(ac, av, &param) == ERROR)
	{
		end_prog(&param, NULL, EXIT_FAILURE);
	}
	check_philosophers(param.thread.head, param.thread.n_thread);
	
	printf("%d bool \n", param.sync.start_signal);
	// end_prog(&param, NULL, EXIT_SUCCESS);
}
