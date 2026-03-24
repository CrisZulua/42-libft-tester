#include "libft_tester.h"

typedef struct s_test
{
	size_t nmemb;
	size_t size;
} t_test;

int test_ft_calloc(void)
{
	t_test tests[] = {
		{0, 0},
		{0, 1},
		{1, 0},
		{1, 1},
		{1, 4},
		{100, 16},
		{10, 2},
		{SIZE_MAX, 2},
		{SIZE_MAX / 2 + 1, 3},
	};

	int num_tests = sizeof(tests) / sizeof(t_test);
	int passed = 0;

	void *res_sys;
	void *res_ft;

	for (int i = 0; i < num_tests; i++)
	{
		res_sys = calloc(tests[i].nmemb, tests[i].size);
		res_ft = ft_calloc(tests[i].nmemb, tests[i].size);

		if ((!res_sys && res_ft) || (res_sys && !res_ft))
			printf("\t❌   FAILED TEST %-2d ❌\t%s failed to allocate memory\n", i, res_sys ? "ft_calloc" : "calloc");
		else if (!res_sys && !res_ft)
			passed++;
		else if (memcmp(res_sys, res_ft, tests[i].nmemb * tests[i].size))
			printf("\t❌   FAILED TEST %-2d ❌\tDifferent bytes value on memory\n", i);
		else
			passed++;

		if (res_sys)
			free(res_sys);
		if (res_ft)
			free(res_ft);
	}
	return (passed == num_tests);
}
