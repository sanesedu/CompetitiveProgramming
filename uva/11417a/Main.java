
import java.util.*;
import java.io.*;

class Main {
    
    public static long gcd(long a, long b){
        
        if(b == 0){
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        boolean b = true;

        while(b){
            
            long n = Long.parseLong(br.readLine());
            
            if(n == 0) {
                b = false;
                break;
            }

            long g = 0;

            for(int i = 1; i < n; i++){
                
                for(int j = 1; j <= n; j++){
                    g += gcd(i, j);
                }   
            }

            System.out.println(g);
        }    
    }
}
