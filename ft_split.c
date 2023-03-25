/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:39:04 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/08 17:39:14 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_wordlen(char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_free(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
	return (NULL);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*help(char **arr, int i, int len)
{
	arr[i] = malloc(sizeof(char) * (len + 1));
	if (!arr[i])
		return (ft_free(arr));
	return (arr[i]);
}

char	**ft_split(char const *s, char c)
{
	int		nword;
	char	**arr;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	nword = ft_countword((char *)s, c);
	arr = (char **)malloc(sizeof(char *) * (nword + 1));
	if (!arr)
		return (NULL);
	i = 1;
	arr[0] = "./push_swap\0";
	while (i <= nword)
	{
		while (*s == c && *s != '\0')
			s++;
		len = ft_wordlen((char *)s, c);
		arr[i] = help(arr, i, len);
		arr[i] = ft_strncpy(arr[i], s, len);
		arr[i][len] = 0;
		i++;
		s = s + len;
	}
	return (arr);
}
