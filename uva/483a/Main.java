
import java.util.*;
import java.io.*;

class Main {

    public static String reverse(String s){

        String res = "";

        for(int i = 0; i < s.length(); i++){
            res += s.substring(s.length()-1-i, s.length()-i);
        }

        return res;
    }

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s, res;

        String[] sp;

        while((s = br.readLine()) != null){
            sp = s.split(" ");
            
            res = "";

            for(int i = 0; i < sp.length; i++){
                if(res.length() > 0){
                    res += " ";
                }
                res += reverse(sp[i]);
            }

            System.out.println(res);
        }
    }
}
