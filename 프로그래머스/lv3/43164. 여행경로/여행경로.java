import java.util.*;

class Solution {
    boolean[] visited;
    ArrayList<String> allRoute = new ArrayList<>();
    
    public String[] solution(String[][] tickets) {
        visited = new boolean[tickets.length];
        Arrays.fill(visited, false);
        
        dfs("ICN", "ICN", tickets, 0);
        Collections.sort(allRoute);
        return allRoute.get(0).split(" ");
    }
    public void dfs(String src, String route, String[][] tickets, int cnt){
        if(cnt == tickets.length){
            allRoute.add(route);
            return;
        }
        for(int i = 0; i < tickets.length; ++i){
            if(tickets[i][0].equals(src) && !visited[i]){
                visited[i] = true;
                dfs(tickets[i][1], route + " " + tickets[i][1], tickets, cnt + 1);
                visited[i] = false;
            }
        }
    }
}