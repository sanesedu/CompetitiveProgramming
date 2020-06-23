
import java.util.*;

public class Cubifinito2 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean b = true;

		while(b){

		    long n = input.nextLong();

		    if (n == 0){
		        b = false;
            } else {

				System.out.print(n + " -");
                boolean c = true;
                boolean res = false;
				long prev = 0;

                while(c){

                    long temp = n;
                    long sum = 0;
                    while (temp!=0) {
                        long aux = temp%10;
                        sum += aux*aux*aux;
                        temp /= 10;
                    }

                    if (prev == 1){
                        res = true;
                        c = false;
                    } else {

                        if (prev == sum){
                            c = false;
                        } else if (sum == (1)){
                            res = true;
                            c = false;
                        } else {
                            n = sum;
                        }
                    }

					System.out.print(" " +sum + " -");

					prev = sum;

                }

                System.out.print(">");

                if (!res){
                    System.out.print(" no");
                }

                System.out.print(" cubifinito.\n");

            }

        }
	}

}
