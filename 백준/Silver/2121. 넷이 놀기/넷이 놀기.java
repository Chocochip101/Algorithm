import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class Main {

    public static void main(String... args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bf.readLine());
        List<Integer> AandB = Arrays.stream(bf.readLine().split(" ")).map(Integer::parseInt)
                .collect(Collectors.toList());

        int A = AandB.get(0);
        int B = AandB.get(1);

        Set<Point> points = new HashSet<>();

        for (int i = 0; i < N; i++) {
            String[] split = bf.readLine().split(" ");
            points.add(new Point(Integer.parseInt(split[0]), Integer.parseInt(split[1])));
        }

        int ans = 0;
        for(Point p: points){
            if(points.contains(new Point(p.x + A, p.y + B)) && points.contains(new Point(p.x, p.y + B)) && points.contains(new Point(p.x + A, p.y))){
                ans++;
            }
        }
        System.out.println(ans);
    }
}


