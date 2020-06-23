
import java.util.*;

public class Main {

    public static final char[] VOWELS = {'a', 'e', 'i', 'o', 'u'};

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        scanner.nextLine();

        for(int i = 0; i < n; i++){

            String s = scanner.nextLine();

            boolean res = true;

            for(int j = 0; j < VOWELS.length && res; j++){
                if(s.indexOf(VOWELS[j]) == -1){
                    res = false;
                }
            }

            if(res){
                System.out.println("SI");
            } else{
                System.out.println("NO");
            }

        }
    }
}
