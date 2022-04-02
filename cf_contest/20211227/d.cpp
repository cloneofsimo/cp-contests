#include <bits/stdc++.h>
using namespace std;

#define N 5005
#define MOD 998244353
using ll = long long;


int n, k;
string S;

int cumsum[N], arr[N];

ll nCm[N][N];

void init_nCm(){
    for(int i = 0; i < N; i++){
        nCm[i][0] = 1;
        for(int j = 1; j <= i; j++){
            nCm[i][j] = (nCm[i-1][j] + nCm[i-1][j-1]) % MOD;
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init_nCm();
    cin >> n >> k;
    cin >> S;
    for(int i = 0; i < n; i++){
        if(S[i] == '0'){
            arr[i] = 0;
        }
        else{
            arr[i] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        cumsum[i] = cumsum[i-1] + arr[i-1];
    }

    if(cumsum[n] < k){
        cout << 1 << '\n';
        return 0;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int starts = arr[i];
        int tot_1 = arr[i];
        int tot_0 = 1 - arr[i];
        for(int j = i + 1; j < n; j++){

            tot_1 = arr[j] + tot_1;
            tot_0 = 1 - arr[j] + tot_0;

            if(tot_1 > k){
                break;
            }

            if(starts + arr[j] == 0 && tot_1 >= 2){
                ans += nCm[(j - i + 1 - 2)][tot_1 - 2];
            }
            else if(starts + arr[j] == 2 && tot_0 >= 2){
                ans += nCm[(j - i + 1 - 2)][tot_0 - 2];
            }
            else if(starts + arr[j] == 1){
                ans += nCm[(j - i + 1 - 2)][tot_1 - 1];
            }

            ans %= MOD;   
        }
    }
    cout << ans + 1 << '\n';
    
}