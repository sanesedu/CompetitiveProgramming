
import java.util.*;

public class MarioJumps {
    
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        for(int i = 0; i < n; i++){
            int length = scanner.nextInt();

            int down = 0;
            int up = 0;

            int prev = scanner.nextInt();
            int val;

            for(int j = 1; j < length; j++){
                val = scanner.nextInt();

                if(val > prev){
                    up++;
                } else if (prev > val){
                    down++;
                }

                prev = val;
            }

            System.out.println(up + " " + down);
        }
    }
}   
