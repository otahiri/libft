#include "unity.h"
#include "libft.h"
#include "unity_internals.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void test_ft_atoi()
{
	TEST_ASSERT_EQUAL(41, ft_atoi("   41sad"));
	TEST_ASSERT_EQUAL(0, ft_atoi("   a41sad"));
	TEST_ASSERT_EQUAL(-2147483648, ft_atoi("       -2147483648dsds"));
	TEST_ASSERT_EQUAL(2147483647, ft_atoi("       2147483647dsds"));
	TEST_ASSERT_EQUAL(0, ft_atoi(" "));
}
void test_ft_bzero()
{
	char buffer[20];
    for (int i = 0; i < 20; i++) buffer[i] = (char)(i + 1);
    ft_bzero(buffer, 10);
    for (int i = 0; i < 10; i++) TEST_ASSERT_EQUAL(0, buffer[i]);
    for (int i = 10; i < 20; i++) TEST_ASSERT_EQUAL(i + 1, buffer[i]);
    for (int i = 0; i < 20; i++) buffer[i] = (char)(i + 1);
    ft_bzero(buffer, 0);
    for (int i = 0; i < 20; i++) TEST_ASSERT_EQUAL(i + 1, buffer[i]);
    for (int i = 0; i < 20; i++) buffer[i] = (char)(i + 1);
    ft_bzero(buffer, 20);
    for (int i = 0; i < 20; i++) TEST_ASSERT_EQUAL(0, buffer[i]);
}

void test_ft_calloc()
{
	int *arr = ft_calloc(5, sizeof(int));
    TEST_ASSERT_NOT_NULL(arr);
    for (int i = 0; i < 5; i++)
        TEST_ASSERT_EQUAL(0, arr[i]);
    free(arr);

    arr = ft_calloc(0, sizeof(int));
    if (arr)
        free(arr);

    arr = ft_calloc(5, 0);
    TEST_ASSERT_NOT_NULL(arr);
    free(arr);

    size_t large_size = 1000000;
    arr = ft_calloc(large_size, sizeof(int));
    if (arr) {
        for (size_t i = 0; i < 10; i++)
            TEST_ASSERT_EQUAL(0, arr[i]);
        free(arr);
    }

    arr = ft_calloc(1, sizeof(int));
    TEST_ASSERT_NOT_NULL(arr);
    free(arr);

}
void test_ft_isalnum()
{
	TEST_ASSERT_EQUAL(1, ft_isalnum('A'));
	TEST_ASSERT_EQUAL(1, ft_isalnum('3'));
	TEST_ASSERT_EQUAL(1, ft_isalnum('a'));
	TEST_ASSERT_EQUAL(1, ft_isalnum('z'));
	TEST_ASSERT_EQUAL(1, ft_isalnum('Z'));
	TEST_ASSERT_EQUAL(1, ft_isalnum('0'));
	TEST_ASSERT_EQUAL(1, ft_isalnum('9'));
	TEST_ASSERT_EQUAL(0, ft_isalnum('%'));
	TEST_ASSERT_EQUAL(0, ft_isalnum(' '));
	TEST_ASSERT_EQUAL(0, ft_isalnum('\0'));
	TEST_ASSERT_EQUAL(0, ft_isalnum('\n'));
}
void test_ft_isalpha()
{
	TEST_ASSERT_EQUAL(1, ft_isalpha('A'));
	TEST_ASSERT_EQUAL(1, ft_isalpha('Z'));
	TEST_ASSERT_EQUAL(1, ft_isalpha('a'));
	TEST_ASSERT_EQUAL(1, ft_isalpha('z'));
	TEST_ASSERT_EQUAL(0, ft_isalpha('2'));
	TEST_ASSERT_EQUAL(0, ft_isalpha('+'));
	TEST_ASSERT_EQUAL(0, ft_isalpha('\n'));
	TEST_ASSERT_EQUAL(0, ft_isalpha('\0'));
}
void test_ft_isascii()
{
	TEST_ASSERT_EQUAL(1, ft_isascii(12));
	TEST_ASSERT_EQUAL(1, ft_isascii(0));
	TEST_ASSERT_EQUAL(1, ft_isascii(127));
	TEST_ASSERT_EQUAL(0, ft_isascii(-127));
	TEST_ASSERT_EQUAL(0, ft_isascii(-1));
}
void test_ft_isdigit()
{
	TEST_ASSERT_EQUAL(1, ft_isdigit('0'));
	TEST_ASSERT_EQUAL(1, ft_isdigit('9'));
	TEST_ASSERT_EQUAL(0, ft_isdigit('A'));
	TEST_ASSERT_EQUAL(0, ft_isdigit('Z'));
	TEST_ASSERT_EQUAL(0, ft_isdigit('a'));
	TEST_ASSERT_EQUAL(0, ft_isdigit('z'));
	TEST_ASSERT_EQUAL(0, ft_isdigit('/'));
	TEST_ASSERT_EQUAL(0, ft_isdigit(' '));
}
void test_ft_isprint()
{
	for (int c = 32; c <= 126; c++)
		TEST_ASSERT_EQUAL(1, ft_isprint(c));
	for (int c = 0; c < 32; c++)
		TEST_ASSERT_EQUAL(0, ft_isprint(c));
	TEST_ASSERT_EQUAL(0, ft_isprint(127));
}
void test_ft_itoa()
{
	TEST_ASSERT_EQUAL_STRING("1234", ft_itoa(1234));
	TEST_ASSERT_EQUAL_STRING("0", ft_itoa(0));
	TEST_ASSERT_EQUAL_STRING("2147483647", ft_itoa(2147483647));
	TEST_ASSERT_EQUAL_STRING("-2147483648", ft_itoa(-2147483648));

}

