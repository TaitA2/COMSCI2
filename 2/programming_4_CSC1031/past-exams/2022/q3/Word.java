import java.lang.String;

public class Word {

    public static void main(String[] args) {
        String s = showLetters("computing", "gpo");
        System.out.println(s);
    }

    public static String showLetters(String s, String chars) {
        char[] sA = s.toCharArray();
        char[] charsA = chars.toCharArray();
        for (int i = 0; i < sA.length; i++) {
            char sc = sA[i];
            boolean found = false;

            for (char cc : charsA) {
                if (sc == cc) {
                    found = true;
                }
            }
            if (!found) {
                sA[i] = '_';
            }
        }
        return String.copyValueOf(sA);
    }

}
