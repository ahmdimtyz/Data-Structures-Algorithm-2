#include <iostream>
#include <vector>

using namespace std;

int fib(int n, vector<int>& dp) {
    if (dp[n] == 0) {
        if (n == 0) {
            dp[n] = 0;
        } else if (n == 1) {
            dp[n] = 1;
        } else {
            dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
        }
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> dp(n + 1, 0);

    int result = fib(n, dp);

    cout << "The " << n << "th Fibonacci number is: " << result << endl;

    return 0;
}