void *map_copy(void *content)
{
	if (!content) return NULL;
	return strdup((char *)content);
}

void del(void *content) { free(content); }
void test_ft_lst_all_extreme(void)
{

	t_list *a = ft_lstnew(strdup("first"));
	t_list *b = ft_lstnew(strdup("second"));
	t_list *c = ft_lstnew(strdup("third"));
	t_list *nullnode = ft_lstnew(NULL);

	ft_lstadd_back(&a, b);
	ft_lstadd_front(&a, c);
	ft_lstadd_back(&a, nullnode);
	TEST_ASSERT_EQUAL(4, ft_lstsize(a));
	TEST_ASSERT_EQUAL_PTR(nullnode, ft_lstlast(a));

	ft_lstdelone(nullnode, del);
	nullnode = ft_lstnew(strdup("new"));
	ft_lstadd_back(&a, nullnode);
	TEST_ASSERT_EQUAL_STRING("new", ft_lstlast(a)->content);

	int count = 0;
	void count_nodes(void *content) { (void)content; count++; }
	ft_lstiter(a, count_nodes);
	TEST_ASSERT_EQUAL(4, count);
	t_list *mapped = ft_lstmap(a, map_copy, del);
	TEST_ASSERT_NOT_NULL(mapped);
	TEST_ASSERT_EQUAL(ft_lstsize(a), ft_lstsize(mapped));

	ft_lstclear(&a, del);
	ft_lstclear(&mapped, del);

	TEST_ASSERT_NULL(a);
	TEST_ASSERT_NULL(mapped);

	ft_lstadd_back(NULL, NULL);
	ft_lstadd_front(NULL, NULL);
	ft_lstclear(NULL, NULL);
	ft_lstdelone(NULL, NULL);
	ft_lstiter(NULL, NULL);
	ft_lstmap(NULL, NULL, NULL);
}

