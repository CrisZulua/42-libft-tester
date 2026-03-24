#ifndef LIBFT_TESTER_H
#define LIBFT_TESTER_H

#include "libft.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

// Type for pointer to function
typedef int (*fttest)(void);

// Struct that holds test functions
typedef struct s_ftlist
{
	char *name;
	fttest fct;
} t_ftlist;

extern const t_ftlist funct_list[];

int run_test(char *ft_name);

#define RST "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define ITALIC "\x1b[3m"

#endif
