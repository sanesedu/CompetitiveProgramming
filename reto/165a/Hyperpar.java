
import java.util.*;

public class Hyperpar {

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean b = true;

		while(b){
		    long n = input.nextLong();
		    if (n < 0){
		        b = false;
            } else{
		        boolean even = true;

		        while(n > 0){
		            long dig = n % 10;

		            if (dig%2!=0){
		                even = false;
		                break;
                    }

		            n /= 10;
                }

                if (even){
                    System.out.println("SI");
                } else{
                    System.out.println("NO");
                }
            }
        }

	}

}
