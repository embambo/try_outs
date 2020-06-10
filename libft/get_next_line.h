/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:08:21 by embambo           #+#    #+#             */
/*   Updated: 2020/06/10 10:14:26 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE   32
# define MAX_FD      2147483647

# include <unistd.h>
# include "libft.h"

int		get_next_line(const int fd, char **line);



# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_line
{
	char	*fnd;
	int		red;
	int		i;
	int		cnt;
	int		ret;
}				t_line;

void			endl_count(char *buff, t_line *li);
void			retemp(char ***temp);
void			rdr(const int fd, t_line *li, char **temp);
void			mvr(char **line, char **temp, t_line *li);
#endif
