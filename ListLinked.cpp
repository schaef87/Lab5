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
List<DataType>::List(int ignored){
	head = 0;
	cursor = 0;
	size = 0;
}

template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr){
	dataItem = nodeData;
	next = nextPtr;
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

template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error){
	if(isFull()){
		throw logic_error("The list is full");
	} else {
		ListNode* nPtr;
		nPtr = cursor->next;   //IT BREAKS HERE*************************************

		ListNode* newNode = new ListNode(newDataItem, nPtr);
		nPtr = newNode;
		cursor = newNode;
		size++;
	}
}

template <typename DataType>
void List<DataType>::remove() throw (logic_error){
	if(this->isEmpty()){
		throw logic_error("The list is empty");
	} else {
		ListNode* toDelete = this->cursor;
		ListNode* cPos = cursor->next;

		gotoPrior();
		cursor = cPos;

		delete toDelete;
		size--;
	}
}

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error){
	if(this->isEmpty()){
		throw logic_error("The list is empty");
	} else {
		cursor->dataItem = newDataItem;
	}
}

template <typename DataType>
void List<DataType>::clear(){
	if(this->isEmpty()){
		throw logic_error("The list is empty");
	} else {
		do{
			gotoEnd();
			remove();
			size--;
		}while(size > 0);
	}
}


template <typename DataType>
bool List<DataType>::isEmpty() const{
	if(size == 0){
		return true;
	} else {
		return false;
	}
}

template <typename DataType>
bool List<DataType>::isFull() const{
	return false;
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error){
	if(this->isEmpty()){
		throw logic_error("The list is empty");
	} else {
		cursor = head;
	}
}

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error){
	if(this->isEmpty()){
		throw logic_error("The list is empty");
	} else {
		gotoBeginning();

		for(int x = 0; x < size; x++){
			gotoNext();
		}
	}
}

template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error){
	if(this->isEmpty()){
		throw logic_error("The list is empty");
		return false;
	} else if(cursor->next == NULL){
		return false;
	} else {
		cursor = cursor->next;
		return true;
	}

}


template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error){
	if(this->isEmpty()){
		throw logic_error("The list is empty");
		return false;
	} else {
		int count;   //Counts how many elements to the end.
		int retrieve;   //Calculated value.

		while(gotoNext()){
			count++;
		}

		retrieve = size - count;  //What element will be selected after operation.
		gotoBeginning();

		for(int x = 1; x < retrieve;x++){  //Work back to the previous element of the
			gotoNext();                    //original.
		}
		return true;
	}

}

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error){
	if(this->isEmpty()){
		throw logic_error("The list is empty.");
	} else {
		return cursor->dataItem;
	}
}

template <typename DataType>
void List<DataType>::insertBefore(const DataType& newDataItem) throw (logic_error){
	if(this->isEmpty()){
		throw logic_error("The list is empty.");
	} else {
		gotoPrior();
		insert(newDataItem);
	}

}

//void insert(const DataType& newDataItem){
//
//}

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
