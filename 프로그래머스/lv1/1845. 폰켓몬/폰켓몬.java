import java.util.*;
import java.util.stream.*;
class Solution {
    public int solution(int[] nums) {
        Set<Integer> set = Arrays.stream(nums).boxed().collect(Collectors.toSet());
        if((int)(nums.length / 2) <= set.size())
            return (int)(nums.length / 2);
        return set.size();
    }
}