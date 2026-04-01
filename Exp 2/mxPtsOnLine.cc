#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) return n;

    int result = 0;

    for (int i = 0; i < n; i++) {
        unordered_map<string, int> slopeCount;
        int duplicates = 1; // count of same points
        int localMax = 0;

        for (int j = i + 1; j < n; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if (dx == 0 && dy == 0) {
                duplicates++;
                continue;
            }

            if (dx == 0) {
                dy = 1;
            } else if (dy == 0) {
                dx = 1;
            } else {
                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                // normalize sign
                if (dx < 0) {
                    dx *= -1;
                    dy *= -1;
                }
            }

            string slope = to_string(dx) + "/" + to_string(dy);
            slopeCount[slope]++;
            localMax = max(localMax, slopeCount[slope]);
        }

        result = max(result, localMax + duplicates);
    }

    return result;
}