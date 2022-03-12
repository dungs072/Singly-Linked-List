#pragma once
#include<iostream>
#include"Node.h"
template<typename T>
class LinkedList
{
private:
	Node<T>* firstNode;
	Node<T>* lastNode;
	int lengthList;
	Node<T>* CreateNode(T data)
	{
		Node<T>* p = new Node<T>();
		p->data = data;
		p->next = NULL;
		return p;
	}
	void SetListNULL()
	{
		firstNode = NULL;
		lastNode = NULL;
	}
public:
	LinkedList<T>()
	{
		firstNode = NULL;
		lastNode = NULL;
		lengthList = 0;
	}
	~LinkedList<T>()
	{
		Clear();
	}
	void Add(T newData)
	{
		if (firstNode == NULL&&lastNode==NULL)
		{
			firstNode = CreateNode(newData);
			lastNode = new Node<T>();
			lastNode = firstNode;
			lengthList++;
		}
		else
		{
			Node<T> *tempNode = CreateNode(newData);
			lastNode->next = tempNode;
			lastNode = tempNode;
			lengthList++;
		}
	}
	void Insert(T newData, T previousData)
	{
		if (firstNode == NULL) { return; }	
		Node<T>* temp = CreateNode(newData);
		Node<T>* p = FindNode(previousData);
		if (p == NULL) { return; }//cannot insert
		temp->next = p->next;
		p->next = temp;
		if (p == lastNode)
		{
			lastNode = temp;
		}
		lengthList++;
	}
	void Insert(T newData, Node<T>* previousNode)
	{
		//check whether previousNode is in linkedList or not
		if (firstNode == NULL||!Contains(previousNode)) { return; }
		Node<T>* temp = CreateNode(newData);
		temp->next = previousNode->next;
		previousNode->next = temp;
		if (previousNode == lastNode)
		{
			lastNode = temp;
		}
		lengthList++;
	}
	void InsertFirstList(T newData)
	{
		Node<T>* temp = CreateNode(newData);
		if (firstNode == NULL)
		{
			firstNode = temp;
			return;
		}
		temp->next = firstNode;
		firstNode = temp;
		lengthList++;
	}
	void Remove(T dataDelete)
	{
		if (firstNode == NULL) { return; }
		Node<T>* p = firstNode;
		if (dataDelete == firstNode->data)
		{
			if (firstNode->next != NULL)
			{
				firstNode = firstNode->next;
			}	
			delete p;
			if (lastNode == p && firstNode == p)
			{
				SetListNULL();
			}
			p = NULL;
			lengthList--;
			return;
		}
		p = FindNode(dataDelete);
		if (p == NULL) { return; }// not have data in linked List
		Node<T>* prevNode = FindPreviousNode(p);
		prevNode->next = p->next;
		if (p == lastNode)
		{
			lastNode = prevNode;
		}
		p->next = NULL;
		delete p;
		if (p == lastNode && p == firstNode)
		{
			SetListNULL();
		}
		p = NULL;
		lengthList--;
		return;
	}
	void RemoveFirst()
	{
		if (firstNode == NULL) { return; }
		Node<T>* p = firstNode;
		if (firstNode->next != NULL)
		{
			firstNode = firstNode->next;
		}	
		delete p;
		if (p == lastNode)
		{
			SetListNULL();
		}
		p = NULL;
		lengthList--;
	}
	void RemoveLast()
	{
		if (lastNode == NULL) { return; }
		Node<T>* p = lastNode;
		if (lastNode != firstNode)
		{
			lastNode = FindPreviousNode(lastNode);
			lastNode->next = NULL;
		}
		delete p;
		if (p == firstNode)
		{
			SetListNULL();
		}
		p = NULL;
		lengthList--;
		
	}
	Node<T> *FindPreviousNode(T data)
	{
		if (firstNode == NULL) { return NULL; }
		if (data == firstNode->data)
		{
			return NULL;
		}
		Node<T> * p = firstNode;
		while (p->next!= NULL)
		{
			if (p->next->data == data)
			{
				return p;
			}
			p = p->next;
		}
		return NULL;
	}
	Node<T> *FindPreviousNode(Node<T>* node)
	{
		if (firstNode == NULL) { return NULL; }
		if (node == firstNode) { return NULL; }
		Node<T>* p = firstNode;
		while (p->next != NULL)
		{
			if (p->next == node)
			{
				return p;
			}
			p = p->next;
		}
		return NULL;
	}
	void DisplayNode()
	{
		//std::cout << firstNode->data << std::endl;
		if (firstNode == NULL) { std::cout << "list is Null" << std::endl; return; }
		Node<T>* p = firstNode;
		while (p != NULL)
		{
			std::cout << p->data << std::endl;
			p = p->next;
		}
	}
	void Reverse()
	{
		if (firstNode == NULL) { return; }
		Node<T>* p = firstNode;
		Node<T>* q = NULL;
		Node<T>*r = NULL;
		while (p != NULL)
		{
			r = q;
			q = p;
			p = p->next;
			q->next = r;
		}
		firstNode = q;
	}
	bool Contains(T data)
	{
		Node<T>* p = FindNode(data);
		return p != NULL ? true : false;
	}
	bool Contains(Node<T>* node)
	{
		Node<T>* p =FindNode(node);
		return p != NULL ? true : false;
	}
	Node<T>* FindNode(T data)
	{
		if (firstNode == NULL) { return NULL; }
		Node<T> * p = firstNode;
		while (p != NULL)
		{
			if (p->data == data)
			{
				return p;
			}
			p = p->next;
		}
		return NULL;
	}
	Node<T>* FindNode(Node<T>* node)
	{
		if (firstNode == NULL) { return NULL; }
		Node<T>* p = firstNode;
		while (p != NULL)
		{
			if (p == node)
			{
				return p;
			}
			p = p->next;
		}
		return NULL;
	}
	int Length()
	{
		return lengthList;
	}
	void Clear()
	{
		if (firstNode == NULL) { return; }
		Node<T>* p = firstNode;
		while (p != NULL)
		{
			firstNode = firstNode->next;
			p->next = NULL;
			delete p;
			if (p == lastNode)
			{
				SetListNULL();
			}
			p = NULL;
			p = firstNode;
			lengthList--;
		}
	}
	Node<T>* First()
	{
		return firstNode;
	}
	Node<T>* Last()
	{
		return lastNode;
	}
	bool IsEmptyList()
	{
		return lengthList == 0;
	}
};

