#include "libft_tester.h"

int test_ft_bzero(void)
{
	size_t tests[] = {0, 1, 6, 10, 15};

	int num_tests = sizeof(tests) / sizeof(size_t);
	int passed = 0;
	char buf_ft[15];
	char buf_sys[15];

	bzero(buf_sys, sizeof(buf_sys));
	for (int i = 0; i < num_tests; i++)
	{
		memset(buf_ft, 'a', sizeof(buf_ft));

		ft_bzero(buf_ft, tests[i]);
		int cmp = memcmp(buf_sys, buf_ft, tests[i]);
		if (!cmp)
			passed++;
		else
			printf("\t❌   FAILED TEST %-2d ❌\tMemory Comparison : %-3d\n", i, cmp);
	}

	return (passed == num_tests);
}
