import java.util.*;
import java.awt.*;
class Solution {
    
    public int bfs(int sx, int sy, int distx, int disty, String[] maps){
        int[][] dist = new int[maps.length][maps[0].length()];
        for(int i = 0; i < maps.length; ++i)
            Arrays.fill(dist[i], -1);
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(sx, sy));
        dist[sx][sy] = 0;
        while(!q.isEmpty()){
            Point p = q.poll();
            if(p.x == distx && p.y == disty){
                return dist[p.x][p.y];
            }
            
            for(int i = 0; i < 4; ++i){
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                
                if(0 <= nx && nx < maps.length && 0 <= ny && ny < maps[0].length())
                    if(maps[nx].charAt(ny) != 'X' && dist[nx][ny] == -1){
                        dist[nx][ny] = dist[p.x][p.y] + 1;
                        q.add(new Point(nx, ny));
                    }
            }
        }
        return -1;
    }
    public int solution(String[] maps) {

        int sx = -1;
        int sy = -1;
        int ex = -1;
        int ey = -1;
        int lx = -1;
        int ly = -1;
        int answer = 0;
        for(int i = 0; i < maps.length; ++i)
            for(int j = 0; j < maps[0].length(); ++j)
                if(maps[i].charAt(j)=='S'){
                    sx = i; sy = j;
                }else if(maps[i].charAt(j)=='L'){
                    lx = i; ly = j;
                }else if(maps[i].charAt(j)=='E'){
                    ex = i; ey = j;
                }
        int res1 = bfs(sx, sy, lx, ly, maps);
        if(res1 == -1)
            return -1;
        answer += res1;
        res1 = bfs(lx, ly, ex, ey, maps);
        if(res1 == -1)
            return -1;
        answer += res1;
        return answer;
    }
}