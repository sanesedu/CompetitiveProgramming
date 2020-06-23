
import java.util.*;

public class LuckyNumbers {

    public static ArrayList<Integer> rem(ArrayList<Integer> data, int d){

        for (int i = 0; i < data.size(); i += d){
            data.set(i, null);
        }

        data.removeAll(Collections.singleton(null));

        return data;
    }

    public static ArrayList<Integer> inv(ArrayList<Integer> data){

        int s = data.size();
        for (int i = 0; i < s/2; i++){
            int temp = data.get(i);
            data.set(i, data.get(s-1-i));
            data.set(s-1-i, temp);
        }

        return data;
    }

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean b = true;

		while(b){
			int n = input.nextInt();

			if (n==0){
			    b = false;
            } else {

			    ArrayList<Integer> list = new ArrayList<>();
                for (int i = 0; i < n; i++){
                    list.add(i+1);
                }

                int d = 2;

                while(d <= list.size()){
                    list = rem(list, d);
                    d++;
                }

                ArrayList<Integer> invert = inv(list);

                StringBuilder sb = new StringBuilder();

                sb.append(n + ":");

                for (int i = 0; i < invert.size(); i++){
                    sb.append(" " + invert.get(i));
                }

                System.out.println(sb);
            }
		}

	}

}
