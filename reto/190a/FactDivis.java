
import java.util.*;

public class FactDivis {

    public static void calc(int num, int pos){
        long res = 1;
        for(int i = 0; i < pos; i++){
            res *= num;
            num--;
        }

        System.out.println(res);
    }

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean b = true;

		while(b){
		    int num = input.nextInt();
		    int den = input.nextInt();

		    if(den > num){
		        b = false;
            } else{
		        calc(num, num-den);
            }
        }

	}

}
