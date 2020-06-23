import java.util.*;
import java.io.*;

public class CuantasPido {

	public static void main(String[] args) throws IOException{
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer tokenizer = new StringTokenizer(reader.readLine());

		int n = Integer.parseInt(tokenizer.nextToken());

		for (int i = 0; i < n; i ++){

			tokenizer = new StringTokenizer(reader.readLine());

			int total = Integer.parseInt(tokenizer.nextToken());
			int bad = Integer.parseInt(tokenizer.nextToken());
			int badOf = Integer.parseInt(tokenizer.nextToken());

			int res = (total / badOf) * bad;

			int diff = total - (total/badOf) * badOf;

			int min = (diff < bad)? diff:bad;

            res += min;

            System.out.println(res);
		}
		
	}

}
