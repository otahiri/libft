#include "unity.h"
#include "libft.h"

void setUp(void) {}
void tearDown(void) {}

//
// ─── CHARACTER FUNCTIONS ───────────────────────────────────────────────
//
void test_isalpha(void)
{
	TEST_ASSERT_TRUE(ft_isalpha('A'));
	TEST_ASSERT_TRUE(ft_isalpha('z'));
	TEST_ASSERT_FALSE(ft_isalpha('1'));
	TEST_ASSERT_FALSE(ft_isalpha('-'));
}

void test_isdigit(void)
{
	TEST_ASSERT_TRUE(ft_isdigit('9'));
	TEST_ASSERT_FALSE(ft_isdigit('a'));
}

void test_isalnum(void)
{
	TEST_ASSERT_TRUE(ft_isalnum('5'));
	TEST_ASSERT_TRUE(ft_isalnum('X'));
	TEST_ASSERT_FALSE(ft_isalnum('$'));
}

void test_isascii(void)
{
	TEST_ASSERT_TRUE(ft_isascii(65));
	TEST_ASSERT_FALSE(ft_isascii(200));
}

void test_isprint(void)
{
	TEST_ASSERT_TRUE(ft_isprint(' '));
	TEST_ASSERT_FALSE(ft_isprint(10)); // newline
}

void test_toupper_tolower(void)
{
	TEST_ASSERT_EQUAL('A', ft_toupper('a'));
	TEST_ASSERT_EQUAL('a', ft_tolower('A'));
}

//
// ─── STRING FUNCTIONS ───────────────────────────────────────────────────
//
void test_strlen(void)
{
	TEST_ASSERT_EQUAL(5, ft_strlen("Hello"));
}

void test_strdup(void)
{
	char *s = ft_strdup("abc");
	TEST_ASSERT_EQUAL_STRING("abc", s);
	free(s);
}

void test_strjoin(void)
{
	char *s = ft_strjoin("foo", "bar");
	TEST_ASSERT_EQUAL_STRING("foobar", s);
	free(s);
}

void test_substr(void)
{
	char *s = ft_substr("abcdef", 2, 3);
	TEST_ASSERT_EQUAL_STRING("cde", s);
	free(s);
}

void test_strtrim(void)
{
	char *s = ft_strtrim("  hello  ", " ");
	TEST_ASSERT_EQUAL_STRING("hello", s);
	free(s);
}

void test_split(void)
{
	char **arr = ft_split("a,b,c", ',');
	TEST_ASSERT_EQUAL_STRING("a", arr[0]);
	TEST_ASSERT_EQUAL_STRING("b", arr[1]);
	TEST_ASSERT_EQUAL_STRING("c", arr[2]);
	TEST_ASSERT_NULL(arr[3]);
	for (int i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}

//
// ─── MEMORY FUNCTIONS ───────────────────────────────────────────────────
//
void test_memset_memcpy(void)
{
	char buf[10];
	ft_memset(buf, 'A', 5);
	buf[5] = '\0';
	TEST_ASSERT_EQUAL_STRING("AAAAA", buf);

	char dest[10];
	ft_memcpy(dest, buf, 6);
	TEST_ASSERT_EQUAL_STRING("AAAAA", dest);
}

void test_memcmp(void)
{
	TEST_ASSERT_EQUAL(0, ft_memcmp("abc", "abc", 3));
	TEST_ASSERT_NOT_EQUAL(0, ft_memcmp("abc", "abd", 3));
}

//
// ─── ITOA AND ATOI ──────────────────────────────────────────────────────
//
void test_itoa_atoi(void)
{
	TEST_ASSERT_EQUAL_STRING("123", ft_itoa(123));
	TEST_ASSERT_EQUAL(-42, ft_atoi("   -42"));
}

//
// ─── LINKED LIST FUNCTIONS ──────────────────────────────────────────────
//
void test_lst_functions(void)
{
	t_list *a = ft_lstnew("x");
	t_list *b = ft_lstnew("y");
	ft_lstadd_back(&a, b);

	TEST_ASSERT_EQUAL(2, ft_lstsize(a));
	TEST_ASSERT_EQUAL_PTR(b, ft_lstlast(a));

	ft_lstdelone(b, NULL);
	ft_lstclear(&a, NULL);
	TEST_ASSERT_NULL(a);
}

//
// ─── MAIN ───────────────────────────────────────────────────────────────
//
int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_isalpha);
	RUN_TEST(test_isdigit);
	RUN_TEST(test_isalnum);
	RUN_TEST(test_isascii);
	RUN_TEST(test_isprint);
	RUN_TEST(test_toupper_tolower);

	RUN_TEST(test_strlen);
	RUN_TEST(test_strdup);
	RUN_TEST(test_strjoin);
	RUN_TEST(test_substr);
	RUN_TEST(test_strtrim);
	RUN_TEST(test_split);

	RUN_TEST(test_memset_memcpy);
	RUN_TEST(test_memcmp);

	RUN_TEST(test_itoa_atoi);

	RUN_TEST(test_lst_functions);

	return UNITY_END();
}
