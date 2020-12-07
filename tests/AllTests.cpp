#include "../include/node.h"
#include "gtest/gtest.h"

int main(int argc, char *argv[]) {
  std::srand(std::time(NULL));
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_death_test_style = "fast";

  return RUN_ALL_TESTS();
}

class TrieTest : public ::testing::Test {
 protected:
};

TEST_F(TrieTest, CheckWorking) { ASSERT_EQ(1, 1); }
