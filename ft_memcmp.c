/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kexu <kexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:24:22 by kexu              #+#    #+#             */
/*   Updated: 2025/11/21 15:42:08 by kexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *p1;
    const unsigned char *p2;

    p1 = (const unsigned char *)s1;
    p2 = (const unsigned char *)s2;
    while (n--)
    {
        if (*p1 != *p2 )
            return (*p1- *p2);
        p1++;
        p2++;
    }
    return (0);
}
#include <stdio.h>
#include <string.h>
#include "libft.h"

void print_result(const char *name, int ft_val, int ori_val)
{
    int ok = ((ft_val == 0 && ori_val == 0) ||
              (ft_val < 0 && ori_val < 0) ||
              (ft_val > 0 && ori_val > 0));

    printf("%s => ft:%d | original:%d | %s\n",
        name,
        ft_val,
        ori_val,
        (ok ? "OK" : "FAIL"));
}

int main(void)
{
    int ft_val, ori_val;

    /* -------- 1. 完全相同 -------- */
    char a1[] = "abcdef";
    char a2[] = "abcdef";
    ft_val  = ft_memcmp(a1, a2, 6);
    ori_val = memcmp(a1, a2, 6);
    print_result("完全相同", ft_val, ori_val);

    /* -------- 2. 第一个字节不同 -------- */
    char b1[] = "xbcdef";
    char b2[] = "abcdef";
    ft_val  = ft_memcmp(b1, b2, 6);
    ori_val = memcmp(b1, b2, 6);
    print_result("第一个不同", ft_val, ori_val);

    /* -------- 3. 中间字节不同 -------- */
    char c1[] = "abzdef";
    char c2[] = "abcdef";
    ft_val  = ft_memcmp(c1, c2, 6);
    ori_val = memcmp(c1, c2, 6);
    print_result("中间不同", ft_val, ori_val);

    /* -------- 4. 最后一个字节不同 -------- */
    char d1[] = "abcdez";
    char d2[] = "abcdef";
    ft_val  = ft_memcmp(d1, d2, 6);
    ori_val = memcmp(d1, d2, 6);
    print_result("最后不同", ft_val, ori_val);

    /* -------- 5. n = 0 情况 -------- */
    char e1[] = "abcdef";
    char e2[] = "ghijkl";
    ft_val  = ft_memcmp(e1, e2, 0);
    ori_val = memcmp(e1, e2, 0);
    print_result("n = 0", ft_val, ori_val);

    /* -------- 6. 包含 '\0' 的字符串 -------- */
    char f1[] = "ab\0def";
    char f2[] = "ab\0xyz";
    ft_val  = ft_memcmp(f1, f2, 6);
    ori_val = memcmp(f1, f2, 6);
    print_result("包含 \\0", ft_val, ori_val);

    /* -------- 7. 高位字符（unsigned 测试） -------- */
    unsigned char g1[] = { 200, 10, 20 };
    unsigned char g2[] = { 150, 10, 20 };
    ft_val  = ft_memcmp(g1, g2, 3);
    ori_val = memcmp(g1, g2, 3);
    print_result("高位字符 unsigned", ft_val, ori_val);

    /* -------- 8. 完全不同但 n 很小 -------- */
    char h1[] = "zzzzzz";
    char h2[] = "aaaaaa";
    ft_val  = ft_memcmp(h1, h2, 1);
    ori_val = memcmp(h1, h2, 1);
    print_result("n = 1", ft_val, ori_val);

    return 0;
}
