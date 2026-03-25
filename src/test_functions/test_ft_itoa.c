#include "libft_tester.h"

typedef struct s_test
{
	int n;
	char *res_expected;
} t_test;

int test_ft_itoa(void)
{
	t_test tests[] = {
		{0, "0"},
		{1, "1"},
		{-1, "-1"},
		{500000, "500000"},
		{-500000, "-500000"},
		{INT32_MIN, "-2147483648"},
		{INT32_MAX, "2147483647"},
	};

	int num_tests = sizeof(tests) / sizeof(t_test);
	int passed = 0;
	char *res_ft;

	for (int i = 0; i < num_tests; i++)
	{
		res_ft = ft_itoa(tests[i].n);

		if (!res_ft)
			printf("\t❌   FAILED TEST %-2d ❌\tNo memory allocation\n", i);
		else
		{
			if (!strcmp(res_ft, tests[i].res_expected))
				passed++;
			else
				printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15s , Got : %-15s\n", i, tests[i].res_expected, res_ft);
		}
	}

	return (passed == num_tests);
}
