import java.util.Scanner;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) {

        final Scanner s = new Scanner(System.in);

        int t, n;
        String line;
        TreeSet<Integer> set = new TreeSet<>();

        while (s.hasNext()) {

            line = s.nextLine();

            for (int i = 0; i < line.length(); i++)
                if (line.charAt(i) == 'T') set.add(i + 1);

            t = s.nextInt();
            for (int i = 0; i < t; i++) {
                n = s.nextInt();
                if (set.contains(n)) {
                    System.out.println("AQUI");
                }
                else {

                    Integer leftCost = set.lower(n);
                    if (leftCost == null) leftCost = n;
                    else leftCost = n - leftCost;

                    Integer rightCost = set.higher(n);
                    if (rightCost == null) rightCost = line.length() - n + 1;
                    else rightCost -= n;

                    if (leftCost < rightCost) System.out.println("PENINSULA");
                    else if (rightCost < leftCost) System.out.println("ISLAS");
                    else {
                        int right = line.length() - n + 1;
                        if (n <= right) System.out.println("PENINSULA");
                        else System.out.println("ISLAS");
                    }

                }
            }

            if (s.hasNext()) s.nextLine();
            set.clear();
        }

    }

}
