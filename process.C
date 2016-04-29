#include "label.h"
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TTree.h>
#include <TMath.h>

#include <complex>


using namespace std;
typedef std::complex<double> Complex;

void process(int s1 = 1)
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
	chV->SetBranchAddress("mult", &mult);

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

	TH2D * hCorr[10];
	TH2D * hCorrR[10];
	TH2D * hCorrHF[10];
	TH2D * hCorrHFp[10];
	TH2D * hCorrHFn[10];

	TH1D * hPhi[10];
	TH1D * hPhiR[10];
	TH1D * hPhiHFp[10];
	TH1D * hPhiHFn[10];
	TH1D * hPhiHF[10];
	for ( int c = 0; c < 10; c++ ) {
		hCorr[c] = new TH2D(Form("hCorr_%i", c), "", 6, 0, 2.4, 200, -2.5, 2.5);
		hCorrR[c] = new TH2D(Form("hCorrR_%i", c), "", 6, 0, 2.4, 200, -2.5, 2.5);
		hCorrHF[c] = new TH2D(Form("hCorrHF_%i", c), "", 6, 0, 2.4, 200, -2.5, 2.5);
		hCorrHFp[c] = new TH2D(Form("hCorrHFp_%i", c), "", 6, 0, 2.4, 200, -2.5, 2.5);
		hCorrHFn[c] = new TH2D(Form("hCorrHFn_%i", c), "", 6, 0, 2.4, 200, -2.5, 2.5);

		hPhi[c] = new TH1D(Form("hPhi_%i", c), "", 200, -TMath::Pi(), TMath::Pi());
		hPhiR[c] = new TH1D(Form("hPhiR_%i", c), "", 200, -TMath::Pi(), TMath::Pi());
		hPhiHF[c] = new TH1D(Form("hPhiHF_%i", c), "", 200, -TMath::Pi(), TMath::Pi());
		hPhiHFp[c] = new TH1D(Form("hPhiHFp_%i", c), "", 200, -TMath::Pi(), TMath::Pi());
		hPhiHFn[c] = new TH1D(Form("hPhiHFn_%i", c), "", 200, -TMath::Pi(), TMath::Pi());
	}
	TH1D * hCent = new TH1D("hCent", "Centrality", 200, 0, 200);
	TH1D * hMult = new TH1D("hMult", "Multiplicity", 5000, 0, 5000);
	unsigned int ievt = 0;
	while (chV->GetEntry(ievt++)) {
		if ( not (ievt%100000) ) cout << "!!! ievt = " << ievt << endl;
		Complex pQ[12];
		Complex nQ[12];
		Complex tQ[12];
		Complex Q(0,0);
		Complex Qr(0,0);
		Complex pHF(pRe,pIm);
		Complex nHF(nRe,nIm);
		Complex HF(pRe+nRe,pIm+nIm);
		double phi[12];
		double phiR[12];
		double phiHF[12];
		double phiHFp[12];
		double phiHFn[12];
		for ( int i = 0; i < 12; i++ ) {
			pQ[i] = Complex(pre[i], pim[i]);
			nQ[i] = Complex(nre[i], nim[i]);
			tQ[i] = pQ[i] + nQ[i];
			Q += tQ[i];
			if ( i > 3 and i < 8 ) Qr += tQ[i];
			phi[i] = std::arg(tQ[i])/2.;
			phiR[i] = phi[i];
			phiHF[i] = phi[i];
			phiHFp[i] = phi[i];
			phiHFn[i] = phi[i];
		}
		const double gphi = std::arg(Q)/2.;
		const double gphiR = std::arg(Qr)/2.;
		const double gphiHF = std::arg(HF)/2.;
		const double gphiHFp = std::arg(pHF)/2.;
		const double gphiHFn = std::arg(nHF)/2.;
		for ( int i = 0; i < 12; i++ ) {
			phi[i] -= gphi;
			phiR[i] -= gphiR;
			phiHF[i] -= gphiHF;
			phiHFp[i] -= gphiHFp;
			phiHFn[i] -= gphiHFn;

			while (phi[i] > TMath::Pi()/2) phi[i] -= TMath::Pi();
			while (phi[i] < -TMath::Pi()/2) phi[i] += TMath::Pi();

			while (phiR[i] > TMath::Pi()/2) phiR[i] -= TMath::Pi();
			while (phiR[i] < -TMath::Pi()/2) phiR[i] += TMath::Pi();

			while (phiHF[i] > TMath::Pi()/2) phiHF[i] -= TMath::Pi();
			while (phiHF[i] < -TMath::Pi()/2) phiHF[i] += TMath::Pi();

			while (phiHFp[i] > TMath::Pi()/2) phiHFp[i] -= TMath::Pi();
			while (phiHFp[i] < -TMath::Pi()/2) phiHFp[i] += TMath::Pi();

			while (phiHFn[i] > TMath::Pi()/2) phiHFn[i] -= TMath::Pi();
			while (phiHFn[i] < -TMath::Pi()/2) phiHFn[i] += TMath::Pi();
		}

		for ( int i = 0; i < 6; i++ ) {
			hCorr[cent/20]->Fill(eta[i], phi[6+i] * phi[5-i]);
			hCorrR[cent/20]->Fill(eta[i], phiR[6+i] * phiR[5-i]);
			hCorrHF[cent/20]->Fill(eta[i], phiHF[6+i] * phiHF[5-i]);
			hCorrHFp[cent/20]->Fill(eta[i], phiHFp[6+i] * phiHFp[5-i]);
			hCorrHFn[cent/20]->Fill(eta[i], phiHFn[6+i] * phiHFn[5-i]);
		}
		hPhi[cent/20]->Fill(std::arg(Q));
		hPhiR[cent/20]->Fill(std::arg(Qr));
		hPhiHF[cent/20]->Fill(std::arg(HF));
		hPhiHFp[cent/20]->Fill(std::arg(pHF));
		hPhiHFn[cent/20]->Fill(std::arg(nHF));
		hCent->Fill(cent);
		hMult->Fill(mult);
	}

	TFile * fwrite = new TFile(Form("%s/output.root", ftxt[s1]), "recreate");
	for ( int c = 0; c < 10; c++ ) {
		hCorr[c]->Write();
		hCorrR[c]->Write();
		hCorrHF[c]->Write();
		hCorrHFp[c]->Write();
		hCorrHFn[c]->Write();
		hPhi[c]->Write();
		hPhiR[c]->Write();
		hPhiHF[c]->Write();
		hPhiHFp[c]->Write();
		hPhiHFn[c]->Write();
	}
	hCent->Write();
	hMult->Write();
	fwrite->Close();
}
