#include "libft_tester.h"

typedef struct s_test
{
	char *src;
	char c;
	size_t n;
} t_test;

int test_ft_memchr(void)
{
	t_test tests[] = {
		{"Hello, World!", 'W', 13},
		{"Hello, World!", 'z', 13},
		{"Hello, World!", 'H', 13},
		{"Hello, World!", '!', 13},
		{"", 'a', 0},
		{"\0hidden", '\0', 7},
		{"aaaaab", 'a', 6},
		{"aaaaab", 'a', 1},
		{"\x01\x02\x03\x04", '\x03', 4},
		{"Hello, World!", 'o', 5}};

	int num_tests = sizeof(tests) / sizeof(t_test);
	int passed = 0;
	char *res_ft = NULL;
	char *res_sys = NULL;

	for (int i = 0; i < num_tests; i++)
	{
		res_sys = memchr(tests[i].src, tests[i].c, tests[i].n);
		res_ft = ft_memchr(tests[i].src, tests[i].c, tests[i].n);

		if (res_sys == res_ft)
			passed++;
		else
			printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15p , Got : %-15p\n", i, res_sys, res_ft);
	}

	return (passed == num_tests);
}
