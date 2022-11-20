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
#include <iomanip>
#include <vector>

// 请不要使用 using namespace std;

namespace sjtu {

class int2048 {
  private:
    int sgn;
    std::vector<long long> num;

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

  protected:
    void reduce();
    friend int2048 abs(const int2048 &);

  public:
    inline friend bool operator==(const int2048 &, const int2048 &);
    inline friend bool operator!=(const int2048 &, const int2048 &);
    inline friend bool operator<(const int2048 &, const int2048 &);
    inline friend bool operator>(const int2048 &, const int2048 &);
    inline friend bool operator<=(const int2048 &, const int2048 &);
    inline friend bool operator>=(const int2048 &, const int2048 &);

    // add a big int
    int2048 &add(int2048);
    // output the sum of a big int
    friend int2048 add(int2048, const int2048 &);

    int2048 &operator+=(int2048);
    friend int2048 operator+(int2048, const int2048 &);

    // minus a big int
    int2048 &minus(int2048);
    // output the difference of a big int
    friend int2048 minus(int2048, const int2048 &);

    int2048 &operator-=(int2048);
    friend int2048 operator-(int2048, const int2048 &);

    
    int2048 &operator*=(const int2048 &);
    friend int2048 operator*(int2048, const int2048 &);

    // int2048 &operator/=(const int2048 &);
    // friend int2048 operator/(int2048, const int2048 &);

    
};
} // namespace sjtu




#endif

