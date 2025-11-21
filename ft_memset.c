/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kexu <kexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:50:55 by kexu              #+#    #+#             */
/*   Updated: 2025/11/21 11:51:47 by kexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *p;
    
    p = (unsigned char *)s;
    while (n--)
        *p++ = (unsigned char)c;
    return (s);
}
/*
 -- void * 是不管类型的通用指针，所以函数传入的参数和返回值都是void *
 -- mem系列函数都是按字节处理，C里“字节”的类型就是unsigend char（永远0～255），
    所以把指针都转换为unsigned char*来逐字节操作，不关心类型
 -- n == 0时，函数什么都不做，没有写入也不应该崩溃
 -- 如果c > 255, 会将int c按unsigned char处理，超出范围会自动截断
 -- 不需要处理NULL指针 memset(NULL,c,len)是undefined behavior，不要if（!s) return NULL保护
 -- 内存边界溢出不是 memset 的责任，不检查内存是否足够
*/

#include <stdio.h>
#include <string.h>
static void test_basic()
{
    char    buf1[20] = "Hello, libft";
    char    buf2[20] = "Hello, libft";
    
    ft_memset(buf1, 'X', 5);
    memset(buf2, 'X', 5);

    printf("ft: %s\n", buf1);
    printf("original: %s\n", buf2);
    printf("\n");
}

static void test_zero()
{
    char    buf1[20] = "Hello, libft";
    char    buf2[20] = "Hello, libft";
    
    ft_memset(buf1, 'X', (size_t)0);
    memset(buf2, 'X', (size_t)0);
    
    printf("ft: %s\n", buf1);
    printf("original: %s\n", buf2);
    printf("\n");
}

static void test_overflow()
{
    printf("[Overflow] This is an undefined behavior demo.\n");
    printf("[Overflow] Program *may* crash or not.\n");

    char buf[5] = "AAAA";

    printf("Before: %s\n", buf);

    // 这是非法的（不要在正式项目中使用）
    ft_memset(buf, 'B', 10);

    printf("After:  %s   (result not reliable)\n", buf);
}

int main()
{
    test_basic();
    test_zero();
    test_overflow();
}
