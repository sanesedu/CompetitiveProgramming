
import java.util.*;

public class Rectangle {

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		while(input.hasNext()){
		    int a = input.nextInt();
		    int b = input.nextInt();

		    if (a < 0 || b < 0){
		        break;
            } else{
		        System.out.println(2*(a+b));
            }
        }

	}

}
