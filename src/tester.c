#include "libft_tester.h"

int run_tests(char *ft_name);

int main(int argc, char **argv)
{
	int passed_test = 0;

	// Check if there is no arguments
	if (argc < 2)
	{
		printf("Bad execution: usage <function|all>\n");
		return (1);
	}

	// Check if all tests are to be runned. If not run only the test
	// for functions specified in arguments
	if (!strcmp(argv[1], "all"))
	{
		// Run every function on funct_list
		for (size_t i = 0; funct_list[i].name != NULL; i++)
		{
			printf("\nExecuting '%s' test\n", funct_list[i].name);
			if (funct_list[i].fct())
				passed_test++;
		}
	}
	else
	{
		for (size_t i = 1; i < argc; i++)
		{
			if (run_test(argv[i]))
				passed_test++;
		}
	}

	printf("Total test passed: %d/%d.\n", passed_test, argc - 1);
	return (0);
}

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
