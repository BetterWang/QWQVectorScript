#include "label.h"
#include <TFile.h>
#include <TH1.h>
#include <TTree.h>
#include <TMath.h>

#include <complex>


using namespace std;
typedef std::complex<double> Complex;

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

	chV->SetBranchAddress("pre", pre);
	chV->SetBranchAddress("pim", pim);
	chV->SetBranchAddress("pw",  pw);

	chV->SetBranchAddress("nre", nre);
	chV->SetBranchAddress("nim", nim);
	chV->SetBranchAddress("nw",  nw);

	chV->SetBranchAddress("pRe",  &pRe);
	chV->SetBranchAddress("pIm",  &pIm);
	chV->SetBranchAddress("pHFw", &pHFw);

	chV->SetBranchAddress("nRe",  &nRe);
	chV->SetBranchAddress("nIm",  &nIm);
	chV->SetBranchAddress("nHFw", &nHFw);

	double eta[12] = {-2.2, -1.8, -1.4, -1.0, -0.6, -0.2, 0.2, 0.6, 1.0, 1.4, 1.8, 2.2};

	TH2D * hCorr[200];
	for ( int c = 0; c < 200; c++ ) {
		hCorr[c] = new TH1D(Form("hCorr_%i", c), "", 100, 0, TMath::Pi()/2);
	}
	TH1D * hCent = new TH1D("hCent", "Centrality", 200, 0, 200);
	TH1D * hMult = new TH1D("hMult", "Multiplicity", 5000, 0, 5000);
	unsigned int ievt = 0;
	while (chV->GetEntry(ievt)) {
		Complex pQ[12];
		Complex nQ[12];
		Complex tQ[12];
		Complex Q(0,0);
		double phi[12];
		for ( int i = 0; i < 12; i++ ) {
			pQ[i] = Complex(pre[i], pim[i]);
			nQ[i] = Complex(nre[i], nim[i]);
			tQ[i] = pQ[i] + nQ[i];
			Q += tQ[i];
			phi[i] = std::arg(tQ[i])/2.;
		}
		const double gphi = std::arg(Q)/2.;
		for ( int i = 0; i < 12; i++ ) {
			phi[i] -= gphi;
			while (phi[i] > TMath::Pi()/2) phi[i] -= TMath::Pi();
			while (phi[i] < -TMath::Pi()/2) phi[i] += TMath::Pi();
		}


		hCent->Fill(cent);
	}
}
