
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SandCounting {

	public static void main(String[] args) throws IOException {

		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

		boolean b = true;

		while(b){
            int n = Integer.parseInt(reader.readLine());
            if (n == 0){
                b = false;
            } else {
                for (int i = 0; i < n; i++){
                    System.out.print(1);
                }
                System.out.println();
            }
        }
	}

}
