import java.util.*;

class Solution {
    public int charDiff(String s1, String s2){
        int cnt = 0;
        for(int i = 0; i < s1.length(); ++i)
            if(s1.charAt(i) != s2.charAt(i))
                cnt++;
        return cnt;
    }
    public int solution(String begin, String target, String[] words) {
        Queue<Pair> q = new LinkedList<>();
        int[] dist = new int[words.length + 1];
        Arrays.fill(dist, -1);
        
        dist[words.length] = 0;
        q.add(new Pair(begin, words.length));
        
        while(!q.isEmpty()){

            Pair p = q.poll();
            if(p.s.equals(target)){
                return dist[p.idx];
            }
            for(int i = 0; i < words.length; ++i){
                if(dist[i] == -1 && charDiff(p.s, words[i]) == 1){
                    q.add(new Pair(words[i], i));
                    dist[i] = dist[p.idx] + 1;
                }
            }
        }
        
        return 0;
    }
}

class Pair{
    String s;
    int idx;
    
    public Pair(String s, int idx){
        this.s = s;
        this.idx = idx;
    }
}