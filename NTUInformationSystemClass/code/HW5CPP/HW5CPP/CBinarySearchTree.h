#pragma once
#include "CNode.h"
#include <queue>
#include <iostream>
template<class T>
class CBinarySearchTree
{
public:
	CNode<T>* m_Root;
	CBinarySearchTree();
	~CBinarySearchTree();
	bool Insert(T value);
	bool Remove(T value);
	void LevelOrder(CNode<T>* root);
private:
	void DeleteTree(CNode<T>* root);
	CNode<T>* GetEmptyNode(CNode<T>* root, T value);
	CNode<T>* GetDeleteNode(CNode<T>* root, T value);
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
inline bool CBinarySearchTree<T>::Insert(T value)
{
	CNode<T>* insertNode = GetEmptyNode(m_Root, value);
	if (!insertNode)
		return false;
	return SetNode(insertNode, value);
}

template<class T>
inline bool CBinarySearchTree<T>::Remove(T value)
{
	CNode<T>* deleteNode = GetDeleteNode(m_Root, value);
	if (!deleteNode)
		return false;
	return DeleteNode(deleteNode);
}

template<class T>
inline void CBinarySearchTree<T>::LevelOrder(CNode<T>* root) 
{
	if (root->m_IsEmpty)
		return;
	std::queue<CNode<T>*> now;
	now.push(root);

	while (!now.empty()) 
	{
		CNode<T>* next = now.front();
		now.pop();
		if (next->m_IsEmpty == false) // not empty
			std::cout << next->m_Value << ", ";
		if (next->m_Left)
			now.push(next->m_Left);
		if (next->m_Right)
			now.push(next->m_Right);
	}
}

template<class T>
inline void CBinarySearchTree<T>::DeleteTree(CNode<T>* root)
{
	if (root == NULL)
		return;
	DeleteTree(root->m_Left);  // 先砍左邊
	DeleteTree(root->m_Right); // 再砍右邊
	delete root; // 最後把自己砍了
}

template<class T>
inline CNode<T>* CBinarySearchTree<T>::GetEmptyNode(CNode<T>* root, T value)
{
	if (root->m_IsEmpty) // 根是空的(m_IsEmpty = true)
		return root; // 直接回傳這個跟回去
	if (!root->m_IsEmpty && value == root->m_Value)
	{
		std::cout << "Replace value: " << value << std::endl; // 重複的數字出現
		return NULL;
	}
	if (value < root->m_Value) 
	{
		if (root->m_Left->m_IsEmpty) // 往左子樹找
			return root->m_Left;
		else
			return GetEmptyNode(root->m_Left, value); // 繼續往左下子樹找
	}
	else if (value > root->m_Value)
	{
		if (root->m_Right->m_IsEmpty) // 往右子樹找
			return root->m_Right;
		else
			return GetEmptyNode(root->m_Right, value); // 繼續往右下子樹找
	}
	return NULL; // 當作保護
}

template<class T>
inline CNode<T>* CBinarySearchTree<T>::GetDeleteNode(CNode<T>* root, T value)
{
	if (root->m_IsEmpty)
		return NULL;
	if (root->m_Value == value) // 如果要刪除的數字等於根裡的數，那就回傳這個根
		return root;
	else if (value < root->m_Value) // 如果要刪除的數字小於根裡的數，那就往左走再比較
		return GetDeleteNode(root->m_Left, value);
	else if (value > root->m_Value) // 如果要刪除的數字大於根裡的數，那就往右走再比較
		return GetDeleteNode(root->m_Right, value);
	else
		return NULL; // 原則上是不會走到這裡，做一個保護
}

template<class T>
inline bool CBinarySearchTree<T>::SetNode(CNode<T>* node, T value) // 設置node(m_Value, m_IsEmpty)，並長兩隻腳(兩個空節點)
{
	if(!node)
		return false;
	node->m_Left = new CNode<T>; // 先長左腳(空點)
	if (!node->m_Left)
		return false;
	node->m_Right = new CNode<T>; // 再長右腳(空點)
	if (!node->m_Right) // 如果右腳(空點)長失敗
	{
		delete node->m_Left; // 要連前面長成功的左腳(空點)也一起砍掉
		return false;
	}
	node->m_Value = value; // 放值進去囉
	node->m_IsEmpty = false; // 最後把這個node要設成非空點 (m_IsEmpty = false)
	return true; 
}

template<class T>
inline bool CBinarySearchTree<T>::DeleteNode(CNode<T>* node)
{
	if (node->m_Left->m_IsEmpty && node->m_Right->m_IsEmpty) // 下面沒有任何兒子了
	{
		delete node->m_Left; // 先刪左空點
		node->m_Left = NULL; // 把指標指向的地方刪掉了，要馬上把指標重新指向NULL(好習慣!)
		delete node->m_Right;// 再刪右空點
		node->m_Right = NULL;
		node->m_IsEmpty = true; // 最後把這個node要設成空點 (m_IsEmpty = true) 不管裡面有沒有值都沒差
	}
	else if (!node->m_Left->m_IsEmpty && node->m_Right->m_IsEmpty) // 有左子樹，右邊是空的(有一個兒子)
	{
		T regValue = node->m_Value; // 暫存這個node裡面的數值
		node->m_Value = node->m_Left->m_Value; // 兒子取代爸爸
		if (!DeleteNode(node->m_Left)) // 如果刪除失敗
		{
			node->m_Value = regValue; // 恢復原狀
			return false; // 回傳刪除失敗
		}
	}
	else if (node->m_Left->m_IsEmpty && !node->m_Right->m_IsEmpty) // 左邊是空的，有右子樹(有一個兒子)
	{
		T regValue = node->m_Value; // 暫存這個node裡面的數值
		node->m_Value = node->m_Right->m_Value; // 兒子取代爸爸
		if (!DeleteNode(node->m_Right)) // 如果刪除失敗
		{
			node->m_Value = regValue; // 恢復原狀
			return false; // 回傳刪除失敗
		}
	}
	else // 有兩個兒子
	{
		CNode<T>* now = GetMaxInLeftTree(node->m_Left); // 去找左邊最大值
		T regValue = node->m_Value; // 暫存這個node裡面的數值(左邊的最大值)
		node->m_Value = now->m_Value; // 那個最大值取代爸爸
		if (!DeleteNode(now)) // 如果刪除失敗
		{
			node->m_Value = regValue; // 恢復原狀
			return false; // 回傳刪除失敗
		}
	}
	return true;
}

template<class T>
inline CNode<T>* CBinarySearchTree<T>::GetMaxInLeftTree(CNode<T>* root)
{
	CNode<T>* now = root;
	while (!now->m_Right->m_IsEmpty) // 非空點就一直往右下走
		now = now->m_Right; // 要找根的左子樹最大值，就是走到根的左子樹後，就一直往右走
	return now; // 把那個最大值的那個node傳回去
}
