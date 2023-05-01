import java.util.*;
import java.util.stream.*;

class Solution {
    public long calPerson(long t, int[] times){
        long res = 0;
        for(int i = 0; i < times.length; ++i)
            res += (long)(t / times[i]);
        return res;
    }
    public long solution(int n, int[] times) {
        long answer = (long)n * Arrays.stream(times).max().getAsInt() + 1;
        long s = 0;
        long e = (long)n * Arrays.stream(times).max().getAsInt() + 1;
        
        while(s <= e){
            long mid = (long)((e + s) / 2);
            long people = calPerson(mid, times);
            if(people < n){
                s = mid + 1;
            }else{
                answer = Math.min(answer, mid);
                e = mid - 1;
            }
            
        }
        return answer;
    }
}