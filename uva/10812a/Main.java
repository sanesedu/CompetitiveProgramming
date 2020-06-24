
import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        long sum, diff, a, b, f, l;

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            
            sum = Long.parseLong(st.nextToken());
            diff = Long.parseLong(st.nextToken());

            if(diff > sum){
                System.out.println("impossible");
            } else {
                a = (sum + diff)/2;
                if((a * 2) != (sum + diff)) {
                    System.out.println("impossible");
                } else {
                    b = sum - a;
                    System.out.printf("%d %d\n", a, b);
                }
            }

        }
    }
}
