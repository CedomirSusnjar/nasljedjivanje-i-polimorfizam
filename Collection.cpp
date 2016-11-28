#include "Collection.h"

void Collection::copy(const Collection &other)
{
	niz = new int[n = other.n];
	std::copy(other.niz, other.niz + other.n, niz);
}

void Collection::move(Collection &&other)
{
	n = other.n;
	niz = other.niz;
	other.niz = 0;
	other.n = 0;
}

Collection::Collection(int n) {niz = new int[this->n=n];}

Collection::Collection(const Collection &other) {copy(other);}

Collection::Collection(Collection &&other) {move(std::move(other));}

Collection & Collection::operator=(const Collection &other)
{
	if (this == &other)return *this;
	delete[]niz;
	copy(other);
	return *this;
}

Collection & Collection::operator=(Collection &&other)
{
	if (this == &other)return *this;
	delete []niz;
	move(std::move(other));
	return *this;
}

Collection::~Collection() {delete[]niz;}

void Collection::add(int a)
{
	int *pom = new int[n];
	std::copy(niz, niz + n, pom);
	niz = new int[n += 1];
	std::copy(pom, pom + n - 1, niz);
	niz[n-1] = a;
}

bool Collection::remove(const int i)
{
	if (i<0 || i>n)return false;
	int p = 0;
	int *pom = new int[n - 1];
	for (int k = 0; k < n; k++)
		if (k != i-1)
		{
			pom[p] = niz[k];
			p++;
		}
	niz = new int[n -= 1];
	std::copy(pom, pom + n, niz);
	return true;
}

int & Collection::operator[](const int i) const
{
	if (i<0 || i>n)return niz[0];
	return niz[i - 1];
}

std::ostream & operator<<(std::ostream &str, const Collection &c)
{
	std::for_each(c.niz, c.niz + c.n, [&str](int &a) {str << a << " "; });
	return str;
}

std::istream & operator >> (std::istream &str, Collection &c)
{
	std::for_each(c.niz, c.niz + c.n, [&str](int &a) {std::cin >> a; });
	return str;
}
