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
int GFloatInt(char *a, char *c) {
	int i, s = 0, p = 0, q = 0, k = 0;
	for (i = 0; a[i] != '\0'; i++) {
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
		if (p == 1) s++;
	}
	c[k] = '\0';
	return s - 1;
}
void GIntFloat(char *a,  int n, char *c) {
	 int i, k = 0,p=0;
	c[0] = '0'; c[1] = '\0';
	if (strlen(a) <= n) {
		//c[k++] = '0';
		c[k++] = '.';
		for (i = 1; i <= (n - strlen(a)); i++)
		{
			c[k++] = 48;
		}
	}
	for (i = 0; a[i] != '\0'; i++) {
			if (i == strlen(a) - n && i != 0) c[k++] = '.';
			c[k++] = a[i];
		}
	c[k] = '\0';
	for (i = k - 1; i > strlen(a) - n && p==0; i--) {
		if (c[i] != '0') {
			p = 1;
		}
		else {
			c[i] = '\0';
		}
	}
	return;
}
void chang(char *a, char *b) {
	int j;
	for (j = 0; b[j] != '\0'; j++) {
		a[j] = b[j];
	}
	a[j] = b[j];
}
void Gnumdiv(char *s1, int n,char *s) {
	chang(s, s1);
	if (n >= strlen(s)) {
		s[0] = '0';
		s[1] = '\0';
	}
	else {
		while (n--) {
			s[strlen(s) - 1] = '\0';
		}
	}
}
void GreatnumMul(char *a, int n, char *s) {
	int i;
	char q[100];
	if (n <= 0) {
		s[0] = '0';
		s[1] = '\0';
		return;
	}
	chang(q, a);
	for (i = 1; i < n; i++) {
		GreatnumAdd(a, q, s);
		chang(q, s);
	}
	chang(s, q);
}
void Greatnum2N_1(char *r, int n, char *s) {
	int i, j;
	for (i = 0; i < n; i++) {
		GreatnumAdd(r, s, s);
		for (j = 0; s[j] != '\0'; j++) {
			r[j] = s[j];
		}
		r[j] = s[j];
	}
}
void BothGreatnumMul(char *r1, char *r2, char *s) {
	int i, j, k = 0, t;
	char d[1000] = { '0' }, q[1000], y[1000];
	for (i = strlen(r2) - 1; i >= 0; i--) {
		t = r2[i] - '0';
		//if (t <=0) t = 0;
		GreatnumMul(r1, t, d);
		for (j = 0; j < k; j++) {
			//d[strlen(d)] = '0';
			//d[strlen(d) + 1] = '\0';
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
	Gnumdiv(s2, 1, s3);
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
	GIntExp(c, n, b);
	GIntFloat(b, k*n, c);
}
int main() {
    int  n = 0,k;
	char a[1000], b[1000], c[1000];
	ifstream fin("Gint.txt");
	ofstream fout("Gintout.txt");
	while (fin >> a >> n) {
		//BothGreatnumMul(a, b, c);
		GFloatExp(a, n, c);
		//k = GFloatInt(a, c);
		//GIntExp(c, n, b);
		//GIntFloat(b,n*k, c);
		//GIntFloat(a, n, c);
		fout << c << endl;
	}
	fin.close();
	fout.close();
		return 0;
}