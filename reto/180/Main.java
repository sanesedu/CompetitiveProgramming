
import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; n++){
            
            st = new StringTokenizer(br.readLine());

            int[] arr = new int[3];
            
            for(int j = 0; j < 3; j++){
                arr[j] = Integer.parseInt(st.nextToken());
            }

            if(arr[0] + arr[1] > arr[2] && arr[0] + arr[2] > arr[1] && arr[1] + arr[2] > arr[0]){
                
                Arrays.sort(arr);

                float alpha = (float) Math.acos((arr[0]*arr[0] + arr[1]*arr[1] - arr[2]*arr[2])/(2*arr[0]*arr[1])); 
                alpha = (float) (alpha * 180 / Math.PI);

                System.out.println(alpha);
                
            } else {
                System.out.println("IMPOSIBLE");
            }
        }
    }
}
