#include <algorithm>
#include <
using namespace std;
using ll = long long;

char brds[1010][1010];
int dang[1010][1010];
int visited[1010][1010];

int dxx[] = {1, 0, -1, 0};
int dyy[] = {0, 1, 0, -1};

int w, h;
int endx, endy;
int startx, starty;
ll MOD = 1010;

ll valof(int x, int y){
    ll val = 0;
    if(brds[x][y] == 'P'){
        val += MOD * MOD * 2;
    }
    else if(brds[x][y] == 'E'){
        val += MOD * MOD * 10;
    }
    val -= x * MOD + y;
    return val;
}

int main(){

    cin >> w >> h;
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            cin >> brds[i][j];
            if(brds[i][j] == 'P'){
                for(int dx = -1; dx <= 1; dx++){
                    for(int dy = -1; dy <= 1; dy++){
                        if((i + dx >= 0) && (i + dx < w) && (j + dy >= 0) && (j + dy < h)){
                            dang[i + dx][j + dy]++;
                        }
                    }
                }
            }
            if(brds[i][j] == 'P'){
                dang[i][j] -= 4;
            }
            else if(brds[i][j] == 'E'){
                endx = i;
                endy = j;
            }
            else if(brds[i][j] == 'S'){
                startx = i;
                starty = j;
            }
        }
    }
    dang[startx][starty] = 0;
    dang[endx][endy] = 0;
    priority_queue<ll, vector<ll>> pq;
    
    ll ans = 0;
    pq.push(valof(startx, starty));
    visited[startx][starty] = 1;
    int curx = -1, cury = -1;
    while(curx != endx || cury != endy){
        ll val = pq.top();
        pq.pop();

        cout << "VAL " << val << endl;

        if(val > MOD * MOD * 5){
            break;
        }
        else{
            if(val > 0){
                val -= MOD * MOD * 2;
            }
        }

        
        val = -val;
        curx = val / MOD;
        cury = val % MOD;
        cout << "VISITING" << curx << " " << cury << endl;
        
        for(int ord = 0; ord < 4; ord++){
            int nx = curx + dxx[ord];
            int ny = cury + dyy[ord];
            if((nx >= 0) && (nx < w) && (ny >= 0) && (ny < h) && (visited[nx][ny] == 0)){
                pq.push(valof(nx, ny));
                visited[nx][ny] = 1;
            }
        }

        ans += dang[curx][cury];

    }
    if(ans < 0) ans = 0;
    cout << ans << endl;

    
    
}