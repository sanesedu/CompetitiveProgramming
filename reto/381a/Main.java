
import java.util.*;
import java.io.*;

public class Main {

    public static int gcd(int a, int b){
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }   

    public static int lcm(int a, int b){
        
        return (a*b)/gcd(a, b);
    }

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        boolean t = true;

        while(t){
            
            int n = Integer.parseInt(br.readLine());

            if(n == 0){
                t = false;
                break;
            } else {
                
                st = new StringTokenizer(br.readLine());

                int l = 1;
                int temp;

                for(int i = 0; i < n; i++){
                    temp = Integer.parseInt(st.nextToken());
                    l = lcm(l, temp);
                }

                System.out.println(l);
                
            }
        }
    }
}
