#include "libft_tester.h"

typedef struct s_test
{
	char c;
	size_t n;
} t_test;

int test_ft_memset(void)
{
	t_test tests[] = {
		{'a', 3},
		{'\t', 10},
		{'b', 0},
	};

	int num_tests = sizeof(tests) / sizeof(t_test);
	int passed = 0;
	char *res_ft = NULL;
	char *res_sys = NULL;
	char buf_ft[25];
	char buf_sys[25];

	for (int i = 0; i < num_tests; i++)
	{
		memset(buf_ft, 0, sizeof(buf_ft));
		memset(buf_sys, 0, sizeof(buf_sys));

		res_sys = memset(buf_sys, tests[i].c, tests[i].n);
		res_ft = ft_memset(buf_ft, tests[i].c, tests[i].n);

		if (res_ft && res_sys)
		{
			if (!memcmp(res_ft, res_sys, tests[i].n))
				passed++;
			else
				printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15s , Got : %-15s\n", i, res_sys, res_ft);
		}
		else if (!res_ft && !res_sys)
			passed++;
		else
			printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-5s , Got : %-5s\n", i, res_sys ? res_sys : "NULL", res_ft ? res_ft : "NULL");
	}

	return (passed == num_tests);
}
