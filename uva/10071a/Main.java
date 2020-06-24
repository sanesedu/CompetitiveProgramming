
import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) throws IOException{
        
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        String s;
        int v, t, res;

        double a;

        while((s = reader.readLine()) != null){
            
            st = new StringTokenizer(s);
            
            v = Integer.parseInt(st.nextToken());
            t = Integer.parseInt(st.nextToken());

            a = (double)v/t;

            res = (int)Math.round(((1./2)*a*(2*t)*(2*t)));

            System.out.println(res);

        }
        
    }
}
