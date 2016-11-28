#pragma once
#include "Collection.h"
class Set : public Collection
{
	void sort(const Set&);
public:
	Set(int);
	Set(const Set&);
	Set(Set&&);
    void FilterSort();
	Set& operator=(const Set&);
	Set& operator=(Set&&);
	void add(const int);
	~Set();
};

