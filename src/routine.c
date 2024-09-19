/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:59:05 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/19 18:24:01 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

# define NC "\e[0m"
# define YELLOW "\e[1;33m"

void	*routine(void	*param)
{
	t_data *data = (t_data *)param;
	
	// verouillage de mutex start
	// deverouillage de mutex start
	printf("%sTest from threads[%ld].%s\n", YELLOW, get_ms(), NC);
	return (NULL);
}
