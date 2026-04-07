import java.util.Base64;

interface EncryptionStrategy {
    String encrypt(String text);
}

class EncryptionService {
    EncryptionStrategy strat;

    public void setEncryptionStrategy(EncryptionStrategy strategy) {
        this.strat = strategy;
    }

    public String encrypt(String text) {
        return this.strat.encrypt(text);
    }
}

// class for ceasar encryption
class CaesarCipherEncryption implements EncryptionStrategy {
    protected int shift;

    public CaesarCipherEncryption(int shift) {
        this.shift = shift;
    }

    @Override
    public String encrypt(String text) {
        StringBuilder result = new StringBuilder();
        for (char ch : text.toCharArray()) {
            if (Character.isLetter(ch)) {
                char base = Character.isLowerCase(ch) ? 'a' : 'A';
                ch = (char) ((ch - base + shift) % 26 + base);
            }
            result.append(ch);
        }
        return result.toString();

    }
}

// class for Base64 encryption
class Base64Encryption implements EncryptionStrategy {

    @Override
    public String encrypt(String text) {
        return Base64.getEncoder().encodeToString(text.getBytes());

    }
}

// class for xor encryption
class XOREncryption implements EncryptionStrategy {
    protected char key;

    public XOREncryption(char key) {
        this.key = key;
    }

    @Override
    public String encrypt(String text) {
        StringBuilder result = new StringBuilder();
        for (char ch : text.toCharArray()) {
            result.append((char) (ch ^ key));
        }
        return result.toString();

    }
}

// class for reverse string encryption
class ReverseStringEncryption implements EncryptionStrategy {

    @Override
    public String encrypt(String text) {
        StringBuilder result = new StringBuilder();
        for (int i = text.toCharArray().length - 1; i >= 0; i--) {
            result.append(text.toCharArray()[i]);
        }
        return result.toString();

    }
}

// class for duplicate character encryption
class DuplicateCharacterEncryption implements EncryptionStrategy {

    @Override
    public String encrypt(String text) {
        StringBuilder result = new StringBuilder();
        for (char ch : text.toCharArray()) {
            result.append(ch);
            result.append(ch);
        }
        return result.toString();

    }
}
