#include "label.h"
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TTree.h>
#include <TMath.h>

#include <complex>
#include <vector>

typedef std::complex<double> Complex;

void process(int s1 = 0)
{
	cout << " s1 = " << s1 << endl;
	addchain(s1);

	// Declaration of leaf types
	Double_t pHFw;
	Double_t pRe;
	Double_t pIm;
	Double_t nHFw;
	Double_t nRe;
	Double_t nIm;
	Double_t pRe2;
	Double_t pIm2;
	Double_t nRe2;
	Double_t nIm2;
	Int_t cent;
	Int_t mult;
	double rQ1p;
	double rQ1p2;
	double rQ2p1;
	double rQ2p2;
	double rQ3p2;
	double rQ3p3;
	double rQ1n;
	double rQ1n2;
	double rQ2n1;
	double rQ2n2;
	double rQ3n2;
	double rQ3n3;
	double iQ1p;
	double iQ1p2;
	double iQ2p1;
	double iQ2p2;
	double iQ3p2;
	double iQ3p3;
	double iQ1n;
	double iQ1n2;
	double iQ2n1;
	double iQ2n2;
	double iQ3n2;
	double iQ3n3;
	double rQMp2;
	double rQMn2;
	double iQMp2;
	double iQMn2;
	double wp1;
	double wp2;
	double wp3;
	double wn1;
	double wn2;
	double wn3;

	chV->SetBranchAddress("pHFw", &pHFw);
	chV->SetBranchAddress("pRe", &pRe);
	chV->SetBranchAddress("pIm", &pIm);
	chV->SetBranchAddress("nHFw", &nHFw);
	chV->SetBranchAddress("nRe", &nRe);
	chV->SetBranchAddress("nIm", &nIm);
	chV->SetBranchAddress("pRe2", &pRe2);
	chV->SetBranchAddress("pIm2", &pIm2);
	chV->SetBranchAddress("nRe2", &nRe2);
	chV->SetBranchAddress("nIm2", &nIm2);
	chV->SetBranchAddress("cent", &cent);
	chV->SetBranchAddress("mult", &mult);
	chV->SetBranchAddress("rQ1p", &rQ1p);
	chV->SetBranchAddress("rQ1p2", &rQ1p2);
	chV->SetBranchAddress("rQ2p1", &rQ2p1);
	chV->SetBranchAddress("rQ2p2", &rQ2p2);
	chV->SetBranchAddress("rQ3p2", &rQ3p2);
	chV->SetBranchAddress("rQ3p3", &rQ3p3);
	chV->SetBranchAddress("rQ1n", &rQ1n);
	chV->SetBranchAddress("rQ1n2", &rQ1n2);
	chV->SetBranchAddress("rQ2n1", &rQ2n1);
	chV->SetBranchAddress("rQ2n2", &rQ2n2);
	chV->SetBranchAddress("rQ3n2", &rQ3n2);
	chV->SetBranchAddress("rQ3n3", &rQ3n3);
	chV->SetBranchAddress("iQ1p", &iQ1p);
	chV->SetBranchAddress("iQ1p2", &iQ1p2);
	chV->SetBranchAddress("iQ2p1", &iQ2p1);
	chV->SetBranchAddress("iQ2p2", &iQ2p2);
	chV->SetBranchAddress("iQ3p2", &iQ3p2);
	chV->SetBranchAddress("iQ3p3", &iQ3p3);
	chV->SetBranchAddress("iQ1n", &iQ1n);
	chV->SetBranchAddress("iQ1n2", &iQ1n2);
	chV->SetBranchAddress("iQ2n1", &iQ2n1);
	chV->SetBranchAddress("iQ2n2", &iQ2n2);
	chV->SetBranchAddress("iQ3n2", &iQ3n2);
	chV->SetBranchAddress("iQ3n3", &iQ3n3);
	chV->SetBranchAddress("rQMp2", &rQMp2);
	chV->SetBranchAddress("rQMn2", &rQMn2);
	chV->SetBranchAddress("iQMp2", &iQMp2);
	chV->SetBranchAddress("iQMn2", &iQMn2);
	chV->SetBranchAddress("wp1", &wp1);
	chV->SetBranchAddress("wp2", &wp2);
	chV->SetBranchAddress("wp3", &wp3);
	chV->SetBranchAddress("wn1", &wn1);
	chV->SetBranchAddress("wn2", &wn2);
	chV->SetBranchAddress("wn3", &wn3);


	TH1D *	hQ1c = new TH1D("hQ1c", "", 200, 0, 200);
	TH1D *	hQ1w = new TH1D("hQ1w", "", 200, 0, 200);
	TH1D *	hQ22 = new TH1D("hQ22", "", 200, 0, 200);
	TH1D *	hQ2w = new TH1D("hQ2w", "", 200, 0, 200);

	TH1D *	hQ1pp = new TH1D("hQ1pp", "", 200, 0, 200);
	TH1D *	hQ1nn = new TH1D("hQ1nn", "", 200, 0, 200);
	TH1D *	hQ1pn = new TH1D("hQ1pn", "", 200, 0, 200);
	TH1D *	hQ1ppw= new TH1D("hQ1ppw", "", 200, 0, 200);
	TH1D *	hQ1nnw= new TH1D("hQ1nnw", "", 200, 0, 200);
	TH1D *	hQ1pnw= new TH1D("hQ1pnw", "", 200, 0, 200);

	TH1D *	hQ2pp = new TH1D("hQ2pp", "", 200, 0, 200);
	TH1D *	hQ2nn = new TH1D("hQ2nn", "", 200, 0, 200);
	TH1D *	hQ2pn = new TH1D("hQ2pn", "", 200, 0, 200);
	TH1D *	hQ2nnw= new TH1D("hQ2nnw", "", 200, 0, 200);
	TH1D *	hQ2ppw= new TH1D("hQ2ppw", "", 200, 0, 200);
	TH1D *	hQ2pnw= new TH1D("hQ2pnw", "", 200, 0, 200);

	TH1D *	hQ3pp = new TH1D("hQ3pp", "", 200, 0, 200);
	TH1D *	hQ3nn = new TH1D("hQ3nn", "", 200, 0, 200);
	TH1D *	hQ3pn = new TH1D("hQ3pn", "", 200, 0, 200);
	TH1D *	hQ3ppw= new TH1D("hQ3ppw", "", 200, 0, 200);
	TH1D *	hQ3nnw= new TH1D("hQ3nnw", "", 200, 0, 200);
	TH1D *	hQ3pnw= new TH1D("hQ3pnw", "", 200, 0, 200);

	TH1D * hCent = new TH1D("hCent", "Centrality", 200, 0, 200);
	TH1D * hMult = new TH1D("hMult", "Multiplicity", 5000, 0, 5000);
	unsigned int ievt = 0;
	while (chV->GetEntry(ievt++)) {
		if ( not (ievt%100000) ) cout << "!!! ievt = " << ievt << endl;
		hCent->Fill(cent);
		hMult->Fill(mult);

		Complex	Q1p  ( rQ1p,  iQ1p );
		Complex	Q1p2 ( rQ1p2, iQ1p2 );
		Complex	Q2p1 ( rQ2p1, iQ2p1 );
		Complex	Q2p2 ( rQ2p2, iQ2p2 );
		Complex	Q3p2 ( rQ3p2, iQ3p2 );
		Complex	Q3p3 ( rQ3p3, iQ3p3 );
		Complex	QMp2 ( rQMp2, iQMp2 );

		Complex	Q1n  ( rQ1n,  iQ1n );
		Complex	Q1n2 ( rQ1n2, iQ1n2 );
		Complex	Q2n1 ( rQ2n1, iQ2n1 );
		Complex	Q2n2 ( rQ2n2, iQ2n2 );
		Complex	Q3n2 ( rQ3n2, iQ3n2 );
		Complex	Q3n3 ( rQ3n3, iQ3n3 );
		Complex	QMn2 ( rQMn2, iQMn2 );

		// <(Q_1c)^2>
		hQ1c->Fill( std::norm(Q1p - Q1n) );
		hQ1w->Fill( wp1 + wn1 );
		// <(Q_2)^2>
		hQ22->Fill( std::norm(Q2p1 + Q2n1 + Q1p*Q1n*2.) );
		hQ2w->Fill( (wp1 + wn1)*(wp1 + wn1 -1) );

		// <cos(i-j)> ++
		hQ1pp->Fill( Q1p2.real() );
		hQ1ppw->Fill( wp2 );
		// <cos(i-j)> --
		hQ1nn->Fill( Q1n2.real() );
		hQ1nnw->Fill( wn2 );
		// <cos(i-j)> +-
		hQ1pn->Fill( (Q1p * std::conj(Q1n)).real() );
		hQ1pnw->Fill( wp1 * wn1 );

		// <cos(2i-2j)> ++
		hQ2pp->Fill( Q2p2.real() );
		hQ2ppw->Fill( wp2 );
		// <cos(2i-2j)> --
		hQ2nn->Fill( Q2n2.real() );
		hQ2nnw->Fill( wn2 );
		// <cos(2i-2j)> +-
		hQ2pn->Fill( (Q2p1 * std::conj(Q2n1)).real() );
		hQ2pnw->Fill( wp1 * wn1 );

		// <cos(i+j-2k)> ++a
		hQ3pp->Fill( (Q3p3 + Q3p2*std::conj(Q2n1)).real() );
		hQ3ppw->Fill( wp3 + wp2*wn1 );
		// <cos(i+j-2k)> --a
		hQ3nn->Fill( (Q3n3 + Q3n2*std::conj(Q2p1)).real() );
		hQ3nnw->Fill( wn3 + wn2*wp1 );
		// <cos(i+j-2k)> +-a
		// -,+,+
	}

	TFile * fwrite = new TFile(Form("%s/output.root", ftxt[s1]), "recreate");
	hCent->Write();
	hMult->Write();
	fwrite->Close();
}
