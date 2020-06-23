
import java.util.*;

public class BalancedParenthesis {

    public static int numOf(String line, char c){
        int openPar = line.length() - line.replace("(", "").length();
        return openPar;
    }

    public static ArrayList<Integer> indexes(String line, String c){
        ArrayList<Integer> opar = new ArrayList<>();
        int n = 0;
        while(line.contains(c)){
            opar.add(line.indexOf(c, n));
            n += line.indexOf(c) + 1;
        }

        return opar;
    }

    public static boolean checkPos(ArrayList<Integer> a, ArrayList<Integer> b, ArrayList<Integer> c, ArrayList<Integer> d){

        boolean res = true;

        if (a.size() > 0 && b.size() > 0){
            int min1 = (a.size() < b.size())? a.size():b.size();

            boolean lower = (a.get(0) < b.get(0));

            for(int i = 1; i < min1; i++){
                if (lower){
                    if (a.get(i) > b.get(i) || c.get(i) > d.get(i)){
                        res = false;
                    }
                } else{
                    if(a.get(i) < b.get(i) || c.get(i) < d.get(i)){
                        res = false;
                    }
                }
            }

        } else {
            res = false;
        }

        return res;
    }

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		while (input.hasNextLine()){
		    String line = input.nextLine().trim();
		    if (!line.isEmpty()){
		        int numop = numOf(line, '(');
		        ArrayList<Integer> indop = indexes(line, "(");

                int numcp = numOf(line, ')');
                ArrayList<Integer> indcp = indexes(line, ")");

                int numoc = numOf(line, '{');
                ArrayList<Integer> indoc = indexes(line, "{");

                int numcc = numOf(line, '}');
                ArrayList<Integer> indcc = indexes(line, "}");

                int numob = numOf(line, '[');
                ArrayList<Integer> indob = indexes(line, "[");

                int numcb = numOf(line, ']');
                ArrayList<Integer> indcb = indexes(line, "]");

                boolean b = (numop == numcp) && (numoc == numcc) && (numob == numcb);

                if (b){
                    b = b && checkPos(indop, indoc, indcp, indcc);

                    b = b && checkPos(indop, indob, indcp, indcb);

                    b = b && checkPos(indoc, indob, indcc, indcb);

                    if (b){
                        System.out.println("YES");
                    } else{
                        System.out.println("NO");
                    }
                } else{
                    System.out.println("NO");
                }

            }
        }

	}

}
