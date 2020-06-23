
import java.util.*;

public class Reversible {

    public static boolean isReversible(int n){
        boolean res = false;

        if (n%10 == 0){
            return false;
        } else{
            int r = reverse(n);
            int diff = n + r;
            String s = String.valueOf(diff);

            int oddCount = 0;

            for (int j = 0; j < s.length(); j++){
                if ((diff%10)%2!=0){
                    oddCount++;
                }
                diff/=10;
            }

            if (oddCount == s.length()){
                res = true;
            }
        }

        return res;
    }

    public static int reverse(int n){
        int num = 0;
        String s = String.valueOf(n);

        for(int i = 0; i < s.length(); i++){
            num = num * 10 + n%10;
            n/=10;
        }

        return num;
    }

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean b = true;

		while(b){
		    int n = input.nextInt();
		    if (n==0){
		        b = false;
            } else{
		        boolean res = isReversible(n);

		        if (res){
		            System.out.println("SI");
                } else{
		            System.out.println("NO");
                }
            }
        }


	}

}
