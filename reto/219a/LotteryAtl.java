import java.util.*;

public class LotteryAtl {

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        for(int i = 0; i < n; i++){
            int a = scanner.nextInt();
            int count = 0;

            for(int j = 0; j < a; j++){
                if(scanner.nextInt() % 2 == 0){
                    count++;
                }
            }
            System.out.println(count);
        }
    }
}
