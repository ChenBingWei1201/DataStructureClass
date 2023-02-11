#pragma once
#include "CNode.h"
#include <iostream>
template<class T>
class CBinarySearchTree
{
public:
	CNode<T> m_Root;
	CBinarySearchTree();
	~CBinarySearchTree();
	void Inorder(CNode<T>* root, T value);
	void Preoder(CNode<T>* root, T value);
	void Posoder(CNode<T>* root, T value);
private:
	void DeleteTree(CNode<T>* root);
	CNode<T>* GetEmptyNode(CNode<T>* root, T value);
	CNode<T>* SetDeleteNode(CNode<T>* root, T value);
	bool SetNode(CNode<T>* node, T value);
	bool DeleteNode(CNode<T>* node);
	CNode<T>* GetMaxInLeftTree(CNode<T>* root);
};

template<class T>
inline CBinarySearchTree<T>::CBinarySearchTree()
{
	m_Root = new CNode<T>;
}

template<class T>
inline CBinarySearchTree<T>::~CBinarySearchTree()
{
	DeleteTree(m_Root);
}

template<class T>
inline void CBinarySearchTree<T>::Inorder(CNode<T>* root,T value)
{
	if (root->isEmpty)
		return;
	Inorder(root->m_Left);
	std::cout << root->m_Value << ", ";
	Inorder(root->m_Right);
}

template<class T>
inline void CBinarySearchTree<T>::Preoder(CNode<T>* root, T value)
{
	if(root->isEmpty)
		return;
	std::cout << root->m_Value << ", ";
	Preoder(root->m_Left);
	Preoder(root->m_Right);
}

template<class T>
inline void CBinarySearchTree<T>::Posoder(CNode<T>* root, T value)
{
	if (root->isEmpty)
		return;
	Posoder(root->m_Left);
	Posoder(root->m_Right);
	std::cout << root->m_Value << ", ";
}

template<class T>
inline void CBinarySearchTree<T>::DeleteTree(CNode<T>* root)
{
	if (root == NULL)
		return;
	DeleteTree(m_Root->m_Left);
	DeleteTree(m_Root->m_Right);
	delete root;
}

template<class T>
inline CNode<T>* CBinarySearchTree<T>::GetEmptyNode(CNode<T>* root, T value)
{
	return nullptr;
}

template<class T>
inline CNode<T>* CBinarySearchTree<T>::SetDeleteNode(CNode<T>* root, T value)
{
	if (root->isEmpty)
		return root;
	if (!root->isEmpty && value == root->m_Value)
	{
		std::cout << "Replace value: " << value << "\n";
		return NULL;
	}
	else if (value < root->m_Value)
	{

	}
}

template<class T>
inline bool CBinarySearchTree<T>::SetNode(CNode<T>* node, T value)
{
	return false;
}

template<class T>
inline bool CBinarySearchTree<T>::DeleteNode(CNode<T>* node)
{
	return false;
}

template<class T>
inline CNode<T>* CBinarySearchTree<T>::GetMaxInLeftTree(CNode<T>* root)
{
	return nullptr;
}
