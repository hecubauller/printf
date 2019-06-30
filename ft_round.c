/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 00:07:30 by shunt             #+#    #+#             */
/*   Updated: 2019/06/20 00:07:33 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_round(char *s, int a)
{
    int     i;
    int     k;
    char    *t;
    char    *c;

    c = NULL;
    k = strlen(s);
    i = t_str(s, &t);
    if (k != i)
        c_str(s, &c, i, k);
    if (t[i - 1] != '.')
    {
        k = i;
        while (t[--i] != '.')
            ;
        if (k - i - 1 < a)
            zrs(t, a, i);
        else
            a ? rnd(t, a, i) : rnd_z(t, i);
    }
    else
        e_zrs(t, a, i);
    s_str(&s, &t, &c);
    return (s);
}