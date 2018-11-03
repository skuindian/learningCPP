#pragma once

namespace NDSBinaryTree
{
	struct TreeNode
	{
		int element;
		struct TreeNode *left;
		struct TreeNode *right;
	};

	TreeNode *addNode(int data)
	{
		TreeNode *node = new TreeNode;

		node->element = data;
		node->left = nullptr;
		node->right = nullptr;

		return node;
	}

	class BinaryTree
	{

	public:
		BinaryTree()
		{
		}

		TreeNode *createTreeNodes(int element, struct TreeNode *BT)
		{
			if (BT->left != nullptr)
			{
				BT = BT->left;
				createTreeNodes(element, BT);
			}
			else if (BT->right != nullptr)
			{
				BT = BT->right;
				createTreeNodes(element, BT);
			}
			else
			{
				return addNode(element);
			}
		}

		void createTree(struct TreeNode **BT, int item[0], int count)
		{
			struct TreeNode *tBT = nullptr;
			for (int index = 0; index < count; index++)
			{
				if (tBT == nullptr)
				{
					tBT = *BT;
					tBT->element = item[index];
					tBT->left = nullptr;
					tBT->right = nullptr;
				}
				else
				{
					tBT = *BT;
					if (tBT->left == nullptr)
					{
						tBT->left = addNode(item[index]);
					}
					else if (tBT->right == nullptr)
					{
						tBT->right = addNode(item[index]);
					}
					else
					{
						createTreeNodes(item[index], tBT);
					}
				}
			}
		}

		void display(struct TreeNode *BT)
		{
			std::cout << "Binary tree nodes." << std::endl;

		}
	};
}