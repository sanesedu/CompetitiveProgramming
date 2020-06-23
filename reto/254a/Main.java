
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        boolean b = true;

        while(b){
            
            int n = Integer.parseInt(br.readLine());

            if(n == 0){
                b = false;
                break;
            }

            int[] heights = new int[n];
            int[] skis = new int[n];

            st = new StringTokenizer(br.readLine());

            for(int i = 0; i < n; i++){
                heights[i] = Integer.parseInt(st.nextToken());
            }

            st = new StringTokenizer(br.readLine());

            for(int j = 0; j < n; j++){
                skis[j] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(heights);
            Arrays.sort(skis);

            int res = 0;

            for(int k = 0; k < n; k++){
                res += Math.abs(heights[k] - skis[k]);
            }

            System.out.println(res);

        }
        br.close();
    }
}
