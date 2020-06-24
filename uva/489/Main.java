
import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String s, t;
        int a, r, w;

        boolean b = true;

        while(b){
            
            a = Integer.parseInt(br.readLine());

            if(a != -1){

                System.out.printf("Round %d\n", a);

                s = br.readLine().trim();
                t = br.readLine().trim();
               
                w = 0;

                for(int j = 0; j < t.length(); j++){
                    if(s.indexOf(t.charAt(j)) == -1){
                        w++;
                    }
                }

                if(w >= 7){
                    System.out.println("You lose.");
                } else {
                    r = 0;

                    for(int i = 0; i < s.length(); i++){
                        if(t.indexOf(s.charAt(i)) != -1){
                            r++;
                        }
                    }

                    if(r == s.length()){
                        System.out.println("You win.");
                    } else {
                        System.out.println("You chickened out.");
                    }

                }

            } else {
                b = false;
            }

        }
    }
}
