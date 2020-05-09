package crio.ds.List;

import java.util.*;

// Definition for a Node.
public class Node {
    public int val;
    public Node next;
    public Node random;

    public Node() {}

    public Node(int _val,Node _next,Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }

    public Node makeList(List<Integer> lst, List<String> random) {
        if (lst.size() == 0)
            return null;

        Map<Integer, Node> map = new HashMap<>();
        Node head = null;
        Node trav = null;
        for (int i = 0; i < lst.size(); ++i) {
            trav = new Node(lst.get(i), null, null);
            map.put(i, trav);
            if (i > 0) {
                Node prev = map.get(i-1);
                prev.next = trav;
            } else {
                head = trav;
            }
        }

        trav = head;
        for (int i = 0; i < random.size(); ++i) {
            if (!random.get(i).equals("null")) {
                trav.random = map.get(Integer.valueOf(random.get(i)) - 1);
            }
            trav = trav.next;
        }

        return head;
    }

    public void print(Node head) {
        Node trav = head;

        while (trav != null) {
            if (trav.random != null) {
                System.out.printf("%d %d\n", trav.val, trav.random.val);
            } else {
                System.out.printf("%d null\n", trav.val);
            }
            trav = trav.next;
        }
    }
};


