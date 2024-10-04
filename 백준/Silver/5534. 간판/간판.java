import java.util.*;
import java.io.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in)); 
        int N = Integer.parseInt(bf.readLine());
        String name = bf.readLine();
        int ans = 0;
        for(int i = 0; i< N; i++){
            if(canMake(name, bf.readLine())){
                ans++;
            }
        }
        System.out.println(ans);
    }

    public static boolean canMake(String to, String from){
        for(int i = 0; i < from.length(); i++){
            for(int jumps = 1; jumps < from.length(); jumps++){

                StringBuilder sb = new StringBuilder();
   
                for(int k = i; k < from.length(); k += jumps){
                        sb.append(from.charAt(k));
                }
            
                // System.out.println("=================");
                // System.out.println("to = " + to);
                // System.out.println(sb.toString() == to);
                if(sb.toString().contains(to)){
                    return true;
                }
            }
        }
        return false;
    }
}