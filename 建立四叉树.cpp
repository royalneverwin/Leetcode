/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    // return 0, 1 或2, 2表示不是全0或全1
    int constructNode(vector<vector<int>> &grid, int x, int y, int length, Node *node){
        if(length == 1){
            if(grid[x][y]){
                node->val = true;
                node->isLeaf = true;
                return 1;
            }
            else{
                node->val = false;
                node->isLeaf = true;
                return 0;
            }
        }
        else{
            Node *node1 = new Node;
            Node *node2 = new Node;
            Node *node3 = new Node;
            Node *node4 = new Node;
            int ret1 = constructNode(grid, x, y, length / 2, node1);
            int ret2 = constructNode(grid, x, y + length/2, length / 2, node2);
            int ret3 = constructNode(grid, x + length/2, y, length / 2, node3);
            int ret4 = constructNode(grid, x + length/2, y + length / 2, length / 2, node4);
            if(ret1 == 0 && ret2 == 0 && ret3 == 0 && ret4 == 0){
                node->val = false;
                node->isLeaf = true;
                return 0;
            }
            else if(ret1 == 1 && ret2 == 1 && ret3 == 1 && ret4 == 1){
                node->val = true;
                node->isLeaf = true;
                return 1;
            }
            else{
                node->val = true;
                node->isLeaf = false;
                node->topLeft = node1;
                node->topRight = node2;
                node->bottomLeft = node3;
                node->bottomRight = node4;
                return 2;
            }
        }
    }

    Node* construct(vector<vector<int>>& grid) {
        Node *ans = new Node;
        constructNode(grid, 0, 0, grid.size(), ans);

        return ans;
    }
};