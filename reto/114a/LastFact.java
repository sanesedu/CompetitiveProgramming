
import java.util.*;

public class LastFact {

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		int n = input.nextInt();

		for(int i = 0; i < n; i++){
		    int a = input.nextInt();
		    if(a >= 5){
		        System.out.println(0);
            } else{
		        switch (a){
                    case 2:
                        System.out.println(2);
                        break;
                    case 3:
                        System.out.println(6);
                        break;
                    case 4:
                        System.out.println(4);
                        break;
                    default:
                        System.out.println(1);

                }
            }
        }

	}

}
