#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <fstream>
#include <string>
#include <stack>


extern "C" {
#include "../app/common.h"
#include "../app/text.h"
#include "../app/_text.h"
}

TEST(mcb, suite1) {
    text txt = create_text();
    load(txt, "./tests/test_input1.txt");

    move(txt, 0, 2);

    mcb(txt);

    EXPECT_EQ(txt -> cursor -> position, 1);
}

TEST(mcb, suite2) {
    text txt = create_text();
    load(txt, "./tests/test_input1.txt");

    move(txt, 1, 4);

    mcb(txt);

    EXPECT_EQ(txt -> cursor -> position, 3);
}

TEST(mcb, suite3) {
    text txt = create_text();
    load(txt, "./tests/test_input1.txt");

    move(txt, 0, 0);

    mcb(txt);

    EXPECT_EQ(txt -> cursor -> position, 0);
}

TEST(showrev, suite1) {
    text txt = create_text();

    testing::internal::CaptureStderr();

    showrev(txt);

    std::string output = testing::internal::GetCapturedStderr();

    EXPECT_EQ(output, "There are already no any lines in the text!\n");
}

TEST(showrev, suite2) {
    text txt = create_text();
    load(txt, "./tests/test_input3.txt");
    
    std::string tmp;
    std::stack<std::string> st;
    int k = 0;

    testing::internal::CaptureStdout();
    
    showrev(txt);

    std::string output = testing::internal::GetCapturedStdout();

    // std::cout << output << std::endl;
    for (int i = 0; i < output.size(); i++) {
        if (output[i] == '\n') {
            st.push(tmp); 
            tmp = ""; 
            continue;
        } else {
            tmp += output[i];
        }
    }

    
    int i = 1;

    while(!st.empty()) {
        tmp = st.top(); st.pop();
        EXPECT_EQ((tmp[0] - '0'), i);
        i++;
    }
    EXPECT_EQ(i - 1, txt -> length);
    // SUCCEED();
}

TEST(rt, suite1) {
    text txt = create_text();

    load(txt, "./tests/test_input3.txt");

    rt(txt);
    EXPECT_EQ(txt->end->contents[0], '2');
}

TEST(rt, suite2) {
    text txt = create_text();
    testing::internal::CaptureStderr();
    
    rt(txt);

    std::string output = testing::internal::GetCapturedStderr();

    EXPECT_EQ(output, "There are already no any lines in the text!\n");   
}
