
import java.util.*;

public class DigitSum {

    public static String digSum(int n){

        if (n==0){
            return "0 = 0";
        }

        String res = "";

        ArrayList<Integer> digits = new ArrayList<Integer>();

        while(n>0){
            digits.add(n%10);
            n/=10;
        }

        for (int i=0; i<digits.size()/2; i++){
            int temp = digits.get(i);
            digits.set(i, digits.get(digits.size()-1-i));
            digits.set(digits.size()-1-i, temp);
        }

        int sum = 0;
        Iterator<Integer> iter = digits.iterator();

        while(iter.hasNext()){
            int a = iter.next();
            sum += a;
            res += a;
            if (digits.indexOf(a) != digits.size()-1){
                res += " + ";
            } else {
                res += " = ";
            }
            digits.set(digits.indexOf(a), null);
        }


        return res + sum;

    }

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean b = true;

		while(b){
            int i = input.nextInt();
            if(i>=0){
                System.out.println(digSum(i));
            } else{
                b = false;
            }
        }

	}

}
