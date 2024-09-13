/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:34:41 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/13 19:18:42 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <pthread.h>
# include <time.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <time.h>
# include <sys/time.h>
# include <stdint.h>

# define SUCCESS 0
# define ERROR 1

typedef enum e_action
{
	EATING,
	SLEEPING,
	THINKING
}	t_action;

//////////////////////////////////////////////////////////////////////////////////////////////
//                                       STRUCT                                            //
////////////////////////////////////////////////////////////////////////////////////////////

typedef struct		s_philo
{
	pthread_t		tid;
	unsigned long	id;
	
	struct s_philo	*next;
	struct s_philo	*prev;
}					t_philo;

typedef struct		s_PhiloListController
{
	t_philo			*head;
	t_philo			*current;
	int				size;
	size_t			n_thread;
}					t_philoControl;

typedef struct	s_time
{
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	
}					t_time;

typedef struct	s_data
{
	t_philoControl	thread;
	t_time			time;
	int32_t			starttime;
	pthread_mutex_t *start;
	bool			rtg;
	// array mutex = nb_thread
}					t_data;


//////////////////////////////////////////////////////////////////////////////////////////////
//                                      PARSING                                            //
////////////////////////////////////////////////////////////////////////////////////////////

int				parsing(int ac, char **av, t_data *param);
int				init_memory(t_data *param);

//////////////////////////////////////////////////////////////////////////////////////////////
//                                      MONITOR                                            //
////////////////////////////////////////////////////////////////////////////////////////////

void			*monitor();

//////////////////////////////////////////////////////////////////////////////////////////////
//                                      THREADS                                            //
////////////////////////////////////////////////////////////////////////////////////////////

void			*routine();

//////////////////////////////////////////////////////////////////////////////////////////////
//                                       UTILS                                             //
////////////////////////////////////////////////////////////////////////////////////////////

int				ft_atoi(const char *nptr);
bool			atoi_overflow(char *strs);
t_philo			*new_philo(int);
void			add_philo(t_philoControl *lst, t_philo *new);
void			free_s_philo(t_philoControl *lst);
size_t 			ft_strlen(char *s);
int				ft_putstr_fd(char *s, int fd);
bool			ft_is_digit(char *split);
void			end_prog(t_data *param, bool exit_code);
void			*ft_memset(void *b, int c, size_t len);



# endif