
import java.util.*;

public class Kaprekar {
	
	public static final int KAPREKAR = 6174;

    public static void kap(int n) {
        if (n == KAPREKAR) {
            System.out.print(0);
        } else if (largest(n) - smallest(n) == 0) {
            System.out.print(8);
        } else {
            int res = n;
            int i = 0;
            while (res != KAPREKAR) {
                res = largest(res) - smallest(res);
                i++;
            }
            System.out.print(i);
        }
    }

    public static int smallest(int n) {
        int res = 0;
        for (int i = 0; i < 4; i++) {
            switch (i) {
                case 0:
                    res = n % 10;
                    n /= 10;
                    break;
                case 1:
                    if (n % 10 <= res) {
                        res += (n % 10) * 10;
                    } else {
                        res *= 10;
                        res += n % 10;
                    }
                    n /= 10;
                    break;
                case 2:
                    if (n % 10 >= res % 10) {
                        res *= 10;
                        res += n % 10;
                    } else if (n % 10 >= (res / 10) % 10) {
                        res = res - (res / 10) * 10 + (res / 10) * 100 + (n % 10) * 10;
                    } else {
                        res += (n % 10) * 100;
                    }
                    n /= 10;
                    break;
                case 3:
                    if (n % 10 >= res % 10) {
                        res *= 10;
                        res += n % 10;
                    } else if (n % 10 >= (res / 10) % 10) {
                        res = res - (res / 10) * 10 + (res / 10) * 100 + (n % 10) * 10;
                    } else if (n % 10 >= (res / 100) % 10) {
                        res = res - (res / 100) * 100 + (res / 100) * 1000 + (n % 10) * 100;
                    } else {
                        res += (n % 10) * 1000;
                    }
                    n /= 10;
                    break;

            }
        }
        return res;
    }

    public static int largest(int n) {
        int res = 0;
        for (int i = 0; i < 4; i++) {
            switch (i) {
                case 0:
                    res = n % 10;
                    n /= 10;
                    break;
                case 1:
                    if (n % 10 <= res) {
                        res *= 10;
                        res += n % 10;
                    } else {
                        res += (n % 10) * 10;
                    }
                    n /= 10;
                    break;
                case 2:
                    if (n % 10 <= res % 10) {
                        res *= 10;
                        res += n % 10;
                    } else if (n % 10 <= (res / 10) % 10) {
                        res = res - (res / 10) * 10 + (res / 10) * 100 + (n % 10) * 10;
                    } else {
                        res += (n % 10) * 100;
                    }
                    n /= 10;
                    break;
                case 3:
                    if (n % 10 <= res % 10) {
                        res *= 10;
                        res += n % 10;
                    } else if (n % 10 <= (res / 10) % 10) {
                        res = res - (res / 10) * 10 + (res / 10) * 100 + (n % 10) * 10;
                    } else if (n % 10 <= (res / 100) % 10) {
                        res = res - (res / 100) * 100 + (res / 100) * 1000 + (n % 10) * 100;
                    } else {
                        res += (n % 10) * 1000;
                    }
                    n /= 10;
                    break;

            }
        }
        return res;
    }

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in).useLocale(Locale.US);

        int cases = input.nextInt();

        for (int i = 0; i < cases; i++) {
            int num = input.nextInt();
            if (num>=0){
                kap(num);
                System.out.print("\n");

            }

        }

    }

}
