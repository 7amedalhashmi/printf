#include "libftprintf.h"

void    ft_ullitoa_base(unsigned long long int n, char *base, int *i)
{       
        char                    *a;
        unsigned long long int  nbr;
        size_t                  size;
        int                     b_len;
        
        b_len = ft_strlen(base);
        nbr = n;
        size = 1;
        while (n /= b_len)
                size++; 
        if (!(a = (char *)malloc(size + 1)))
        	return ;
        a[size--] = '\0';
        while (nbr > 0)
        {       
                a[size--] = base[nbr % b_len];
                nbr /= b_len;
        }
        if (size == 0 && a[1] == '\0')
                a[0] = '0';
	while (a >= 0)
	{
                //ft_putchar(*a, i);
		write(1, a, ft_strlen(a));
                *i += ft_strlen(a);
		return ;
	}
}