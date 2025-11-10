#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class karta {

	public:
	int broj;
	string zog;
};

class mac {

	vector<karta*>karte;
};

class igrac {

	string ime;
	int bodovi;
	vector<string>kombinacija;
	string zvanje;
};


int main()
{
	karta k; 
	    k.broj = 1;
		k.zog = "Spade";



	return 0;
}