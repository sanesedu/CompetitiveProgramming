
import java.util.*;

public class KaprekarNumber {

    public static boolean isKap(long n){

        long l = n*n;

        String s = "0" + String.valueOf(l);

        boolean res = false;

        int lim = s.length();

        for (int i = 1; i < lim; i++){
            long a = Long.parseLong(s.substring(0, i));
            long b = Long.parseLong(s.substring(i));

            if (b!=0 && a + b == n){
                res = true;
                break;
            }
        }

        return res;
    }

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean b = true;

		while(b){
            long n = input.nextInt();
		    if (n==0){
		        b = false;
            } else{
		        if (isKap(n)){
                    System.out.println("SI");
                } else {
		            System.out.println("NO");
                }
            }
        }

	}

}
