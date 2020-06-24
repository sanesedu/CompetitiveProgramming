
import java.util.*;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner scn = new Scanner(System.in);

        String line;

        while(scn.hasNext()) {
            line = scn.nextLine();
            System.out.println(line.replaceAll("[^a-zA-Z]+", " ").trim().split(" ").length);
        }

    }

}
