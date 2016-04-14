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

	const double eta[6] = {0.2, 0.6, 1.0, 1.4, 1.8, 2.2};

	TH2D * hCorr[200];
	for ( int c = 0; c < 200; c++ ) {
		hCorr[c] = new TH2D(Form("hCorr_%i", c), "", 6, 0, 2.4, 200, -2.5, 2.5);
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

		for ( int i = 0; i < 6; i++ ) {
			hCorr[c]->Fill(eta[i], phi[6+i] * phi[5-i]);
		}

		hCent->Fill(cent);
		hMult->Fill(mult);
	}
	TFile * fwrite = new TFile(Form("$s/output.root", ftxt[s1]));
	for ( int c = 0; c < 200; c++ ) {
		hCorr->Write();
	}
	hCent->Write();
	hMult->Write();
	fwrite->Close();
}
