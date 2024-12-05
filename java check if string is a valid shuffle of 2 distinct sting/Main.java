import java.util.Arrays;

public class Test {
    static boolean checkLen(String s1, String s2, String res) {
        return s1.length() + s2.length() == res.length();
    }

    static String sortString(String s) {
        char[] charArray = s.toCharArray();
        Arrays.sort(charArray);
        return new String(charArray);
    }

    static boolean shuffleCheck(String s1, String s2, String res) {
        if (!checkLen(s1, s2, res)) {
            return false;
        }
        
        s1 = sortString(s1);
        s2 = sortString(s2);
        res = sortString(res);
        
        int i = 0, j = 0, k = 0;
        while (k < res.length()) {
            if (i < s1.length() && s1.charAt(i) == res.charAt(k)) {
                i++;
            } else if (j < s2.length() && s2.charAt(j) == res.charAt(k)) {
                j++;
            } else {
                return false;
            }
            k++;
        }
        return true;
    }

    public static void main(String[] args) {
        String s1 = "XY";
        String s2 = "12";
        String[] res = {"1XY2", "Y1X2", "Y21XX"};
        for (String i : res) {
            if (shuffleCheck(s1, s2, i)) {
                System.out.println(i + " is a valid shuffle of " + s1 + " and " + s2);
            } else {
                System.out.println(i + " is not a valid shuffle of " + s1 + " and " + s2);
            }
        }
    }
}
