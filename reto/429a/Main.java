
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        boolean t = true;

        while(t){
            
            int h = Integer.parseInt(br.readLine());

            if(h == 0){
                t = false;
                break;
            }

            int[] han = new int[h];

            st = new StringTokenizer(br.readLine());

            for(int i = 0; i < h; i++){
                han[i] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(han);

            int n = Integer.parseInt(br.readLine());
            
            st = new StringTokenizer(br.readLine());

            int[] ships = new int[n];

            for(int j = 0; j < n; j++){
                ships[j] = Integer.parseInt(st.nextToken());

                for(int k = han.length-1; k >= 0; k--){
                    if(han[k] - ships[j] >= 0){
                        han[k] -= ships[j];
                        ships[j] = 0;
                        break;
                    }
                }

                Arrays.sort(han);
            }

            boolean a = true;

            for(int r = 0; r < ships.length && a; r++){
                if(ships[r] != 0) {
                    a = false;
                }
            }

            if(a){
                System.out.println("SI");
            } else {
                System.out.println("NO");
            }

        }
    }
}
