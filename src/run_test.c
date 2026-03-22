#include "libft_tester.h"

int run_test(char *ft_name)
{
	for (size_t i = 0; funct_list[i].name != NULL; i++)
	{
		if (!strcmp(ft_name, funct_list[i].name))
			return (funct_list[i].fct());
	}
	printf("\nError : Unknown function (%s)\n", ft_name);
	return (0);
}
