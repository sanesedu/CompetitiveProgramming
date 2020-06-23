
import java.util.*;

public class ZerosFact {

    public static long zeros (long n){
        long res = 0;

        for (long i = 5; (n/i) >= 1; i *= 5) {
            res += (n/i);
        }

        return res;
    }

    public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		long n = input.nextLong();

		for(long i = 0; i < n; i++){
		    long a = input.nextLong();
		    System.out.println(zeros(a));
        }

	}

}
