
import java.util.*;

class Main {

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        long a, b;

        while(scanner.hasNextLine()){
            a = scanner.nextLong();
            b = scanner.nextLong();

            System.out.println(Math.abs(b - a));

            scanner.nextLine();
        }
    }
}
