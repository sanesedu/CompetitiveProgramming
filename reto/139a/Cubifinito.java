
import java.util.*;

public class Cubifinito {

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean b = true;

        ArrayList<Long> arrayList = new ArrayList<>();

		while(b){

		    long n = input.nextLong();
            arrayList.clear();

		    if (n == 0){
		        b = false;
            } else {

                arrayList.add(n);

                boolean c = true;
                boolean res = false;

                while(c){
                    long temp = n;
                    long sum = 0;
                    while (temp!=0) {
                        long aux = temp%10;
                        sum += aux*aux*aux;
                        temp /= 10;
                    }
					
					boolean already = false;

					for(int i = 0; i < arrayList.size(); i++){
						if(arrayList.get(i) == sum){
							already = true;
						}
					}


                    if (already){
                        c = false;
						if(arrayList.get(arrayList.size()-1) == 1){
							res = true;
						}else{
							arrayList.add(sum);
						}
                    } else {

						arrayList.add(sum);

                        if (arrayList.get(arrayList.size()-1).equals(arrayList.get(arrayList.size()-2))){
                            c = false;
                        } else if (arrayList.get(arrayList.size()-1) == (1)){
                            res = true;
                            c = false;
                        } else {
                            n = sum;
                        }
                    }

                }

                StringBuilder sb = new StringBuilder();

                int lim = arrayList.size();

                for (int i = 0; i < lim; i++){
                    if (i != 0) {
                        sb.append(" ");
                    }
                    sb.append(arrayList.get(i));
                    sb.append(" -");
                }

                sb.append(">");

                if (!res){
                    sb.append(" no");
                }

                sb.append(" cubifinito.");

                System.out.println(sb);
            }

        }
	}

}
