#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX_V 800 + 1
using namespace std;
typedef pair<int, int> p;


int N, M;
vector<p> graph[MAX_V];



vector<int> dijkstra(int start, int vertex)

{

    vector<int> distance(vertex, INF);
    distance[start] = 0;

    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({ 0, start });

    while (!pq.empty())
    {

        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();



        if (distance[cur] < cost)
            continue;



        for (int i = 0; i < graph[cur].size(); i++){
            int neighbor = graph[cur][i].first;
            int neighborDistance = cost + graph[cur][i].second;

            //업데이트할 때마다 trace도 업데이트
            if (distance[neighbor] > neighborDistance){
                distance[neighbor] = neighborDistance;
                pq.push({ neighborDistance, neighbor });
            }

        }

    }
    return distance;
}



int main(void)

{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    N++;
    for (int i = 0; i < M; i++)
    {

        int u, v, w;

        cin >> u >> v >> w;



        //양방향
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });

    }



    int node1, node2;

    cin >> node1 >> node2;



    vector<int> result = dijkstra(1, N);

    vector<int> temp1 = dijkstra(node1, N);

    vector<int> temp2 = dijkstra(node2, N);

    //두 가지 경우

    //1. 1 -> node1 -> node2 -> N
    //2. 1 -> node2 -> node1 -> N

    int answer = min({ result[node1] + temp1[node2] + temp2[N - 1], result[node2] + temp2[node1] + temp1[N - 1] });

    if (answer >= INF || answer < 0)

        cout << -1 << "\n";

    else

        cout << answer << "\n";

    return 0;

}
