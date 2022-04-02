#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        int a[3]; cin >> a[0] >> a[1] >> a[2];
        sort(a, a+3);
        if(a[2] == a[0] + a[1]) cout << "YES" << '\n';
        else{
            if(a[0] == a[1] && (a[2] % 2 == 0)) cout << "YES" << '\n';
            else{
                sort(a, a + 3, greater<int>());
                if (a[0] == a[1] && (a[2] % 2 == 0)) cout << "YES" << '\n';
                else cout << "NO" << '\n';
            }
        }
    }
}