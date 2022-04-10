#include <bits/stdc++.h>
using namespace std;

void testcase() {
    string S; cin >> S;
    int N = S.size();
    string ansS;

    for(int i = 0; i < N - 1; i++){
        if(S[i] < S[i+1]){
          ansS += S[i];
          ansS += S[i];  
        }
        else{
            ansS += S[i];
        }
    }
    ansS += S[N-1];
    cout << ansS << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    for (int _t = 0; _t < T; _t++) {
        cout << "Case #" << _t + 1 << ": ";
        testcase();
    }
}