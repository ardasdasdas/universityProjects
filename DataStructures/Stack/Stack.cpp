#include "Stack.h"
#include<iostream>
using namespace std;
/**
* @brief	: Constructor fonksiyonu.
*/
stack::stack()
{
	top1 = NULL;
}
/**
* @brief	: Destructor fonksiyonu.
*/
stack::~stack()
{
}
/**
* @brief	: Yiginin icine eleman ekler.
* @param	: int tipinde bir parametre alir, aldigi degeri yiginin icerisine ekler.
*/
void stack::push(int data)
{
	StackNode *p = new StackNode(data);
	p->next = top1;
	top1 = p;	
}
/**
* @brief	: Yigin icerisinden en son eklenen sayiyi cikarir.
*/
int stack::pop()
{
		StackNode *temp = top1;
		top1 = top1->next;
		return temp->data;
}
/**
* @brief	: Yiginin bos mu dolu mu oldugunu kontrol eder.
*/
bool stack::isEmpty() {
	if (top1 == NULL)
		return true;
	else
		return false;
}
/**
* @brief	: Yigine eklenennen son elemani gösterir.
*/
int stack::peek() {
	if (isEmpty()) {
		cout << "Stack is empty!" << endl;
		return -1;
	}
	return top1->data;
}