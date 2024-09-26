/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:34:41 by sben-tay          #+#    #+#             */
/*   Updated: 2024/09/26 19:56:54 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

# define SUCCESS 0
# define ERROR 1
# define DIED 2
# define SATIATE 3
# define STOP 4

//////////////////////////////////////////////////////////////////
//                          STRUCT		                       //
////////////////////////////////////////////////////////////////

typedef struct s_philo
{
	pthread_t		tid;
	unsigned int	id;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	unsigned int	last_meal_time;
	unsigned int	count_eat;
	unsigned int	limit_meal;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	bool			optionnal;
	struct s_sync	*sync;
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

typedef struct s_time
{
	unsigned int			time_to_die;
	unsigned int			time_to_eat;
	unsigned int			time_to_sleep;
	unsigned int			n_of_time_eat;
}					t_time;

typedef struct s_fork
{
	pthread_mutex_t	*fork;
	size_t			size;
}					t_fork;

typedef struct s_sync
{
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	start_lock;
	bool			optionnal;
	bool			dead;
}					t_sync;

typedef struct s_monitor
{
	pthread_t		monitor_thread;
}					t_monitor;

typedef struct s_data
{
	t_philoControl	thread;
	t_time			time;
	t_fork			mutex;
	t_monitor		monitor;
	t_sync			sync;
}					t_data;

//////////////////////////////////////////////////////////////////
//                          PARSING		                       //
////////////////////////////////////////////////////////////////

int					parsing(int ac, char **av, t_data *param);
int					check_digit(int ac, char **av);
int					check_overflow(int ac, char **av);
int					setup_mutex(t_data *param);
int					init_mutex_thread(t_data *param, size_t nb_fork);
int					setup_threads(t_data *param);
int					create_philo(t_data *param);
int					init_mutex_routine(t_data *param);
int					setup_arg(int ac, char **av, t_data *param);
int					check_none_args(int ac, t_data *param);
int					sequential_thread_launch(t_data *param, t_philo *current);

//////////////////////////////////////////////////////////////////
//                          MONITOR		                       //
//////////////////////////////////////////////unsigned//////////////////

void				*monitor(void *arg);
int					check_philosopher_dead(t_philo *philo, long current_time,
						t_data *param);
int					check_global_death(t_data *param);
int					monitor_philosophers(t_data *param);
int					check_global_satiate(t_data *param);

//////////////////////////////////////////////////////////////////
//                          ROUTINE		                       //
////////////////////////////////////////////////////////////////

void				*routine(void *arg);
int					*routine_left_handed(void *arg);
int					*routine_rigt_handed(void *arg);
int					philo_take_fork_a(t_philo *philo);
int					philo_take_fork_b(t_philo *philo);
int					philo_eat_a(t_philo *philo);
int					philo_eat_b(t_philo *philo);
int					philo_sleep(t_philo *philo);
int					print_fork(t_philo *philo);
int					print_eat(t_philo *philo);
int					print_sleep(t_philo *philo);
int					print_think(t_philo *philo);
int					print_die(t_philo *philo);

//////////////////////////////////////////////////////////////////
//                          UTILS		                       //
////////////////////////////////////////////////////////////////

int					ft_atoi(const char *nptr);
bool				atoi_overflow(char *strs);
t_philo				*new_philo(int nb, t_data *param);
void				add_philo(t_philoControl *lst, t_philo *new);
void				free_s_philo(t_philoControl *lst);
size_t				ft_strlen(char *s);
void				*ft_calloc(size_t count, size_t size);
int					ft_putstr_fd(char *s, int fd);
bool				ft_is_digit(char *split);
void				end_prog(t_data *param, char *stderr, int exit_code);
void				*ft_memset(void *b, int c, size_t len);
void				free_s_fork(t_fork *param);
long int			get_ms(void);

//////////////////////////////////////////////////////////////////
//                          DEBUG		                       //
////////////////////////////////////////////////////////////////

void				check_philosophers(t_philo *head, int num_philos);

#endif
