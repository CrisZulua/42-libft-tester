#include "libft_tester.h"

typedef struct s_test
{
	char *str;
	char *res_expected;
} t_test;

/*
	This function adds 1 to char values in odd indexes.
	Modify this function to do other tasks and test your
	implementation of ft_strmapi.

	Make sure to modify the res_expected field inside tests[]
	to your expected return values.
*/
static char func(unsigned int index, char c)
{
	return (c + (index % 2));
}

int test_ft_strmapi(void)
{
	t_test tests[] = {
		{"Hello World!", "Hflmo!Wprmd\""},
		{"aaaa", "abab"},
		{"123456789", "133557799"},
		{"", ""},
	};

	int num_tests = sizeof(tests) / sizeof(t_test);
	int passed = 0;
	char *res_ft;

	for (int i = 0; i < num_tests; i++)
	{
		res_ft = ft_strmapi(tests[i].str, func);

		if (!res_ft)
			printf("\t❌   FAILED TEST %-2d ❌\tNo memory allocation\n", i);
		else
		{
			if (!strcmp(res_ft, tests[i].res_expected))
				passed++;
			else
				printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15s , Got : %-15s\n", i, tests[i].res_expected, res_ft);
			free(res_ft);
		}
	}

	return (passed == num_tests);
}
