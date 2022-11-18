#include "../include/BigInteger/int2048.h"

namespace sjtu {

const int digit_len = 16;
const long long digit_mul[] = {1,
                               10,
                               100,
                               1000,
                               10000,
                               100000,
                               1000000,
                               10000000,
                               100000000,
                               1000000000,
                               10000000000,
                               100000000000,
                               1000000000000,
                               10000000000000,
                               100000000000000,
                               1000000000000000,
                               10000000000000000};
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
        printf("%016lld", num[i]);
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
        out << std::setw(6) << std::setfill('0') << x.num[i];
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
            if (num[i] > max_num) {
                num[i + 1] += num[i] / max_num;
                num[i] %= max_num;
            }
        }
    } else {
        for (int i = 0; i < len1 - 1; i++) {
            num[i] += x.num[i];
            if (num[i] > max_num) {
                num[i + 1] += num[i] / max_num;
                num[i] %= max_num;
            }
        }
        num[len1 - 1] += x.num[len1 - 1];
        if (num[len1 - 1] > max_num) {
            num.push_back(num[len1 - 1] / max_num);
            num[len1 - 1] %= max_num;
        } else if (len2 > len1)
            num.push_back(0);
        for (int i = len1; i < len2; i++) {
            num[i] += x.num[i];
            num.push_back(0);
            if (num[i] > max_num) {
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



} // namespace sjtu
