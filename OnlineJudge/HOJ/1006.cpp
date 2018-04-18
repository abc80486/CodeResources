
 //     /*
#include <iostream>
#include <math.h>
#include<iomanip>
using namespace std;
int main() {
	int p=0;
	double h=0.0, m=0.0, s=0.0,d=0,t,s1,s2;
	double angh, angm, angs, sum ;
	double anghm, anghs, angms;
	//f = 1 / 120;
	while (cin >> d) {
		//h = 0.0; m = 0.0; s = 0.0, sum = 0.0;
		//while(1){
		sum = 0;
		for (t = 0; t < 43200; t=t+0.1) {
			anghm = 11.0 / 120 * t;
			anghs = 719.0 / 120 * t;
			angms = 5.9*t;
			while (anghm >= 360) anghm -= 360;
			while (anghs >= 360) anghs -= 360;
			while (angms >= 360) angms -= 360;
			if (anghm > 180) anghm = 360.0 - anghm;
			if (anghs > 180) anghs = 360.0 - anghs;
			if (angms > 180) angms = 360.0 - angms;

			if (anghm >= d && anghs >= d && angms >= d) {
				if (p == 0) {
					s1 = t;
					//cout << t << ends;
					p = 1;
				}
				//sum += 1;
			}
			else {
				if (p == 1) {
					s2 = t;
					sum += s2 - s1;
					//cout << t << endl;
					p = 0;
				}
			}
			
		
		}
		cout << sum/432.0 << endl;
			/*
			if (s > 59) { m += 1; s = 0; }			
			if (m > 59) { h += 1; m = 0; }					
			if (h == 12) break;
			angh = h*30.00 + m/2.00 + s/120.00;
			angm = s/10.00 + m * 6.00;
			angs = s * 6.00;
			
			if (angh >= angm) {
				anghm = angh - angm;
			}
			else {
				anghm = angm - angh;
			}

			if (angh >= angs) {
				anghs = angh - angs;
			}
			else {
				anghs = angs - angh;
			}

			if (angs >= angm) {
				angms = angs - angm;
			}
			else {
				angms = angm - angs;
			}

			if (anghm > 180) anghm = 360.0-anghm;
			if (anghs > 180) anghs = 360.0-anghs;
			if (angms > 180) angms = 360.0-angms;
			if (anghm >= d) {
				if (anghs >= d) {
					if (angms >= d) {
						sum+=1;
					}
				}
			}
			s+=1;
			
		}
		*/
		//sum = sum / 432.0;
		//cout<<setiosflags(ios_base::fixed);
		//cout <<setprecision(5)<<anghs << endl<<anghm<<endl<<angms<<endl;
		//cout << setprecision(4) << sum << endl;
	}
	
	
}
// */
