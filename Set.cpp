#include "Set.h"

void Set::sort(const Set &s)
{
	for(int i=0;i<s.n;i++)
		for (int j = 0; j < s.n; j++)
		{
			if (s.niz[i] > s.niz[j])
			{
				int pom = s.niz[i];
				s.niz[i] = s.niz[j];
				s.niz[j] = pom;
			}
	   }
}

Set::Set(int i) :Collection(i) {}

Set::Set(const Set &other)  { copy(other);}

Set::Set(Set &&other) { move(std::move(other));}

void Set::FilterSort()
{
	int p = 1, k = 0; 
	Set b(n);
	for (int i = 0; i < n; i++)
	{
		p = 1;
	    for (int j = i + 1; j < n && p; j++)
	         {
		       if (niz[i] == niz[j])
			       p = 0;
	         }
	    if (p)
	        {
		      b.niz[k] = niz[i];
		      k++;
	        }
    }
	niz = new int[k];
	n = k;
	std::copy(b.niz, b.niz + k, niz);
	sort(*this);
}

Set & Set::operator=(const Set &other)
{
	if (this == &other) return *this;
	delete[]niz;
	copy(other);
	return *this;
}

Set & Set::operator=(Set &&other)
{
	if (this == &other)return *this;
	delete[]niz;
	move(std::move(other));
	return *this;
}

void Set::add(const int a)
{
	for (int i = 0; i < n; i++)
		if (niz[i] == a)
			return;
	int *pom = new int[n];
	std::copy(niz, niz + n, pom);
	niz = new int[n += 1];
	std::copy(pom, pom + n - 1, niz);
	niz[n - 1] = a;
}

Set::~Set(){}