void test_ft_mem_all_extreme(void)
{
    char buffer1[20];
    char buffer2[20];
    char buffer3[20];
    char buffer4[20];
    char *ptr;

    for (int i = 0; i < 20; i++) buffer1[i] = (char)(i + 1);
    for (int i = 0; i < 20; i++) buffer2[i] = (char)(i + 2);
    for (int i = 0; i < 20; i++) buffer3[i] = (char)(i + 3);
    for (int i = 0; i < 20; i++) buffer4[i] = (char)(i + 4);

    ptr = ft_memchr(buffer1, 5, 20);
    TEST_ASSERT_NOT_NULL(ptr);
    TEST_ASSERT_EQUAL(5, *ptr);

    TEST_ASSERT_EQUAL(0, ft_memcmp(buffer1, buffer1, 20));
    TEST_ASSERT(ft_memcmp(buffer1, buffer2, 20) != 0);

    ft_memcpy(buffer3, buffer1, 20);
    TEST_ASSERT_EQUAL_MEMORY(buffer1, buffer3, 20);

    ft_memmove(buffer4 + 2, buffer4, 18);
    TEST_ASSERT_EQUAL(buffer4[2], 4);
    TEST_ASSERT_EQUAL(buffer4[19], 21);

    ft_memset(buffer1, 0, 20);
    for (int i = 0; i < 20; i++) TEST_ASSERT_EQUAL(0, buffer1[i]);

    FILE *tmp = tmpfile();
    TEST_ASSERT_NOT_NULL(tmp);
    ft_putchar_fd('X', fileno(tmp));
    fseek(tmp, 0, SEEK_SET);
    char c = fgetc(tmp);
    TEST_ASSERT_EQUAL('X', c);
    fclose(tmp);

    // Extreme edge cases
    TEST_ASSERT_NULL(ft_memchr(buffer1, 1, 0));
    TEST_ASSERT_EQUAL(0, ft_memcmp(buffer1, buffer2, 0));

    char empty[1];
    ft_memcpy(empty, buffer1, 0);
    ft_memmove(empty, buffer2, 0);
    ft_memset(empty, 0, 0);
}
void test_ft_put_fd_extreme(void)
{
    FILE *tmp = tmpfile();
    TEST_ASSERT_NOT_NULL(tmp);

    ft_putchar_fd('A', fileno(tmp));
    ft_putendl_fd("BCD", fileno(tmp));
    ft_putnbr_fd(12345, fileno(tmp));
    ft_putstr_fd("XYZ", fileno(tmp));

    fseek(tmp, 0, SEEK_SET);
    char read_buf[50] = {0};
    size_t n = fread(read_buf, 1, 50, tmp);
    TEST_ASSERT(n > 0);

    // check expected content
    char expected[50];
    snprintf(expected, 50, "A""BCD\n""12345""XYZ");
    for (size_t i = 0; i < n; i++)
        TEST_ASSERT_EQUAL(expected[i], read_buf[i]);

    fclose(tmp);

    // extreme edge: empty strings, negative numbers
    tmp = tmpfile();
    TEST_ASSERT_NOT_NULL(tmp);
    ft_putendl_fd("", fileno(tmp));
    ft_putnbr_fd(-99999, fileno(tmp));
    fseek(tmp, 0, SEEK_SET);
    memset(read_buf, 0, 50);
    n = fread(read_buf, 1, 50, tmp);
    TEST_ASSERT(n > 0);
    fclose(tmp);
}

