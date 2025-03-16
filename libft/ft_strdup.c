/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 04:47:37 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/16 04:47:38 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ret_arr;
	int		i;

	i = 0;
	ret_arr = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!ret_arr)
		return (NULL);
	while (src[i])
	{
		ret_arr[i] = src[i];
		i++;
	}
	ret_arr[i] = '\0';
	return (ret_arr);
}
