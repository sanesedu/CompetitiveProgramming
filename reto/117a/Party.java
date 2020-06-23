
import java.util.*;

public class Party {

    public static void hola(String s){
        if(!s.trim().isEmpty()){
            String[] sp = s.split("\\s+");
            String name = sp[1];

            String res = "Hola, " + name + ".";

            System.out.println(res);
        }
    }

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		int n = input.nextInt();

		String s = input.nextLine();

		for(int i=0; i < n; i++) {
            s = input.nextLine();
            hola(s);

        }

	}

}
