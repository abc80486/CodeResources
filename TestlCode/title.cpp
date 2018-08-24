#include<locale>
#include<cstdio>
#include<iostream>
#include<string>
#include<fstream>
#define random(x) (rand(x)%x)
#define N 100
using namespace std;
int main() {
	//wifstream wfin("123.txt");
	ifstream tin("124.txt");
	locale china("chs");
	wcin.imbue(china);
	wcout.imbue(china);
	wstring title[N],titleans[N];
	char ans[N];
	int titlenum = 0,t,score=100,q;
	char a;
	// wchar_t wc=L&#39;。&#39;;
	cin >> q;
	do {
		//wcout << s << endl;
		getline(wcin, title[titlenum]);
		getline(wcin, titleans[titlenum]);
		tin>>ans[titlenum]; 
		titlenum++;
	} while (titlenum!=q);
	//wcout << titleans[1];
	do {
		t = rand() % titlenum;
		wcout <<endl<< title[t] << endl << titleans[t]<<endl;
		cin >> a;
		//if (a == '0') break;
		if (a == ans[t]) {
			score += 5;cout << "True   " << "Score: " << score<<endl;
		}
		else {
			score -= 25; cout << "False   " << "Score: " << score<<endl;
		}
	}while (a!='0');
	return 0;
}