import java.util.*;
import java.awt.Point;
class Solution {
    
    public int solution(int n, int[][] edge) {
        boolean[][] graph = new boolean[n + 1][n + 1];
        int[] dist = new int[n + 1];
        
        for(int i = 0; i < n; ++i){
            Arrays.fill(graph[i], false);
        }
        Arrays.fill(dist, -1);
        for(int[] e: edge){
            graph[e[0]][e[1]] = true;
            graph[e[1]][e[0]] = true;
        }
        Queue<Integer> q = new LinkedList<>();
        dist[1] = 0;
        q.add(1);
        int maxDist = 0;
        while(!q.isEmpty()){
            int now = q.poll();
            for(int i = 1; i < n + 1; ++i){
                if(dist[i] == -1 && graph[now][i]){
                    dist[i] = dist[now] + 1;
                    maxDist = Math.max(maxDist, dist[i]);
                    q.add(i);
                }
            }
        }
        int answer = 0;
        for(int i = 1; i < n + 1; ++i)
            if(dist[i] == maxDist)
                answer++;

        return answer;
    }
}