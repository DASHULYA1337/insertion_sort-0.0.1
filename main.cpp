#include <iostream>
#include <sstream>

using namespace std;

bool numbers(int & n, int * array)
{
	string string;
	getline(cin, string);
	istringstream stream(string);
	bool success = true;
	for (int i = 0; i < n; ++i) {
		if (!(stream >> array[i])) {
			success = false;
			break;
		}
	}
	return success;
}

int main() {
	int n;

	string s;
	getline(cin, s);
	istringstream stream(s);
	
	if (stream >> n) {
		int * array = new int [n];
		if (numbers(n, array)) {
			int a, j; 
			for (int i = 1; i < n; i++){
				a = array[i];
				j = i - 1; 
				while (array[j] > a && j >= 0){
					array[j + 1] = array[j];
					array[j] = a;
					j--;
				}
			}

			for (int i = 0; i < n; i++) {
				cout << array[i] << " ";
			}
		}
		else {
			cout << "An error has occured while reading input data.";
		}
	}
	return 0;
}
