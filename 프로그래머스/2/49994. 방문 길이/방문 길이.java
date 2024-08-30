import java.util.*;

class Solution {
    public int solution(String dirs) {
        int answer = 0;
        int x = 0;
        int y = 0;
        
        boolean[][][] routes = new boolean[13][13][4];

        for(int i = 0; i < dirs.length(); i++){
            System.out.println("x = " + x + ", y = " + y);
            if(dirs.charAt(i) == 'U'){
                int nx = x - 1;
                int ny = y;
                
                if(!valid(nx, ny)){
                    continue;
                }
                
                if(!routes[x + 5][y + 5][0] && !routes[nx + 5][ny + 5][1]){
                    answer++;
                    routes[x + 5][y + 5][0] = true;
                }
                x = nx;
                y = ny;
            }else if(dirs.charAt(i) == 'D'){
                int nx = x + 1;
                int ny = y;
                
                if(!valid(nx, ny)){
                    continue;
                }
                
                if(!routes[x + 5][y + 5][1] && !routes[nx + 5][ny + 5][0]){
                    answer++;
                    routes[x + 5][y + 5][1] = true;
                }
                x = nx;
                y = ny;
            }else if(dirs.charAt(i) == 'R'){
                int nx = x;
                int ny = y + 1;
                
                if(!valid(nx, ny)){
                    continue;
                }
                
                if(!routes[x + 5][y + 5][2] && !routes[nx + 5][ny + 5][3]){
                    answer++;
                    routes[x + 5][y + 5][2] = true;
                }
                x = nx;
                y = ny;
                
            }else if(dirs.charAt(i) == 'L'){
                int nx = x;
                int ny = y - 1;
                
                if(!valid(nx, ny)){
                    continue;
                }
                
                if(!routes[x + 5][y + 5][3] && !routes[nx + 5][ny + 5][2]){
                    answer++;
                    routes[x + 5][y + 5][3] = true;
                }
                x = nx;
                y = ny;
            }
        }

        return answer;
    }
    public boolean valid(int nx, int ny){
        return -5 <= nx && nx <= 5 && -5 <= ny && ny <= 5;
    }
 
}