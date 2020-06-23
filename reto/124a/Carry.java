
import java.util.*;

public class Carry {

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean exit = true;

		while(exit){
		    String a = input.next().trim();
		    String b = input.next().trim();

		    if (a.equalsIgnoreCase("0") && b.equalsIgnoreCase("0")){
		        exit = false;
            } else{

		        String smallest = (a.length() < b.length())? a:b;
		        String largest = (a.length() > b.length())? a:b;

		        long carryNum = 0;
		        boolean carry = false;

		        for(int i = smallest.length() - 1; i >= 0; i--){
                    int sum = Character.getNumericValue(a.charAt(i)) + Character.getNumericValue(b.charAt(i));
                    if (carry){
                        sum += 1;
                    }
		            if (sum >= 10){
		                carryNum += 1;
		                carry = true;
                    } else {
		                carry = false;
                    }
                }

                if (a.length() != b.length()){
                    for (int j = smallest.length(); j < largest.length() && carry; j++){
                        int value = Character.getNumericValue(largest.charAt(j)) + 1;
                        if (value >= 10){
                            carryNum += 1;
                            carry = true;
                        } else {
                            carry = false;
                        }
                    }

                }

                System.out.println(carryNum);

            }
        }

	}

}
