
import java.util.*;
import java.math.BigInteger;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner scn = new Scanner(System.in);

        int n;

        while(scn.hasNext()) {
            n = scn.nextInt();

            BigInteger u = new BigInteger(String.valueOf(n));
            int x = Integer.parseInt(new StringBuilder().append(String.valueOf(n)).reverse().toString());
            BigInteger v = BigInteger.valueOf(x);
            boolean b = u.isProbablePrime(10);

            if(b) {
                boolean p = v.isProbablePrime(10);
                if(n != x && p) {
                    System.out.println(n + " is emirp.");
                } else {
                    System.out.println(n + " is prime.");
                }
            } else {
                System.out.println(n + " is not prime.");
            }

        }

    }

}
