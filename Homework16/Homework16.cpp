#include <iostream>
#include "Turn.h"
#include "Array.h"
using namespace std;

int main()
{
	/*Turn<char> turn;
	turn.Add('!');
	turn.Add('h');
	turn.Add('g');
	turn.Add('i');
	turn.Add('H');

	turn.Print();

	cout << turn.Derive().Data;
	cout << turn.Derive().Data;
	cout << turn.Derive().Data;
	cout << turn.Derive().Data;
	cout << turn.Derive().Data;

	cout << endl << endl;

	Turn<int> turn2;
	turn2.Add(1);
	turn2.Add(2);
	turn2.Add(3);
	turn2.Add(4);
	turn2.Add(5);

	turn2.Print();

	cout << turn2.Derive().Data;
	cout << turn2.Derive().Data;
	cout << turn2.Derive().Data;
	cout << turn2.Derive().Data;
	cout << turn2.Derive().Data;

	cout << endl << endl;*/

	setlocale(0, "");
	Array<int> test;

	cout << "метод \"GetSize\":\n";
	cout << test.GetSize() << endl << endl;

	test.Add(1);
	test.Add(2);
	test.Add(3);
	cout << "метод \"Add\":\n";
	cout << test << endl << endl;

	cout << "метод \"GetUpperBound\":\n";
	cout << test.GetUpperBound() << endl << endl;

	cout << "метод \"IsEmpty\":\n";
	cout << boolalpha << test.IsEmpty() << endl << endl;

	cout << "метод \"GetSize\" (показываем количество элементов массива, под которые выделена память):\n";
	cout << test.GetSize() << endl << endl;

	test.SetSize(5, 5);
	cout << "метод \"SetSize\" (устанавилваем размер равнывй 5):\n";
	cout << test.GetSize() << endl << endl;

	test.SetAt(3, 4);
	test.SetAt(4, 5);
	cout << "метод \"SetAt\" (устанавилваем значение 4 и 5):\n";
	cout << test << endl << endl;

	cout << "метод \"FreeExtra\" (устанавливаем размер 10, используем фри экстра):\n";
	test.SetSize(10, 5);
	test.FreeExtra();
	cout << test.GetSize() << endl << endl;

	cout << "метод \"GetAt\" (Получаем значение 3-го элемента):\n";
	try {
		cout << test.GetAt(2) << endl << endl;
	}
	catch (int ex) {
		cout << "Error: The element with index " << ex << " does not exist" << endl << endl;
	}

	cout << "метод \"operator[]\" (Получаем значение 3-го элемента):\n";
	try {
		cout << test[2] << endl << endl;
	}
	catch (int ex) {
		cout << "Error: The element with index " << ex << " does not exist" << endl << endl;
	}

	Array<int> test2;
	test2 = test;
	cout << "метод \"operator=\" (создали второй массив и приравняли первому.)\n";
	cout << test2 << endl << endl;

	cout << "метод \"GetData\" (Получаем адрес массива):\n";
	cout << test.GetData() << endl << endl;

	cout << "метод \"Append\" (Прибавили к первому массиву второй):\n";
	test.Append(test2);
	cout << test << endl << endl;

	cout << "метод \"InsertAt\" (Вставили во вторую позицию цифру 256):\n";
	test.InsertAt(2, 256);
	cout << test << endl << endl;

	cout << "метод \"RemoveAt\" (Убрали со второй позиции цифру 256):\n";
	test.RemoveAt(2);
	cout << test << endl << endl;
    
}
