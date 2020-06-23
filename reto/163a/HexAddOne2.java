
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class HexAddOne2 {

    public static final char[] hexDigits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

		boolean b = true;

		while(b){
			String line = reader.readLine().toUpperCase();

            if (line.equalsIgnoreCase("FIN")){
                b = false;
            } else{
                char[] original = line.toCharArray();

                char[] duplicate = new char[original.length+1];
                duplicate[0] = '0';

                for (int i = 1; i <= original.length; i++){
                    duplicate[i] = original[i-1];
                }

                boolean cont = true;

                for (int j = 1; j<= duplicate.length && cont; j++){
                    int pos = -1;

                    for (int k = 0; pos == -1; k++){
                        if (duplicate[duplicate.length-j]=='F'){
                            pos = 15;
                            duplicate[duplicate.length-j] = '0';
                        } else if (duplicate[duplicate.length-j] == hexDigits[k]){
                            pos = k;
                            duplicate[duplicate.length-j] = hexDigits[pos+1];
                            cont = false;
                        }
                    }
                }

                boolean z = false;

                for (int h = 0; h < duplicate.length; h++){
                    if (duplicate[h] != '0'){
                        z = true;
                    }

                    if (z){
                        System.out.print(duplicate[h]);
                    }

                }

                System.out.println();

            }
		}

	}

}
