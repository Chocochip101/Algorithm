// import java.awt.Point;
import java.util.*;

class Solution {

    public int solution(int[][] maps) {
        int N = maps.length;
        int M = maps[0].length;
        
        int[][] dist = new int[N][M];
        boolean[][] visited = new boolean[N][M];
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};
        
        Queue<Pair> q = new LinkedList<Pair>();
        q.add(new Pair(0, 0));
        dist[0][0] = 1;
        while(!q.isEmpty()){
            Pair now_cord = q.poll();
            visited[now_cord.x][now_cord.y] = true;
            for(int i = 0; i < 4; ++i){
                int nx = now_cord.x + dx[i];
                int ny = now_cord.y + dy[i];
                
                if(0 <= nx && nx < maps.length && 0 <= ny && ny < maps[0].length){
                    if(!visited[nx][ny] && maps[nx][ny] == 1 && dist[nx][ny] == 0){
                        dist[nx][ny] = dist[now_cord.x][now_cord.y] + 1;
                        q.add(new Pair(nx, ny));
                    }
                }
            }
        }
        
        if(!visited[N - 1][M - 1])
            return -1;
        
        return dist[N - 1][M - 1];
    }
    
    public static class Pair{
        int x;
        int y;
        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}