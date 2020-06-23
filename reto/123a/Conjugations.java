import java.util.*;

public class Conjugations {

    public static String[] prons = {"yo", "tu", "el", "nosotros", "vosotros", "ellos"};

    public static String[] prf = {"o", "as", "a", "amos", "ais", "an"};
    public static String[] prs = {"o", "es", "e", "emos", "eis", "en"};
    public static String[] prt = {"o", "es", "e", "imos", "is", "en"};

    public static String[] paf = {"e", "aste", "o", "amos", "asteis", "aron"};
    public static String[] pas = {"i", "iste", "io", "imos", "isteis", "ieron"};
    public static String[] pat = {"i", "iste", "io", "imos", "isteis", "ieron"};

    public static String[] fut = {"e", "as", "a", "emos", "eis", "an"};

    public static void print(String v, char c, String t){
        if(c<97) c += 32;
        String lex = v.substring(0, v.length()-2);
        String[] morf = new String[fut.length];
        switch(t){
            case "A":
                if(c == 'a') morf = prf;
                else if(c == 'e') morf = prs;
                else morf = prt;
                break;
            case "P":
                if(c == 'a') morf = paf;
                else if(c == 'e') morf = pas;
                else morf = pat;
                break;
            case "F":
                lex = v;
                morf = fut;
                break;
        }

        for(int i = 0; i < prons.length; i++){
            System.out.println(prons[i] + " " + lex + morf[i]);
        }
    }

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);
        boolean b = true;

        while(b){
            
            String line = scanner.nextLine();
            String[] sp = line.split(" ");

            String verb = sp[0];
            String tense = sp[1];
            
            char c = verb.charAt(verb.length()-2);
            
            if(tense.equalsIgnoreCase("T")){
                b = false;
                break;
            } else{
                print(verb, c, tense);
            }
            
        }

    }
}
