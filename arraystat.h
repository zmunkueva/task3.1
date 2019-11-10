#pragma once
#include "pch.h"
#include <iostream>
#include <vector>

class ArrayStat {
private: std::vector <int> v;
		 double m_mean;
		 double m_rms;
		 int max, min, a;

public:
	int get_max() const { return max; }
	int get_min() const { return min; }
	double mean() { return m_mean; }
	double rms() { return m_rms; }
	void print() const;
	void readf();
	void arraystat();
	size_t count(int a) const;
};