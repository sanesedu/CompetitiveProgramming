
import java.util.*;
import java.math.BigInteger;

public class Main {
    
    public static void main(String[] args) {
    
        Scanner scn = new Scanner(System.in);

        int n, f;

        int bill = 1;

        while(true) {
            n = scn.nextInt();
            f = scn.nextInt();
            if(n == 0 && f == 0) break;
            scn.nextLine();

            BigInteger bi = BigInteger.ZERO;

            while(n-- != 0) {
                bi = bi.add(new BigInteger(scn.nextLine()));
            }

            BigInteger res = bi.divide(new BigInteger(String.valueOf(f)));

            System.out.println("Bill #" + bill++ + " costs " + bi.toString() + ": each friend should pay " + res.toString() + "\n");
        }
    }

}
