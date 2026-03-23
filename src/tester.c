#include "libft_tester.h"

int main(int argc, char **argv)
{
	int passed_test = 0;

	// Check if there is no arguments
	if (argc < 2)
	{
		printf("Bad execution: usage <function|all>\n");
		return (1);
	}

	// Check if all tests are to be runned. If not run only the test
	// for the functions specified in arguments
	printf("---------------------TESTING--------------------------\n\n");
	if (!strcmp(argv[1], "all"))
	{
		for (int i = 0; funct_list[i].name != NULL; i++)
		{
			printf("⚡ Executing '%s' test:\n", funct_list[i].name);
			if (funct_list[i].fct())
			{
				printf("\t🟢 TEST SUCCESSFUL\n");
				passed_test++;
			}
			else
				printf("\t🔴 TEST FAILED\n");
		}
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			printf("⚡ Executing '%s' test:\n", argv[i]);
			if (run_test(argv[i]))
			{
				printf("\t🟢 TEST SUCCESSFUL\n");
				passed_test++;
			}
			else
				printf("\t🔴 TEST FAILED\n");
		}
	}

	printf("\n---------------------RESULTS--------------------------\n");
	printf("Total tests passed: %d/%d.\n", passed_test, strcmp(argv[1], "all") ? argc - 1 : 2);
	return (0);
}
