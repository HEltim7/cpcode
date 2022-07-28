constexpr int p = 1e9 + 7;
template<class T> T norm(const T &x) { return (x % p + p) % p; }
template<class T> constexpr T ksm(T a, int b, const int &p)
{
    T c = 1;
    for (a %= p;b;a *= a, b >>= 1) if (b & 1) c *= a;
    return c;
}
struct Z
{
    using F = long long; F x;
    Z(long long _x = 0) : x(norm(_x)) {}
    auto operator<=>(const Z &) const = default;
    Z operator-() const { return Z(norm(p - x)); }
    Z inv() const { return ksm(*this, p - 2, p); }
    Z &operator*=(const Z &R) { return x = x * R.x % p, *this; }
    Z &operator+=(const Z &R) { return x = norm(x + R.x), *this; }
    Z &operator-=(const Z &R) { return x = norm(x - R.x), *this; }
    Z &operator/=(const Z &R) { return *this *= R.inv(); }
    Z &operator%=(const F &R) { return x %= R, *this; }
    friend Z operator*(Z L, const Z &R) { return L *= R; }
    friend Z operator+(Z L, const Z &R) { return L += R; }
    friend Z operator-(Z L, const Z &R) { return L -= R; }
    friend Z operator/(Z L, const Z &R) { return L /= R; }
    friend Z operator%(Z L, const F &R) { return L %= R; }
    friend auto &operator>>(istream &i, Z &z) { return i >> z.x; }
    friend auto &operator<<(ostream &o, const Z &z) { return o << z.x; }
};