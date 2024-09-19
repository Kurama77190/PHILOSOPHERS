/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:02:07 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/19 18:23:02 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

# define NC "\e[0m"
# define YELLOW "\e[1;33m"

void	*monitor(void *param)
{
	
	t_data *data = (t_data *)param;
	while(data->)
	{
		
	}
	printf("%sTest from threads[%ld].%s\n", YELLOW, get_ms(), NC);
	return (NULL);
}
