#include <iostream>
#include <vector>
using namespace std;

void checkTriangle (vector<int> array, int n)
{
	int length = n * 3;
	for (int i = 0; i < length; i = i + 3)
    {
    	if (array[i] == array[i+1] && array[i] == array[i+2])
    		cout << "Equilateral\n";
    	else if (array[i] == array[i+1] || array[i] == array[i+2] || array[i+1] == array[i+2])
    		cout << "Isosceles\n";
    	else
    		cout << "None of these\n";
    }
}

int main() 
{
    int n;
    int array[10000];
    cin >> n;
    int num;
    int length = n * 3;
    while (length > 0)
    {
    	cin >> num;
    	array.push_back (num);
    	length--;
    }

    checkTriangle (array, n);

    return 0;
}