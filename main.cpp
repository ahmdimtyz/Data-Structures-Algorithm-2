#include <iostream>
#include <vector>

using namespace std;

int maxAmountFromCoins(const vector<int>& coins) {
    int n = coins.size();
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return coins[0];
    }

    vector<int> dp(n, 0);
    dp[0] = coins[0];
    dp[1] = max(coins[0], coins[1]);

    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + coins[i]);
    }

    return dp[n - 1];
}

int main() {
    vector<int> coins = {7, 2, 1, 12, 5};
    
    int maxAmount = maxAmountFromCoins(coins);

    cout << "The maximum amount that can be picked up is: " << maxAmount << endl;

    return 0;
}

//i will add the 2 condition after this sorry for submitting late. -imtiyaz.
