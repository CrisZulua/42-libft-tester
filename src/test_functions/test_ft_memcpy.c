#include "libft_tester.h"

typedef struct s_test
{
	char *src;
	size_t n;
} t_test;

int test_ft_memcpy(void)
{
	t_test tests[] = {
		{"Hello World!", 5},
		{"Hello World!", 2},
		{"Hello World!", 0},
		{"Hello\0World!", 9},
		{"42", 2},
		{"0123456789ABCDF", 15}};

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

		res_sys = memcpy(buf_sys, tests[i].src, tests[i].n);
		res_ft = ft_memcpy(buf_ft, tests[i].src, tests[i].n);

		if (!memcmp(res_ft, res_sys, tests[i].n))
			passed++;
		else
			printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15s , Got : %-15s\n", i, res_sys, res_ft);
	}

	return (passed == num_tests);
}