void test_ft_split()
{
	char **result;

	result = ft_split("a,b,c", ',');
	TEST_ASSERT_NOT_NULL(result);
	TEST_ASSERT_EQUAL_STRING("a", result[0]);
	TEST_ASSERT_EQUAL_STRING("b", result[1]);
	TEST_ASSERT_EQUAL_STRING("c", result[2]);
	TEST_ASSERT_NULL(result[3]);
	for (int i = 0; result[i]; i++) free(result[i]);
	free(result);

	result = ft_split("", ',');
	TEST_ASSERT_NOT_NULL(result);
	TEST_ASSERT_NULL(result[0]);
	free(result);

	result = ft_split(NULL, ',');
	TEST_ASSERT_NULL(result);

	result = ft_split(",,,", ',');
	TEST_ASSERT_NOT_NULL(result);
	TEST_ASSERT_NULL(result[0]);
	free(result);

	result = ft_split("a,,b,,,c", ',');
	TEST_ASSERT_NOT_NULL(result);
	TEST_ASSERT_EQUAL_STRING("a", result[0]);
	TEST_ASSERT_EQUAL_STRING("b", result[1]);
	TEST_ASSERT_EQUAL_STRING("c", result[2]);
	TEST_ASSERT_NULL(result[3]);
	for (int i = 0; result[i]; i++) free(result[i]);
	free(result);
}
void test_ft_strchr()
{
    TEST_ASSERT_EQUAL_STRING("world", ft_strchr("helloworld", 'w'));
    TEST_ASSERT_EQUAL_STRING("ello", ft_strchr("hello", 'e'));
    TEST_ASSERT_EQUAL_STRING("a", ft_strchr("a", 'a'));
    TEST_ASSERT_EQUAL_STRING("o", ft_strchr("hello", 'o'));
    TEST_ASSERT_NULL(ft_strchr("hello", 'x'));
    TEST_ASSERT_EQUAL_STRING("hhello", ft_strchr("hhello", 'h'));
    TEST_ASSERT_EQUAL_STRING("", ft_strchr("hello", '\0'));
    TEST_ASSERT_NULL(ft_strchr("", 'a'));
    TEST_ASSERT_EQUAL_STRING("", ft_strchr("", '\0'));
    TEST_ASSERT_EQUAL_STRING("llllo", ft_strchr("helllo", 'l'));
    TEST_ASSERT_EQUAL_STRING(" world!", ft_strchr("hello world!", ' '));
    TEST_ASSERT_EQUAL_STRING("@world", ft_strchr("@world", '@'));
    TEST_ASSERT_EQUAL_STRING("1234", ft_strchr("01234", '1'));
    TEST_ASSERT_EQUAL_STRING("!end", ft_strchr("start!end", '!'));

    char big[1000];
    for (int i = 0; i < 999; i++) big[i] = 'a';
    big[999] = '\0';
    TEST_ASSERT_EQUAL_STRING(big, ft_strchr(big, 'a'));
}
void test_ft_strdup()
{
	TEST_ASSERT_EQUAL_STRING("hello", ft_strdup("hello"));
	TEST_ASSERT_EQUAL_STRING("world!", ft_strdup("world!"));
	TEST_ASSERT_EQUAL_STRING("a", ft_strdup("a"));
	TEST_ASSERT_EQUAL_STRING("", ft_strdup(""));
	TEST_ASSERT_EQUAL_STRING("hello world", ft_strdup("hello world"));
	TEST_ASSERT_EQUAL_STRING("   ", ft_strdup("   "));
	TEST_ASSERT_EQUAL_STRING("!@#$%^&*()", ft_strdup("!@#$%^&*()"));
	TEST_ASSERT_EQUAL_STRING("\n\t\r", ft_strdup("\n\t\r"));

	char long_str[1000];
	for (int i = 0; i < 999; i++) long_str[i] = 'x';
	long_str[999] = '\0';
	TEST_ASSERT_EQUAL_STRING(long_str, ft_strdup(long_str));

	char *s1 = ft_strdup("test");
	TEST_ASSERT_NOT_EQUAL(s1, "test");
	free(s1);
}
void to_upper(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

void add_index(unsigned int i, char *c)
{
    *c = *c + i;
}

void test_ft_striteri(void)
{
    char str1[] = "hello";
    char str2[] = "abcde";

    ft_striteri(str1, to_upper);
    TEST_ASSERT_EQUAL_STRING("HELLO", str1);

    ft_striteri(str2, add_index);
    TEST_ASSERT_EQUAL_STRING("acegi", str2);

    char empty[] = "";
    ft_striteri(empty, to_upper);
    TEST_ASSERT_EQUAL_STRING("", empty);

    char single[] = "a";
    ft_striteri(single, to_upper);
    TEST_ASSERT_EQUAL_STRING("A", single);
}
void test_ft_strjoin()
{
	const char *tests[] = {
		"", "a", "b", "hello", "world", "123", "!@#", " \t\n", "longstringlongstringlongstring"
	};
	const int n = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char *joined = ft_strjoin(tests[i], tests[j]);

			int expected_len = strlen(tests[i]) + strlen(tests[j]);
			char *expected = malloc(expected_len + 1);
			strcpy(expected, tests[i]);
			strcat(expected, tests[j]);

			TEST_ASSERT_EQUAL_STRING(expected, joined);

			free(joined);
			free(expected);
		}
	}

	// Very long strings
	char *long1 = malloc(1000);
	char *long2 = malloc(1000);
	for (int i = 0; i < 999; i++)
	{
		long1[i] = 'x';
		long2[i] = 'y';
	}
	long1[999] = '\0';
	long2[999] = '\0';

	char *joined = ft_strjoin(long1, long2);
	for (int i = 0; i < 999; i++) TEST_ASSERT_EQUAL_CHAR('x', joined[i]);
	for (int i = 0; i < 999; i++) TEST_ASSERT_EQUAL_CHAR('y', joined[i+999]);

	free(long1);
	free(long2);
	free(joined);
}
void test_ft_strlcat()
{
	char dest[20];
	size_t ret;

	strcpy(dest, "hello");
	ret = ft_strlcat(dest, "world", sizeof(dest));
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen("helloworld"), (unsigned int)ret);
	TEST_ASSERT_EQUAL_STRING("helloworld", dest);

	strcpy(dest, "hello");
	ret = ft_strlcat(dest, "", sizeof(dest));
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen("hello"), (unsigned int)ret);
	TEST_ASSERT_EQUAL_STRING("hello", dest);

	dest[0] = '\0';
	ret = ft_strlcat(dest, "world", sizeof(dest));
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen("world"), (unsigned int)ret);
	TEST_ASSERT_EQUAL_STRING("world", dest);

	strcpy(dest, "hello");
	ret = ft_strlcat(dest, "world", 3);
	TEST_ASSERT_EQUAL_UINT((unsigned int)(strlen("hello") + strlen("world")), (unsigned int)ret);
	TEST_ASSERT_EQUAL_STRING("hello", dest);

	strcpy(dest, "hi");
	ret = ft_strlcat(dest, "there", 3);
	TEST_ASSERT_EQUAL_UINT((unsigned int)(strlen("hi") + strlen("there")), (unsigned int)ret);
	TEST_ASSERT_EQUAL_STRING("hit", dest);

	strcpy(dest, "abc");
	ret = ft_strlcat(dest, "def", 0);
	TEST_ASSERT_EQUAL_UINT((unsigned int)(strlen("abc") + strlen("def")), (unsigned int)ret);
	TEST_ASSERT_EQUAL_STRING("abc", dest);

	strcpy(dest, "1234");
	ret = ft_strlcat(dest, "567", 8);
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen("1234567"), (unsigned int)ret);
	TEST_ASSERT_EQUAL_STRING("1234567", dest);

	strcpy(dest, "12345");
	ret = ft_strlcat(dest, "6789", 8);
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen("123456789"), (unsigned int)ret);
	TEST_ASSERT_EQUAL_STRING("1234567", dest);

	char long_dest[2000];
	char long_src[2000];
	for (int i = 0; i < 1999; i++)
	{
		long_dest[i] = 'A';
		long_src[i] = 'B';
	}
	long_dest[1999] = '\0';
	long_src[1999] = '\0';

	ret = ft_strlcat(long_dest, long_src, sizeof(long_dest));
	TEST_ASSERT_EQUAL_UINT((unsigned int)(1999 + 1999), (unsigned int)ret);
	for (int i = 0; i < 1999; i++) TEST_ASSERT_EQUAL_CHAR('A', long_dest[i]);
	TEST_ASSERT_EQUAL_CHAR('\0', long_dest[1999]);
}
void test_ft_strlcpy()
{
	char dest[20];
	size_t ret;

	// Normal copy
	ret = ft_strlcpy(dest, "hello", sizeof(dest));
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen("hello"), (unsigned int)ret);
	TEST_ASSERT_EQUAL_STRING("hello", dest);

	// Empty src
	ret = ft_strlcpy(dest, "", sizeof(dest));
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen(""), (unsigned int)ret);
	TEST_ASSERT_EQUAL_STRING("", dest);

	// dest size smaller than src length
	ret = ft_strlcpy(dest, "world", 3);
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen("world"), (unsigned int)ret);
	TEST_ASSERT_EQUAL_STRING("wo", dest);

	// dest size exactly 1 (only room for null terminator)
	ret = ft_strlcpy(dest, "abc", 1);
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen("abc"), (unsigned int)ret);
	TEST_ASSERT_EQUAL_STRING("", dest);

	// dest size zero
	ret = ft_strlcpy(dest, "abc", 0);
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen("abc"), (unsigned int)ret);
	// dest unchanged, cannot assert string content

	// Empty dest
	char empty[1];
	ret = ft_strlcpy(empty, "x", sizeof(empty));
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen("x"), (unsigned int)ret);
	TEST_ASSERT_EQUAL_STRING("x", empty);

	// Long strings
	char long_src[2000];
	char long_dest[2000];
	for (int i = 0; i < 1999; i++)
		long_src[i] = 'A';
	long_src[1999] = '\0';

	ret = ft_strlcpy(long_dest, long_src, sizeof(long_dest));
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen(long_src), (unsigned int)ret);
	for (int i = 0; i < 1999; i++) TEST_ASSERT_EQUAL_CHAR('A', long_dest[i]);
	TEST_ASSERT_EQUAL_CHAR('\0', long_dest[1999]);
}
void test_ft_strlen()
{
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen("hello"), (unsigned int)ft_strlen("hello"));
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen(""), (unsigned int)ft_strlen(""));
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen("a"), (unsigned int)ft_strlen("a"));
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen(" "), (unsigned int)ft_strlen(" "));
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen("1234567890"), (unsigned int)ft_strlen("1234567890"));
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen("!@#$%^&*()_+-=[]{}|;:'\",.<>/?"), 
												(unsigned int)ft_strlen("!@#$%^&*()_+-=[]{}|;:'\",.<>/?"));
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen("\n\t\r"), (unsigned int)ft_strlen("\n\t\r"));

	char long_str[2000];
	for (int i = 0; i < 1999; i++)
		long_str[i] = 'x';
	long_str[1999] = '\0';
	TEST_ASSERT_EQUAL_UINT((unsigned int)strlen(long_str), (unsigned int)ft_strlen(long_str));
}

