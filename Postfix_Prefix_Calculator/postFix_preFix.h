#pragma once
#include"Stack.h"
#include<iostream>
#include<string>
using namespace std;
/**
* @brief	: Senaryo icin bir class olusturuldu.
*/
class postFix_preFix
{
private:
	string str;
public:
	postFix_preFix();
	~postFix_preFix();
	void getProblem();
	void postfixCalculate();
	void prefixCalculate();
	string prefix_to_postfix();
	void menu();
	void display();
};

