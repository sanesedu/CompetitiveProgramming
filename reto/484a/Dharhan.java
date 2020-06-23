import java.util.*;

public class Dhahran4 {

    public static void main(String[] args){

    	Scanner scanner = new Scanner(System.in);

		while(scanner.hasNext()){
			String line = scanner.nextLine().trim();
			int dotPos = line.indexOf('.');
			int index1 = -1;
			boolean b = true;
			int lim = (dotPos >= 0) ? dotPos : line.length();
			int i;
			for(i = 0; i < lim && b; i++){
				if(line.charAt(i) != '0' && line.charAt(i) != '.'){
					index1 = i;
					b = false;
				}
			}

			int index2 = -1;

			if(dotPos != -1){
				b = true;
				for(int j = line.length() - 1; j > dotPos && b; j--){
					if(line.charAt(j) != '0' && line.charAt(j) != '.'){
						index2 = j;
						b = false;
					}
				}

			}

			if(dotPos == -1 && index1 >= 0){
				System.out.println(line.substring(index1));
			} else if(index1 >= 0 && index2 >= 0){
				System.out.println(line.substring(index1, index2 + 1));
			} else if(index1 >= 0){
				System.out.println(line.substring(index1, dotPos));
			} else if(index2 >= 0){
				System.out.println("0" + line.substring(dotPos, index2 + 1));
			} else{
				System.out.println(0);
			}

		}
    }

}
