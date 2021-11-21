/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:14:37 by ldavids           #+#    #+#             */
/*   Updated: 2020/01/26 13:47:00 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

int ft_strlen(char *str)
{
	int x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

static int ft_return(char **str, int ret)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	if (ret > 0)
		return (1);
	return (ret);
}

int ft_read(char *str, char **line, int fd)
{
	int ret;
	char *buf;
	int new_line_02;

	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ft_return(line, -1));
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((new_line_02 = ft_search(buf, '\n')) >= 0)
		{
			ft_strcpy(str, buf + new_line_02 + 1);
			buf[new_line_02] = '\0';
			if (!(*line = ft_strjoin(*line, buf)))
				return (ft_return(&buf, -1));
			return (ft_return(&buf, ret));
		}
		if (!(*line = ft_strjoin(*line, buf)))
			return (ft_return(&buf, -1));
	}
	if (ret < 0)
		return (ft_return(&buf, -1));
	return (ft_return(&buf, ret));
}

int get_next_line(int fd, char **line)
{
	static char str[OPEN_MAX][BUFFER_SIZE + 1] = {{0}};
	int new_line_01;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (-1);
	if (!(*line = ft_strdup("")))
		return (-1);
	if (str[fd][0] == '\0')
		return (ft_read(str[fd], line, fd));
	if ((new_line_01 = ft_search(str[fd], '\n')) >= 0)
	{
		free(*line);
		if (!(*line = ft_substr(str[fd], 0, new_line_01)))
			return (-1);
		(*line)[new_line_01] = '\0';
		ft_strcpy(str[fd], str[fd] + new_line_01 + 1);
		return (1);
	}
	free(*line);
	if (!(*line = ft_strdup(str[fd])))
		return (-1);
	str[fd][0] = '\0';
	return (ft_read(str[fd], line, fd));
}

int             main(void)
{
	char        *line;
	int         fd;
	int         i = 0;
	int 		ret;

	line = NULL;
	fd = open("dico", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d || %s\n", ret, line);
		/*printf("\n");*/
		free(line);
		i++;
	}
	printf("%d || %s\n", ret , line);
	free(line);
	close(fd);
	return (0);
}
#endif