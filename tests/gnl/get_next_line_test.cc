/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.cc                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:02:43 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/15 18:14:44 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include <iostream>

extern "C" {
#include "get_next_line.h"
#include "../gnl/get_next_line_priv.h"
#include <unistd.h>
}

/*
** BETTER TESTS AT THE VERY BOTTOM
*/

/*
** ================================ Fixture ================================= **
*/

struct GnlTest: public ::testing::Test {
	const char	*input;
	char		*read_line;
	int			ret;
	int		fds[2];
	GnlTest(): read_line (nullptr) {
		pipe(fds);
	}
	void init(const char *input) {
		this->input = input;
		write(fds[1], input, strlen(input));
		close(fds[1]); // If we don't close it, gnl's read will hang, waiting for EOF
		gnl();
	}
	void gnl() {
		free(read_line);
		ret = get_next_line(fds[0], &read_line);
	}
	~GnlTest() {
		free(read_line);
		close(fds[0]);
	}
};

/*
** ============================== Simple Tests ============================== **
*/

TEST_F(GnlTest, simpleLine) {
	init("hello");
	EXPECT_STREQ(input, read_line);
	EXPECT_EQ(0, ret);
	gnl();
	EXPECT_STREQ("", read_line);
	EXPECT_EQ(0, ret);
}

TEST_F(GnlTest, simpleLongLine) {
	init("12345678901234567890");
	EXPECT_STREQ(input, read_line);
	EXPECT_EQ(0, ret);
}

TEST_F(GnlTest, twoLines) {
	init("hello\nworld");
	EXPECT_STREQ("hello", read_line);
	EXPECT_EQ(1, ret);
	gnl();
	EXPECT_STREQ("world", read_line);
	EXPECT_EQ(0, ret);
	gnl();
	EXPECT_STREQ("", read_line);
	EXPECT_EQ(0, ret);
}

TEST_F(GnlTest, oneLineWithCarriage) {
	init("hello\n");
	EXPECT_STREQ("hello", read_line);
	EXPECT_EQ(1, ret);
	gnl();
	EXPECT_STREQ("", read_line);
	EXPECT_EQ(0, ret);
}

TEST_F(GnlTest, oneLineWithCarriageBefore) {
	init("\nhello");
	EXPECT_STREQ("", read_line);
	EXPECT_EQ(1, ret);
	gnl();
	EXPECT_STREQ("hello", read_line);
	EXPECT_EQ(0, ret);
}


TEST_F(GnlTest, emptyFile) {
	init("");
	EXPECT_STREQ("", read_line);
	EXPECT_EQ(0, ret);
	gnl();
	EXPECT_STREQ("", read_line);
	EXPECT_EQ(0, ret);
}

TEST_F(GnlTest, carriageOnly) {
	init("\n");
	EXPECT_STREQ("", read_line);
	EXPECT_EQ(1, ret);
	gnl();
	EXPECT_STREQ("", read_line);
	EXPECT_EQ(0, ret);
}

/*
** ============================== Error Tests =============================== **
*/

// Errors should return (-1) and NULL string

TEST(GnlTestError, BadFd) {
	char	*s = NULL;
	EXPECT_EQ(get_next_line(-1, &s), -1);
	EXPECT_EQ(s, (char *)NULL);
}

TEST(GnlTestError, BadFd2) {
	char	*s = NULL;
	close(42);
	EXPECT_EQ(get_next_line(42, &s), -1);
	EXPECT_EQ(s, (char *)NULL);
}

TEST(GnlTestError, BadPtr) {
	EXPECT_EQ(get_next_line(0, NULL), -1);
}

/* =========================== Parametrized tests =========================== */

struct GnlTestSingleLine: public ::testing::WithParamInterface<const char *>, GnlTest {
};

TEST_P(GnlTestSingleLine, tests) {
	init(GetParam());
	EXPECT_STREQ(input, read_line);
	EXPECT_EQ(0, ret);
	gnl();
	EXPECT_STREQ("", read_line);
	EXPECT_EQ(0, ret);
	// std::cout << read_line << std::endl;
}

