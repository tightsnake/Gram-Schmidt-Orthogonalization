// Basis_1.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>

using namespace std;

typedef vector<double> VECTOR;
typedef vector<VECTOR> VECTORSPACE;

double dotProduct(const VECTOR& v1, const VECTOR& v2) {
	double ret = 0;
	for (int i = 0; i < v1.size(); ++i)
		ret += (v1.at(i) * v2.at(i));
	return ret;
}

VECTOR operator * (const double& c, const VECTOR& v) {
	VECTOR ret = v;
	for (auto& d : ret)
		d *= c;
	return ret;

}

VECTOR operator - (const VECTOR& v1, const VECTOR& v2) {
	VECTOR ret;
	for (int i = 0; i < v1.size(); ++i)
		ret.push_back(v1.at(i) - v2.at(i));
	return ret;

}

VECTOR proj(const VECTOR& v1, const VECTOR& v2) {
	VECTOR proj = (dotProduct(v1, v2) / dotProduct(v1, v1))*v1;
	return proj;
}

double mag(const VECTOR& v) {
	double ret = 0;
	for (auto& d : v)
		ret += (d*d);
	return sqrt(ret);
}

VECTORSPACE gSchmidt(const VECTORSPACE & vspace) {
	VECTORSPACE uspace, ret;
	for (int i = 0; i < vspace.size(); ++i)
	{
		uspace.push_back(vspace.at(i));
		for (int j = 0; j < i; ++j) 
		{
			uspace.at(i) = uspace.at(i) - proj(uspace.at(j),vspace.at(i));
		}

	}
	for (int i = 0; i < uspace.size(); ++i)
		ret.push_back(1/mag(uspace.at(i))*uspace.at(i));

	return ret;
}

void printVS(const VECTORSPACE& vspace) {
	for (auto& v : vspace) {
		cout << '|';
		for (auto& d : v)
			cout << d << ' ';
		cout << "|\n";
	}
}


int main()
{
	VECTORSPACE vspace1 = {
		{3,1},
		{1,2}
	};

	VECTORSPACE vspace2 = gSchmidt(vspace1);

	printVS(vspace1);
	cout << "After Gram-Schmidt:" << endl;
	printVS(vspace2);
	cout << endl;

	VECTORSPACE vspace3 = {
		{ 0,3,0 },
		{ 0,0,2 },
		{ 3,0,0 },
	};

	VECTORSPACE vspace4 = gSchmidt(vspace3);

	printVS(vspace3);
	cout << "After Gram-Schmidt:" << endl;
	printVS(vspace4);
	cout << endl;

	VECTORSPACE vspace5 = {
		{ 20,5,10,0 },
		{ 30,10,0,20 },
		{ 15,0,15,15 },
		{ 0,15,15,15 }
	};

	VECTORSPACE vspace6 = gSchmidt(vspace5);

	printVS(vspace5);
	cout << "After Gram-Schmidt:" << endl;
	printVS(vspace6);
	cout << endl;

	VECTORSPACE vspace7 = {
		{ 5,5,0,5,5 },
		{ 3,3,3,0,0 },
		{ 2,0,2,0,2 },
		{ 2,2,2,2,2 },
		{ 2,1,1,0,3 }
	};

	VECTORSPACE vspace8 = gSchmidt(vspace7);

	printVS(vspace7);
	cout << "After Gram-Schmidt:" << endl;
	printVS(vspace8);
	cout << endl;
	
	int x;
	cin >> x;
    return 0;
}

