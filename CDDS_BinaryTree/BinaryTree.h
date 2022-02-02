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

	void draw(TreeNode<T>* currentNode, int x, int y, int horizontalSpacing, TreeNode<T>* selected = nullptr);

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
	return m_root <= 0;
}

template<typename T>
inline void BinaryTree<T>::insert(T value)
{
	TreeNode<T>* newNode = new TreeNode<T>(value);
	if (newNode < m_root)
	{

	}
	if (newNode > m_root)
	{

	}

}

template<typename T>
inline void BinaryTree<T>::remove(T value)
{
}

template<typename T>
inline TreeNode<T>* BinaryTree<T>::find(T value)
{
	return NULL;
}

template<typename T>
inline void BinaryTree<T>::draw(TreeNode<T>* selected)
{
		
}

template<typename T>
inline bool BinaryTree<T>::findNode(T searchValue, TreeNode<T>*& nodeFound, TreeNode<T>*& nodeParent)
{
	return false;
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
			drawLine(x, y, x - horizontalSpacing, y + 80, RED);

			//draws the left child
			draw(currentNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		//Draws the right child of the node has one
		if (currentNode->hasRight())
		{
			//Draw the horizontal space between the child and current node
			drawLine(x, y, x - horizontalSpacing, y + 80, RED);

			//draws the right child
			draw(currentNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		//Draws the current node
		currentNode->draw(x, y, (selected == currentNode));
	}
}
