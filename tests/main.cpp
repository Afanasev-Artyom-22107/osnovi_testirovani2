#include "test_save.h"
#include "test_stand.h"
#include "test_ind_func.h"
#include "test_functions.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
