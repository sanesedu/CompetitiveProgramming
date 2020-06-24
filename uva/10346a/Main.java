
import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        String s;

        int a, b, temp;

        while((s = br.readLine()) != null){
            
            st = new StringTokenizer(s);

            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            temp = a;

            while(temp >= b){
                a += temp/b;
                temp = temp/b + temp%b;
            }

            System.out.println(a);

        }
    }
}
