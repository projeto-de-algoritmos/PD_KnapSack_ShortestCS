#include <bits//stdc++.h>
#define MAX_N 1000
#define MAX_W 5000
using namespace std;

//Declaração de uma matriz.
int dp[MAX_N][MAX_W];

//Declarando um vetor para o peso.
int wt[MAX_N+1];

//Declarando variavel(um vetor) para os itens(valores)
int val[MAX_N+1];

//Função para usar o bellman
int bottom_up(int n, int W){
        for(int i=0; i <= n; i++){
            for(int j=0; j <= W; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                if(j - wt[i-1] >= 0){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    return dp[n][W];
}

int main()
{
    int n, m;
    //O programa termina assim que tiver EOF.
    while(scanf("%d %d", &m, &n) == 2) {

        if(n == 0 && m == 0) break;

        memset(dp, -1, sizeof(dp));

        for(int i=0; i<n; i++)
            scanf("%d %d", &wt[i], &val[i]);

        int answer, re;
        answer = bottom_up(n, m);

        for(int i=0; i<=m; i++) {
            if(dp[n][i] == answer) {
                re = i;
                break;
            }
        }
        // Total de itens e peso.
        printf("%d %d\n", re, answer);
    }
    return 0;
}