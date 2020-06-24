
import java.util.*;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner scn = new Scanner(System.in);

        String line;

        while(!(line = scn.nextLine().trim()).equals("*")) {
            if(line.matches("[-+]?\\d+(\\.\\d+([eE][-+]?\\d+)?|[eE][-+]?\\d+)")) {
                System.out.println(line + " is legal.");
            } else {
                System.out.println(line + " is illegal.");
            }
        }

    }

}

