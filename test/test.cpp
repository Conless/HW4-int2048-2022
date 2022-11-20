#include "gtest/gtest.h"
#include "int2048/int2048.h"

using namespace std;

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(SuiteName, TestName1) {
    sjtu::int2048 a, b;
    cin >> a >> b;
    cout << a / b << endl;
}