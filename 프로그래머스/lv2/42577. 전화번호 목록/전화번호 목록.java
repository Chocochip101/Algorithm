import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        Set<String> set = new HashSet<>();
        Arrays.sort(phone_book, new Comparator<String>(){
            public int compare(String s1, String s2){
                return s1.length() - s2.length();
            }
        });
        for(String phone_num: phone_book){
            if(set.size() == 0)
                set.add(phone_num);
            else{
                for(int i = 1; i< phone_num.length() + 1; ++i){
                    if(set.contains(phone_num.substring(0, i)))
                        return false;
                }
                set.add(phone_num);
            }
        }
        return true;
    }
}