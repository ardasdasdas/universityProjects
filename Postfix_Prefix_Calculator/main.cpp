/**
* @author	: Muzaffer Arda Uslu -> e-mail -> usluarda60@icloud.com |
* @date		: 25 Kasim 2019 Pazartesi
* @brief	: Bu kod Veri Yapilari Lab 4 icin yazilmis bir koddur. 
*			girilen postfix ve prefix degerleri hesaplayan koddur. Bagli listelerle stack yapisi kullanilmistir.
*/
#include"Stack.h"
#include<locale.h>
#include "postFix_preFix.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "Turkish");
	postFix_preFix p;
	p.menu();
	system("pause");
}