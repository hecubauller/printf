/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 01:37:48 by shunt             #+#    #+#             */
/*   Updated: 2019/06/04 01:37:50 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_len(int k)
{
    int     l;

    l = 4;
    while (k / 100)
    {
        ++l;
        k /= 100;
    }
    return (l);
}

static char *ifz(int a, int b)
{
	char	*r;

	if (b)
	{
		if (!(r = (char *) malloc(sizeof(char) * 8)))
			return (NULL);
	}
	else
		if (!(r = (char *)malloc(sizeof(char) * 7)))
			return (NULL);
	r[0] = b ? '-' : '0';
	r[1] = b ? '0' : '.';
	if (b)
		r[2] = '.';
	else
		r[2] = a ? 'e' : 'E';
	if (b)
		r[3] = a ? 'e' : 'E';
	else
		r[3] = '+';
	r[4] = b ? '+' : '0';
	r[5] = '0';
	r[6] = b ? '0' : '\0';
	b ? r[7] = '\0' : 0;
	return (r);
}

char     *ft_e(long double e, int a)
{
    char    *s;
    char    *r;
    int     i;
    int     j;
    int     k;
    int     l;

    s = ft_fld(e, a);
    if (s[0] == 'i' || s[0] == 'I' || s[0] == 'n' ||
    s[0] == 'N' || s[1] == 'i' || s[1] == 'I')
    	return (s);
    i = (s[0] == '-') ? 0 : -1;
    if (s[++i] != '0')
    {
        while (s[i] && s[i] != '.')
            ++i;
        k = (s[0] == '-') ? i - 2 : i - 1;
    }
    else
    {
        i += 1;
        while (s[++i] == '0')
            ;
        if (!s[i])
			return (s[0] == '-' ? ifz(a, 1) : ifz(a, 0));
        k = (s[0] == '-') ? (i - 2) : (i - 1);
    }
    l = ft_strlen(s) + ft_len(k);
    r = (char *)malloc(sizeof(char) * (l + 1));
    r[l] = '\0';
    i = 0;
    while (s[i] && (s[i] == '-' || s[i] == '0' || s[i] == '.'))
        ++i;
    j = 0;
    if (s[0] == '-')
        r[j++] = '-';
    r[j] = (!s[i]) ? '0' : s[i];
    r[++j] = '.';
    while (s[i] && s[++i])
    {
        if (s[i] != '.')
            r[++j] = s[i];
    }
    r[++j] = a ? 'e' : 'E';
    if (s[0] == '-')
        r[++j] = (s[1] == '0') ? '-' : '+';
    else
        r[++j] = (s[0] == '0') ? '-' : '+';
    if (k < 10)
    {
        r[++j] = '0';
        r[++j] = k + 48;
    }
    else
        while (k)
        {
            r[--l] = k % 10 + 48;
            k /= 10;
        }
    free(s);
    return (r);
}