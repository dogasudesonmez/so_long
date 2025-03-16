/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 04:48:03 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/16 04:48:04 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret_arr;
	int		len;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	ret_arr = malloc(sizeof(char) * (len + 1));
	if (!ret_arr)
		return (NULL);
	while (s[i])
	{
		ret_arr[i] = f(i, s[i]);
		i++;
	}
	ret_arr[i] = '\0';
	return (ret_arr);
}
