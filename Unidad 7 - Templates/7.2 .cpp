#include <iostream>
using namespace std;
template<typename T> 

void clamp(T &val, T min, T max) {
	if (val<min) val = min;
	else if (val>max) val = max;
}
int main() {
	float a = -0.1, b = 0.5, c = 2.0, min = 0.0, max = 1.0;
	clamp(a, min, max); // a<0.0 -> a=0.0
	clamp(b, min, max); // 0.0<=b<=1.1 -> b ok
	clamp(c, min, max); // c>1.0 -> c=1.0
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	return 0;
}

