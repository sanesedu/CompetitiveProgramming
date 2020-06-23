
import java.util.*;
import java.io.*;

class Main {

    public static final String UPPER ="ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    public static final String LOWER ="abcdefghijklmnopqrstuvwxyz";

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String s;

        boolean b = true;

        char[] end = {'p', 'F', 'I', 'N'};

        while(b){
            
            s = br.readLine();

            int diff = s.charAt(0) - 'p';
            int vowels = 0;
            char[] arr = new char[s.length()];
            arr[0] = 'p';

            for(int i = 1; i < s.length(); i++){
                
                if (s.charAt(i) > 64 && s.charAt(i) < 91) {
                    int j = (s.charAt(i)-65-diff)%26; if (j<0) j+=26;
                    arr[i] = UPPER.charAt(j);
                } else if (s.charAt(i) > 96 && s.charAt(i) < 123){
                    int j = (s.charAt(i)-97-diff)%26; if (j<0) j+=26;
                    arr[i] = LOWER.charAt(j);
                }
                else arr[i] = s.charAt(i);

                if  (arr[i]==65 || arr[i]== 69 || arr[i]== 73 || arr[i]== 79 || arr[i]== 85 ||
                     arr[i]==97 || arr[i]==101 || arr[i]==105 || arr[i]==111 || arr[i]==117) vowels++;

            }

            if(s.length() == 4){
                boolean f = true;

                for(int k = 0; k < arr.length && f; k++){
                    if(arr[k] != end[k]) f = false;
                }     

                if(f){
                    b = false;
                    break;
                }
           } 

           System.out.println(vowels);
           
        }
    }
}
