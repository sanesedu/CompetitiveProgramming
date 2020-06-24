
import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        String s; 

        while((s = br.readLine()) != null){
            
            st = new StringTokenizer(s);

            int max = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            
            int[] arr = new int[n];

            for(int i = 0; i < n; i++){
                arr[i] = Integer.parseInt(st.nextToken());
            }
        }
    }
}
