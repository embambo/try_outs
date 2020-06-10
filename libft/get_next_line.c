/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:07:26 by embambo           #+#    #+#             */
/*   Updated: 2020/06/10 10:06:32 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "libft.h"

#include "get_next_line.h"

void	endl_count(char *buff, t_line *li)
{
	li->cnt = 0;
	li->i = 0;
	while (buff[li->i])
	{
		if (buff[li->i] == '\n' && li->i != 0)
			li->cnt++;
		li->i++;
	}
	if (li->cnt > 0)
	{
		li->i = 0;
		while (buff[li->i] != '\n')
			li->i++;
	}
	else if ((ft_strlen(buff) == 1 && buff[0] == '\n') || ft_strlen(buff) == 0)
		li->cnt = -1;
}

void	retemp(char ***temp)
{
	char *tmp;

	if (**temp != NULL)
	{
		if (ft_strlen(**temp) > 1)
		{
			tmp = (char*)ft_memalloc(ft_strlen(**temp) * sizeof(char));
			ft_strcpy(tmp, **temp + 1);
			ft_strdel(*temp);
			**temp = tmp;
		}
	}
}

void	mvr(char **line, char **temp, t_line *li)
{
	if (*temp[0] == '\n')
		retemp(&temp);
	endl_count(*temp, li);
	if (li->cnt == -1)
	{
		li->ret = 0;
		ft_strdel(temp);
	}
	else if (li->cnt == 0 && ft_strlen(*temp) > 0)
	{
		*line = (char*)ft_memalloc((ft_strlen(*temp) + 1) * sizeof(char));
		ft_strcpy(*line, *temp);
		ft_strdel(temp);
	}
	else if (li->cnt > 0)
	{
		*line = ft_strsub(*temp, 0, (size_t)li->i);
		li->fnd = (char*)ft_memalloc(((ft_strlen(*temp)
			- li->i) + 1) * sizeof(char));
		ft_strcpy(li->fnd, ft_strchr(*temp, '\n'));
		ft_strdel(temp);
		*temp = li->fnd;
	}
}

void	rdr(const int fd, t_line *li, char **temp)
{
	char		buff[BUFF_SIZE + 1];

	li->red = read(fd, buff, BUFF_SIZE);
	if (li->red == -1)
		li->ret = -1;
	else if (li->red == 0 && *temp == NULL)
		li->ret = 0;
	else if (li->red >= 1)
	{
		buff[li->red] = '\0';
		if (*temp != NULL)
		{
			li->fnd = ft_strjoin(*temp, buff);
			ft_strdel(temp);
			*temp = li->fnd;
		}
		else
		{
			*temp = ft_strnew(BUFF_SIZE + 1);
			ft_strcpy(*temp, buff);
		}
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	*temp = NULL;
	t_line		li;

	li.red = BUFF_SIZE;
	li.fnd = NULL;
	li.ret = 1;
	if (temp == NULL)
	{
		while (li.red == BUFF_SIZE)
			rdr(fd, &li, &temp);
	}
	if (li.ret == 1)
		mvr(line, &temp, &li);
	return (li.ret);
}

/*
void	*ft_substring(int fd, char *file[], char **line, int el)
{
	unsigned int	line_len;
	size_t			file_len;
	int				len;
	char			*substr;

	line_len = (unsigned int)ft_strlen(*line);
	file_len = (size_t)ft_strlen(file[fd]);
	len = (int)ft_strlen(*line);
	substr = ft_strsub(file[fd], line_len + el, file_len - len + el);
	return (substr);
}

int		get_next_line(const int fd, char **line)
{
	static char *file[MAX_FD];
	char		buf[BUFF_SIZE + 1];
	char		*temp;
	int			ret;
	int			el;

	if (fd < 0 || read(fd, NULL, 0) == -1
			|| (!file[fd] && !(file[fd] = ft_strnew(1))) || !line)
		return (-1);
	while (!ft_strchr(file[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = file[fd];
		file[fd] = ft_strjoin(file[fd], buf);
		ft_strdel(&temp);
	}
	if (ret == -1 || !*(temp = file[fd]))
		return (ret == -1 ? -1 : 0);
	if ((el = (ft_strchr(file[fd], '\n') > 0)))
		*line = ft_strsub(file[fd], 0, ft_strchr(file[fd], '\n') - file[fd]);
	else
		*line = ft_strdup(file[fd]);
	file[fd] = (char*)ft_substring(fd, file, line, el);
	ft_strdel(&temp);
	return (!(!file[fd] && !ft_strlen(*line)));
}
*/
