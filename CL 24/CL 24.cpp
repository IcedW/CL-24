#include "array.h"

int main() {
	SetConsoleOutputCP(1251);
	srand(time(0));

	/*while (true)
	{
		Array a;
		a.Add10RandomNumbers();
	}*/

	Array a;

	a.AddToBack(5);
	a.AddToBack(10);
	a.AddToBack(15);
	a.AddToBack(10);
	a.AddToBack(20);
	a.Print(); // 5, 10, 15, 10, 20.

	a.Insert(99, 2);
	a.Print(); // 5, 10, 99, 15, 10, 20.

	a.RemoveAt(3);
	a.Print(); // 5, 10, 99, 10, 20.

	a.RemoveByValue(10);
	a.Print(); // 5, 99, 20.

	int ind = a.IndexOf(99);
	cout << "IndexOf(99): " << ind << "\n";

	int lastInd = a.LastIndexOf(20);
	cout << "LastIndexOf(20): " << lastInd << "\n";

	a.Reverse();
	a.Print(); // 20, 99, 5

	a.IsEmpty(); // false

	a.Clear();
	a.Print();

	a.IsEmpty(); // true

}