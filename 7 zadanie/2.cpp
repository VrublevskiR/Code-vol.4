#include <iostream>

struct TreeNode
{
    int value;
    int frequency;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), frequency(1), left(nullptr), right(nullptr) {}
};

class FrequencyTree
{
private:
    TreeNode *root;

    void addValue(TreeNode *node, int value)
    {
        if (value == node->value)
        {
            node->frequency++;
        }
        else if (value < node->value)
        {
            if (node->left)
            {
                addValue(node->left, value);
            }
            else
            {
                node->left = new TreeNode(value);
            }
        }
        else
        {
            if (node->right)
            {
                addValue(node->right, value);
            }
            else
            {
                node->right = new TreeNode(value);
            }
        }
    }

    void printInOrder(TreeNode *node)
    {
        if (node)
        {
            printInOrder(node->left);
            std::cout << node->value << " " << node->frequency << std::endl;
            printInOrder(node->right);
        }
    }

public:
    FrequencyTree() : root(nullptr) {}

    void addValue(int value)
    {
        if (!root)
        {
            root = new TreeNode(value);
        }
        else
        {
            addValue(root, value);
        }
    }

    void printValues()
    {
        printInOrder(root);
    }
};

int main()
{
    // Пример использования
    FrequencyTree ftree;

    ftree.addValue(4);
    ftree.addValue(4);

    std::cout << "Output after adding 4 and 4:\n";
    ftree.printValues();

    FrequencyTree ftree2;

    ftree2.addValue(2);
    ftree2.addValue(2);
    ftree2.addValue(2);
    ftree2.addValue(3);
    ftree2.addValue(3);

    std::cout << "\nOutput after adding 2 three times, and 3 twice:\n";
    ftree2.printValues();

    return 0;
}
