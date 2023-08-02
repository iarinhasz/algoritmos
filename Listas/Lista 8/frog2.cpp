#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    int h[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &h[i]);
    }
    //ok
    vector<int> dp(N, 1e9);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j <= i + K && j < N; j++) {
            dp[j] = min(dp[j], dp[i] + abs(h[j] - h[i]));
        }
    }
    //ok
    printf("%d\n", dp[N-1]);
    return 0;
}