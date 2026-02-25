/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 */
var CBTInserter = function (root) {
    this.root = root
    this.deque = []
    const queue = [this.root]
    while (queue.length > 0) {
        const node = queue.shift()
        if (!node.left || !node.right) {
            this.deque.push(node)
        }
        if (node.left) {
            queue.push(node.left)
        }
        if (node.right) {
            queue.push(node.right)
        }
    }
};

/** 
 * @param {number} val
 * @return {number}
 */
CBTInserter.prototype.insert = function (val) {
    const newNode = new TreeNode(val, null, null)
    const front = this.deque[0]
    this.deque.push(newNode)
    if (!front.left) {
        front.left = newNode
    } else {
        front.right = newNode
        this.deque.shift()
    }
    return front.val
};

/**
 * @return {TreeNode}
 */
CBTInserter.prototype.get_root = function () {
    return this.root
};

/** 
 * Your CBTInserter object will be instantiated and called as such:
 * var obj = new CBTInserter(root)
 * var param_1 = obj.insert(val)
 * var param_2 = obj.get_root()
 */