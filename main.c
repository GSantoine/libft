/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:51:59 by agras             #+#    #+#             */
/*   Updated: 2021/12/15 12:20:16 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"


void	print_mem(void *ptr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%c\n", ((char *)ptr)[i]);
		i++;
	}
	printf("\n");
}

//-------------------------- Additional functions ---------------------------------

void	test_ft_strtrim(void)
{
	printf("----------------------------------\n");
	printf("ft_strtrim\n");
	printf("----------------------------------\n");

	char	*s = NULL;
	char	*set = NULL;

	char	*res = ft_strtrim(s, set);
	if (res)
		printf("test 1 = %s\n", res);
}

void	test_ft_strchr(void)
{
	printf("----------------------------------\n");
	printf("ft_strchr\n");
	printf("----------------------------------\n");

	char	*src = "īœ˙ˀ˘¯ˇ¸¯.œ«‘––™ª•¡¶¢˜ˀ";

	char	*d1 = strchr(src, L'–');
	char	*d2 = ft_strchr(src, L'–');
	printf("%s\n", d1);
	printf("%s\n", d2);

	char s[] = "tripouille";
	printf("test tripouille = %s\n", strchr(s, 't' + 513));
}

void	test_ft_putnbr_fd(void)
{
	printf("----------------------------------\n");
	printf("ft_putnbr_fd\n");
	printf("----------------------------------\n");

	ft_putnbr_fd(-2147483648LL, 1);
}

void	test_ft_memmove(void)
{
	printf("----------------------------------\n");
	printf("ft_memmove\n");
	printf("----------------------------------\n");

	char	src1[] = "123456";
	char	*dest1 = src1 + 3;

	char	*res = (char *)ft_memmove(dest1, src1, 6);
	for (int i = 0; i < 6; i++)
		printf("%c\n", res[i]);
}

void	test_ft_calloc(void)
{
	printf("----------------------------------\n");
	printf("ft_calloc\n");
	printf("----------------------------------\n");

	int	*ptr = ft_calloc(20, 4);
	for (int i = 0; i < 20; i++)
		ptr[i] = i;
	for (int i = 0; i < 90; i++)
		printf("%d\n", ptr[i]);
}

void	test_ft_memcmp(void)
{
	printf("----------------------------------\n");
	printf("ft_memcmp\n");
	printf("----------------------------------\n");

	unsigned char	s1[] = "abd";
	unsigned char	s2[] = "abc";
	unsigned char	s1a[] = "ab";
	unsigned char	s2a[] = "ac";
	unsigned char	s1b[] = "a";
	unsigned char	s2b[] = "a";
	unsigned char	s1c[] = "a";
	unsigned char	s2c[] = "";
	unsigned char	s1d[] = "";
	unsigned char	s2d[] = "";

	// printf("%d\n", ft_memcmp(s1, s2, 2));
	(ft_memcmp(s1, s2, 2) == memcmp(s1, s2, 2)) ? printf("OK\n") : printf("NOPE\n");
	(ft_memcmp(s1, s2, 3) == memcmp(s1, s2, 3)) ? printf("OK\n") : printf("NOPE\n");
	(ft_memcmp(s1, s2, 4) == memcmp(s1, s2, 4)) ? printf("OK\n") : printf("NOPE\n");
	(ft_memcmp(s1a, s2a, 1) == memcmp(s1a, s2a, 1)) ? printf("OK\n") : printf("NOPE\n");
	(ft_memcmp(s1a, s2a, 2) == memcmp(s1a, s2a, 2)) ? printf("OK\n") : printf("NOPE\n");
	(ft_memcmp(s1a, s2a, 0) == memcmp(s1a, s2a, 0)) ? printf("OK\n") : printf("NOPE\n");
	(ft_memcmp(s1b, s2b, 1) == memcmp(s1b, s2b, 1)) ? printf("OK\n") : printf("NOPE\n");
	(ft_memcmp(s1b, s2b, 2) == memcmp(s1b, s2b, 2)) ? printf("OK\n") : printf("NOPE\n");
	(ft_memcmp(s1c, s2c, 1) == memcmp(s1c, s2c, 1)) ? printf("OK\n") : printf("NOPE\n");
	(ft_memcmp(s1c, s2c, 0) == memcmp(s1c, s2c, 0)) ? printf("OK\n") : printf("NOPE\n");
	(ft_memcmp(s1d, s2d, 1) == memcmp(s1d, s2d, 1)) ? printf("OK\n") : printf("NOPE\n");
	(ft_memcmp(s1d, s2d, 0) == memcmp(s1d, s2d, 0)) ? printf("OK\n") : printf("NOPE\n");
}

void	test_ft_memcpy(void)
{
	printf("----------------------------------\n");
	printf("ft_memcpy\n");
	printf("----------------------------------\n");

	unsigned char	dest1a[5] = "";
	unsigned char	src1a[] = "abcde";
	unsigned char	dest1b[5] = "";
	unsigned char	src1b[] = "abcde";
	unsigned char	dest2a[7] = "";
	unsigned char	src2a[7] = "";
	unsigned char	dest2b[7] = "";
	unsigned char	src2b[7] = "";

	// print_mem(ft_memcpy(dest2b, src2b, 7), 7);
	(ft_memcmp(ft_memcpy(dest1a, src1a, 5), memcpy(dest1b, src1b, 5), 5) == 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_memcmp(ft_memcpy(dest1a, src1a, 4), memcpy(dest1b, src1b, 4), 4) == 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_memcmp(ft_memcpy(dest1a, src1a, 0), memcpy(dest1b, src1b, 0), 1) == 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_memcmp(ft_memcpy(dest2a, src2a, 7), memcpy(dest2b, src2b, 7), 7) == 0) ? printf("OK\n") : printf("NOPE\n");
}

int	ft_strcmp(char *s1, char *s2)
{
	int	balance;

	balance = 0;
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	balance = *s1 - *s2;
	return (balance);
}

void	test_ft_substr(void)
{
	printf("----------------------------------\n");
	printf("ft_substr\n");
	printf("----------------------------------\n");

	(strcmp(ft_substr("abcdefg", 2, 5), "cdefg") == 0) ? printf("OK\n") : printf("NOPE\n");
	(strcmp(ft_substr("abcdefg", 2, 4), "cdef") == 0) ? printf("OK\n") : printf("NOPE\n");
	(strcmp(ft_substr("abcdefg", 2, 6), "cdefg") == 0) ? printf("OK\n") : printf("NOPE\n");
	(strcmp(ft_substr("abcdefg", 2, 7), "cdefg") == 0) ? printf("OK\n") : printf("NOPE\n");
	(strcmp(ft_substr("abcdefg", 0, 4), "abcd") == 0) ? printf("OK\n") : printf("NOPE\n");
	(strcmp(ft_substr("abcdefg", 0, 0), "") == 0) ? printf("OK\n") : printf("NOPE\n");
	(strcmp(ft_substr("abcdefg", 2, 0), "") == 0) ? printf("OK\n") : printf("NOPE\n");
	(strcmp(ft_substr("abcdefg", 2, 1), "c") == 0) ? printf("OK\n") : printf("NOPE\n");
	(strcmp(ft_substr("abcdefg", 2, 4), "cdef") == 0) ? printf("OK\n") : printf("NOPE\n");
	(strcmp(ft_substr("", 0, 1), "") == 0) ? printf("OK\n") : printf("NOPE\n");

}

//-------------------------- Basic functions --------------------------------------

void	test_ft_bzero(void)
{
	printf("----------------------------------\n");
	printf("ft_bzero\n");
	printf("----------------------------------\n");
}

void	test_mem(void *sa, void *sb, int c, int n)
{
	int	i;

	i = 0;
	printf("mem->test\n");
	while (i < n)
	{
		// test for every byte
		((((unsigned char *)sa)[i]) == (((unsigned char *)sb)[i])) ? printf("	uchar OK\n") : printf("	uchar NOPE\n");
//		printf("%u | %u\n", (((unsigned char *)sa)[i]), (((unsigned char *)sb)[i]));
//		test every 4 bytes (size of int)
		if (i % 4 == 0)
			((((int *)sa)[i / 4]) == (((int *)sb)[i / 4])) ? printf("	int OK\n") : printf("	int NOPE\n");
		i += 1;
	}
	printf("test end *s + offset of 1 : ");
	printf("%u | %u\n", (((unsigned char *)sa)[i]), (((unsigned char *)sb)[i]));
	printf("%u | %u\n", (((unsigned char *)sa)[i + 1]), (((unsigned char *)sb)[i + 1]));
	// test non significatif si byte = 0 (mem non init)
	(((unsigned char *)sa)[i] != ((unsigned char *)sb)[i] && ((unsigned char *)sa)[i] != c) ? printf("OK\n") : printf("NOPE\n");
}

void	test_ft_memset(void)
{
	char	s1a[2];
	char	s1b[2];
	char	s2a[17];
	char	s2b[17];
	char	s3a[17];
	char	s3b[17];

	printf("----------------------------------\n");
	printf("ft_memset\n");
	printf("----------------------------------\n");
	test_mem(ft_memset(s1a, 'g', 1), memset(s1b, 'g', 1), 'g', 1);
	test_mem(ft_memset(s2a, 'g', 16), memset(s2b, 'g', 16), 'g', 16);
	test_mem(ft_memset(s3a, 300, 16), memset(s3b, 300, 16), 300, 16);
}

void	test_ft_strlen(void)
{
	printf("----------------------------------\n");
	printf("ft_strlen\n");
	printf("----------------------------------\n");
	(ft_strlen("12345") == strlen("12345")) ? printf("OK\n") : printf("NOPE\n");
	(ft_strlen("1") == strlen("2")) ? printf("OK\n") : printf("NOPE\n");
	(ft_strlen("") == strlen("")) ? printf("OK\n") : printf("NOPE\n");
	(ft_strlen("1234") != strlen("12345")) ? printf("OK\n") : printf("NOPE\n");
	(ft_strlen("123456") != strlen("12345")) ? printf("OK\n") : printf("NOPE\n");
}

int	main(void)
{
	printf("----------------------------------\n");
	printf("ft_isalpha\n");
	printf("----------------------------------\n");
	(ft_isalpha('a') != 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isalpha('z') != 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isalpha('A') != 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isalpha('Z') != 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isalpha('a' - 1) == 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isalpha('A' - 1) == 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isalpha('Z' + 1) == 0) ? printf("OK\n") : printf("NOPE\n");
	printf("----------------------------------\n");
	printf("ft_isdigit\n");
	printf("----------------------------------\n");
	(ft_isdigit('0') != 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isdigit('9') != 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isdigit('9' + 1) == 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isdigit('0' - 1) == 0) ? printf("OK\n") : printf("NOPE\n");
	printf("----------------------------------\n");
	printf("ft_isalnum\n");
	printf("----------------------------------\n");
	(ft_isalnum('a') != 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isalnum('z') != 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isalnum('A') != 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isalnum('Z') != 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isalnum('a' - 1) == 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isalnum('A' - 1) == 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isalnum('Z' + 1) == 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isalnum('0') != 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isalnum('9') != 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isalnum('9' + 1) == 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isalnum('0' - 1) == 0) ? printf("OK\n") : printf("NOPE\n");
	printf("----------------------------------\n");
	printf("ft_isascii\n");
	printf("----------------------------------\n");
	(ft_isascii(37) != 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isascii(-1) == 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isascii(128) == 0) ? printf("OK\n") : printf("NOPE\n");
	printf("----------------------------------\n");
	printf("ft_isprint\n");
	printf("----------------------------------\n");
	(ft_isprint(32) != 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isprint(127) != 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isprint(255) != 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isprint(31) == 0) ? printf("OK\n") : printf("NOPE\n");
	(ft_isprint(256) == 0) ? printf("OK\n") : printf("NOPE\n");
	test_ft_strlen();
	test_ft_memset();
	test_ft_substr();
	test_ft_memcmp();
	test_ft_memcpy();
	test_ft_calloc();
//	test_ft_memmove();
	test_ft_putnbr_fd();
	test_ft_strchr();
	test_ft_strtrim();
}