char map_to_upper(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

char map_add_index(unsigned int i, char c)
{
    return c + i;
}

void test_ft_strmapi(void)
{
    char *result;

    result = ft_strmapi("hello", map_to_upper);
    TEST_ASSERT_EQUAL_STRING("HELLO", result);
    free(result);

    result = ft_strmapi("abcde", map_add_index);
    TEST_ASSERT_EQUAL_STRING("acegi", result);
    free(result);

    result = ft_strmapi("", map_to_upper);
    TEST_ASSERT_EQUAL_STRING("", result);
    free(result);

    result = ft_strmapi("a", map_to_upper);
    TEST_ASSERT_EQUAL_STRING("A", result);
    free(result);

    result = ft_strmapi("xyz", map_add_index);
    TEST_ASSERT_EQUAL_STRING("xza", result);
    free(result);

    char long_str[1000];
    for (int i = 0; i < 999; i++)
        long_str[i] = 'a';
    long_str[999] = '\0';

    result = ft_strmapi(long_str, map_add_index);
    for (int i = 0; i < 999; i++)
        TEST_ASSERT_EQUAL_CHAR('a' + i, result[i]);
    free(result);
}
void test_ft_strncmp()
{
	TEST_ASSERT_EQUAL_INT(strncmp("hello", "hello", 5), ft_strncmp("hello", "hello", 5));
	TEST_ASSERT_EQUAL_INT(strncmp("hello", "hell", 5), ft_strncmp("hello", "hell", 5));
	TEST_ASSERT_EQUAL_INT(strncmp("hell", "hello", 5), ft_strncmp("hell", "hello", 5));
	TEST_ASSERT_EQUAL_INT(strncmp("abc", "abd", 3), ft_strncmp("abc", "abd", 3));
	TEST_ASSERT_EQUAL_INT(strncmp("abc", "abd", 2), ft_strncmp("abc", "abd", 2));
	TEST_ASSERT_EQUAL_INT(strncmp("abc", "abc", 0), ft_strncmp("abc", "abc", 0));
	TEST_ASSERT_EQUAL_INT(strncmp("", "", 1), ft_strncmp("", "", 1));
	TEST_ASSERT_EQUAL_INT(strncmp("a", "", 1), ft_strncmp("a", "", 1));
	TEST_ASSERT_EQUAL_INT(strncmp("", "a", 1), ft_strncmp("", "a", 1));

	char long1[1000];
	char long2[1000];
	for (int i = 0; i < 999; i++)
	{
		long1[i] = 'a';
		long2[i] = 'a';
	}
	long1[999] = '\0';
	long2[999] = '\0';
	TEST_ASSERT_EQUAL_INT(strncmp(long1, long2, 999), ft_strncmp(long1, long2, 999));

	long2[500] = 'b';
	TEST_ASSERT_EQUAL_INT(strncmp(long1, long2, 1000), ft_strncmp(long1, long2, 1000));
}
const char *my_strnstr(const char *haystack, const char *needle, size_t n)
{
    size_t needle_len;

    if (!*needle)
        return haystack;

    needle_len = strlen(needle);
    for (size_t i = 0; i + needle_len <= n && haystack[i]; i++)
    {
        if (strncmp(haystack + i, needle, needle_len) == 0)
            return haystack + i;
    }
    return NULL;
}

void test_ft_strnstr_extreme(void)
{
    TEST_ASSERT_EQUAL_STRING(my_strnstr("hello world", "hello", 11), ft_strnstr("hello world", "hello", 11));
    TEST_ASSERT_EQUAL_STRING(my_strnstr("hello world", "world", 11), ft_strnstr("hello world", "world", 11));
    TEST_ASSERT_EQUAL_STRING(my_strnstr("hello world", "world", 5), ft_strnstr("hello world", "world", 5));
    TEST_ASSERT_EQUAL_STRING(my_strnstr("hello world", "", 5), ft_strnstr("hello world", "", 5));
    TEST_ASSERT_EQUAL_STRING(my_strnstr("", "a", 1), ft_strnstr("", "a", 1));
    TEST_ASSERT_EQUAL_STRING(my_strnstr("", "", 0), ft_strnstr("", "", 0));
    TEST_ASSERT_EQUAL_STRING(my_strnstr("abc", "d", 3), ft_strnstr("abc", "d", 3));
    TEST_ASSERT_EQUAL_STRING(my_strnstr("abcabcabc", "cab", 9), ft_strnstr("abcabcabc", "cab", 9));
    TEST_ASSERT_EQUAL_STRING(my_strnstr("abcabcabc", "cab", 7), ft_strnstr("abcabcabc", "cab", 7));

    char long_hay[1000];
    char long_needle[100];
    for (int i = 0; i < 999; i++) long_hay[i] = 'a';
    long_hay[999] = '\0';
    for (int i = 0; i < 99; i++) long_needle[i] = 'a';
    long_needle[99] = '\0';

    TEST_ASSERT_EQUAL_STRING(my_strnstr(long_hay, long_needle, 1000), ft_strnstr(long_hay, long_needle, 1000));

    long_needle[50] = 'b';
    TEST_ASSERT_EQUAL_STRING(my_strnstr(long_hay, long_needle, 1000), ft_strnstr(long_hay, long_needle, 1000));
}
void test_ft_strrchr()
{
	TEST_ASSERT_EQUAL_STRING(strrchr("hello world", 'l'), ft_strrchr("hello world", 'l'));
	TEST_ASSERT_EQUAL_STRING(strrchr("hello world", 'h'), ft_strrchr("hello world", 'h'));
	TEST_ASSERT_EQUAL_STRING(strrchr("hello world", 'd'), ft_strrchr("hello world", 'd'));
	TEST_ASSERT_EQUAL_STRING(strrchr("hello world", 'x'), ft_strrchr("hello world", 'x'));
	TEST_ASSERT_EQUAL_STRING(strrchr("aaaaaa", 'a'), ft_strrchr("aaaaaa", 'a'));
	TEST_ASSERT_EQUAL_STRING(strrchr("abcabcabc", 'c'), ft_strrchr("abcabcabc", 'c'));
	TEST_ASSERT_EQUAL_STRING(strrchr("", 'a'), ft_strrchr("", 'a'));
	TEST_ASSERT_EQUAL_STRING(strrchr("a", 'a'), ft_strrchr("a", 'a'));
	TEST_ASSERT_EQUAL_STRING(strrchr("abc\0def", 'd'), ft_strrchr("abc\0def", 'd'));
	TEST_ASSERT_EQUAL_STRING(strrchr("hello\0", '\0'), ft_strrchr("hello\0", '\0'));

	char long_str[1000];
	for (int i = 0; i < 999; i++)
		long_str[i] = 'x';
	long_str[999] = '\0';
	TEST_ASSERT_EQUAL_STRING(strrchr(long_str, 'x'), ft_strrchr(long_str, 'x'));
	TEST_ASSERT_EQUAL_STRING(strrchr(long_str, 'y'), ft_strrchr(long_str, 'y'));
}
void test_ft_strtrim()
{
	char *result;

	result = ft_strtrim("   hello   ", " ");
	TEST_ASSERT_EQUAL_STRING("hello", result);
	free(result);

	result = ft_strtrim("xxabcxx", "x");
	TEST_ASSERT_EQUAL_STRING("abc", result);
	free(result);

	result = ft_strtrim("!!@@test@@!!", "!@");
	TEST_ASSERT_EQUAL_STRING("test", result);
	free(result);

	result = ft_strtrim("hello", "");
	TEST_ASSERT_EQUAL_STRING("hello", result);
	free(result);

	result = ft_strtrim("", "abc");
	TEST_ASSERT_EQUAL_STRING("", result);
	free(result);

	result = ft_strtrim("   ", " ");
	TEST_ASSERT_EQUAL_STRING("", result);
	free(result);

	result = ft_strtrim("abc", "abc");
	TEST_ASSERT_EQUAL_STRING("", result);
	free(result);

	result = ft_strtrim("  a  ", " ");
	TEST_ASSERT_EQUAL_STRING("a", result);
	free(result);

	char long_str[1000];
	for (int i = 0; i < 999; i++) long_str[i] = 'x';
	long_str[999] = '\0';

	result = ft_strtrim(long_str, "x");
	TEST_ASSERT_EQUAL_STRING("", result);
	free(result);

	result = ft_strtrim(long_str, "");
	TEST_ASSERT_EQUAL_STRING(long_str, result);
	free(result);
}
void test_ft_substr()
{
	char *result;

	result = ft_substr("hello world", 0, 5);
	TEST_ASSERT_EQUAL_STRING("hello", result);
	free(result);

	result = ft_substr("hello world", 6, 5);
	TEST_ASSERT_EQUAL_STRING("world", result);
	free(result);

	result = ft_substr("hello", 0, 10);
	TEST_ASSERT_EQUAL_STRING("hello", result);
	free(result);

	result = ft_substr("hello", 5, 5);
	TEST_ASSERT_EQUAL_STRING("", result);
	free(result);

	result = ft_substr("", 0, 5);
	TEST_ASSERT_EQUAL_STRING("", result);
	free(result);

	result = ft_substr("abc", 1, 0);
	TEST_ASSERT_EQUAL_STRING("", result);
	free(result);

	result = ft_substr("abc", 0, 0);
	TEST_ASSERT_EQUAL_STRING("", result);
	free(result);

	result = ft_substr("abc", 2, 1);
	TEST_ASSERT_EQUAL_STRING("c", result);
	free(result);

	char long_str[1000];
	for (int i = 0; i < 999; i++) long_str[i] = 'x';
	long_str[999] = '\0';

	result = ft_substr(long_str, 500, 400);
	for (int i = 0; i < 400; i++) TEST_ASSERT_EQUAL_CHAR('x', result[i]);
	TEST_ASSERT_EQUAL_CHAR('\0', result[400]);
	free(result);

	result = ft_substr(long_str, 999, 10);
	TEST_ASSERT_EQUAL_STRING("", result);
	free(result);
}


void test_ft_tolower(void)
{
    for (int i = 0; i <= 127; i++)
    {
        TEST_ASSERT_EQUAL_INT(tolower(i), ft_tolower(i));
    }
}

void test_ft_toupper(void)
{
    for (int i = 0; i <= 127; i++)
    {
        TEST_ASSERT_EQUAL_INT(toupper(i), ft_toupper(i));
    }
}

//
// ─── MAIN ───────────────────────────────────────────────────────────────
//
int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_ft_atoi);
	RUN_TEST(test_ft_calloc);
	RUN_TEST(test_ft_isalnum);
	RUN_TEST(test_ft_isalpha);
	RUN_TEST(test_ft_isascii);
	RUN_TEST(test_ft_isdigit);
	RUN_TEST(test_ft_isprint);
	RUN_TEST(test_ft_itoa);
	RUN_TEST(test_ft_lst_all_extreme);
	RUN_TEST(test_ft_mem_all_extreme);
	RUN_TEST(test_ft_put_fd_extreme);
	RUN_TEST(test_ft_split);
	RUN_TEST(test_ft_strchr);
	RUN_TEST(test_ft_strdup);
	RUN_TEST(test_ft_striteri);
	RUN_TEST(test_ft_strjoin);
	RUN_TEST(test_ft_strlcat);
	RUN_TEST(test_ft_strlcpy);
	RUN_TEST(test_ft_strlen);
	RUN_TEST(test_ft_strmapi);
	RUN_TEST(test_ft_strncmp);
	RUN_TEST(test_ft_strnstr_extreme);
	RUN_TEST(test_ft_strrchr);
	RUN_TEST(test_ft_strtrim);
	RUN_TEST(test_ft_substr);
	RUN_TEST(test_ft_tolower);
	RUN_TEST(test_ft_toupper);
	return UNITY_END();
}
