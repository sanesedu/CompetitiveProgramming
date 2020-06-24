
import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        double a, d;

        for(int i = 0; i < n; i++){
           
            a = (double) Integer.parseInt(br.readLine());

            d = (((((a*567)/9)+7492)*235)/47)-498;

            int res = (int) Math.abs((d/10)%10);

            System.out.println(res);
        }
    }
}
