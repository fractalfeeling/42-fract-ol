/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:57:44 by lwee              #+#    #+#             */
/*   Updated: 2022/07/06 06:02:23 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*ft_initstr(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		count;

	count = ft_wordcount(s, c);
	array = malloc(sizeof(char *) * (count + 1));
	if (array == NULL)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		while (s[0] == c)
			s++;
		array[i] = ft_initstr(s, c);
		if (!array[i])
		{
			while (i-- > 0)
				free(array[i]);
			free(array);
			return (NULL);
		}
		s = s + ft_strlen(array[i]);
	}
	array[i] = 0;
	return (array);
}
