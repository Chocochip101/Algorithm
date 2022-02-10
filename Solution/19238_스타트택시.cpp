#include<bits/stdc++.h>
#define endl "\n"
#define MAX 25
#define ll long long
using namespace std;
typedef pair<int, int> p;
p Dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct coord{
    int x, y, dist;
};
int N, M, restFuel;
// wall: -1, 
int board[MAX][MAX];

// visited, dist
int tempBoard[MAX][MAX];

p TAXI;
p DEST[MAX * MAX];
bool finished[MAX * MAX];

int cnt = 0;
vector<coord> coords;
bool valid(int x, int y){ return 1 <= x && x <= N && 1 <= y && y <= N;}
bool cmp(coord a, coord b){
    if(a.dist == b.dist && a.x == b.x) return a.y < b.y;
    if(a.dist == b.dist) return a.x < b.x;
    return a.dist < b.dist;
}
void bfs(){
    coords.clear();
    memset(tempBoard, -1, sizeof(tempBoard));
    queue<p> q;
    tempBoard[TAXI.first][TAXI.second] = 0;
    q.push(TAXI);

    while(!q.empty()){
        
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(board[x][y] != -1 && board[x][y] != 0 && !finished[board[x][y]])
            coords.push_back({x, y, tempBoard[x][y]});


        for(int i = 0; i < 4; ++i){
            int nx = x + Dir[i].first;
            int ny = y + Dir[i].second;

            if(valid(nx, ny) && tempBoard[nx][ny] == -1 && board[nx][ny] != -1){
                tempBoard[nx][ny] = tempBoard[x][y] + 1;
                q.push({nx, ny});
            } 

        }
    }
}
int moveToDest(p dest){
    memset(tempBoard, -1, sizeof(tempBoard));
    queue<p> q;
    tempBoard[TAXI.first][TAXI.second] = 0;
    q.push(TAXI);
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == dest.first && y == dest.second)
            return tempBoard[x][y];
        
        for(int i = 0; i < 4; ++i){
            int nx = x + Dir[i].first;
            int ny = y + Dir[i].second;

            if(valid(nx, ny) && tempBoard[nx][ny]== -1 && board[nx][ny] != -1){
                q.push({nx ,ny});
                tempBoard[nx][ny] = tempBoard[x][y] + 1;
            }
        }
    }
    return -1;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> restFuel;

    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N ; ++j){
            cin >> board[i][j];
            if(board[i][j] == 1)
                board[i][j] = -1;
        }
            
    
    cin >> TAXI.first >> TAXI.second;

    for(int i = 1; i <= M; ++i){
        int a, b, c, d; 
        cin >> a >> b>> c>> d;
        board[a][b] = i;
        DEST[i] = {c, d};
    }

    while(1){
        if(cnt >= M) break;
        
        // TAXI -> Passenger
        bfs();
        sort(coords.begin(), coords.end(), cmp);
        if(coords.empty()) {            
            cout << -1 << endl;
            return 0;
        }
        restFuel -= coords[0].dist;
        if(restFuel < 0) {
            cout << -1 << endl;
            return 0;
        }   
        int passengerIdx = board[coords[0].x][coords[0].y];
        finished[passengerIdx] = true;
        TAXI = {coords[0].x, coords[0].y};

        // Passenger -> Destination
        int cost = moveToDest(DEST[passengerIdx]);
        if(restFuel < cost || cost == -1) {
            cout << -1 << endl;
            return 0;
        }  
        restFuel += cost;
        TAXI = DEST[passengerIdx];
        cnt++;
    }
    cout << restFuel << endl;
    return 0;
}