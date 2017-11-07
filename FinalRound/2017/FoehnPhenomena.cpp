#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>
#define IO cin.tie(NULL);cout.tie(NULL);
template<typename T> inline void read(T &x) {
    char c;
    bool neg = false;
    while (!isdigit(c = getchar()) && c != '-');
    x = 0;
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    do {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
    if (neg) x = -x;
}
template<typename T> inline void write(T x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }
    if (x < 10) {
        putchar(char(x + 48));
    }
    else {
        write(x/10);
        putchar(char(48 + x%10));
    }
}
template<typename T> inline void writeln(T x) {
    write(x);
    putchar('\n');
}
using namespace std;

int n, q;
vector<long long> a, b;
long long neg, po, s, t;

void Up(int u, int x) {
    if (b[u] < 0) neg -= b[u];
    else po -= b[u];
    b[u] += x;
    if (b[u] < 0) neg += b[u];
    else po += b[u];
}

int main() {
    IO;
    read(n);read(q);read(s);read(t);
    a.resize(n + 5);
    b.resize(n + 5);
    REP(i, n + 1) read(a[i]);
    FOR(i, 1, n) b[i] = 0;
    int l, r, x;
    neg = po = 0;
    FOR(i, 1, n) Up(i, a[i] - a[i - 1]);
    while (q--) {
        read(l);read(r);read(x);
        Up(l, x);
        if (r != n) Up(r + 1, -x);
        long long ans = -neg * t - po * s;
        writeln(ans);
    }
}
