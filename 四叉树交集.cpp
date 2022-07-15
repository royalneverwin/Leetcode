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
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        Node *ret = new Node;
        if(quadTree1->isLeaf == true) {
            if(quadTree1->val == true) {
                return quadTree1;
            }
            else {
                return quadTree2;
            }
        }
        else if(quadTree2->isLeaf == true) {
            if(quadTree2->val == true) {
                return quadTree2;
            }
            else {
                return quadTree1;
            }
        }
        else { // 都被分成了4份
            ret->val = true; // 不重要
            ret->isLeaf = false;
            ret->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
            ret->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
            ret->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            ret->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
            // 可能会有合并
            if(ret->topLeft->isLeaf == true && ret->topRight->isLeaf == true &&
               ret->bottomLeft->isLeaf == true && ret->bottomRight->isLeaf == true &&
               ret->topLeft->val == ret->topRight->val &&
               ret->topRight->val == ret->bottomLeft->val &&
               ret->bottomLeft->val == ret->bottomRight->val) {
                ret->isLeaf = true;
                ret->val = ret->topLeft->val;
                ret->topLeft = nullptr;
                ret->topRight = nullptr;
                ret->bottomLeft = nullptr;
                ret->bottomRight = nullptr;
            }
            return ret;
        }
    }
};