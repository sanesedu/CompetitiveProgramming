
import java.util.*;
import java.math.BigInteger;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner scn = new Scanner(System.in);

        int b;
        BigInteger c, d, res;

        while(true) {
            b = scn.nextInt();
            if(b == 0) break;

            c = new BigInteger(scn.next(), b);
            d = new BigInteger(scn.next(), b);

            res = c.mod(d);

            System.out.println(res.toString(b));
        }

    }

}
