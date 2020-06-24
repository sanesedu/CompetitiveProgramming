
import java.util.*;
import java.io.*;

class Main {
    
    public static void main(String[] args) throws IOException{

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(reader.readLine());

        int n = Integer.parseInt(st.nextToken());

        int a, b;

        for(int i = 0; i < n; i++){
            
            st = new StringTokenizer(reader.readLine());

            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            if(a == b){
                System.out.println("=");
            } else if (a > b){
                System.out.println(">");
            } else {
                System.out.println("<");
            }

        }


    }
}
