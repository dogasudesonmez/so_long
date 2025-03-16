/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 04:47:28 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/16 04:47:30 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**ret_arr;
	size_t	i;
	size_t	j;
	size_t	arr_index;

	i = 0;
	arr_index = 0;
	ret_arr = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!ret_arr)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		if (ft_count_word(s, c) == arr_index)
			break ;
		ret_arr[arr_index++] = ft_substr(s, i, j - i);
		i = j;
	}
	ret_arr[arr_index] = 0;
	return (ret_arr);
}
