/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kexu <kexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:08:41 by kexu              #+#    #+#             */
/*   Updated: 2025/11/21 14:54:46 by kexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 -- 标准库允许dest和src是NULL，但必须 n == 0 ， 返回NULL
 -- n > 0 且 NULL 会崩溃
 综上，不要过渡保护而写成 
 	if (!src || !dest)
		return (NULL); 这样上面第二种情况时不会崩溃而返回 NULL
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	if (!src && !dest)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;

	while (n--)
		*d++ = *s++;
	return (dest);
}

#include <stdio.h>
#include <string.h>

static void test()
{
	char dest1[20] = "Hello, libft.";
	char dest2[20] = "Hello, libft.";
	char src[20] = "HELLO";
	
	ft_memcpy(dest1, src, 5);
	memcpy(dest2, src, 5);
	
	printf("ft: %s\n", dest1);
	printf("original: %s\n", dest2);
}
int	main()
{
	test();
	return (0);
}
