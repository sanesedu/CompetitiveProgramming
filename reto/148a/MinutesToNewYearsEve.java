
import java.util.*;

public class MinutesToNewYearsEve {

    public static final int midnight = 24 * 60;

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean b = true;

		while (b){
		    String time = input.next();

		    if (time.equalsIgnoreCase("00:00")){
		        b = false;
            } else{

		        String[] sp = time.split(":");

		        int hour = Integer.parseInt(sp[0]);
		        int min = Integer.parseInt(sp[1]);

		        int minutes = hour * 60 + min;

		        System.out.println(midnight - minutes);

            }

        }

	}

}
