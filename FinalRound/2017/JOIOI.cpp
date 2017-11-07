#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 2001
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

int n, m, a[N][N], b[N][N];
bool check(int x, int minAll) {
    int minA = 1e9 + 1;
    int maxA = 0;
    int flag = n;
    FOR(i, 1, m) {
        FOR(j, 1, flag) if (a[i][j] > x) {
            FOR(k, j, n) {
                minA = min(minA, a[i][k]);
                maxA = max(maxA, a[i][k]);
            }
            flag = j - 1;
            break;
        }
        FOR(j, flag + 1, n) {
            minA = min(minA, a[i][j]);
            maxA = max(maxA, a[i][j]);
        }
    }
    return maxA - minA <= x - minAll;
}

void Rotate() {
    FOR(i, 1, n) FOR(j, 1, m) b[i][j] = a[j][n - i + 1];
    swap(n, m);
    FOR(i, 1, m) FOR(j, 1, n) a[i][j] = b[i][j];
}
bool ok(int x, int minAll) {
    if (check(x, minAll)) return true;
    Rotate();
    if (check(x, minAll)) return true;
    Rotate();
    if (check(x, minAll)) return true;
    Rotate();
    if (check(x, minAll)) return true;
    return false;
}
int main() {
    IO;
    read(m);read(n);
    int minA = 1e9 + 1;
    int maxA = 0;
    FOR(i, 1, m) FOR(j, 1, n) {
        read(a[i][j]);
        minA = min(minA, a[i][j]);
        maxA = max(maxA, a[i][j]);
    }
    int l = 0;
    int r = maxA - minA;
    int cur = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(mid + minA, minA)) {
            cur = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    writeln(cur);
}
