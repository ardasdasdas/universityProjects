#pragma once
#include<iostream>
#include<string>
using namespace std;
/**
* @brief	: Yigin icerisinde kullanabilmek icin struct ile bagli liste olusturuldu.
*/
struct StackNode {
	int data;
	StackNode *next;
	StackNode(int e) {
		data = e;
		next = NULL;
	}
};
/**
* @brief	: Yigin veri yapisi icin class olusturuldu.
*/
class stack
{
private:
	StackNode *top1;
public:
	void push(int data);
	int pop();
	int peek();
	bool isEmpty();
	stack();
	~stack();
};
