
import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        boolean b = true;

        int tc, c1, c2, p1, p2;

        String res;

        while(b){
            
            tc = Integer.parseInt(br.readLine());

            if(tc != 0){

                st = new StringTokenizer(br.readLine());

                c1 = Integer.parseInt(st.nextToken());
                c2 = Integer.parseInt(st.nextToken());

                for(int i = 0; i < tc; i++){
                    st = new StringTokenizer(br.readLine());
                    p1 = Integer.parseInt(st.nextToken());
                    p2 = Integer.parseInt(st.nextToken());

                    if(p2 == c2){
                        res = "divisa";     
                    } else if(p2 < c2){
                        res = "S";

                        if(p1 == c1){
                            res = "divisa";
                        } else if(p1 < c1){
                            res += "O";
                        } else{
                            res += "E";
                        }

                    } else {
                        res = "N";
                        if(p1 == c1){
                            res = "divisa";
                        } else if(p1 < c1){
                            res += "O";
                        } else{
                            res += "E";
                        }

                    }
                    System.out.println(res);
                }

            } else {
                b = false;
                break;
            }
            
        }
    }
}
