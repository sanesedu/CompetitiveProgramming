
import java.io.*;
import java.util.*;

public class Gum3 {

	//first element of the array is the received gum, the second one if the remaining envelops

	public static int[] received(int initial, int needed, int reward){
		int[] res = new int[2];

		while (initial>0){
			res[0] += reward * initial;
			res[1] = initial%needed;
			initial /= needed;
		}

		return res;
	}

	public static void main(String[] args) throws IOException{

		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer tokenizer;

		boolean exit = true;

		while(exit){
            tokenizer = new StringTokenizer(reader.readLine());
			int needed = Integer.parseInt(tokenizer.nextToken());
			int reward = Integer.parseInt(tokenizer.nextToken());
			int bought = Integer.parseInt(tokenizer.nextToken());

			if (needed == 0 && reward == 0 && bought == 0){
				exit = false;
			} else {
				if (reward >= needed && bought >= needed){
					System.out.println("RUINA");
				} else {
					int[] rec = received(bought, needed, reward);
					System.out.println(rec[0] + " " + rec[1]);
				}
			}

		}

	}

}

