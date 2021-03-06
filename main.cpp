#include <cmath>
#include "plot.h"

#define ツ return
typedef double R;
typedef int I;

// Activation
R f  ( R a ) { ツ 1/(1+std::exp(-a)); }
R df ( R a ) { ツ a*(1-a); }

// Costs
R q  ( R a, I y ) { ツ (y-a)*(y-a)/2.; }
R dq ( R a, I y ) { ツ a-y; }
R c  ( R a, I y ) { ツ -y*std::log(a)-(1-y)*std::log(1-a); }
R dc ( R a, I y ) { ツ (a-y)/(a*(1-a)); }
#define C c
#define dC dc

I main() {
	if(!Plot::init(400)) return 0;

	I i = 0;
	I e = 1000;
	I y = 0;
	R u = .15;
	R a;
	R z;
	R w = 4.;
	R b = 1.;
	R x = 1;

	// R dcda;
	// R dadz;
	// R dzdw;
	// R dzdb;
	// R dcdw;
	// R dcdb;

	R dcda;
	R dcdz;
	R dcdw;
	R dcdb;

	while ( i++ < e ) {
		z = w * x + b;
		a = f( z );
		Plot::draw(400*i/double(e),400*a);

		// https://en.wikipedia.org/wiki/Automatic_differentiation
		// Reverse mode?
		//dcda = dC( a, y );
		//dadz = df( a );
		//dzdw = x;
		//dzdb = 1;
		//dcdw = dcda * dadz * dzdw;
		//dcdb = dcda * dadz * dzdb;

		// Forward mode?
		dcda = dC( a, y );
		dcdz = dcda * df( a );
		dcdw = dcdz * x;
		dcdb = dcdz;

		w += -u*dcdw;
		b += -u*dcdb;
	}
	Plot::display();
	ツ 0;
}
