//#include "stdafx.h"

  //         /*
#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>
#define N 1100
#pragma warning(disable:4996);
using namespace std;
void GExp(char *a, int n, char *s);
void chang10_2(int a, char *s);
void GExp2_n(char *a, int n, char *s);
void GreatnumAdd(char *s1, char *s2, char *s3);
int GFloatInt(char *a, char *c);
void GIntFloat(char *a, int n, char *c);
void chang(char *a, char *b);
void Gnumdiv(char *s1, char *s);
void GreatnumMul(char *a, int n, char *s);
void Gnum2N(char *r, int n, char *s);
void BothGreatnumMul(char *r1, char *r2, char *s);
void GIntExp(char *r, int n, char *s);
void Gnumfx1(char *s1, char *s2, char *s3);
void GFloatExp(char *a, int n, char *c);
void chang10_2(int a, char *s) {  //a必须为正整数；<512;
	int i=0, k = 0;
	char d[20];
	while (a > 0) {
		d[k++] = (a % 2)+'0';
		a /= 2;
	}
	d[k] = '\0';
	k = 0;
	for (i = 0; d[i]!='\0'; i++) {
		if (d[i]=='1') {
			s[k++] = i+'0';
		}
		
	}
	s[k] = '\0';
}
void GExp2_n(char *a, int n, char *s) { //计算a的2的n次方；
	int i;
	char p[1000], q[1000];
	if (strlen(a) == 0) {
		s[0] = '0'; s[1] = '\0';
		return;
	}
	else {
		chang(s, a);
		chang(p, a);
		chang(q, a);
		for (i = 1; i <= n; i++) {
			BothGreatnumMul(p, q, s);
			chang(p, s);
			chang(q, s);
		}
	}
}
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
	int a[1000] = { 0 }, b[1000] = { 0 }, Len1, Len2, c, k, i, p = 0, t = 0, ab = 0;
	bool n1 = false, n2 = false;
	if (s2[0] == '0'&&s2[1] == '\0') {
		//s3[0] = '0'; s3[1] = '\0';
		chang(s3, s1);
		return;
	}
	if (s1[0] == '0'&&s1[1] == '\0') {
		chang(s3, s2);
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
int GFloatInt(char *a, char *c) {
	int i, s = 0, p = 0, q = 0, k = 0;
	for (i = 0; a[i] != '\0'; i++) {
		if (p == 1) s++;
		if (a[i] == '.') {
			p = 1;
		}
		else if (a[i] == 0) {
			if (q == 1) {
				c[k++] = '0';
			}
		}
		else{
			q = 1; 
			c[k++] = a[i];
		}
		
	}
	c[k] = '\0';
	return s;
}
void GIntFloat(char *a,  int n, char *c) {
	 int i, k = 0,p=0;
	c[0] = '0'; c[1] = '\0';
	if (strlen(a) <= n) {
		//c[k++] = '0';
		c[k++] = '.';
		for (i = 1; i <= (n - strlen(a)); i++)
		{
			c[k++] = '0';
		}
	}
	for (i = 0; a[i] != '\0'; i++) {
		if (i == strlen(a) - n && i != 0) {
			c[k++] = '.';
		}
		c[k++] = a[i];
	}
	c[k] = '\0';
	
	return;
}



void chang(char *a, char *b) {
	int j;
	for (j = 0; b[j] != '\0'; j++) {
		a[j] = b[j];
	}
	a[j] = b[j];
}
void Gnumdiv(char *s1, char *s) {
	int i, k = 0, p = 0,q=0;
	for (i = 0; s1[i] != '\0'; i++) {
		if (s1[i] == '.') {
			q = 1;
			s[k++] = s1[i];
		}
		else if (s1[i] == '0') {
			if(q==1||p==1) s[k++] = s1[i];
		}
		else if (s1[i] >= '1'&&s1[i] <= '9') {
			p = 1;
			s[k++] = s1[i];
		}
		else;
	}
	s[k] = '\0';
	if (q == 1) {
		for (i = strlen(s) - 1; i > 0; i--) {
			if (s[i] == '0' || s[i] == '.') {
				if (s[i] == '.') {
					s[i] = '\0';
					break;
				}
				s[i] = '\0';
			}
			else	break;
		}
	}
	if (p==0) {
		s[0] = '0';s[1] = '\0';
	}
}
void GreatnumMul(char *a, int n, char *s) {
	int i=0;
	char q[1000],d[20], p[1000];
	s[0] = '\0';
	chang10_2(n, d);
	chang(q, a);
	if (n <= 0) {
		s[0] = '0';
		s[1] = '\0';
		return;
	}
	if (n == 1) {
		chang(s, a); return;
	}
	if (n<4) {
		for (i = 1; i < n; i++) {
			GreatnumAdd(a, q, s);
			chang(q, s);
		}
		return;
	}
	if(n>=4){
		for (i = 0; d[i] != '\0'; i++) {
			//q[0] = '0'; q[1] = '\0';
			//p[0] = '0'; p[1] = '\0';
			Gnum2N(a, d[i]-'0', q);
			if (s[0] == '\0') 
				chang(s, q);
			else {
				GreatnumAdd(q, s, p);
				chang(s, p);
			}
		}
	}
	
	//chang(s, q);
}
void Gnum2N(char *a, int n, char *s) {
	int i;
	char p[1000],  q[1000];
	s[0] = '\0';
	//if (n < 0) { s[0] = '0'; s[1] = '\0'; return; }
	if (n == 0) {
		chang(s, a);
		return;
	}
	chang(p, a);
	chang(q, a);
	for (i = 1; i <= n; i++) {
		GreatnumAdd(q, p, s);
		chang(q, s); 
		chang(p, s);
	}
	return;
}
void BothGreatnumMul(char *r1, char *r2, char *s) {
	int i, j, k = 0, t;
	char d[1000] , q[1000], y[1000];
	for (i = strlen(r2) - 1; i >= 0; i--) {
		t = r2[i] - '0';
		GreatnumMul(r1, t, d);
		for (j = 0; j < k; j++) {
			chang(y, d);
			GreatnumMul(y, 10, d);
		}
		if (k == 0) {
			chang(s, d);
		}
		else {
			chang(q, s);
			GreatnumAdd(d, q, s);
		}
		k++;
	}
}
void GIntExp(char *r, int n, char *s) {
	int i;
	char q[1000];
	if (n == 0) {
		s[0] = '1';
		s[1] = '\0';
		return;
	}
	if (n == 1) {
		chang(s, r);
		return;
	}
	chang(q, r);
	for (i = 1; i < n; i++) {
		BothGreatnumMul(r, q, s);
		chang(q, s);
	}
	//chang(s, q);

}
void Gnumfx1(char *s1,char *s2,char *s3) {  //求大数阶乘；
	GIntExp(s1, 2, s2);
	GreatnumAdd(s1, s2, s3);
	GreatnumMul(s3, 5, s2);
	Gnumdiv(s2, s3);
}
void GExp(char *a, int n, char *s) {  //n必须少于500；正整数；
	int i, t;
	char b[20]; char m[N]; char q[N];
	q[0] = '1'; q[1] = '\0';
	if (n == 0) {
		s[0] = '0'; s[1] = '1';
	}
	else if (n == 1) chang(s, a);
	else {
		chang10_2(n, b);
		for (i = 0; b[i] != '\0'; i++) {
			t = b[i] - '0';
			GExp2_n(a, t, m);
			BothGreatnumMul(m, q, s);
			chang(q, s);
		}
	}
}
void GFloatExp(char *a, int n, char *c) {
	if (n == 1) {
		chang(c, a);
		return;
	}
	if (n == 0) {
		c[0] = '1';
		c[1] = '\0';
		return;
	}
	int k = 0;
	char b[1000];
	k = GFloatInt(a, c);
	//GIntExp(c, n, b);
	//GExp2_n(c, n, b);
	GExp(c, n, b);
	GIntFloat(b, k*n, c);
	//Gnumdiv(c, b);
	//chang(c, b);
}



int main() {
    int  n = 0;
	char a[1000] , b[1000] , c[1000];
	ifstream fin("Gint.txt");
	ofstream fout("Gintout.txt");
	//std::ios::sync_with_stdio(false);
	while (fin  >>a>>n){
		
		//BothGreatnumMul(a, b, c);
		//chang10_2(n, c);
		q = clock();
		GFloatExp(a, n, c);
		Gnumdiv(c, b);
		chang(c, b);
		//Gnum2N(a, n, c);
		//GreatnumMul(a, n, c);
		//Gnumdiv(a, c);
		//k = GFloatInt(a, c);
		//GIntExp(c, n, b);
		//GIntFloat(b,n*k, c);
		//GIntFloat(a, n, c);
		w = clock();
		fout << c << endl;
		fout << w - q << endl;
		//printf("%s\n%d\n", c, w - q);
	}
	
	//fin.close();
	//fout.close();
	//w = clock();
	//e = w - q;
	//cout << e<< endl;
		return 0;
}









 //      *///#include "stdafx.h"

  //         /*
#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>
#define N 1100
#pragma warning(disable:4996);
using namespace std;
void GExp(char *a, int n, char *s);
void chang10_2(int a, char *s);
void GExp2_n(char *a, int n, char *s);
void GreatnumAdd(char *s1, char *s2, char *s3);
int GFloatInt(char *a, char *c);
void GIntFloat(char *a, int n, char *c);
void chang(char *a, char *b);
void Gnumdiv(char *s1, char *s);
void GreatnumMul(char *a, int n, char *s);
void Gnum2N(char *r, int n, char *s);
void BothGreatnumMul(char *r1, char *r2, char *s);
void GIntExp(char *r, int n, char *s);
void Gnumfx1(char *s1, char *s2, char *s3);
void GFloatExp(char *a, int n, char *c);
void chang10_2(int a, char *s) {  //a必须为正整数；<512;
	int i=0, k = 0;
	char d[20];
	while (a > 0) {
		d[k++] = (a % 2)+'0';
		a /= 2;
	}
	d[k] = '\0';
	k = 0;
	for (i = 0; d[i]!='\0'; i++) {
		if (d[i]=='1') {
			s[k++] = i+'0';
		}
		
	}
	s[k] = '\0';
}
void GExp2_n(char *a, int n, char *s) { //计算a的2的n次方；
	int i;
	char p[1000], q[1000];
	if (strlen(a) == 0) {
		s[0] = '0'; s[1] = '\0';
		return;
	}
	else {
		chang(s, a);
		chang(p, a);
		chang(q, a);
		for (i = 1; i <= n; i++) {
			BothGreatnumMul(p, q, s);
			chang(p, s);
			chang(q, s);
		}
	}
}
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
	int a[1000] = { 0 }, b[1000] = { 0 }, Len1, Len2, c, k, i, p = 0, t = 0, ab = 0;
	bool n1 = false, n2 = false;
	if (s2[0] == '0'&&s2[1] == '\0') {
		//s3[0] = '0'; s3[1] = '\0';
		chang(s3, s1);
		return;
	}
	if (s1[0] == '0'&&s1[1] == '\0') {
		chang(s3, s2);
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
int GFloatInt(char *a, char *c) {
	int i, s = 0, p = 0, q = 0, k = 0;
	for (i = 0; a[i] != '\0'; i++) {
		if (p == 1) s++;
		if (a[i] == '.') {
			p = 1;
		}
		else if (a[i] == 0) {
			if (q == 1) {
				c[k++] = '0';
			}
		}
		else{
			q = 1; 
			c[k++] = a[i];
		}
		
	}
	c[k] = '\0';
	return s;
}
void GIntFloat(char *a,  int n, char *c) {
	 int i, k = 0,p=0;
	c[0] = '0'; c[1] = '\0';
	if (strlen(a) <= n) {
		//c[k++] = '0';
		c[k++] = '.';
		for (i = 1; i <= (n - strlen(a)); i++)
		{
			c[k++] = '0';
		}
	}
	for (i = 0; a[i] != '\0'; i++) {
		if (i == strlen(a) - n && i != 0) {
			c[k++] = '.';
		}
		c[k++] = a[i];
	}
	c[k] = '\0';
	
	return;
}



void chang(char *a, char *b) {
	int j;
	for (j = 0; b[j] != '\0'; j++) {
		a[j] = b[j];
	}
	a[j] = b[j];
}
void Gnumdiv(char *s1, char *s) {
	int i, k = 0, p = 0,q=0;
	for (i = 0; s1[i] != '\0'; i++) {
		if (s1[i] == '.') {
			q = 1;
			s[k++] = s1[i];
		}
		else if (s1[i] == '0') {
			if(q==1||p==1) s[k++] = s1[i];
		}
		else if (s1[i] >= '1'&&s1[i] <= '9') {
			p = 1;
			s[k++] = s1[i];
		}
		else;
	}
	s[k] = '\0';
	if (q == 1) {
		for (i = strlen(s) - 1; i > 0; i--) {
			if (s[i] == '0' || s[i] == '.') {
				if (s[i] == '.') {
					s[i] = '\0';
					break;
				}
				s[i] = '\0';
			}
			else	break;
		}
	}
	if (p==0) {
		s[0] = '0';s[1] = '\0';
	}
}
void GreatnumMul(char *a, int n, char *s) {
	int i=0;
	char q[1000],d[20], p[1000];
	s[0] = '\0';
	chang10_2(n, d);
	chang(q, a);
	if (n <= 0) {
		s[0] = '0';
		s[1] = '\0';
		return;
	}
	if (n == 1) {
		chang(s, a); return;
	}
	if (n<4) {
		for (i = 1; i < n; i++) {
			GreatnumAdd(a, q, s);
			chang(q, s);
		}
		return;
	}
	if(n>=4){
		for (i = 0; d[i] != '\0'; i++) {
			//q[0] = '0'; q[1] = '\0';
			//p[0] = '0'; p[1] = '\0';
			Gnum2N(a, d[i]-'0', q);
			if (s[0] == '\0') 
				chang(s, q);
			else {
				GreatnumAdd(q, s, p);
				chang(s, p);
			}
		}
	}
	
	//chang(s, q);
}
void Gnum2N(char *a, int n, char *s) {
	int i;
	char p[1000],  q[1000];
	s[0] = '\0';
	//if (n < 0) { s[0] = '0'; s[1] = '\0'; return; }
	if (n == 0) {
		chang(s, a);
		return;
	}
	chang(p, a);
	chang(q, a);
	for (i = 1; i <= n; i++) {
		GreatnumAdd(q, p, s);
		chang(q, s); 
		chang(p, s);
	}
	return;
}
void BothGreatnumMul(char *r1, char *r2, char *s) {
	int i, j, k = 0, t;
	char d[1000] , q[1000], y[1000];
	for (i = strlen(r2) - 1; i >= 0; i--) {
		t = r2[i] - '0';
		GreatnumMul(r1, t, d);
		for (j = 0; j < k; j++) {
			chang(y, d);
			GreatnumMul(y, 10, d);
		}
		if (k == 0) {
			chang(s, d);
		}
		else {
			chang(q, s);
			GreatnumAdd(d, q, s);
		}
		k++;
	}
}
void GIntExp(char *r, int n, char *s) {
	int i;
	char q[1000];
	if (n == 0) {
		s[0] = '1';
		s[1] = '\0';
		return;
	}
	if (n == 1) {
		chang(s, r);
		return;
	}
	chang(q, r);
	for (i = 1; i < n; i++) {
		BothGreatnumMul(r, q, s);
		chang(q, s);
	}
	//chang(s, q);

}
void Gnumfx1(char *s1,char *s2,char *s3) {  //求大数阶乘；
	GIntExp(s1, 2, s2);
	GreatnumAdd(s1, s2, s3);
	GreatnumMul(s3, 5, s2);
	Gnumdiv(s2, s3);
}
void GExp(char *a, int n, char *s) {  //n必须少于500；正整数；
	int i, t;
	char b[20]; char m[N]; char q[N];
	q[0] = '1'; q[1] = '\0';
	if (n == 0) {
		s[0] = '0'; s[1] = '1';
	}
	else if (n == 1) chang(s, a);
	else {
		chang10_2(n, b);
		for (i = 0; b[i] != '\0'; i++) {
			t = b[i] - '0';
			GExp2_n(a, t, m);
			BothGreatnumMul(m, q, s);
			chang(q, s);
		}
	}
}
void GFloatExp(char *a, int n, char *c) {
	if (n == 1) {
		chang(c, a);
		return;
	}
	if (n == 0) {
		c[0] = '1';
		c[1] = '\0';
		return;
	}
	int k = 0;
	char b[1000];
	k = GFloatInt(a, c);
	//GIntExp(c, n, b);
	//GExp2_n(c, n, b);
	GExp(c, n, b);
	GIntFloat(b, k*n, c);
	//Gnumdiv(c, b);
	//chang(c, b);
}



int main() {
    int  n = 0;
	int q, w;
	
	char a[1000] , b[1000] , c[1000];
	ifstream fin("Gint.txt");
	ofstream fout("Gintout.txt");
	//std::ios::sync_with_stdio(false);
	while (fin  >>a>>n){
		
		//BothGreatnumMul(a, b, c);
		//chang10_2(n, c);
		q = clock();
		GFloatExp(a, n, c);
		Gnumdiv(c, b);
		chang(c, b);
		//Gnum2N(a, n, c);
		//GreatnumMul(a, n, c);
		//Gnumdiv(a, c);
		//k = GFloatInt(a, c);
		//GIntExp(c, n, b);
		//GIntFloat(b,n*k, c);
		//GIntFloat(a, n, c);
		w = clock();
		fout << c << endl;
		fout << w - q << endl;
		//printf("%s\n%d\n", c, w - q);
	}
	
	//fin.close();
	//fout.close();
	//w = clock();
	//e = w - q;
	//cout << e<< endl;
		return 0;
}









 //      */