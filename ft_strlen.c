#include "printf.h"

size_t	ft_strlen(const char *c)
{
	if (*c == 0)
		return (0);
	return (ft_strlen(c + 1) + 1);
}