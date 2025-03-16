/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:01:24 by dsonmez           #+#    #+#             */
/*   Updated: 2025/03/14 23:01:29 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptrlen(unsigned long ptr)
{
	int	i;

	i = 0;
	while (ptr)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}

static void	ft_putptr_helper(unsigned long ptr, char *hex)
{
	if (ptr < 16)
	{
		ft_putchar(hex[ptr % 16]);
	}
	else
	{
		ft_putptr_helper(ptr / 16, hex);
		ft_putchar(hex[ptr % 16]);
	}
}

int	ft_putptr(unsigned long ptr)
{
	int	counter;

	counter = 0;
	counter += write(1, "0x", 2);
	if (ptr == 0)
		counter += write(1, "0", 1);
	else
	{
		ft_putptr_helper(ptr, "0123456789abcdef");
		counter += ptrlen(ptr);
	}
	return (counter);
}
