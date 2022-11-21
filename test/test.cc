#include "gtest/gtest.h"
#include "int2048/int2048.h"

using namespace std;

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(SuiteName, TestName1) {
    sjtu::int2048 a, b, c;
    freopen("test/P1919_1.in", "r", stdin);
    cin >> a >> b;
    cin.clear();
    freopen("test/P1919_1.out", "r", stdin);
    cin >> c;
    EXPECT_EQ(a * b, c);
}