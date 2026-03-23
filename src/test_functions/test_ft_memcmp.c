#include "libft_tester.h"

typedef struct s_test
{
	char *s1;
	char *s2;
	size_t n;
} t_test;

int test_ft_memcmp(void)
{
	t_test tests[] = {
		{"Hello, World!", "Hello, World!", 13},
		{"Hello, World!", "Hello, World!", 0},
		{"abc", "abd", 3},
		{"abd", "abc", 3},
		{"abc", "abcd", 3},
		{"abc\0xyz", "abc\0abc", 7},
		{"\x01\x02\x03", "\x01\x02\x04", 3},
		{"AAAB", "AAAA", 4},
		{"AAAA", "AAAB", 4},
		{"Hello", "Hello", 3}};

	int num_tests = sizeof(tests) / sizeof(t_test);
	int passed = 0;
	int res_ft;
	int res_sys;

	for (int i = 0; i < num_tests; i++)
	{
		res_sys = memcmp(tests[i].s1, tests[i].s2, tests[i].n);
		res_ft = ft_memcmp(tests[i].s1, tests[i].s2, tests[i].n);

		if (res_sys == res_ft)
			passed++;
		else
			printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-5d , Got : %-5d\n", i, res_sys, res_ft);
	}

	return (passed == num_tests);
}
