
import java.util.*;
import java.io.*;

class Main {
    
    public static int sum(int a){
        
        if(a == 0){
            return 0;
        } else {
            return a%10 + sum(a/10);
        }
    }

    public static void main(String[] args) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        boolean b = true;

        int a;

        while(b){
            
            a = Integer.parseInt(br.readLine());

            if(a == 0){
                b = false;
            } else {
                
                int res = sum(a);

                while(res > 9){
                    res = sum(res);
                }

                System.out.println(res);
            }
        }
    }
}
