#include <bits/stdc++.h>
using namespace std;
#define N 200005
using ll = long long;

const ll INF = 1e15;
ll n, k;
ll arr[N];
ll cumsum[N];


// sum from l to r - 1
ll sums(int l, int r){
    return cumsum[r] - cumsum[l];
}

int is_t(ll t){
    for(int i = 0; i <= min(t, (ll)n - 1); i++){
        if(sums(1, n - i) + (arr[0] - (t - i)) * (i + 1) <= k){
            return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){

        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        // cumsum

        cumsum[0] = 0;
        for(int i = 1; i <= n; i++) cumsum[i] = cumsum[i-1] + arr[i-1];


        // find minimum t such that sum(arr[0..t]) <= k
        ll ans;
        ll l = 0, r = INF;
        while(l < r){
            ll mid = (l + r) / 2;
            if(is_t(mid)){
                ans = mid;
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        cout << ans << '\n';
        
    }    
}