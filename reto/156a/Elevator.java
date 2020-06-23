
import java.util.*;

public class Elevator {

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean b = true;

		while(b){
		    String line = input.nextLine();

		    if (!line.trim().isEmpty()){
                String[] sp = line.split("\\s+");

                int prev = Integer.parseInt(sp[0]);

                if (prev < 0){
                    b = false;
                } else{
                    int distance = 0;
                    for(int i = 1; i < sp.length; i++){
                        int temp = Integer.parseInt(sp[i]);
                        if (temp == -1){
                            break;
                        }
                        distance += Math.abs(prev - temp);
                        prev = temp;

                    }

                    System.out.println(distance);
                }
            }

        }

	}

}
