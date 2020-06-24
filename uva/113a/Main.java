
import java.util.*;
import java.io.*;
import java.math.*;

class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String s;

        BigInteger p;
        int n;

        while((s = br.readLine()) != null){
            
            n = Integer.parseInt(s);
            p = new BigInteger(br.readLine());

            boolean b = true;
            BigInteger res;

            int i, j;

            for(i = 1; i <= 1000000000 && b; i++){
                res = new BigInteger(String.valueOf(i));
                res = res.pow(n);
                if(res.equals(p)){
                    b = false;
                    break;
                }
            }

            System.out.println(i);

        }
    }
}
