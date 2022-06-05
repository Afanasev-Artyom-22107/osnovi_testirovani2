#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

/* using namespace testing; */
extern "C" {
#include "../app/common.h"
}

TEST(testFunctionsParse, suite1) {
    char input[] = "4 4";
    int curr[2] = {4,4};    
    int curr_ret = 0;
    
    int out[2];
    int check = parse_convert(input, out);
    if (check == curr_ret && 
        (check == 1 || (out[0] == curr[0] && out[1] == curr[1]))) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(testFunctionsParse, suite2) {
    char input[] = "0 0";
    int curr[2] = {0,0};    
    int curr_ret = 0;

    int out[2];
    int check = parse_convert(input, out);
    if (check == curr_ret && 
        (check == 1 || (out[0] == curr[0] && out[1] == curr[1]))) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(testFunctionsParse, suite3) {
    char input[] = "4 ";
    int curr[2] = {0,0};    
    int curr_ret = 1;

    int out[2];
    int check = parse_convert(input, out);
    if (check == curr_ret && 
        (check == 1 || (out[0] == curr[0] && out[1] == curr[1]))) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(testFunctionsParse, suite4) {
    char input[] = "";
    int curr[2] = {0,0};    
    int curr_ret = 1;

    int out[2];
    int check = parse_convert(input, out);
    if (check == curr_ret && 
        (check == 1 || (out[0] == curr[0] && out[1] == curr[1]))) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(testFunctionsParse, suite5) {
    char input[] = "255 255";
    int curr[2] = {255,255};    
    int curr_ret = 0;

    int out[2];
    int check = parse_convert(input, out);
    if (check == curr_ret && 
        (check == 1 || (out[0] == curr[0] && out[1] == curr[1]))) {
        SUCCEED();
    } else {
        FAIL();
    }
}
TEST(testFunctionsParse, suite6) {
    char input[] = "256 256";
    int curr[2] = {256,256};    
    int curr_ret = 1;

    int out[2];
    int check = parse_convert(input, out);
    if (check == curr_ret && 
        (check == 1 || (out[0] == curr[0] && out[1] == curr[1]))) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(testFunctionsParse, suite7) {
    char input[] = "25 -10";
    int curr[2] = {25, -10};    
    int curr_ret = 1;

    int out[2];
    int check = parse_convert(input, out);
    if (check == curr_ret && 
        (check == 1 || (out[0] == curr[0] && out[1] == curr[1]))) {
        SUCCEED();
    } else {
        FAIL();
    }
}