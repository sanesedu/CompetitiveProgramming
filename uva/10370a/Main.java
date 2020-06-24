
import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;

        for(int i = 0; i < n; i++){
            
            st = new StringTokenizer(br.readLine());

            int l = Integer.parseInt(st.nextToken());

            int[] arr = new int[l];

            int sum = 0;

            for(int j = 0; j < l; j++){
                arr[j] = Integer.parseInt(st.nextToken());
                sum += arr[j];
            }

            double avg = (double)sum/l;

            int count = 0;

            for(int k = 0; k < arr.length; k++){
                if(arr[k] > avg){
                    count++;
                }
            }

            double res = 100 * (double)count/l;

            String temp = "%";

            System.out.printf("%2.3f%s\n", res, temp);

        }
    }
}
