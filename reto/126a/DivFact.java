
import java.util.*;

public class DivFact {

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean b = true;

		while(b){
			int p = input.nextInt();
			int n = input.nextInt();

			if(p < 0 && n < 0){
				b = false;
			} else {
			    if (n == 0 && p == 1){
                    System.out.print("YES");
               } else if (n >= p){
					System.out.print("YES");
				} else{
					System.out.print("NO");
				}
				System.out.print("\n");

			}
		}

	}

}
