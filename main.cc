#include <iostream>

using namespace std;
int main()
{

	cout << "******************************" << endl;
	cout << "* *" << endl;
	cout << "* HESAP MAKINESI *" << endl;
	cout << "* *" << endl;
	cout << "* Toplama Icin + kullaniniz *" << endl;
	cout << "* Cikarma Icin - kullaniniz *" << endl;
	cout << "* Carpma Icin * kullaniniz *" << endl;
	cout << "* Bolme Icin / kullaniniz. *" << endl;
	cout << "* *" << endl;
	cout << "* *" << endl;
	cout << "******************************" << endl;
	cout << endl;

	double number1, number2, result;
	char islem;

	cout << "Birinci sayiyi giriniz: ";
	cin >> number1;
	cout << endl;

	cout << "Islemi giriniz: ";
	cin >> islem;
	cout << endl;

	cout << "Ikinci sayiyi giriniz: ";
	cin >> number2;
	cout << endl;

    switch (islem)
	{
	case '+':
		result = (number1 + number2);
		cout << "Toplamanin sonucu: " << result << endl; break;
	case '-':
		result = (number1 - number2);
		cout << "Cikarmanin sonucu: " << result << endl; break;
	case '*':
		result = (number1 * number2);
		cout << "Carpmanin sonucu: " << result << endl; break;
	case '/':
		result = (number1 / number2);
		cout << "Bolmenin sonucu: " << result << endl; break;
	}

    return 0;
}
