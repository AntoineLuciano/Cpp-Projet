#include <stdio.h>
#include "Chaine.h"

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	Chaine test;
	Chaine test2;
	test2.afficher();
	test2.convertMaj();
	test2.afficher();
	Chaine test3 = test;
	test3.convertMin();
	test3.afficher();
	Chaine b1 = test2 +test3;
	b1.afficher();
	cout <<"\npalindrome :"<<  estPalindrome(test3);
	cout << "\nanagramme : " << estAnagramme(test2,test3);
	Sigle testt;
	testt.afficherSigle();
	Sigle a(testt);
	a.afficherSigle();
	Sigle b = a;
	b.afficherSigle();
	Sigle c = a + b;
	c.afficherSigle();
	c(3);
	c.afficherSigle();
}