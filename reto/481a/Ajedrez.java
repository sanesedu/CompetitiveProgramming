import java.util.*;
import java.io.*;

public class Ajedrez {

	public static void main(String[] args) throws IOException{
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer tokenizer;

		boolean b = true;

		while(b){

			tokenizer = new StringTokenizer(reader.readLine());

			int row = Integer.parseInt(tokenizer.nextToken());
			int col = Integer.parseInt(tokenizer.nextToken());

			if (row == 0 && col == 0){
			    break;
            } else{
			    char resRow = (char) (105 - row);
			    System.out.println(resRow + "" + col);
            }

		}
		
	}

}
