
import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        for(int i = 1; i <= n; i++){
            
            int a = Integer.parseInt(br.readLine());
            int b = Integer.parseInt(br.readLine());

            int low = (a % 2 == 0) ? a + 1 : a;

            int res = 0;

            for(int j = low; j <= b; j += 2){
                res += j;
            }

            System.out.printf("Case %d: %d\n", i, res);
        }

    }
}
