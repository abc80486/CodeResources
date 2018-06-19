#include<locale>
#include<iostream>
#include<string>
using namespace std;
int main(){
    locale china("chs");
    wcin.imbue(china);
    wcout.imbue(china);
    wstring s;
   // wchar_t wc=L&#39;。&#39;;
    while(getline(wcin,s)){
        wcout<<s<<endl;
    }
    return 0;
}