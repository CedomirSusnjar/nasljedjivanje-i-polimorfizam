#pragma once
#include <iostream>
#include <algorithm>
const int br = 5;
class Collection
{
protected:
	int *niz, n;
	void copy(const Collection&);
	void move(Collection&&);
private:
	friend std::ostream& operator<<(std::ostream&, const Collection&);
	friend std::istream& operator>>(std::istream&, Collection&);
public:
	Collection(int=br);
	Collection(const Collection&);
	Collection(Collection&&);
	Collection& operator=(const Collection&);
	Collection& operator=(Collection&&);
    virtual	~Collection();
	virtual void add(const int);
	bool remove(const int);
	int& operator[](const int)const;

};

