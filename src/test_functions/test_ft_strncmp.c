#include "libft_tester.h"

typedef struct s_test
{
	char *s1;
	char *s2;
	size_t n;
} t_test;

int test_ft_strncmp()
{
	const t_test tests[] = {
		{"Hello World!", "Hello World!", 12},
		{"Hello World!", "Hello World", 12},
		{"Hello World!", "Hello world!", 12},
		{"", "", 10},
		{"\t\r\f\n", "\t\r\f\n", 1},
		{"\t\r\f\n", "\t\f\n", 3},
		{"42 piscine", "42 pissine", 10},
		{"42 piscine", "42 piscine", 0},
		{"abcdfgh", "abcdefg", 5},
	};

	int num_tests = sizeof(tests) / sizeof(tests[0]);
	int passed = 0;

	for (int i = 0; i < num_tests; i++)
	{
		int res_sys = strncmp(tests[i].s1, tests[i].s2, tests[i].n);
		int res_ft = ft_strncmp(tests[i].s1, tests[i].s2, tests[i].n);

		if (res_sys == res_ft)
			passed++;
		else
			printf("\t❌ FAIL TEST %-3d ❌\tExpected : %-5d , Got : %-5d\n", i, res_sys, res_ft);
	}

	return (passed == num_tests);
}
