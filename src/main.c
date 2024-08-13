/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:36:12 by sben-tay          #+#    #+#             */
/*   Updated: 2024/08/13 18:44:45 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	*routine()
{
	printf("Test from threads\n");
	return (NULL);
}

int main(void)
{
	pthread_t t1;
	if (pthread_create(&t1, NULL, &routine, NULL))
		return (1);
	if (pthread_join(t1, NULL))
		return (2);
	return (0);
}	
