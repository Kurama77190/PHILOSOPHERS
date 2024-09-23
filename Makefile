# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 16:20:32 by sben-tay          #+#    #+#              #
#    Updated: 2024/09/23 23:32:19 by sben-tay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

# Définitions de base

NAME = philo
#NAME_BNS = philosophers_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror 
CPPFLAGS = -I./include -pthread

UTILS = src/utils/
PARS  = src/parsing/
MONITOR = src/monitor/
ROUTINE = src/routine/
BUILD = builder/

# CFLAGS += -fsanitize=address
# CFLAGS += -fsanitize=thread

#=================================================__SRC__OF__PROJECT__=============================================================================
SRC = src/main.c src/debug.c \
	$(addprefix $(PARS), parsing.c pars_utils.c pars_utils2.c ) \
	$(addprefix $(ROUTINE), routine.c routine_utils.c routine_utils2.c ) \
	$(addprefix $(MONITOR), monitor.c monitor_utils.c ) \
	$(addprefix $(UTILS), ft_atoi.c add_philo.c free_s_philo.c atoi_overflow.c \
	new_philo.c ft_strlen.c ft_putstr_fd.c ft_is_digit.c \
	end_prog.c ft_memset.c free_s_fork.c get_ms.c ft_calloc.c )

$(shell mkdir -p $(BUILD))

OBJ = $(SRC:%.c=$(BUILD)%.o)
#OBJ_BNS = $(SRC_BNS:%.c=$(BUILD)%.o)
#==================================================================================================================================================

HEADER = ./include/philosophers.h
DEP = $(OBJ:.o=.d)

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
CYAN = \033[0;36m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m
BLANC = \033[0;37m

all:	$(NAME)

$(NAME): $(OBJ)


#==================================ASCII_MOD_COMPILATION==================================

	@echo "$(GREEN)"

	@echo -n "Compilation progress: ["
	@for i in $$(seq 0.1 50); do \
		sleep 0.02; \
		echo -n "#"; \
	done
	@echo "] 100 %"
	@echo "$(CYAN)Starting $(MAGENTA)PHILOSOPHERS$(CYAN) compilations..."
	@sleep 1
	@echo "Done !$(BLANC)"
	@$(CC) $(OBJ) $(CFLAGS) $(CPPFLAGS) -o $(NAME)

#=============================================================================================

%.o:%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ -MMD -MP


 # Règle pour créer l'exécutable bonus

bonus:

teste:

	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME)

clean: # Règles pour nettoyer les fichiers objets

	@echo "$(RED)Cleaning up...$(NC)"
	@printf "$(CYAN)configure$(NC) [$(GREEN)info$(NC)] : Execute make clean from Projet of philosophers.\n"
	@rm -rf $(BUILD)

fclean: clean # Règles pour nettoyer les fichiers objets et l'exécutable

	@rm -f $(NAME)
#	@rm -f $(NAME_BNS)


re: fclean all # Règle pour recompiler

.PHONY: all clean fclean re bonus

-include $(DEP)
