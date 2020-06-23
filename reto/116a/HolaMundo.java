
import java.util.*;

public class HolaMundo {

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		int a = input.nextInt();

		for(int i = 0; i < a; i++){
            System.out.print("Hola mundo.\n");
        }

	}

}
