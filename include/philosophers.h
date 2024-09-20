/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:34:41 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/20 03:44:42 by sben-tay         ###   ########.fr       */
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
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	long			last_meal_time;
	long			last_get_ms;
	bool			dead;
	struct s_philo	*next;
	struct s_philo	*prev;
}					t_philo;

typedef struct s_philoControl
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

typedef struct s_fork
{
	pthread_mutex_t	*fork;
	size_t			size;
}					t_fork;

typedef struct s_sync
{
    pthread_mutex_t	routines_fork;
    bool 			start_signal;
}					t_sync;

typedef	struct s_monitor
{
	pthread_t		monitor_thread;
	pthread_mutex_t	monitors_fork;
	bool			start_signal;
}					t_monitor;

typedef struct	s_data
{
	t_philoControl	thread;
	t_time			time;
	t_fork			mutex;
	t_monitor		monitor;
	t_sync			sync;
}					t_data;


//////////////////////////////////////////////////////////////////////////////////////////////
//                                      PARSING                                            //
////////////////////////////////////////////////////////////////////////////////////////////

int				parsing(int ac, char **av, t_data *param);
int				check_digit(char **av);
int				check_overflow(char **av);
int				setup_fork(t_data *param);
int				init_fork(t_data *param, size_t nb_fork);
int				setup_threads(t_data *param);

//////////////////////////////////////////////////////////////////////////////////////////////
//                                      MONITOR                                            //
////////////////////////////////////////////////////////////////////////////////////////////

void			*monitor(void *param);

//////////////////////////////////////////////////////////////////////////////////////////////
//                                      THREADS                                            //
////////////////////////////////////////////////////////////////////////////////////////////

void			*routine(void *param);

//////////////////////////////////////////////////////////////////////////////////////////////
//                                       UTILS                                             //
////////////////////////////////////////////////////////////////////////////////////////////

int				ft_atoi(const char *nptr);
bool			atoi_overflow(char *strs);
t_philo			*new_philo(int nb, t_data *param);
void			add_philo(t_philoControl *lst, t_philo *new);
void			free_s_philo(t_philoControl *lst);
size_t 			ft_strlen(char *s);
int				ft_putstr_fd(char *s, int fd);
bool			ft_is_digit(char *split);
void			end_prog(t_data *param, char *stderr, int exit_code);
void			*ft_memset(void *b, int c, size_t len);
void			free_s_fork(t_fork	*param);
long int		get_ms(void);

//////////////////////////////////////////////////////////////////////////////////////////////
//                                       DEBUG                                             //
////////////////////////////////////////////////////////////////////////////////////////////

void 			check_philosophers(t_philo *head, int num_philos);


# endif