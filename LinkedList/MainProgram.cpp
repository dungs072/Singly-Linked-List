#include"LinkedList.h"
#include"Node.h"
using namespace std;
int main()
{
	//Node<int> *temp = new Node<int>();
	//temp->data = 8;
	//temp->next = NULL;
	LinkedList<int>* heel = new LinkedList<int>();
	heel->Add(5);
	heel->Add(6);
	heel->Add(7);
	heel->Add(8);
	heel->Add(9);
	heel->Add(10);
	//heel->Remove(5);
	/*heel->RemoveLast();
	heel->RemoveLast();
	heel->RemoveLast();
	heel->RemoveLast();
	heel->RemoveLast();
	heel->RemoveLast();
	heel->RemoveLast();*/
	
	//cout<<heel->Last()->data;
	/*heel->Remove(10);
	heel->Remove(5);
	heel->Remove(6);
	heel->Remove(7);
	heel->Remove(8);
	heel->Remove(9);*/
	heel->RemoveFirst();
	heel->RemoveFirst();
	heel->RemoveFirst();
	heel->RemoveFirst();
	heel->RemoveFirst();
	heel->RemoveFirst();
	if (heel->Last()==NULL)
	{
		cout << "is Nulllll" << endl;
	}
	if (heel->First() == NULL)
	{
		cout << "is Null" << endl;
	}
	/*if (heel->First() == NULL)
	{
		cout << "is NULL" << endl;
	}
	cout << "length: " << heel->Length() << endl;*/
	//heel->RemoveLast();

	//heel->Clear();

	//heel->Insert(5, 10);
	//heel->InsertFirstList(123);
	//heel->FindNode(10);
	//heel->Remove(10);
	////cout << heel->FindLast()->data;
	//heel->DisplayNode();
	heel->DisplayNode();
	return 0;
}