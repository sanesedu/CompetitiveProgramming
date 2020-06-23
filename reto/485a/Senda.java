import java.util.*;
import java.io.*;

public class Senda {

	public static void main(String[] args) throws IOException{
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer tokenizer;

		boolean b = true;

		while(b){

			tokenizer = new StringTokenizer(reader.readLine());

			int n = Integer.parseInt(tokenizer.nextToken());

			if (n==0){
			    break;
            } else {
                String line = reader.readLine();
                String[] sp = line.split("\\s+");

                int[] values = new int[sp.length];

                int total = 0;

                for (int i = 0; i < sp.length; i++){
                    values[i] = Integer.parseInt(sp[i]);
                    total += values[i];
                }

                System.out.print(total);

                int subs = 0;

                for (int j = 0; j < values.length - 1; j++){
                    subs += values[j];
                    System.out.print(" " + (total - subs));

                }

                System.out.println();

            }
		}
		
	}

}
