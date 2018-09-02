#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>
using namespace std;
void bigintadd(int *a, int *b, int c) {
	int i;
	for (i = c; i >= 0; i--) {
		a[i] += b[i];
		if (a[i] >= 10) {
			a[i] -= 10;
			a[i - 1]++;
		}
	}
	return;
}
void bigintdec(int *a, int *b, int c) {
	int i;
	for (i = c; i >= 0; i--) {
		a[i] -= b[i];
		if (a[i] < 0) {
			a[i] += 10;
			a[i - 1]--;
		}
	}
	return;
}
void GreatnumAdd(char *s1, char *s2, char *s3) {
	int a[100] = { 0 }, b[100] = { 0 }, Len1, Len2, c, k, i, p = 0, t = 0, ab = 0;
	bool n1 = false, n2 = false;
	if (s1[0] == '0' && s1[1] == '\0' &&s2[0] == '0'&&s2[1] == '\0') {
		s3[0] = '0'; s3[1] = '\0';
		return;
	}
	s3[0] = '\0';
	Len1 = strlen(s1);
	Len2 = strlen(s2);
	k = Len1 < Len2 ? Len2 : Len1;
	c = k;
	for (i = 0; i < Len1; k--, i++)
		a[k] = s1[Len1 - i - 1] - '0';
	for (k = c, i = 0; i < Len2; k--, i++)
		b[k] = s2[Len2 - i - 1] - '0';
	if (s1[0] == '-') {
		n1 = true; a[c - Len1 + 1] = 0;
	}
	if (s2[0] == '-') {
		n2 = true; b[c - Len2 + 1] = 0;
	}
	for (i = 1; i <= c; i++)
		if (a[i] > b[i])
			ab = 1;
	if (n1 == false && n2 == false) bigintadd(a, b, c);
	else if (n1 == true && n2 == true) {
		bigintadd(a, b, c);
		s3[p++] = '-';
	}
	else if (ab == 1 && n1 == true) {
		bigintdec(a, b, c);
		s3[p++] = '-';
	}
	else if (ab == 1 && n1 == false) {
		bigintdec(a, b, c);
	}
	else if (ab == 0 && n1 == false) {
		bigintdec(b, a, c);
		s3[p++] = '-';
	}
	else	bigintdec(b, a, c);
	if (ab == 0 && ((n1 == false && n2 == true) || (n2 == false && n1 == true))) {
		for (i = 0; i <= c; i++) {
			if (b[i] == 0 && t == 0);
			else {
				s3[p++] = b[i] + '0';	t = 1;
			}
		}
	}
	else 
		for (i = 0; i <= c; i++) 
			if (a[i] == 0 && t == 0);
			else {
				s3[p++] = a[i] + '0';	t = 1;
			}
	if (t == 0||p==0) {
		s3[0] = 0; s3[1] = '\0';
	}
	else
		s3[p] = '\0';
	return;
}
int main() {
    int  n = 0,k;
	char a[1000], b[1000], c[1000];
    cin>>n;

	while ( n--) {
		cin>>a>>b;
        cout<<"Case 1:"<<endl;
        cout<<a<<"+"<<b<<"=";
        GreatnumAdd(a,b,c);
		cout << c << endl<<endl;
	}
	
		return 0;
}