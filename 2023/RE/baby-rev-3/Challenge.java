import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Challenge {
    private static Character[] flagArray = {'V', 'K', 'U', '{', 'j', 'a', 'v', 'a', '_', 'a', 'l', 's', 'o', '_', 'b', 'e', 'i', 'n', 'g', '_', 'u', 's', 'e', 'd', '_', 'i', 'n', '_', 'r', 'e', 'v', 'e', 'r', 's', 'i', 'n', 'g', '}'};

    public static void main(String[] args) {
        List<Character> flagList = Arrays.asList(flagArray);
        Collections.shuffle(flagList);

        Character[] shuffledFlag = flagList.toArray(new Character[0]);

        String encrypted = encrypt(shuffledFlag);
        System.out.println("Please reverse me to find the flag");
        System.out.println("Flag Encrypted: " + encrypted);
    }

    private static String encrypt(Character[] flagArray) {
        StringBuilder encrypted = new StringBuilder();
        for (char c : flagArray) {
            encrypted.append((char) (c + 1));
        }
        return encrypted.toString();
    }
}
