#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    cin >> x;

    for (long long i = sqrt(x); i >= 1; --i) {
        if (x % i == 0 && __gcd(i, x / i) == 1) {
            cout << i << ' ' << x / i;
            return 0;
        }
    }
}
