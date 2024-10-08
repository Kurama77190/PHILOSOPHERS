/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:36:12 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/29 17:38:49 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	param;

	ft_memset(&param, 0, sizeof(t_data));
	if (parsing(ac, av, &param) == ERROR)
	{
		end_prog(&param, NULL, EXIT_FAILURE);
	}
	end_prog(&param, NULL, EXIT_SUCCESS);
}

// creer le mutex meal_lock et proteger la viariable
// last_meal_time
//