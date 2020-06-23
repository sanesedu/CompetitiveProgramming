
import java.util.*;

public class Polidivisible {
    
    public static boolean poli(int n, int l){
        if(l == 0){
            return true;
        } else {
            if(n % l == 0){
                return poli(n/10, l-1);
            } else {
                return false;
            }
        }
    }

    public static int length(int n){
        int t = 0;

        while(n > 0){
            n /= 10;
            t++;
        }

        return t;
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        while(scanner.hasNext()){
            int a = scanner.nextInt();

            if(poli(a, length(a))){
                System.out.println("POLIDIVISIBLE");
            } else {
                System.out.println("NO POLIDIVISIBLE");
            }
        }   
    }
}
