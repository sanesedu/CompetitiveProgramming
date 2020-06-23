
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        boolean t = true;

        while(t){
            
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if(a == 0 && b == 0){
                t = false;
                break;
            }

            double d = (a*b)/2.;

            System.out.printf("%.1f\n", (double)Math.round(d*10)/10.);
            
        }
    }
}