INSTANTIATE_TEST_SUITE_P(GnlTestSingleLineSuite, GnlTestSingleLine, ::testing::Values(
			"hello",
			"world",
			"",
			"a",
			"ab",
			"abc",
			"hello\b\t\vworld",
			"😀 😃 😄 😁 😆 😅 😂 🤣 🥲 ☺️ 😊 😇 🙂 🙃 😉 😌 😍 🥰 😘 😗 😙 😚 😋 😛 😝 😜 🤪 🤨 🧐 🤓 😎 🥸 🤩 🥳 😏 😒 😞 😔 😟 😕 🙁 ☹️ 😣 😖 😫 😩 🥺 😢 😭 😤 😠 😡 🤬 🤯 😳 🥵 🥶 😱 😨 😰 😥 😓 🤗 🤔 🤭 🤫 🤥 😶 😐 😑 😬 🙄 😯 😦 😧 😮 😲 🥱 😴 🤤 😪 😵 🤐 🥴 🤢 🤮 🤧 😷 🤒 🤕 🤑 🤠 😈 👿 👹 👺 🤡 💩 👻 💀 ☠️ 👽 👾 🤖 🎃 😺 😸 😹 😻 😼 😽 🙀 😿 😾",
			"😀 😃 😄 😁 😆 🤥  💀 ☠️ 👽 👾 fésdfa🤖 🎃 😺 😸 😹 😻 😼 😽 🙀 😿 😾"
			));

/*
** ============================== GnlSizeTests ============================== **
*/

struct GnlSizeTestSingleLine: public ::testing::WithParamInterface<int>, GnlTest {
};

TEST_P(GnlSizeTestSingleLine, tests) {
	char	s[GetParam() + 1];

	memset(s, 'a', GetParam());
	s[GetParam()] = '\0';
	init(s);
	EXPECT_STREQ(input, read_line);
	EXPECT_EQ(0, ret);
	// std::cout << read_line << std::endl;
}

INSTANTIATE_TEST_SUITE_P(GnlSizeTestSingleLineSuite, GnlSizeTestSingleLine, ::testing::Values(
			1,
			2,
			3,
			GNL_BUFFER_SIZE - (GNL_BUFFER_SIZE > 2 ? 2 : 0),
			GNL_BUFFER_SIZE - (GNL_BUFFER_SIZE > 1 ? 1 : 1),
			GNL_BUFFER_SIZE,
			GNL_BUFFER_SIZE + 1,
			GNL_BUFFER_SIZE + 2,
			42,
			442,
			4442,
			44442
			));

/*
** ============================ Gnl Param Tests ============================= **
*/


struct GnlParamTest:
	public ::testing::TestWithParam<std::tuple<const char *, std::vector<const char *>>>
{
	const char	*input;
	int			fds[2];
	char		*read_line;
	int			ret_gnl;
	std::vector<const char *>	expected_lines;
	GnlParamTest():
		input          (std::get<0> (GetParam ())),
		expected_lines (std::get<1> (GetParam ())),
		read_line      (nullptr)
	{
		pipe(fds);
		write(fds[1], input, strlen(input));
		close(fds[1]);
	}
	void	gnl() {
		ret_gnl = get_next_line(fds[0], &read_line);
	}
	~GnlParamTest() {
		close(fds[0]);
	}
};

TEST_P(GnlParamTest, multiLineTests) {
	size_t	i (0);

	while (i < expected_lines.size())
	{
		free(read_line);
		gnl();
		EXPECT_STREQ(read_line, expected_lines[i]);
		if (i == expected_lines.size() - 1)
			EXPECT_EQ(ret_gnl, 0);
		else
			EXPECT_EQ(ret_gnl, 1);
		i++;
	}
	free(read_line);
}

#define P std::make_tuple<const char *, std::vector<const char *>>

INSTANTIATE_TEST_SUITE_P(GnlParamTestSuite, GnlParamTest, testing::Values(
			P("hello", { "hello" }),
			P("hello\n", { "hello", "" }),
			P("hello\nworld", { "hello", "world" }),
			P("\nhello\nworld", { "", "hello", "world" }),
			P("\nhello\n\n\n", { "", "hello", "", "", "" }),
			P("a\nBc\ndeF\nghij12\nxxklxx=é!", { "a", "Bc", "deF", "ghij12", "xxklxx=é!" }),
			P("💎\nhel🔥lo\n✨❤️‍🔥!\n🌎\nxyz", { "💎", "hel🔥lo", "✨❤️‍🔥!", "🌎", "xyz" })
			));