namespace sjtu {

const int digit_len = 4;
const long long digit_mul[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
const long long max_num = digit_mul[digit_len];

int2048::int2048() {
    sgn = 1;
    num.clear();
    num.push_back(0);
}

int2048::int2048(const int2048 &x) {
    sgn = x.sgn;
    num = x.num;
    reduce();
}

int2048::int2048(const std::string &x) {
    int n = x.length();
    int las_digit = n;
    if (x[0] == '-') {
        sgn = -1;
        las_digit = n - 1;
    } else {
        sgn = 1;
    }
    num.clear();
    for (int i = 0; i < las_digit; i++) {
        if (i % digit_len == 0) {
            num.push_back(0);
        }
        num.back() += (x[n - 1 - i] - '0') * digit_mul[i % digit_len];
    }
    reduce();
}

int2048::int2048(const char *s) {
    std::string ss = s;
    *this = ss;
}

int2048::int2048(long long x) {
    num.clear();
    if (x < 0) {
        x = -x;
        sgn = -1;
    }
    while (x) {
        num.push_back(x % max_num);
        x /= max_num;
    }
    reduce();
}

void int2048::read(const std::string &s) {
    *this = int2048(s);
    return;
}

void int2048::print() const {
    int len = num.size();
    if (sgn == -1)
        putchar('-');
    printf("%lld", num[len - 1]);
    for (int i = len - 2; i >= 0; i--) {
        printf("%04lld", num[i]);
    }
    return;
}

std::istream &operator>>(std::istream &in, int2048 &x) {
    std::string s;
    in >> s;
    x = s;
    return in;
}

std::ostream &operator<<(std::ostream &out, const int2048 &x) {
    int len = x.num.size();
    if (x.sgn == -1)
        putchar('-');
    out << x.num[len - 1];
    for (int i = len - 2; i >= 0; i--) {
        out << std::setw(digit_len) << std::setfill('0') << x.num[i];
    }
    return out;
}

void int2048::reduce() {
    while (!num.empty() && !num.back())
        num.pop_back();
    if (num.empty()) {
        sgn = 1;
        num.push_back(0);
    }
}

int2048 abs(const int2048 &x) {
    int2048 xx = x;
    xx.sgn = 1;
    return xx;
}

inline bool operator==(const int2048 &x, const int2048 &y) {
    if (x.sgn != y.sgn)
        return false;
    int lenx = x.num.size(), leny = y.num.size();
    if (lenx != leny)
        return false;
    for (int i = 0; i < lenx; i++)
        if (x.num[i] != y.num[i])
            return false;
    return true;
}
inline bool operator!=(const int2048 &x, const int2048 &y) { return (x == y) ^ 1; }
inline bool operator<(const int2048 &x, const int2048 &y) {
    if (x.sgn != y.sgn)
        return x.sgn < y.sgn;
    if (x.sgn == -1)
        return abs(x) > abs(y);
    int lenx = x.num.size(), leny = y.num.size();
    if (lenx != leny)
        return lenx < leny;
    for (int i = lenx - 1; i >= 0; i--)
        if (x.num[i] != y.num[i])
            return x.num[i] < y.num[i];
    return false;
}
inline bool operator>(const int2048 &x, const int2048 &y) {
    if (x.sgn != y.sgn)
        return x.sgn > y.sgn;
    if (x.sgn == -1)
        return abs(x) < abs(y);
    int lenx = x.num.size(), leny = y.num.size();
    if (lenx != leny)
        return lenx > leny;
    for (int i = lenx - 1; i >= 0; i--)
        if (x.num[i] != y.num[i])
            return x.num[i] > y.num[i];
    return false;
}
inline bool operator<=(const int2048 &x, const int2048 &y) { return (x > y) ^ 1; }
inline bool operator>=(const int2048 &x, const int2048 &y) { return (x < y) ^ 1; }

int2048 &int2048::add(int2048 x) {
    int flag = 1;
    if (sgn == 1) {
        if (x.sgn == -1) {
            x.sgn = 1;
            minus(x);
            return *this;
        }
    } else {
        if (x.sgn == 1) {
            x.minus(abs(*this));
            *this = x;
            return *this;
        } else {
            sgn = x.sgn = 1;
            flag = -1;
        }
    }
    int len1 = num.size(), len2 = x.num.size();
    if (len1 > len2) {
        for (int i = 0; i < len2; i++) {
            num[i] += x.num[i];
            if (num[i] >= max_num) {
                num[i + 1] += num[i] / max_num;
                num[i] %= max_num;
            }
        }
    } else {
        for (int i = 0; i < len1 - 1; i++) {
            num[i] += x.num[i];
            if (num[i] >= max_num) {
                num[i + 1] += num[i] / max_num;
                num[i] %= max_num;
            }
        }
        num[len1 - 1] += x.num[len1 - 1];
        if (num[len1 - 1] >= max_num) {
            num.push_back(num[len1 - 1] / max_num);
            num[len1 - 1] %= max_num;
        } else if (len2 > len1)
            num.push_back(0);
        for (int i = len1; i < len2; i++) {
            num[i] += x.num[i];
            num.push_back(0);
            if (num[i] >= max_num) {
                num[i + 1] += num[i] / max_num;
                num[i] %= max_num;
            }
        }
        if (num.back() == 0)
            num.pop_back();
    }
    sgn = flag;
    reduce();
    return *this;
}

int2048 add(int2048 x, const int2048 &y) { return x.add(y); }

int2048 &int2048::minus(int2048 x) {
    int flag = 1;
    if (sgn == 1) {
        if (x.sgn == 1) {
            if (*this < x) {
                int2048 res = x.minus(*this);
                res.sgn = -1;
                *this = res;
                return *this;
            }
        } else {
            x.sgn = 1;
            add(x);
            return *this;
        }
    } else {
        if (x.sgn == 1) {
            x.sgn = -1;
            add(x);
            return *this;
        } else {
            if (abs(*this) < abs(x)) {
                sgn = x.sgn = 1;
                x.minus(*this);
                *this = x;
                return *this;
            } else {
                sgn = x.sgn = 1;
                flag = -1;
            }
        }
    }
    int len = num.size(), lenx = x.num.size();
    for (int i = 0; i < lenx; i++) {
        num[i] -= x.num[i];
        if (num[i] < 0) {
            num[i + 1]--;
            num[i] += max_num;
        }
    }
    for (int i = lenx; i < len; i++) {
        if (num[i] < 0) {
            num[i + 1]--;
            num[i] += max_num;
        }
    }
    sgn = flag;
    reduce();
    return *this;
}

int2048 minus(int2048 x, const int2048 &y) { return x.minus(y); }

void change(std::vector<std::complex<long double> > &a, int len) {
    for (int i = 1, j = len / 2; i < len - 1; i++) {
        if (i < j)
            std::swap(a[i], a[j]);
        int k = len / 2;
        while (j >= k) {
            j -= k;
            k >>= 1;
        }
        if (j < k)
            j += k;
    }
}

const int MAXN = 6e6 + 6;
const long long MOD = 998244353;
const long long g = 3, gi = 332748118;
long long r[MAXN];

inline long long qpow(long long a, long long k) {
    long long res = 1LL;
    while (k) {
        if (k & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return res;
}

void change(std::vector<long long> &a, int len) {
    for (int i = 1, j = len / 2; i < len - 1; i++) {
        if (i < j)
            std::swap(a[i], a[j]);
        int k = len / 2;
        while (j >= k) {
            j -= k;
            k >>= 1;
        }
        if (j < k)
            j += k;
    }
}

void NTT(std::vector<long long> &a, int len, int opt) {
    change(a, len);
    for (int i = 1; i < len; i <<= 1)
    {
        long long gn = qpow(opt ? g : gi, (MOD - 1) / (i << 1));
        for (int j = 0; j < len; j += (i << 1)) {
            long long g0 = 1;
            for (int k = 0; k < i; ++k, g0 = g0 * gn % MOD) {
                long long x = a[j + k], y = g0 * a[i + j + k] % MOD;
                a[j + k] = (x + y) % MOD;
                a[i + j + k] = (x - y + MOD) % MOD;
            }
        }
    }
}

int2048 &int2048::operator*=(const int2048 &x) {
    std::vector<long long> f, g;
    int n = num.size() - 1, m = x.num.size() - 1;
    int res = n + m;
    int k = 1, lg = 0;
    while (k <= res) {
        k <<= 1;
        lg++;
    }
    f.resize(k);
    g.resize(k);
    for (int i = 0; i <= n; i++)
        f[i] = num[i];
    for (int i = n + 1; i < k; i++)
        f[i] = 0;
    for (int i = 0; i <= m; i++)
        g[i] = x.num[i];
    for (int i = m + 1; i < k; i++)
        g[i] = 0;
    NTT(f, k, 1);
    NTT(g, k, 1);
    for (int i = 0; i <= k; i++)
        f[i] = f[i] * g[i] % MOD;
    NTT(f, k, 0);
    long long inv = qpow(k, MOD - 2);
    num.clear();
    num.resize(n + m + 2);
    for (int i = 0; i <= n + m; i++) {
        num[i] += f[i] * inv % MOD;
        if (num[i] >= max_num) {
            num[i + 1] += num[i] / max_num;
            num[i] %= max_num;
        }
    }
    reduce();
    return *this;
}

int2048 operator*(int2048 x, const int2048 &y) { return x *= y; }

} // namespace sjtu

using sjtu::int2048;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    freopen("P1919_1.in", "r", stdin);
    freopen("P1919_2.out", "w", stdout);
    int2048 a, b;
    cin >> a >> b;
    cout << a * b << endl;
    return 0;
}