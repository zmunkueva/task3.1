#include "pch.h"
#include "arraystat.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <iterator>

using namespace std;

void ArrayStat::arraystat() {
	int N = v.size();
	max = v.back();
	min = v.front();
	m_mean = accumulate(v.begin(), v.end(), 0.) / v.size();

	vector <int> squares(v.size());
	auto squarer = [](int a) { return a * a; };
	transform(v.begin(), v.end(), squares.begin(), squarer);

	double mean_sq = accumulate(squares.begin(), squares.end(), 0.) / squares.size();
	m_rms = sqrt(mean_sq - m_mean * m_mean);
}

void ArrayStat::readf()
{
	v.clear();
	fstream file("filename.txt");
	if (!file.good()) {
		cout << "cannot open a file" << endl;
		exit(1);
	}
	else {
		copy(istream_iterator<int>(file), istream_iterator<int>(), back_inserter(v));
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
		sort(v.begin(), v.end());
	}
}
size_t ArrayStat::count(int a) const {
	size_t count;
	auto value = upper_bound(v.begin(), v.end(), a);
	count = distance(value, v.end());
	return count;
}
void ArrayStat::print() const
{
	cout << "the length is " << v.size() << endl;
	for (auto const &value : v)
	{
		cout << value << ' ';
	}
	int a;
	cout << "input your value" << endl;
	cin >> a;
	cout << "number of vector's elements which is more then your value: " << count(a) << endl;
}