
import java.util.*;
import java.io.*;

class Main {
    
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        int[] arr = new int[3];

        int counter = 1;

        for(int i = 0; i < n; i++){
            
            st = new StringTokenizer(br.readLine());

            for(int j = 0; j < arr.length; j++){
                arr[j] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(arr);

            System.out.printf("Case %d: %d\n", counter, arr[1]);

            counter++;
        }
    }
}
