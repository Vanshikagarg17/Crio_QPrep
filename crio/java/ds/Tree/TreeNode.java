package crio.ds.Tree;

import java.io.*;
import java.util.*;

public class TreeNode {
    public long val;
    public TreeNode left;
    public TreeNode right;

//    TreeNode () {}

    TreeNode (long x) {
        val = x;
        left = null;
        right = null;
    }

    public static TreeNode makeTreeFromArray(int idx , String tree[] , TreeNode root) {
        if(idx >= tree.length)
            return null;

        if(tree[idx].equals("null"))
            return null;

        long x = Long.parseLong(tree[idx]);
        root = new TreeNode(x);
        root.left = makeTreeFromArray(2*idx + 1  , tree , root.left);
        root.right = makeTreeFromArray(2*idx + 2 , tree , root.right);
        return root;
    }
}
