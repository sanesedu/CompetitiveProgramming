import java.util.*;

public class Encrypt{

    public static final char REF = 'p';
    public static final String VOWELS = "aeiouAEIOU";

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        boolean b = true;

        while(b){
            String s = scanner.nextLine();
            char[] arr = s.toCharArray();

            int diff = REF - arr[0];
            
            if(diff != 0){
                for(int i = 1; i < arr.length; i++){
                    if(Character.isLetter(arr[i])){
                        int temp = arr[i] + diff;
                        if(temp < 65){
                            arr[i] = (char)('Z' + (diff+1));
                        } else if (temp > 90 && temp < 97 && Character.isLowerCase(arr[i])){
                            arr[i] = (char)('z' + (diff+1));
                        } else if (temp > 90 && temp < 97 && Character.isUpperCase(arr[i])){
                            arr[i] = (char)('A' + (diff-1));
                        } else if (temp > 122){
                            arr[i] = (char)('a' + (diff-1));
                        } else {
                            arr[i] += diff;
                        }
                    }

                }
            }

            if(arr.length == 4 && arr[1] == 'F' && arr[2] == 'I' && arr[3] == 'N'){
                b = false;
            } else {
                
                int num = 0;

                for(int j = 1; j < arr.length; j++){
                    if(VOWELS.indexOf(arr[j]) != -1){
                        num++;
                    }

                }

                System.out.println(num);

            }

        }
    }
}
