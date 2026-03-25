#include "libft_tester.h"

typedef struct s_test
{
	char *path;
	char *str;
} t_test;

int test_ft_putstr_fd(void)
{
	t_test tests[] = {
		{"./test1.txt", "Hello World!"},
		{"./test1.txt", "    "},
		{"./test1.txt", "\x02"},
		{"./test1", "42 \t\r piscine"},
		{"./test2", "1234\n123\n12\n1\n"},
	};

	int num_tests = sizeof(tests) / sizeof(t_test);
	int passed = 0;
	char buf[64];
	bzero(buf, 64);

	for (int i = 0; i < num_tests; i++)
	{
		int fd = open(tests[i].path, O_RDWR | O_CREAT, 00700);
		ft_putstr_fd(tests[i].str, fd);
		close(fd);

		fd = open(tests[i].path, O_RDONLY);
		read(fd, buf, 64);
		close(fd);

		if (!strncmp(tests[i].str, buf, strlen(tests[i].str)))
			passed++;
		else
			printf("\t❌   FAILED TEST %-2d ❌\tExpected : %-15s , Got : %-15s\n", i, tests[i].str, buf);
	}

	return (passed == num_tests);
}
