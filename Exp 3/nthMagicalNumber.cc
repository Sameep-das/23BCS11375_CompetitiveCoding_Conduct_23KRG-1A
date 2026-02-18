#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int nthMagicalNumber(int n, int a, int b) {
        const int MOD = 1e9 + 7;

        long long g = gcd(a, b);
        long long lcm = (1LL * a * b) / g;

        long long start = min(a, b);
        long long end = 1LL * min(a, b) * n;
        long long ans = 0;

        while (start <= end) {
            long long mid = start + (end - start) / 2;

            long long count = mid / a + mid / b - mid / lcm;

            if (count >= n) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans % MOD;
    }
};
