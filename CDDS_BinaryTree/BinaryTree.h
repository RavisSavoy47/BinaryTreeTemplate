#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#pragma once
template<typename T>
class TreeNode;

template<typename T>
class BinaryTree
{
public:

	BinaryTree();
	~BinaryTree();

	/// <summary>
	/// Returns whether or not there are any nodes in the list
	/// </summary>
	bool isEmpty() const;
	/// <summary>
	/// Creates a new node that stores the given value and places it into the tree
	/// </summary>
	/// <param name="value">The new value to add to the tree</param>
	void insert(T value);
	/// <summary>
	/// Finds the node with the given value and removes it from the tree
	/// </summary>
	/// <param name="value">The value of the node to search for in the tree</param>
	void remove(T value);
	/// <summary>
	/// Finds and returns a node with the given value in the tree
	/// </summary>
	/// <param name="value">The value of the node to search for</param>
	TreeNode<T>* find(T value);

	void draw(TreeNode<T>* selected = nullptr);

private:
	/// <summary>
	/// Finds the node that matches the value in the list
	/// </summary>
	/// <param name="searchValue">The value of the node to search for</param>
	/// <param name="nodeFound">A pointer that will store the address of the node that was found</param>
	/// <param name="nodeParent">A pointer that will store the address of the parent of the node that was found</param>
	/// <returns>Whether or not a node matching the value could be found</returns>
	bool findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent);

	void draw(TreeNode<T>*, int x, int y, int horizontalSpacing, TreeNode<T>* selected = nullptr);

	TreeNode<T>* m_root = nullptr;
};

#endif

template<typename T>
inline BinaryTree<T>::BinaryTree()
{
}

template<typename T>
inline BinaryTree<T>::~BinaryTree()
{
}

template<typename T>
inline bool BinaryTree<T>::isEmpty() const
{
	if (m_root == nullptr)
		return true;
	return false;
}

template<typename T>
inline void BinaryTree<T>::insert(T value)
{
	//creates a newNode for the value
	TreeNode<T>* newNode = new TreeNode<T>(value);
	//creates a currentNode for the root
	TreeNode<T>* currentNode = m_root;
	bool nodeInserted = false;

	//checks if the the root is null
	if (m_root == nullptr)
	{
		//sets the root to be the new value
		m_root = newNode;
		return;
	}

	//loops until the node is inserted
	while (!nodeInserted)
	{
		//if the value is greater than 
		if (value > currentNode->getData())
		{
			//checks if the currentNode has a right 
			if (currentNode->hasRight())
				//gets the nodes right
				currentNode = currentNode->getRight();

			else
			{
				//set the newNode as the currentNodes right
				currentNode->setRight(newNode);
				nodeInserted = true;
			}
		}

		//if the value is less than 
		else if (value < currentNode->getData())
		{
			//chceks if the currentNode has a left
			if (currentNode->hasLeft())
				//gets the currentNodes left
				currentNode = currentNode->getLeft();
			else
			{
				//set the newNode as the currentNodes left
				currentNode->setLeft(newNode);
				nodeInserted = true;
			}
		}
		//checks if the value and the data are equal
		else if (value == currentNode->getData())
			return;
	}
	return;
}

template<typename T>
inline void BinaryTree<T>::remove(T value)
{
	TreeNode<T>* nodeToRemove = new TreeNode<T>(value);
	TreeNode<T>* nodeParent = new TreeNode<T>();
	TreeNode<T>* currentNode = nullptr;
	bool removed = false;

	if (!findNode(value, nodeToRemove, nodeParent))
		return;

	//to remove a leaf
	if (!nodeToRemove->hasRight() && !nodeToRemove->hasLeft())
	{
		if (nodeToRemove->getData() < nodeParent->getData())
			nodeParent->setLeft(nullptr);
		else if (nodeToRemove->getData() > nodeParent->getData())
			nodeParent->setRight(nullptr);
		else if (!nodeParent->getLeft() && !nodeParent->getRight())
			m_root = nullptr;
		delete nodeToRemove;
	}
	//remove a right with a parent or a left with a parent
	else if (bool(nodeToRemove->hasRight()) ^ bool(nodeToRemove->hasLeft()))
	{
		if (!nodeParent->getLeft() && !nodeParent->getRight() && nodeToRemove->hasLeft())
			m_root = nodeToRemove->getLeft();

		else if (!nodeParent->getLeft() && !nodeParent->getRight() && nodeToRemove->hasRight())
			m_root = nodeToRemove->getRight();

		else if (nodeParent->getData() < nodeToRemove->getData() && nodeToRemove->hasRight())
			nodeParent->setRight(nodeToRemove->getRight());

		else if (nodeParent->getData() < nodeToRemove->getData() && nodeToRemove->hasLeft())
			nodeParent->setRight(nodeToRemove->getLeft());

		else if (nodeParent->getData() > nodeToRemove->getData() && nodeToRemove->hasRight())
			nodeParent->setLeft(nodeToRemove->getRight());

		else if (nodeParent->getData() > nodeToRemove->getData() && nodeToRemove->hasLeft())
			nodeParent->setLeft(nodeToRemove->getLeft());

		delete nodeToRemove;
	}
	return;
}

template<typename T>
inline TreeNode<T>* BinaryTree<T>::find(T value)
{
	//checks if the value is null
	if (value == NULL)
		return nullptr;

	//sets the reutrnNode as the root
	TreeNode<T>* returnNode = m_root;

	//iterates through returnNode
	while (returnNode)
	{
		//if the value is less than 
		if (value < returnNode->getData())
		{
			//finds the left node
			returnNode = returnNode->getLeft();
		}
		//if the value is greater than
		else if (value > returnNode->getData())
		{
			//finds the right node
			returnNode = returnNode->getRight();
		}
		//checks if the returnNode data is equal to its value
		else if (returnNode->getData() == value)
			return returnNode;
	}
	return returnNode;
}

template<typename T>
inline void BinaryTree<T>::draw(TreeNode<T>* selected)
{
	draw(m_root, 400, 40, 400, selected);
}

template<typename T>
inline bool BinaryTree<T>::findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent)
{
	//checks if the search Value is not their
	if (!searchValue || !find(searchValue))
		return false;

	//starts from the root
	nodeFound = m_root;
	//iterates through nodeFound searchValue 
	while (searchValue != nodeFound->getData())
	{
		//sets the parent node
		nodeParent = nodeFound;
		//if the searchValue is less than
		if (searchValue < nodeFound->getData())
		{
			//get the left node
			nodeFound = nodeFound->getLeft();
		}
		//if the searchValue is greater than
		else if (searchValue > nodeFound->getData())
		{
			//get the right node
			nodeFound = nodeFound->getRight();
		}
	}
	return true;
}

template<typename T>
inline void BinaryTree<T>::draw(TreeNode<T>* currentNode, int x, int y, int horizontalSpacing, TreeNode<T>* selected)
{
	//decreases the horizontal space 
	horizontalSpacing /= 2;

	//Chceks if the current node is null
	if(currentNode)
	{
		//Draws the left child of the node has one
		if (currentNode->hasLeft())
		{
			//Draw the horizontal space between the child and current node
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);

			//draws the left child
			draw(currentNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		//Draws the right child of the node has one
		if (currentNode->hasRight())
		{
			//Draw the horizontal space between the child and current node
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			//draws the right child
			draw(currentNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		//Draws the current node
		currentNode->draw(x, y, (selected == currentNode));
	}
}
