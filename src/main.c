/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:36:12 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/21 03:58:51 by sben-tay         ###   ########.fr       */
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
	while (!param.sync.dead)
		;
	end_prog(&param, NULL, EXIT_SUCCESS);
}
