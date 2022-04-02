#include <bits/stdc++.h>
using namespace std;
#define N 200005

int n, tot_like;
int orgarr[N];
int did_like[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> orgarr[i];
        string S;
        cin >>S;
        vector<int> likes, unlikes;
        map<int, int> lkm, ukm;
        for(int i = 0; i < n; i++){
            if(S[i] == '0'){
                did_like[i] = 0;

                unlikes.push_back(orgarr[i]);
            }
            else{
                did_like[i] = 1;

                likes.push_back(orgarr[i]);
            }
        }
        int ans = 0;
        sort(likes.begin(), likes.end());
        sort(unlikes.begin(), unlikes.end());
        
        int lidx = 1;
        for(int t : unlikes){
            ukm[t] = lidx;
            lidx += 1;
        }
        for(int t : likes){
            lkm[t] = lidx;
            lidx += 1;
        }
        for(int i = 0; i < n; i++){
            if(did_like[i]){
                cout << lkm[orgarr[i]] << ' ';
            }
            else{
                cout << ukm[orgarr[i]] << ' ';
            }
        }
        cout << '\n';


    }
    
}