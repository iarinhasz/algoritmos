#include <iostream>
#include <vector>
using namespace std;

int knapsack(int n, vector<int> &weights, vector<int> &valor, int W) {
    
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (weights[i - 1] <= j){
                dp[i][j] = max(dp[i - 1][j], valor[i - 1] + dp[i - 1][j - weights[i - 1]]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}
int main() {
    int capacidade, itens;
    scanf("%d %d", &capacidade, &itens);

    vector<int> size(itens), value(itens);
    for (int i = 0; i < itens; i++){
        scanf("%d %d", &size[i], &value[i]);
    }
    printf("%d\n",knapsack(itens, size, value, capacidade));

    return 0;
}
