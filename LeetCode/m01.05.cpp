#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int n = first.size();
        int m = second.size();
        if (fabs(n - m) >= 2) {
            return false;
        }

        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i++) { dp[i][0] = i; }
        for (int i = 0; i <= m; i++) { dp[0][i] = i; }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (first[i-1] == second[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                }
            }
        }

        return dp[n][m] <= 1;
    }
};

