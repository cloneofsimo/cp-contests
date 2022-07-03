#include <bits/stdc++.h>
using namespace std;
#define MAXN 500100
#define K 22

int n, m;
vector<string> gjs, rsh;
map<string, int> gjcnt;


int arrs[MAXN];
int lg[MAXN + 1];


struct validx{
    int val, idx;
};



validx st[MAXN][22];
bool comp(validx a, validx b){
    if(a.val == b.val){
        return a.idx < b.idx;
    }
    return a.val < b.val;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        gjcnt[s]++;
    }
    m = gjcnt.size();
    // gjcnt keys to gjs
    for(auto it = gjcnt.begin(); it != gjcnt.end(); it++){
        gjs.push_back(it->first);
    }
    // sort
    sort(gjs.begin(), gjs.end());
    for(int i = 0; i < m; i++){
        arrs[i] = gjcnt[gjs[i]];
    }
    //
    lg[1] = 0;
    for(int i = 2; i <= MAXN; i++){
        lg[i] = lg[i / 2] + 1;
    }

    for(int i = 0; i < m; i++){
        st[i][0].val = -arrs[i];
        st[i][0].idx = i;
    }
    for(int j = 1; j <= K; j++){
        for(int i = 0; i + (1 << j) <= m; i++){
            if(comp(st[i][j-1], st[i + (1 << (j - 1))][j - 1]))
                st[i][j] = st[i][j - 1];
            else
                st[i][j] = st[i + (1 << (j - 1))][j - 1];
        }
    }

    cout << "RMQ" << endl;
    for(int i = 0; i < m; i++){
        cout << gjs[i] << ' ' << arrs[i] << ' ' << '\n';
    }

    int k; cin >> k;
    for(int i = 0; i < k; i++){
        string s; cin >> s;
        int sts = lower_bound(gjs.begin(), gjs.end(), s) - gjs.begin();
        int ste = upper_bound(gjs.begin(), gjs.end(), s) - gjs.begin();
        cout << sts << ' ' << ste << '\n';
        if(sts == ste){
            cout << "0" << '\n';
            continue;
        }

        int j = lg[ste - sts];
        validx ans = comp(st[sts][j], st[ste - 1 - (1 << j)][j]) ? st[sts][j] : st[ste - 1 - (1 << j)][j];
        cout << gjs[ans.idx] << ' ' << ans.val << '\n';
    }
}