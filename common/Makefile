# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: embambo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 13:18:34 by embambo           #+#    #+#              #
#    Updated: 2020/06/09 12:21:32 by embambo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re silent_clean silent_fclean silent_re

NAME = slib.a
RM = /bin/rm -rfv
RMS = /bin/rm -rf
CFILES = validators.c function.c new_list_stack.c is_sorted.c
CFILES += is_sorted2.c operations.c operations2.c operations3.c
CFILES += print_stack.c 
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): 
	@echo "$(NAME) compiling... \c"
	@gcc -Wall -Wextra -Werror -c $(CFILES)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)
	@echo "$(NAME) created"
	
clean: 
	@$(RM) $(OFILES) | wc -l | tr '\n' ' ' && echo ft_*.o files deleted

fclean: clean
	@$(RM) $(NAME) | wc -l | tr '\n' ' ' && echo $(NAME) deleted

re: fclean all

silent_clean:
	@$(RMS) $(OFILES)

silent_fclean: silent_clean
	@$(RMS) $(NAME)

silent_re: silent_fclean all
