
import java.util.*;

public class HowManyReversible {

	public static boolean isReversible(int n){
		boolean res = false;

		String s = String.valueOf(n);

		int sum = 0;
        for(int i = 0; i < s.length();i++){
            sum += n % 10;
            n/=10;
        }

		if (s.length()%2==0){
		    if (sum%2>0){
		        res = true;
            }
        } else {
		    if (sum%2==0){
		        res = true;
            }
        }

		return res;
	}

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

        boolean b = true;

        while(b){
            int n = input.nextInt();
            if (n==0){
                b = false;
            } else{
                int init = 1;
                for (int j = 0; j < n - 1; j++){
                    init *= 10;
                }

                long counter = 0;

                for (int i = init; i < (init*10); i++){
                    if (isReversible(i)){
                        counter++;
                    }

                    if ((i/init)%2 > 0){
                        i++;
                    } else if(i%10>0 && i%10<9){
                        i++;
                    }

                }

                System.out.println(counter);
            }
        }

	}

}
