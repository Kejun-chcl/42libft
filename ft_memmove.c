/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kexu <kexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:01:36 by kexu              #+#    #+#             */
/*   Updated: 2025/11/21 14:54:01 by kexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s && d < s + n)
		while (n--) //注意這個n先減去1再進入循環
			d[n] = s[n];
	else
		ft_memcpy(d, s, n);
	return (dest);
}

/*
 -- 想用临时arr存诸src的内容再传给dest，但是不允许malloc所以不可行
 -- 分情况：1,有overlap，從後向前copy
           2, 沒有overlap，正常memcpy
*/
#include <stdio.h>
#include <string.h>

int    main()
{
    char buf1[20] = "abcdefg";
    char buf2[20] = "abcdefg";
    ft_memmove (buf1+2, buf1, 5);
    memmove(buf2+2, buf2, 5);
    printf("ft: %s\n",buf1);
  printf("original: %s\n",buf2);
  return (0);
}