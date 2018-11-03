#pragma once

namespace NDSBinarySearchTree
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

	class BinarySearchTree
	{

	public:
		BinarySearchTree()
		{
		}

		void createTree(struct TreeNode **BST, int item[0], int count)
		{
			struct TreeNode *tBST = nullptr;
			for (int index = 0; index < count; index++)
			{
				if (tBST == nullptr)
				{
					tBST = *BST;
					tBST->element = item[index];
					tBST->left = nullptr;
					tBST->right = nullptr;
				}
				else
				{
					tBST = *BST;
					while (tBST != nullptr)
					{
						if (tBST->element >= item[index])
						{
							if (tBST->left == nullptr)
							{
								tBST->left = addNode(item[index]);
								break;
							}
							else
							{
								tBST = tBST->left;
							}
						}
						else
						{
							if (tBST->right == nullptr)
							{
								tBST->right = addNode(item[index]);
								break;
							}
							else
							{
								tBST = tBST->right;
							}
						}
					}

				}
			}

		}

		void display(struct TreeNode *BST)
		{
			std::cout << "Binary search tree nodes." << std::endl;

		}
	};
}