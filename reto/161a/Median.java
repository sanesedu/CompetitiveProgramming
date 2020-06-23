
import java.util.*;

public class Median {

	public static double median(int[] data){
		double med;
		Arrays.sort(data);
		if (data.length%2==0){
			med = (data[data.length/2] + data[data.length/2 - 1])/2.;
		} else {
			med = data[data.length/2];
		}

		return med;
	}

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean b = true;

		while(b){
		    int n = input.nextInt();

		    if (n == 0){
		        b = false;
            } else {
		        int[] arr = new int[n];

		        for (int i = 0; i < arr.length; i++){
		            arr[i] = input.nextInt();
                }

                System.out.println((int)(2*median(arr)));
            }
        }

	}

}
