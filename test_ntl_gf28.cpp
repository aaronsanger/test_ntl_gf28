#include <NTL/GF2X.h>
#include <NTL/GF2XFactoring.h>
#include <NTL/GF2EXFactoring.h>
#include <cstdint>

using namespace std;
using namespace NTL;

int main(int argc, char *argv[]) {
	
	GF2X irred_poly;
	
	BuildSparseIrred(irred_poly, 8);
	long poly_degree;

	poly_degree = deg(irred_poly);

	cout << poly_degree << endl;

	GF2 lead_coeff;
	lead_coeff = LeadCoeff (irred_poly);
	cout << lead_coeff << endl;

	GF2 const_term;
	const_term = ConstTerm(irred_poly);
	cout << const_term << endl;

	GF2 coeff_value;
	int8_t i;

	for(i = 8; i >= 0; i--) {
		coeff_value = coeff(irred_poly, i);
		cout << coeff_value << " ";
	}

	cout << endl;

	SetCoeff(irred_poly, 2, 1);
	SetCoeff(irred_poly, 1, 0);

	for(i = 8; i >= 0; i--) {
		coeff_value = coeff(irred_poly, i);
		cout << coeff_value << " ";
	}

	cout << endl;
	cout << irred_poly[8] << endl;

	return 0;
}