
import java.util.*;
import java.io.*;

class Main {

    public static int calc(int a, int b){
        
        if(a == b){
            return 0;
        } else {
            
            return Math.min(Math.min(calc((a+1)%10000, b) + 1, calc((a*2)%10000, b) + 1), calc((a/3)%10000, b) + 1);
        }

    }

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        String s;

        while((s = br.readLine()) != null){
            
            st = new StringTokenizer(s);

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            
            System.out.println(calc(a, b));
        }
    }
}
