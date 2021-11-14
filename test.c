#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *c)
{
	if (*c == 0)
		return (0);
	return (ft_strlen(c + 1) + 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)// 42 -> "teapot" , [2, 3, 1, , , , , , , , , , ,]
{
	int	size_base;
	int	nbr_final[100];
	int	i;

	i = 0;
	size_base = 0;
	if (check_base(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		while (base[size_base])
			size_base++;
		while (nbr)
		{
			nbr_final[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[nbr_final[i]]);
	}
}

char	*ft_ullitoa_base(unsigned long long int n, char *base)
{
	char			*a;
	unsigned long long int	nbr;
	size_t			size;
	int			b_len;

	b_len = ft_strlen(base);
	nbr = n;
	size = 1;
	while (n /= b_len)
		size++;
	if (!(a = (char *)malloc(size + 1)))
		return (0);
	a[size--] = '\0';
	while (nbr > 0)
	{
		a[size--] = base[nbr % b_len];
		nbr /= b_len;
	}
	if (size == 0 && a[1] == '\0')
		a[0] = '0';
	return (a);
}

void    ft_ullitoa_base1(unsigned long long int n, char *base)
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
		ft_putstr("0x");
		write(1, a, ft_strlen(a));
		return ;
	}
}


void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

int	ft_printf(const char *c, ...)
{
	va_list		arg;

	va_start(arg, c);
	while (*c != '\0')
	{
		if (*c == '%')
		{
			c++;
			if (*c == 'i')
				ft_putnbr(va_arg(arg, int));
			else if (*c == 'd')
				ft_putnbr_base((va_arg(arg, int)), "0123456789");
			else if (*c == 'u')
				ft_putnbr_base((va_arg(arg, unsigned int)), "0123456789");
			else if (*c == 'c')
				ft_putchar(va_arg(arg, int));
			else if (*c == 's')
				ft_putstr(va_arg(arg, char *));
			else if (*c == 'x')
				ft_putnbr_base((va_arg(arg, unsigned int)), "0123456789abcdef");
			else if (*c == 'X')
				ft_putnbr_base((va_arg(arg, unsigned int)), "0123456789ABCDEF");
			else if (*c == 'p')
				ft_ullitoa_base1((va_arg(arg, unsigned long)), "0123456789abcdef");
			else if (*c == '%')
				ft_putchar('%');
		}
		else
			ft_putchar(*c);
	c++;
	}
	va_end(arg);
	return (0);
}

int main()
{
//	printf("%s hamed %d", "hamed", 123);
//	fun("%d", 123);
	char b;
	b = 42;
	ft_printf("FAKE: %p %X %u %i this is %d %s %d %c %c %% \n", &b, 980, 010, 010, -123, "hamed", 321, 'g', 'b');
	printf("REAL: %p %X %u %i this is %d %s %d %c %c %% \n", &b, 980, 010, 010, -123, "hamed", 321, 'g', 'b');
}
