import java.util.*;
class Solution {
    boolean[] isPrime = new boolean[100000000];
    boolean[] visited = new boolean[8];
    Set<Integer> set = new HashSet<>();
    
    public void prime(){
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i < Math.sqrt(100000000); ++i)
            if(isPrime[i])
                for(int j = 2 * i; j <100000000; j += i)
                    isPrime[j] = false;
        return;
    }
    public void dfs(int idx, String now, String numbers){  
        if(now.length() != 0 && isPrime[Integer.parseInt(now)]){
            set.add(Integer.parseInt(now));
        }
        
        for(int i = 0; i < numbers.length(); ++i){
            if(i != idx && !visited[i]){
                visited[i] = true;
                dfs(i, now + numbers.charAt(i), numbers);
                visited[i] = false;
            }
        }
        return;
    }
    public int solution(String numbers) {
        prime();

        dfs(-1, "", numbers);
        return set.size();
    }
}