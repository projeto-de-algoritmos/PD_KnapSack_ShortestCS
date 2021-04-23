#include <bits/stdc++.h>
using namespace std;

vector<char> v;
char s1[1005] , s2[1005];
int dp[105][105];

// Função recursiva.
void backtrace(int i, int j)
{
    if(i == 0 || j == 0)
        return; // Caso base.
    else if(s1[i-1] == s2[j-1]) {
            backtrace(i-1, j-1);
            v.push_back(s1[i-1]);
    }
    else {
        if(dp[i][j-1] > dp[i-1][j])
            backtrace(i, j-1);
        else
            backtrace(i-1, j);
    }
}

//Função para encontrar lcs de s1 e s2 cujos comprimentos são len1 e len2, respectivamente
// longest common subsequence (LCS)

void lcs()
{
    int n = strlen(s1);
    int m = strlen(s2);

    memset(dp, 0, sizeof(dp));
    // Caso base
    for(int i = 0; i <= n; ++i)
        dp[i][0] = 0;
    // Outro caso base    
    for(int i = 0; i <= m; ++i) 
        dp[0][i] = 0;	

    /* Preenchendo a tabela dp [] [] para LCS "dp: dynamic programming; 
     LCS: longest common subsequence (LCS)". */
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
}


int main()
{
    //Termina o trabalho com um  EOF.
    while(scanf("%s %s", s1, s2) == 2)
    {
        v.clear();
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        lcs();
        backtrace(len1, len2); //Obtendo o lcs por recursividade.

        int l1 = 0, l2 = 0;

        // Imprimir
        for(int i = 0; i < v.size(); ++i) {
            while(l1 < len1 && s1[l1] != v[i]) {
                cout << s1[l1];
                ++l1;
            }

            while(l2 < len2 && s2[l2] != v[i]) {
                cout << s2[l2];
                ++l2;
            }

            cout << v[i];
            ++l2, ++l1;
        }

        while(l1<len1)
            cout << s1[l1++];
        while(l2 < len2)
            cout << s2[l2++];
        cout << endl;
	}

	return 0;
}