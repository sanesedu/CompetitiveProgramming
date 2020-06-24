
import java.util.*;
import java.io.*;
import java.math.*;

class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        String s;

        while((s = br.readLine()) != null){
            
            st = new StringTokenizer(s);

            int n = Integer.parseInt(st.nextToken());
            BigInteger a = BigInteger.valueOf(Integer.parseInt(st.nextToken()));

            BigInteger res = new BigInteger("0");

            for(int i = 1; i <= n; i++){
                res = res.add(BigInteger.valueOf(i).multiply(a.pow(i))); 
            }

            System.out.println(res);

        }
    }
}
