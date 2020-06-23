
import java.util.*;
import java.io.*;

public class HolaMundo2 {

	public static void main(String[] args) throws IOException {

		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer tokenizer = new StringTokenizer(reader.readLine());

		int a = Integer.parseInt(tokenizer.nextToken());

		for(int i = 0; i < a; i++){
			System.out.print("Hola mundo.\n");
		}

	}

}