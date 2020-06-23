import java.util.*;

public class RichProblems {

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        for(int i = 0; i < n; i++){
            int num = scanner.nextInt();
            int max = scanner.nextInt();
            int diff = scanner.nextInt();

            int res = max;
            int prev = max;

            for(int j = 1; j < num; j++){
                prev -= diff;
                res += prev;
            }

            System.out.println(res);
        }
    }
}
