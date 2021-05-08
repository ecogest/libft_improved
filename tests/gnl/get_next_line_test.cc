/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.cc                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:02:43 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/08 22:55:05 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include <iostream>

extern "C" {
#include "get_next_line.h"
#include "../gnl/get_next_line_priv.h"
}

/*
** ================================ Fixture ================================= **
*/

struct GnlTest: public ::testing::Test {
	const char	*input;
	char		*read_line;
	int			ret;
	FILE	*file;
	int		fd;
	GnlTest(): read_line (nullptr) {
		file = tmpfile();
		fd = fileno(file);
	}
	void init(const char *input) {
		this->input = input;
		write(fd, input, strlen(input));
		lseek(fd, 0, SEEK_SET);
		gnl();
	}
	void gnl() {
		free(read_line);
		ret = get_next_line(fd, &read_line);
	}
	~GnlTest() {
		free(read_line);
		fclose(file);
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

TEST(GnlTestError, BadFd) {
	char	*s = NULL;
	EXPECT_EQ(get_next_line(-1, &s), -1);
}

TEST(GnlTestError, BadFd2) {
	char	*s = NULL;
	close(42);
	EXPECT_EQ(get_next_line(42, &s), -1);
	free(s); // TODO: no need to free on error
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
			BUFFER_SIZE - (BUFFER_SIZE > 2 ? 2 : 0),
			BUFFER_SIZE - (BUFFER_SIZE > 1 ? 1 : 1),
			BUFFER_SIZE,
			BUFFER_SIZE + 1,
			BUFFER_SIZE + 2,
			42,
			442,
			4442,
			44442
			));
