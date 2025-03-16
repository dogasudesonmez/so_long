/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 04:45:31 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/16 04:45:33 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret_arr;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	ret_arr = (void *)malloc(count * size);
	if (!ret_arr)
		return (NULL);
	ft_bzero(ret_arr, (count * size));
	return (ret_arr);
}
