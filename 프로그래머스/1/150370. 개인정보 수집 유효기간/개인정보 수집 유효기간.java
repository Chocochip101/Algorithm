import java.util.*;
class Solution {
    private int today;
    private Map<String, Integer> terms;
    
    public List<Integer> solution(String t, String[] stringTerms, String[] privacies) {
        today = stringDateToInt(t);
        terms = stringTermToMap(stringTerms);
        List<Integer> answer = new ArrayList<>();
        for(int i = 0; i < privacies.length; i++){
            String[] splited = privacies[i].split(" ");
            if(isExpired(splited[1], splited[0])){
                answer.add(i + 1);
            }
        }
        return answer;
    }
    
    private boolean isExpired(String term, String d){
        // System.out.println(term);
        // System.out.println(d);
        int date = stringDateToInt(d);
        int protectDate = terms.get(term);
        // System.out.println("today = " + today);
        // System.out.println("protectDate = " + protectDate);
        // System.out.println("date = " + date);
        // System.out.println("========");
        return today >= protectDate + date;
    }
    
    private Map<String, Integer> stringTermToMap(String[] terms){
        Map<String, Integer> result = new HashMap<>();
        for(String term: terms){
            String[] splited = term.split(" ");
            result.put(splited[0], Integer.parseInt(splited[1]) * 28);
        }
        return result;
    }
    
    private int stringDateToInt(String d){
        String[] parsed = d.split("\\.");
        int day = Integer.parseInt(parsed[2]);
        int month = (Integer.parseInt(parsed[1]) - 1) * 28;
        int year = (Integer.parseInt(parsed[0]) - 2000) * 12 * 28;
        return year + month + day;
    }
}