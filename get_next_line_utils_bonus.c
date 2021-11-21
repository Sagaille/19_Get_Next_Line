/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:37:16 by ldavids           #+#    #+#             */
/*   Updated: 2020/01/26 13:42:39 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s)
{
	int		index;
	char	*copy;

	index = 0;
	while (s[index])
		index++;
	if (!(copy = (char *)malloc(sizeof(char) * (index + 1))))
		return (NULL);
	index = 0;
	while (s[index])
	{
		copy[index] = s[index];
		index++;
	}
	copy[index] = '\0';
	return (copy);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		index1;
	int		index2;
	char	*temp;

	index1 = (int)ft_strlen(s1);
	index2 = (int)ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	temp = ft_strdup(s1);
	free(s1);
	if (!(s1 = (char *)malloc(((index1 + index2) * sizeof(char)) + 1)))
		return (NULL);
	index1 = 0;
	index2 = 0;
	while (temp[index1])
	{
		s1[index1] = temp[index1];
		index1++;
	}
	while (s2[index2])
		s1[index1++] = s2[index2++];
	s1[index1] = '\0';
	free(temp);
	return (s1);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char				*newstr;
	int					index;
	unsigned int		strlen;

	index = 0;
	strlen = 0;
	if (s == NULL)
		return (NULL);
	if (!(newstr = (char *)malloc((sizeof(char) * len + 1))))
		return (NULL);
	while (s[strlen])
		strlen++;
	if (!(start > strlen))
	{
		while (len > index && s[start + index])
		{
			newstr[index] = s[start + index];
			index++;
		}
	}
	newstr[index] = '\0';
	return (newstr);
}

int		ft_search(const char *str, int c)
{
	int		i;
	char	*s;
	char	ch;

	i = 0;
	s = (char *)str;
	ch = (char)c;
	while (s[i])
	{
		if (s[i] == ch)
			return (i);
		i++;
	}
	if (s[i] == ch)
		return (i);
	return (-1);
}

size_t	ft_strcpy(char *dest, char *src)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (dest == NULL)
		return (0);
	while (src[count])
		count++;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}
