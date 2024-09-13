# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 16:20:32 by sben-tay          #+#    #+#              #
#    Updated: 2024/09/13 19:02:06 by sben-tay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

# Définitions de base

NAME = philosophers
#NAME_BNS = philosophers_bonus
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror 
CPPFLAGS = -I./include -pthread

UTILS = src/utils/
PARS  = src/parsing/
BUILD = builder/

#=================================================__SRC__OF__PROJECT__=============================================================================
SRC = src/main.c \
	$(addprefix $(UTILS), ft_atoi.c add_philo.c free_s_philo.c atoi_overflow.c \
	new_philo.c ft_strlen.c ft_putstr_fd.c ft_is_digit.c \
	end_prog.c ft_memset.c ) \
	$(PARS)parsing.c

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

.PHONY: all clean fclean re bonus teste # Pour éviter les conflits avec des fichiers du même nom

-include $(DEP)
