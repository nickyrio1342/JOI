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

int n, m, k, s[N];
long long t, b, a, c;
priority_queue<int> heap;
multiset<int> tab;
int main() {
    IO;
    read(n);read(m);read(k);
    read(a);read(b);read(c);
    read(t);
    FOR(i, 1, m) read(s[i]);
    int ans = 0, used = 0;
    k -= m;
    FOR(i, 1, m - 1) {
        long long newT = t - (s[i] - 1) * b;
        if (newT < 0) break;
        int now = s[i];
        if ((newT - c * (now - s[i])) / a >= s[i + 1] - s[i] - 1) {
            ans += s[i + 1] - s[i];
            continue;
        }
        int cnt = 0;
        while (true) {
            if (cnt == k) break;
            if (newT - c * (now - s[i]) < 0) break;
            if (now + (newT - c * (now - s[i])) / a >= s[i + 1]) {
                //heap.push(s[i + 1] - now);
                if (tab.size() < k) tab.insert(s[i + 1] - now);
                else {
                    if (s[i + 1] - now > *tab.begin()) {
                        tab.erase(tab.begin());
                        tab.insert(s[i + 1] - now);
                    }
                }
                break;
            }
            if (now != s[i]) {
                cnt++;
                //heap.push((newT - c * (now - s[i])) / a + 1);
                if (tab.size() < k) tab.insert((newT - c * (now - s[i])) / a + 1);
                else {
                    if ((newT - c * (now - s[i])) / a + 1 > *tab.begin()) {
                        tab.erase(tab.begin());
                        tab.insert((newT - c * (now - s[i])) / a + 1);
                    } else break;
                }
            } else ans += (newT - c * (now - s[i])) / a + 1;
            now = now + (newT - c * (now - s[i])) / a + 1;
        }
    }
    if (b * (n - 1) <= t) ans++;
    auto it = tab.end();
    while (used < k && it != tab.begin()) {
        it--;
        ans += *it;
        used++;
    }
    writeln(ans - 1);
}
