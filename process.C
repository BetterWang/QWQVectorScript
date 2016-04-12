#include "label.h"
#include <TFile.h>
#include <TH1.h>
#include <TTree.h>

using namespace std;

void process(int s1)
{
	cout << " s1 = " << s1 << endl;
	addchain(s1);

	int cent;
	int mult;
	double pRe, pIm, pHFw;
	double nRe, nIm, nHFw;

	double pre[12], pim[12], pw[12];
	double nre[12], nim[12], nw[12];

	chV->SetBranchAddress("cent", &cent);
	chV->SetBranchAddress("Mult", &mult);

}
