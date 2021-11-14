#include "printf.h"

void    ft_ullitoa_base(unsigned long long int n, char *base)
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
        	return ;        //return (0);
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
		//ft_putstr("0x");
		write(1, a, ft_strlen(a));
		return ;
	}
}