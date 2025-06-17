#include <iostream>
#include <windows.h>
#include <algorithm>
using namespace std;

class Array {
	int* data; // �������� �� �������� ��������� �����
	unsigned int length;

public:
	Array() {
		data = nullptr;
		length = 0;
		cout << "�������� ������ �����\n";
	}

	Array(int ar[], unsigned int size) {
		if (size > 1000000) throw "error!\n";

		// ���� � ���� � ����-��������, �� ���� ����� � ����������� ����� ���� ��Ĳ���� ���'��� �������� �� ��� ��������
		length = size;
		data = new int[length];
		for (int i = 0; i < length; i++) {
			data[i] = ar[i];
		}
		cout << "�������� �������� ����� �� " << size << " ��������\n";
	}

	// ����������� - �����, � ���� �� ����������� ���� ��������� ��'���� (�������� �������� � ����, �������� ���'��� �� ����-���������)
	// ���������� - �����, ���� ����������� ����������� ������������ ����� ���, �� ��'��� ���� �������.
	// 1) ��� ����� ������� ���������� � ������������ �� ��'��� ��������� ��������
	// 2) ���'��� ������� �� ����-��������� ���� ���� �������� ���� ���

	void Print() const {
		if (length == 0) {
			cout << "����� ������, ���� ���� ���������� :(\n";
		}
		else {
			cout << "�������� ������: ";
			for (int i = 0; i < length; i++)
			{
				cout << data[i];
				cout << (i == length - 1 ? "." : ", ");
			}
			cout << "\n";
		}
	}

	unsigned int GetLength() const {
		return length;
	}

	void AddToBack(int value) {
		// ������ ����� �����, � ����� ���� �� 1 ������� �����
		int* temp = new int[length + 1];
		// ����������� �������� � ������� ������ � �����
		for (int i = 0; i < length; i++)
		{
			temp[i] = data[i];
		}
		// � ����� ������ ������ ������ �������� �������� ����� ��������
		temp[length] = value;
		// ������ ����� ����� ���������, ������ ���� ����� ���'��
		delete[] data;
		// ������������� �������� �������� � ������� ������ (����� ������ ��� � �� ����), �� ����� �����
		data = temp;
		// ��� �� �������� ��������� 1 �������� � ����� ������, �� ���� ������� ����� +1 
		length++;
	}

	void RemoveFromBack() {
		if (length == 0) {
			cout << "���� ���� ��������, ����� ��� ������!\n";
			return; // ���� ���� ���� ��������, �� ������ ����� �� ������
			// throw "�������! �������� ����!";
		}
		length--;
		int* temp = new int[length];
		for (int i = 0; i < length; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
	}

	void AddToFront(int value) {
		// ������ ����� �����, � ����� ���� �� 1 ������� �����
		int* temp = new int[length + 1];
		// ����������� �������� � ������� ������ � �����
		for (int i = 0; i < length; i++)
		{
			temp[i + 1] = data[i];
		}
		// �� ������� ������ ������ ������ �������� �������� ����� ��������
		temp[0] = value;
		// ������ ����� ����� ���������, ������ ���� ����� ���'��
		delete[] data;
		// ������������� �������� �������� � ������� ������ (����� ������ ��� � �� ����), �� ����� �����
		data = temp;
		// ��� �� �������� ��������� 1 �������� � ����� ������, �� ���� ������� ����� +1 
		length++;
	}

	void RemoveFromFront() {
		if (length == 0) {
			cout << "���� ���� ��������, ����� ��� ������!\n";
			return; // ���� ���� ���� ��������, �� ������ ����� �� ������
			// throw "�������! �������� ����!";
		}
		length--;
		int* temp = new int[length];
		for (int i = 1; i < length + 1; i++)
			temp[i - 1] = data[i];
		delete[] data;
		data = temp;
	}

	void SortAZ() {
		sort(data, data + length);
	}

	void Shuffle() {
		for (int i = 0; i < 10000; i++)
		{
			int ri1 = rand() % length;
			int ri2 = rand() % length;
			swap(data[ri1], data[ri2]);
		}
	}

	void Add10RandomNumbers() {
		for (int i = 0; i < 10000; i++)
			AddToBack(rand() % 100);
	}

	void Insert(int value, int index) {
		if (index < 0 || index > length) {
			cout << "eror\n";
			return;
		}
		int* temp = new int[length + 1];
		for (int i = 0, j = 0; i < length + 1; i++) {
			if (i == index)
				temp[i] = value;
			else
				temp[i] = data[j++];
		}
		delete[] data;
		data = temp;
		length++;
	}

	void RemoveAt(int index) {
		if (index < 0 || index >= length) {
			cout << "eror\n";
			return;
		}
		int* temp = new int[length - 1];
		for (int i = 0, j = 0; i < length; i++) {
			if (i != index)
				temp[j++] = data[i];
		}
		delete[] data;
		data = temp;
		length--;
	}

	void RemoveByValue(int value) {
		int count = 0;
		for (int i = 0; i < length; i++)
			if (data[i] == value) count++;
		if (count == 0) return;

		int* temp = new int[length - count];
		for (int i = 0, j = 0; i < length; i++)
			if (data[i] != value)
				temp[j++] = data[i];
		delete[] data;
		data = temp;
		length -= count;
	}

	void Clear() {
		delete[] data;
		data = nullptr;
		length = 0;
		cout << "data cleared\n";
	}

	bool IsEmpty() const {
		return length == 0;
	}

	int IndexOf(int value) const {
		for (int i = 0; i < length; i++)
			if (data[i] == value)
				return i;
		return -1;
	}

	int LastIndexOf(int value) const {
		for (int i = length - 1; i >= 0; i--)
			if (data[i] == value)
				return i;
		return -1;
	}

	void Reverse() {
		for (int i = 0; i < length / 2; i++)
			swap(data[i], data[length - 1 - i]);
	}

	// ������� �����������
	// ���������� �� ����� �������������, �� ����� �� ������ ���������!
	~Array() {
		if (data != nullptr) {
			delete[] data;
		}
		cout << "��'��� ���� �������, � ���'��� - ���������!\n";
	}
};