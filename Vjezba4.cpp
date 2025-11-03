#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

using namespace std;

void input_vector(vector<int>& v)
{
	int num;
	cout << "Unesi brojeve, ako uneses 0 prekida se" << endl;

	while (true)
	{
		cin >> num;

		if (num == 0) break;
		v.push_back(num);
	}
	
}

void print_vector(const vector<int>& v)
{
	for (int i = 0; i < v.size(); i++) {
		cout <<v[i];
		if ((i+1) < v.size())
		{
			cout << ",";
		}
		
	}

}



int main()
{
	vector<int>vect;

	input_vector(vect);

	cout << "Vektor glasi:" << endl;;
	print_vector(vect);
	cout << endl;

	vector<int>jedinstveni;

	for (const auto& el:vect) 
	{
		if (find(jedinstveni.begin(), jedinstveni.end(), el) == jedinstveni.end()) {
			jedinstveni.push_back(el);
		}
	}
	cout << "Jedinstveni elementi: ";
	print_vector(jedinstveni);
	cout << endl;

	sort(jedinstveni.begin(), jedinstveni.end(),[](int a, int b)
	{
		return abs(a) < abs(b);
	});
	
	

	return 0;
}