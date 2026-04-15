import java.util.*;

class TrieNode {
    Character value;
    Map<Character, TrieNode> children;
    boolean isLeaf;

    public TrieNode(Character val) {
        value = val;
        children = new HashMap<>();
        isLeaf = false;
    }

    public void markAsLeaf() {
        this.isLeaf = true;
    }
}

class PrefixTree {
    private TrieNode root = new TrieNode(' ');

    public void insert(String word) {
        TrieNode cur = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            if (cur.children.get(ch) == null) {
                cur.children.put(ch, new TrieNode(ch));
            }
            cur = cur.children.get(ch);
        }
        cur.markAsLeaf();
    }

    public boolean search(String word) {
        TrieNode cur = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            if (cur.children.get(ch) == null) {
                return false;
            }
            cur = cur.children.get(ch);
        }
        return cur != null && cur.isLeaf;
    }

    public boolean startsWith(String prefix) {
        TrieNode cur = root;
        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix.charAt(i);
            if (cur.children.get(ch) == null) {
                return false;
            }
            cur = cur.children.get(ch);
        }
        return true;
    }

    public void traverse() {

        for (TrieNode child : root.children.values()) {
            rTraverse(child, 0);
        }

    }

    private void rTraverse(TrieNode node, int depth) {
        if (node == null) {
            return;
        }

        String word = "";
        for (int i = 0; i < depth; i++) {
            word = word.concat("  ");
        }

        word = word.concat("  └── " + node.value.toString());

        if (node.isLeaf) {
            word = word.concat(" (end)");
        }
        System.out.println(word);

        for (TrieNode child : node.children.values()) {
            rTraverse(child, depth + 1);
        }

    }
}
