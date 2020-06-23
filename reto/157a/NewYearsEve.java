
import java.util.*;

public class NewYearsEve {

    public static final int[] daysPerMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    public static final int daysInYear = 365;


	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		int n = input.nextInt();

		for (int i = 0; i < n; i++){
		    int day = input.nextInt();
		    int month = input.nextInt();

		    int total = day;

		    for(int j = 1; j < month; j++){
		        total += daysPerMonth[j];
            }

            int left = daysInYear - total;

            System.out.println(left);
        }

	}

}
