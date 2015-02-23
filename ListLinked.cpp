//*************************************
//
//            LAB 5
//    Created by: Justin Schaefer
//                Pacis Bana
//           Due: 2-3-2015
//
//*************************************


#include "ListLinked.h"

//Constructor. Creates an emtpy list.
template <typename DataType>
List<DataType>::List(int ignored = 0){
	List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr){
		DataType dataItem = nodeData;
		ListNode* next = nextPtr;
	}

	ListNode* head = *ListNode;
	ListNode* cursor = 0;
}
// Copy constructor. Creates a list which is equivalent in content
// to the "other" list.
template <typename DataType>
List<DataType>::List(const List& other)
: head(0), cursor(0){
	operator=(other);
}


// Overloaded assignment operator. Reinitializes the list to be
// equivalent in content to the "other" list.
// Note: we include self-assignment protection by checking whether
// "this" object is identical to the "other" object.
template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other){
	if( this != &other ) {
		clear();
		ListNode *otherPtr = other.head;
		ListNode *holdCursor = 0;
		while( otherPtr != 0 ) {
			insert(otherPtr->dataItem);
			if(otherPtr == other.cursor) {
				holdCursor = cursor;
			}
			otherPtr = otherPtr->next;
		}
		cursor = holdCursor;
	}

	return *this;
}


// Destructor. Frees the memory used by a list.
template <typename DataType>
List<DataType>::~List() {
	clear();
}

//**********************************
//
//            GIVEN CODE
//
//**********************************
template <typename DataType>
void List<DataType>::showStructure() const

// Outputs the items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing and
// debugging purposes only.

{
	if ( isEmpty() )
	{
		cout << "Empty list" << endl;
	}
	else
	{
		for (ListNode* temp = head; temp != 0; temp = temp->next) {
			if (temp == cursor) {
				cout << "[";
			}

			// Assumes that dataItem can be printed via << because
			// is is either primitive or operator<< is overloaded.
			cout << temp->dataItem;

			if (temp == cursor) {
				cout << "]";
			}
			cout << " ";
		}
		cout << endl;
	}
}