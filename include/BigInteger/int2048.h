#ifndef SJTU_BIGINTEGER
#define SJTU_BIGINTEGER

// Integer 1:
// 实现一个有符号的大整数类，只需支持简单的加减

// Integer 2:
// 实现一个有符号的大整数类，支持加减乘除，并重载相关运算符

// 请不要使用除了以下头文件之外的其它头文件
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

// 请不要使用 using namespace std;

namespace sjtu {

class int2048 {
  private:
    int sgn;
    std::vector<int> num;

  public:
    // constructor functions
    int2048();
    int2048(const int2048 &);
    int2048(const std::string &);
    int2048(const char *);
    int2048(long long x);

  public:
    // read a big int
    void read(const std::string &);
    // output a big int
    void print() const;

    friend std::istream &operator>>(std::istream &, int2048 &);
    friend std::ostream &operator<<(std::ostream &, const int2048 &);


  public:
    friend int2048 abs(const int2048 &);

    inline friend bool operator==(const int2048 &, const int2048 &);
    inline friend bool operator!=(const int2048 &, const int2048 &);
    inline friend bool operator<(const int2048 &, const int2048 &);
    inline friend bool operator>(const int2048 &, const int2048 &);
    inline friend bool operator<=(const int2048 &, const int2048 &);
    inline friend bool operator>=(const int2048 &, const int2048 &);

    // add a big int
    int2048 add(int2048);
    // output the sum of a big int
    friend int2048 add(int2048, const int2048 &);

    // minus a big int
    int2048 minus(int2048);
    // output the difference of a big int
    friend int2048 minus(int2048, const int2048 &);

    // int2048 &operator+=(int2048);
    // friend int2048 operator+(int2048, const int2048 &);

    // int2048 &operator-=(int2048);
    // friend int2048 operator-(int2048, const int2048 &);

    // int2048 &operator*=(const int2048 &);
    // friend int2048 operator*(int2048, const int2048 &);

    // int2048 &operator/=(const int2048 &);
    // friend int2048 operator/(int2048, const int2048 &);

    
};
} // namespace sjtu

#endif
