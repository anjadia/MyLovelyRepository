#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <Windows.h>
#include <string>
using namespace std;

//Lubimy zmiany
class BinaryNumber
{
	string bin_;
	int dec_;
public:
	BinaryNumber(string bin);
	BinaryNumber(int dec);
	int binToDec();
	int decToBin();
	~BinaryNumber();
};
{
	bool IfBin(string bin) {
		for (int i = 0; i < bin.length(); i++) {
			if (bin[i] != '0' && bin[i] != '1') { return false; break; }
			else { return true; }
		}
	}
	BinaryNumber::BinaryNumber(string bin)
	{
		if (IfBin(bin)) {
			this->bin_ = bin;
		}
	}


	BinaryNumber::BinaryNumber(int dec)
	{
		dec_ = dec;
	}

	int BinaryNumber::binToDec()
	{
		int dec = 0, j = 0;
		for (int i = this->bin_.length() - 1; i >= 0; i--) {
			if (this->bin_[i] == '1') { dec += pow(2, j); }
			j++;
		}
		return dec;
	}

	int BinaryNumber::decToBin() {
		//return dectobin(Dec);
		int bin = 0, i = 0;
		if (dec_ == 0) bin = 0;
		if (dec_ >= 1) {
			while (dec_ > 0) {
				bin += (dec_ % 2)*pow(10, i);
				dec_ = dec_ / 2;
				i++;
			}
		}
		return bin;
	}

	BinaryNumber::~BinaryNumber()
	{

	}
}

long long int Fibonacci(long long int n) {
	if (n == 1) return 1;
	if (n == 0) return 0;
	else {
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

long long int Sum() {
	long long int sum = 0;
	long long int fibo_1 = 1, fibo_2 = 1, fibo_3=0;
	while (fibo_3 < 1'000'000) {
		fibo_3 = fibo_1 + fibo_2;
		if (fibo_3 % 2 == 0) sum += fibo_3;
		fibo_1 = fibo_2;
		fibo_2 = fibo_3;
	}
	return sum;
}

bool Prime(int n) {
	for (int i = 2; i< sqrt(n); i++) {
		if (n%i==0 ) {
			return false;
			break;
		}
		else return true;
	}
}

void IfPrime(int count) {
	if (count == 0 || count == 1) {
		cout << "Only the God knows the truth\n";
	}
	else {
		if (Prime(count)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
}

bool Year(int y) {
	if (y % 100 == 0) {
		if (y % 400 == 0) return true;
		else return false;
	}
	else {
		int end = y % 100;
		if ((y % 100) % 4 == 0) return true;
		else return false;
	}
}

void IfYear(int y) {
	if (y == 0) {
		cout << "Only the God knows the truth\n";
	}
	else {
		if (Year(y)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

int Searching(vector<int> v, int S) {
	int poz = 0;
	if (v[0] > S) return -1;
	if (v[0] == S) return 0;
	else {
		for (int i = 0; i < v.size(); i++) {
			mt19937 gen(time(0));
			uniform_int_distribution<int> dist(i, v.size());
			for (int j = dist(gen); j < v.size(); j++) {
				if (v[j] == S) poz = j;
			 }
		}
		if (poz == 0) return -1;
		else return poz;
	}
	
}

void Menu() {
	int choice = 8;
	char stop = '1';
	while (choice != 7) {
		system("cls");
		cout << "1 - Fibonacci\n"
			"2 - Prime\n"
			"3 - Year\n"
			"4 - Bin to Dec\n"
			"5 - Dec to Bin\n"
			"6 - Searching\n"
			"7 - Exit\n";
			switch (choice) {
				case 1: {	cout << "FIBONACCI" << endl;
					cout << "Sum =" << Sum() << endl;
					break; }
				case 2: {	cout << "PRIME" << endl;
					cout << "3? "; IfPrime(3); cout << endl;
					cout << "14? "; IfPrime(14); cout << endl;
					cout << "563? "; IfPrime(563); cout << endl;
					cout << "0? "; IfPrime(0); cout << endl;
					break; }
				case 3: {	cout << "YEAR" << endl;
					cout << "2000? "; IfYear(2000); cout << endl;
					cout << "14? "; IfYear(14); cout << endl;
					cout << "1563? "; IfYear(1563); cout << endl;
					cout << "2016? "; IfYear(2016); cout << endl;
					cout << "0? "; IfYear(0); cout << endl;
					break; }
				case 4: {	cout << "BIN to DEC" << endl;
					BinaryNumber number("111");
					cout << "111(2) = " << number.binToDec();
					break; }
				case 5: {	cout << "DEC to BIN" << endl;
					BinaryNumber number(101);
					cout << "101(10) = " << number.decToBin() << endl;
					break; }
				case 6: { cout << "SEARCHING" << endl;
					mt19937 genA(time(0));
					uniform_int_distribution<int> distA(0, 100);
					int a = distA(genA);
					mt19937 genB(time(0));
					uniform_int_distribution<int> distB(a, 100);
					int b = distB(genB);
					vector<int> v;
					for (int i = a; i < b; i++) {
						v.push_back(i);
					}
					for (int i = 0; i < v.size(); i++) {
						cout << v[i] << " ";
					}
					cout << "\nWhat are you looking for?\n";
					int S;
					cin >> S;
					int find = Searching(v, S);
					if (find != (-1)) cout << "Your element is on " << find << " position\n";
					else cout << "Element doesn't exist\n";
					break; }
				case 7: {	exit;  break;	}
			}
		cout << "\n";
		cin >> choice;
	}

}

int main() {
	Menu();
	system("pause");
	return 0;
}