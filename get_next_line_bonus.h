/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:08:41 by ldavids           #+#    #+#             */
/*   Updated: 2020/01/26 13:43:14 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, int len);
int		ft_search(const char *str, int c);
size_t	ft_strcpy(char *dest, char *src);
int		ft_strlen(char *str);

#endif
