
import java.util.*;

public class HexAddOne {

    public static final String[] hexDigits = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

    public static int getIndex(String s){

        int index = -1;

        for (int i = 0; i < hexDigits.length; i++){
            if (s.equalsIgnoreCase(hexDigits[i])){
                index = i;
            }
        }

        return index;
    }

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean b = true;

		while(b){

		    String s = input.next().toUpperCase();

		    if (s.equalsIgnoreCase("FIN")){
		        b = false;
            } else {

		        String[] sp = s.split("");

		        int carry = 1;
		        int counter = sp.length - 1;

		        while (carry > 0){
		            if (sp[counter].equalsIgnoreCase("F")){
		                sp[counter] = hexDigits[0];
                    } else {
		                sp[counter] = hexDigits[getIndex(sp[counter])+1];
		                carry = 0;
                    }
                    counter--;
		            if (counter < 0){
		                break;
                    }
                }

                StringBuilder sb = new StringBuilder();

				int start = 0;

                if (sp[0].equals(hexDigits[0]) && carry == 1){
                    sb.append(1);

                } else{
					
					while(sp[start].equals("0") && start < sp.length-1){
						start++;
					}

				}
			

                for (int j = start; j < sp.length; j++){
                  	sb.append(sp[j]);
                }

                System.out.println(sb);
        }

        }

	}

}
