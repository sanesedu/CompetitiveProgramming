
import java.util.*;
import java.io.*;

class Mainold1 {
    
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s, res;

        boolean end = false;

        int c = 0;

        while((s = br.readLine()) != null){
            
            if(c != 0){
                System.out.println();
            }
            res = "";

            int ind = s.indexOf("\"");
            int prevind = -1;
            
            while(ind != -1){
                
                if(end){
                    res += s.substring(prevind + 1, ind);
                    res += "\'\'";
                    end = false;
                } else {
                    res += s.substring(prevind + 1, ind);
                    res += "``";
                    end = true;
                }
                prevind = ind;
                ind = s.indexOf("\"", prevind + 1);
            }

            res += s.substring(prevind + 1, s.length()); 

            System.out.print(res);
            c++;
        }
    }
}
