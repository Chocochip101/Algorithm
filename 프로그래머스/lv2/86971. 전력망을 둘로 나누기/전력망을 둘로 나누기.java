import java.util.*;

class Solution {
    int[][] graph;
    boolean[] visited;
    ArrayList<Integer> arr = new ArrayList<>();
    int cnt = 0;
    public void dfs(int now, int n){
        visited[now] = true;
        cnt++;
        for(int next = 1; next <= n; ++next){
            if(!visited[next] && graph[now][next] == 1)
                dfs(next, n);
        }
        return;
    }
    public int solution(int n, int[][] wires) {
        graph = new int[n + 1][n + 1];
        visited = new boolean[n + 1];
        
        for(int[] wire: wires){
            graph[wire[0]][wire[1]] = 1;
            graph[wire[1]][wire[0]] = 1;
        }

        int answer = Integer.MAX_VALUE;
        for(int[] wire: wires){
            arr.clear();
            graph[wire[0]][wire[1]] = 0;
            graph[wire[1]][wire[0]] = 0;

            Arrays.fill(visited, false);
            for(int i = 1; i <= n; ++i){
                if(!visited[i]){
                    cnt = 0;
                    dfs(i, n);
                    arr.add(cnt);
                }
            }
            answer = Math.min(Math.abs(arr.get(1) - arr.get(0)), answer);
            graph[wire[0]][wire[1]] = 1;
            graph[wire[1]][wire[0]] = 1;
        }
        return answer;
    }
}