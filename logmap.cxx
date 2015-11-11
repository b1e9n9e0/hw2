#include <iostream>
#include <fstream>
using namespace std;

int main(){
	double x0 = 0.5;
	double x;
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	double xout[Nend - Nskip]; //Array to store the data going out into the file

	x = x0;

	ofstream out("out.foo");

	for(double r=0; r <= 4; r += 0.001){
	   x=x0;
	   for(int i=1; i < Nskip; i++)
			x = r*x*(1-x);

		xout[0]=r*x*(1-x);
	   for(int i=Nskip+1; i <= Nend; i++){
	   		xout[i-Nskip] = r*xout[i-Nskip-1]*(1-xout[i-Nskip-1]);
	   		   
   	   }
   	   for(int i = 0; i < Nend-Nskip; i++)
   	   		out << r << "\t" << xout[i] << endl;
	}

	out.close();
	return 0;
}
