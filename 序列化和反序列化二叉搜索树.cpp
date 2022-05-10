/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // 前序遍历
        if(root == nullptr)
            return "";
        else{
            string ret = "";
            string tmp1 = serialize(root->left);
            string tmp2 = serialize(root->right);
            ret = ret + to_string(root->val);
            if(tmp1 == "" && tmp2 == "")
                return ret;
            else if(tmp1 == "")
                return ret + "," + tmp2;
            else if(tmp2 == "")
                return ret + "," + tmp1;
            else
                return ret + "," + tmp1 + "," + tmp2;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0)
            return nullptr;

        int start = 0, end = 0;
        while(end != data.length() && data[end] != ','){
            end++;
        }
        TreeNode *ret = new TreeNode;
        ret->val = stoi(data.substr(start, end - start).c_str());

        if(end == data.length()){
            ret->left = nullptr;
            ret->right = nullptr;
            return ret;
        }
        else{
            end++;
            int beginLeft = end;
            int endLeft;
            start = end;
            while(1){
                while(end != data.length() && data[end] != ','){
                    end++;
                }
                int tmp = stoi(data.substr(start, end - start).c_str());
                if(tmp > ret->val){
                    endLeft = start - 1;
                    break;
                }
                else if(end == data.length()){
                    endLeft = end;
                    break;
                }
                else{
                    end++;
                    start = end;
                }
            }

            if(endLeft < beginLeft)
                ret->left = nullptr;
            else
                ret->left = deserialize(data.substr(beginLeft, endLeft - beginLeft));

            if(endLeft == data.length()){
                ret->right = nullptr;
                return ret;
            }
            else{
                ret->right = deserialize(data.substr(endLeft + 1, data.length() - (endLeft + 1)));
                return ret;
            }
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;