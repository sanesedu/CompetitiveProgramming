
import java.util.*;
import java.io.*;

public class Main {

    public static int lcs(String a, String b){
        
        int[][] memo = new int[a.length()+1][b.length()+1];

        for(int i = 1; i < memo.length; i++){
            
            for(int j = 1; j < memo[0].length; j++){
                
                if(a.charAt(i-1) == b.charAt(j-1)){
                    memo[i][j] = memo[i-1][j-1] + 1;
                } else {
                    memo[i][j] = Math.max(memo[i-1][j], memo[i][j-1]);
                }

            }
        }

        return memo[a.length()][b.length()];
    }
/*
    public static int lcs2(String a, String b){
        
        if(a.length() == 0 || b.length() == 0){
            return 0;
        }

        if(a.charAt(0) == b.charAt(0)){
            return 1 + lcs(a.substring(1, a.length()), b.substring(1, b.length()));
        } else {
            return Math.max(lcs(a.substring(1, a.length()), b), lcs(a, b.substring(1, b.length())));
        }

    }
**/
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        String s, a, b;

        while((s = br.readLine()) != null){
            st = new StringTokenizer(s);

            a = st.nextToken();
            b = st.nextToken();

            System.out.println(lcs(a, b));
        }
    }
}
