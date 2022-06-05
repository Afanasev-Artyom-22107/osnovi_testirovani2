#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <stdio.h>
#include <string>
#include <fstream>

/* using namespace testing; */
extern "C" {
#include "../app/common.h"
#include "../app/text.h"
#include "../app/_text.h"
}

static char path_to_file[] = "./tests/test_input1.txt";

TEST(load, suite1) {
    text txt = create_text();
    load(txt, path_to_file);
    std::ifstream f;
    f.open(path_to_file);
    std::string s;
    std::string cur;
    node *current = txt->begin;
    EXPECT_NE(txt->begin, nullptr);
    EXPECT_NE(txt->end, nullptr);
    size_t len = txt -> length;
    int cnt = 0;
    while (std::getline(f, s))
    {
        cnt++;
        // fprintf(stderr, "%s %s\n", current->contents, s);
        cur = current -> contents;
        if (s[s.size()-1] == '\n')
            cur += "\n";
        EXPECT_EQ(cur, s);
        current = current->next;
    }
}

TEST(move_cursor, sute1) {
    text txt = create_text();
    load(txt, path_to_file);
    move(txt, 2, 3);
    EXPECT_EQ(txt->cursor->position, 3);
    int k = 0;
    node *current = txt->begin;
    while(current != txt->cursor->line)
    {
        k++;
        current = current->next;
    }
    EXPECT_EQ(k, 2);
    remove_all(txt);
}

TEST(move_cursor, sute2) {
    text txt = create_text();
    load(txt, path_to_file);
    move(txt, -3, 0);
    EXPECT_EQ(txt->cursor->position, 17); 
    int k = 0;
    node *current = txt->begin;
    while(current != txt->cursor->line)
    {
        k++;
        current = current->next;
    }
    EXPECT_EQ(k, 2);
    remove_all(txt);
}

TEST(move_cursor, sute3) {
    text txt = create_text();
    load(txt, path_to_file);
    move(txt, 15, 0);
    EXPECT_EQ(txt->cursor->position, 17);
    int k = 0;
    node *current = txt->begin;
    while(current != txt->cursor->line)
    {
        k++;
        current = current->next;
    }
    EXPECT_EQ(k, txt->length - 1);
    remove_all(txt);
}

TEST(move_cursor, sute4) {
    text txt = create_text();
    load(txt, path_to_file);
    move(txt, 2, -5);
    EXPECT_EQ(txt->cursor->position, 17);
    int k = 0;
    node *current = txt->begin;
    while(current != txt->cursor->line)
    {
        k++;
        current = current->next;
    }
    EXPECT_EQ(k, 2);
    remove_all(txt);
}


TEST(move_cursor, sute5) {
    text txt = create_text();
    load(txt, path_to_file);
    move(txt, 2, 30);
    EXPECT_EQ(txt->cursor->position, 17);
    int k = 0;
    node *current = txt->begin;
    while(current != txt->cursor->line)
    {
        k++;
        current = current->next;
    }
    EXPECT_EQ(k, 2);
    remove_all(txt);
}

TEST(move_cursor, sute6) {
    text txt = create_text();
    testing::internal::CaptureStderr();

    move(txt, 2, 30);
        
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "There are already no any lines in the text!\n");

    remove_all(txt);
}

TEST(show, suite1) {
    text txt = create_text();
    load(txt, path_to_file);
    move(txt, 1, 2);
    testing::internal::CaptureStdout();
    show(txt);
    std::string output = testing::internal::GetCapturedStdout();
    int i = 0;
    node *current = txt->begin;
    while(current)
    {
        for (int j = 0; j < strlen(current->contents); j++)
        {
            if (current == txt->cursor->line
                   && j == txt->cursor->position)
            {
                EXPECT_EQ(output[i], '|');
                i++;
            }
            EXPECT_EQ(output[i], current->contents[j]);
            i++;
        }
        i++;
        current = current->next;
    }
    remove_all(txt);
}

TEST(show, suite2) {
    text txt = create_text();
    testing::internal::CaptureStderr();
    show(txt);
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "There are already no any lines in the text!\n");

    remove_all(txt);
}