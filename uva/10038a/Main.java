
import java.util.*;
import java.io.*;

class Main {
    
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        String s;

        int[] arr, darr;    

        while((s = br.readLine()) != null){
            
            st = new StringTokenizer(s);

            int l = Integer.parseInt(st.nextToken());
            
            arr = new int[l];
            darr = new int[l-1];
            
            arr[0] = Integer.parseInt(st.nextToken());

            for(int i = 1; i < l; i++){
                arr[i] = Integer.parseInt(st.nextToken());

                darr[i-1] = Math.abs(arr[i] - arr[i-1]);

            } 

            Arrays.sort(darr);

            boolean b = true;

            for(int j = 1; j < l && b; j++){
                if(j != darr[j-1]){
                    b = false;
                }
            } 

            if(b){
                System.out.println("Jolly");
            } else {
                System.out.println("Not jolly");
            }
        }
    }
}
