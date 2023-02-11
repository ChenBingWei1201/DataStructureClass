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
	DeleteTree(root->m_Left);  // ���奪��
	DeleteTree(root->m_Right); // �A��k��
	delete root; // �̫��ۤv��F
}

template<class T>
inline CNode<T>* CBinarySearchTree<T>::GetEmptyNode(CNode<T>* root, T value)
{
	if (root->m_IsEmpty) // �ڬO�Ū�(m_IsEmpty = true)
		return root; // �����^�ǳo�Ӹ�^�h
	if (!root->m_IsEmpty && value == root->m_Value)
	{
		std::cout << "Replace value: " << value << std::endl; // ���ƪ��Ʀr�X�{
		return NULL;
	}
	if (value < root->m_Value) 
	{
		if (root->m_Left->m_IsEmpty) // �����l���
			return root->m_Left;
		else
			return GetEmptyNode(root->m_Left, value); // �~�򩹥��U�l���
	}
	else if (value > root->m_Value)
	{
		if (root->m_Right->m_IsEmpty) // ���k�l���
			return root->m_Right;
		else
			return GetEmptyNode(root->m_Right, value); // �~�򩹥k�U�l���
	}
	return NULL; // ��@�O�@
}

template<class T>
inline CNode<T>* CBinarySearchTree<T>::GetDeleteNode(CNode<T>* root, T value)
{
	if (root->m_IsEmpty)
		return NULL;
	if (root->m_Value == value) // �p�G�n�R�����Ʀr����ڸ̪��ơA���N�^�ǳo�Ӯ�
		return root;
	else if (value < root->m_Value) // �p�G�n�R�����Ʀr�p��ڸ̪��ơA���N�������A���
		return GetDeleteNode(root->m_Left, value);
	else if (value > root->m_Value) // �p�G�n�R�����Ʀr�j��ڸ̪��ơA���N���k���A���
		return GetDeleteNode(root->m_Right, value);
	else
		return NULL; // ��h�W�O���|����o�̡A���@�ӫO�@
}

template<class T>
inline bool CBinarySearchTree<T>::SetNode(CNode<T>* node, T value) // �]�mnode(m_Value, m_IsEmpty)�A�ê��Ⱖ�}(��ӪŸ`�I)
{
	if(!node)
		return false;
	node->m_Left = new CNode<T>; // �������}(���I)
	if (!node->m_Left)
		return false;
	node->m_Right = new CNode<T>; // �A���k�}(���I)
	if (!node->m_Right) // �p�G�k�}(���I)������
	{
		delete node->m_Left; // �n�s�e�������\�����}(���I)�]�@�_�屼
		return false;
	}
	node->m_Value = value; // ��ȶi�h�o
	node->m_IsEmpty = false; // �̫��o��node�n�]���D���I (m_IsEmpty = false)
	return true; 
}

template<class T>
inline bool CBinarySearchTree<T>::DeleteNode(CNode<T>* node)
{
	if (node->m_Left->m_IsEmpty && node->m_Right->m_IsEmpty) // �U���S�������l�F
	{
		delete node->m_Left; // ���R�����I
		node->m_Left = NULL; // ����Ы��V���a��R���F�A�n���W����Э��s���VNULL(�n�ߺD!)
		delete node->m_Right;// �A�R�k���I
		node->m_Right = NULL;
		node->m_IsEmpty = true; // �̫��o��node�n�]�����I (m_IsEmpty = true) ���޸̭����S���ȳ��S�t
	}
	else if (!node->m_Left->m_IsEmpty && node->m_Right->m_IsEmpty) // �����l��A�k��O�Ū�(���@�Ө�l)
	{
		T regValue = node->m_Value; // �Ȧs�o��node�̭����ƭ�
		node->m_Value = node->m_Left->m_Value; // ��l���N����
		if (!DeleteNode(node->m_Left)) // �p�G�R������
		{
			node->m_Value = regValue; // ��_�쪬
			return false; // �^�ǧR������
		}
	}
	else if (node->m_Left->m_IsEmpty && !node->m_Right->m_IsEmpty) // ����O�Ū��A���k�l��(���@�Ө�l)
	{
		T regValue = node->m_Value; // �Ȧs�o��node�̭����ƭ�
		node->m_Value = node->m_Right->m_Value; // ��l���N����
		if (!DeleteNode(node->m_Right)) // �p�G�R������
		{
			node->m_Value = regValue; // ��_�쪬
			return false; // �^�ǧR������
		}
	}
	else // ����Ө�l
	{
		CNode<T>* now = GetMaxInLeftTree(node->m_Left); // �h�䥪��̤j��
		T regValue = node->m_Value; // �Ȧs�o��node�̭����ƭ�(���䪺�̤j��)
		node->m_Value = now->m_Value; // ���ӳ̤j�Ȩ��N����
		if (!DeleteNode(now)) // �p�G�R������
		{
			node->m_Value = regValue; // ��_�쪬
			return false; // �^�ǧR������
		}
	}
	return true;
}

template<class T>
inline CNode<T>* CBinarySearchTree<T>::GetMaxInLeftTree(CNode<T>* root)
{
	CNode<T>* now = root;
	while (!now->m_Right->m_IsEmpty) // �D���I�N�@�����k�U��
		now = now->m_Right; // �n��ڪ����l��̤j�ȡA�N�O����ڪ����l���A�N�@�����k��
	return now; // �⨺�ӳ̤j�Ȫ�����node�Ǧ^�h
}
