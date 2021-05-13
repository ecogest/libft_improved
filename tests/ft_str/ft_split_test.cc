#include <gtest/gtest.h>

extern "C" {
#include "libft.h"
}

#include <climits>
#include <iostream>
#include <vector>
#include <tuple>

/*
** ================================ Fixture ================================= **
*/

struct FtSplitTest: public ::testing::TestWithParam<std::tuple<const char *, char, std::vector<const char *>>> {
	// Params
	const char			*test_input;
	char				separator;
	const char	*const	*expected_tab;
	// Return
	char				**ret_tab;
	// Constructor
	FtSplitTest() {
	}
	// Create the array
	void init(const char *str = NULL, char sep = ' ', std::vector<const char *>v = {})
	{
		test_input         = str;
		separator          = sep;
		this->expected_tab = v.data();
		ret_tab            = ft_split(test_input, separator);
	}
	// Run the test
	void test() {
	char		*str_ret;
	const char	*str_expected;
	size_t		i;

	if (!ret_tab)
		EXPECT_EQ(ret_tab, expected_tab);            // CASE OF NULL RETURN
	else
	{
		i = 0;
		while (1)
		{
			str_ret      = ret_tab[i];
			str_expected = expected_tab[i];
			if (!expected_tab[i])
				EXPECT_EQ(str_ret, str_expected);    // CHECK THE LAST NULL COMPONENT
			else
				EXPECT_STREQ(str_ret, str_expected); // CMP STRINGS OF THE RETURNED TABLE AND THE EXPECTED ONE
			if (!expected_tab[i])
				break ;
			i++;
		}
	}
	}
	// Destructor
	~FtSplitTest() {
		if (!ret_tab)
			return ;
		size_t	i;
		i = 0;
		while (ret_tab[i])
		{
			free(ret_tab[i]);
			i++;
		}
		free(ret_tab);
	}
};

/*
** =========================== Parametrized Tests =========================== **
*/

TEST_P(FtSplitTest, all) {
	init(std::get<0>(GetParam()), std::get<1>(GetParam()), std::get<2>(GetParam()));
	test();
}

#define P std::make_tuple<const char *, char, std::vector<const char *>>

INSTANTIATE_TEST_SUITE_P(FtSplitParamTest, FtSplitTest, testing::Values(
			/* Classic Tests */
			P("h", ' ', { "h", NULL }),                                    // One letter
			P("hello", ' ', { "hello", NULL }),                            // One word
			P("hello world", ' ', { "hello", "world", NULL }),             // two words
			P("hello world ", ' ', { "hello", "world", NULL }),            // sep ended
			P(" hello world", ' ', { "hello", "world", NULL }),            // sep started
			P(" hello world ", ' ', { "hello", "world", NULL }),           // sep started and ended
			P("    hello world        ", ' ', { "hello", "world", NULL }), // multi sep started and ended
			P("hello world", 'l', { "he", "o wor", "d", NULL }),           // other sep char
			/* Long string tests */
			P("helllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllo wooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooorld", ' ', { "helllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllo", "wooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooorld", NULL }), // two words
			/* Empty Value Tests */
			P("", ' ', { NULL }),               // Empty string (see Basic Test section for NULL string)
			P(" ", ' ', { NULL }),              // String of one sep char
			P("xxxxxxxxx", 'x', { NULL }),      // Only sep chars
			/* Tricky tests */
			P("hello", '\0', { "hello", NULL }) // Sep is Null char
			));

/*
** ============================== Basic Tests =============================== **
*/

TEST(FtSplitTest, Null)
{
	EXPECT_EQ(ft_split(NULL, ' '), (char **)NULL);
	// EXPECT_EQ(*ft_split("", ' '), (char *)NULL); // test would leak, use fixture instead
}

/*
** ========================= Classic fixture tests ========================== **
*/


// TEST_F(FtSplitTest, empty) {
// 	init();
// 	test();
// }
//
// TEST_F(FtSplitTest, nothingToSplit) {
// 	init("hello", ' ', { "hello", NULL });
// 	test();
// }
//
// TEST_F(FtSplitTest, oneSplit) {
// 	init("hello world", ' ', { "hello", "world", NULL });
// 	test();
// }
