class Solution {
  public int minDepth(TreeNode root) {
    if (root == null) return 0;

    var queue = new ArrayDeque<TreeNode>();
    queue.offer(root);

    for (var depth = 1; !queue.isEmpty(); depth++) {
      for (var i = queue.size(); i > 0; i--) {
        var node = queue.poll();

        if (node.left == null && node.right == null)
          return depth;

        if (node.left != null) queue.offer(node.left);
        if (node.right != null) queue.offer(node.right);
      }
    }
    return -1;
  }
}