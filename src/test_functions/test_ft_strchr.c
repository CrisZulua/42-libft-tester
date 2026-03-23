#include "libft_tester.h"

typedef struct s_test
{
	char *str;
	char c;
} t_test;

int test_ft_strchr(void)
{
	t_test tests[] = {
		{"42 piscine", '4'},
		{"42 piscine", 'p'},
		{"42 piscine", '\0'},
		{"42 piscine", ' '},
		{"42 \tpiscine", '\t'},
		{"42 \0piscine", 'p'},
		{"42 piscine", 'l'}};

	int num_tests = sizeof(tests) / sizeof(t_test);
	int passed = 0;

	for (int i = 0; i < num_tests; i++)
	{
		char *res_sys = strchr(tests[i].str, tests[i].c);
		char *res_ft = ft_strchr(tests[i].str, tests[i].c);

		if (res_sys == res_ft)
			passed++;
		else
			printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15p , Got : %-15p\n", i, res_sys, res_ft);
	}
	return (passed == num_tests);
}
