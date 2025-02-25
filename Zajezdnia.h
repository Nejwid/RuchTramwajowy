#pragma once
#include "RodzajeTramwajów.h"
#include <memory>
#include <iostream>

using namespace std;

class Zajezdnia {
public:
	virtual unique_ptr<Tramwaj> BrygadaPierwsza(int nr) = 0;
	virtual unique_ptr<Tramwaj> BrygadaDruga(int nr) = 0;
};

class ZajezdniaBorek : public Zajezdnia {
public:
	unique_ptr<Tramwaj> BrygadaPierwsza(int nr) override;
	unique_ptr<Tramwaj> BrygadaDruga(int nr) override;
};

class ZajezdniaGaj : public Zajezdnia {
public:
	unique_ptr<Tramwaj> BrygadaPierwsza(int nr) override;
	unique_ptr<Tramwaj> BrygadaDruga(int nr) override;
};

class ZajezdniaO³bin : public Zajezdnia {
public:
	unique_ptr<Tramwaj> BrygadaPierwsza(int nr) override;
	unique_ptr<Tramwaj> BrygadaDruga(int nr) override;
};