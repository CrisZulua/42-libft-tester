#include "libft_tester.h"

typedef struct s_test
{
	char *path;
	int n;
	char *res_expected;
} t_test;

int test_ft_putnbr_fd(void)
{
	t_test tests[] = {
		{"./test1.txt", 0, "0"},
		{"./test1.txt", INT32_MAX, "2147483647"},
		{"./test1.txt", INT32_MIN, "-2147483648"},
		{"./test1.txt", 1234, "12347483648"},
		{"./test1.txt", -1234, "-1234483648"},
		{"./test2", INT32_MIN, "-2147483648"},
	};

	int num_tests = sizeof(tests) / sizeof(t_test);
	int passed = 0;
	char buf[64];
	bzero(buf, 64);

	for (int i = 0; i < num_tests; i++)
	{
		int fd = open(tests[i].path, O_RDWR | O_CREAT, 00700);
		ft_putnbr_fd(tests[i].n, fd);
		close(fd);

		fd = open(tests[i].path, O_RDONLY);
		int bread = read(fd, buf, 64);
		close(fd);

		if (!strncmp(tests[i].res_expected, buf, bread))
			passed++;
		else
			printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15s , Got : %-15s\n", i, tests[i].res_expected, buf);
		rm_created_file(tests[i].path);
	}

	return (passed == num_tests);
}
