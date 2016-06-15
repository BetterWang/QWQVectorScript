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
	TH1D *	hQ2  = new TH1D("hQ2",  "", 200, 0, 200);
	TH1D *	hQ2w = new TH1D("hQ2w", "", 200, 0, 200);
	TH2D *	h2Q2 = new TH1D("h2Q2", "", 200, 0, 200, 500, 0, 0.5);

	TH1D *	hQ1pp = new TH1D("hQ1pp", "", 200, 0, 200);
	TH1D *	hQ1nn = new TH1D("hQ1nn", "", 200, 0, 200);
	TH1D *	hQ1pn = new TH1D("hQ1pn", "", 200, 0, 200);
	TH1D *	hQ1ppw= new TH1D("hQ1ppw", "", 200, 0, 200);
	TH1D *	hQ1nnw= new TH1D("hQ1nnw", "", 200, 0, 200);
	TH1D *	hQ1pnw= new TH1D("hQ1pnw", "", 200, 0, 200);

	TH1D *	hQ2pp = new TH1D("hQ2pp", "", 200, 0, 200);
	TH1D *	hQ2nn = new TH1D("hQ2nn", "", 200, 0, 200);
	TH1D *	hQ2pn = new TH1D("hQ2pn", "", 200, 0, 200);
	TH1D *	hQ2aa = new TH1D("hQ2aa", "", 200, 0, 200);
	TH1D *	hQ2nnw= new TH1D("hQ2nnw", "", 200, 0, 200);
	TH1D *	hQ2ppw= new TH1D("hQ2ppw", "", 200, 0, 200);
	TH1D *	hQ2pnw= new TH1D("hQ2pnw", "", 200, 0, 200);
	TH1D *	hQ2aaw= new TH1D("hQ2aaw", "", 200, 0, 200);

	TH1D *	hQ3pp = new TH1D("hQ3pp", "", 200, 0, 200);
	TH1D *	hQ3nn = new TH1D("hQ3nn", "", 200, 0, 200);
	TH1D *	hQ3ss = new TH1D("hQ3ss", "", 200, 0, 200);
	TH1D *	hQ3pn = new TH1D("hQ3pn", "", 200, 0, 200);
	TH1D *	hQ3ppw= new TH1D("hQ3ppw", "", 200, 0, 200);
	TH1D *	hQ3nnw= new TH1D("hQ3nnw", "", 200, 0, 200);
	TH1D *	hQ3ssw= new TH1D("hQ3ssw", "", 200, 0, 200);
	TH1D *	hQ3pnw= new TH1D("hQ3pnw", "", 200, 0, 200);

	TH1D *	hQ3Sc = new TH1D("hQ3Sc", "", 200, 0, 200);

	TH2D * hDPhi = new TH2D("hDPhi", "", 200, 0, 200, 18, 0, TMath::Pi()/2);

	TH1D * hCent = new TH1D("hCent", "Centrality", 200, 0, 200);
	TH1D * hMult = new TH1D("hMult", "Multiplicity", 5000, 0, 5000);

	TH1D *	hMultp = new TH1D("hMultp", "", 200, 0, 200);
	TH1D *	hMultn = new TH1D("hMultn", "", 200, 0, 200);
	unsigned int ievt = 0;
	while (chV->GetEntry(ievt++)) {
		if ( not (ievt%100000) ) cout << "!!! ievt = " << ievt << endl;
		hCent->Fill(cent);
		hMult->Fill(mult);
		hMultp->Fill(cent, wp1);
		hMultn->Fill(cent, wn1);

		// Exp(I * phi_i) +
		Complex	Q1p  ( rQ1p,  iQ1p );
		// Exp(I * (phi_i - phi_j) ) ++
		Complex	Q1p2 ( rQ1p2, iQ1p2 );
		// Exp(I * 2phi_i) +
		Complex	Q2p1 ( rQ2p1, iQ2p1 );
		// Exp(I * (2phi_i - 2phi_j)) ++
		Complex	Q2p2 ( rQ2p2, iQ2p2 );
		// Exp(I * (phi_i + phi_j)) ++
		Complex	Q3p2 ( rQ3p2, iQ3p2 );
		// Exp(I * (phi_i + phi_j - 2 phi_k)) +++
		Complex	Q3p3 ( rQ3p3, iQ3p3 );
		// Exp(I * (phi_i + - 2 phi_j)) ++
		Complex	QMp2 ( rQMp2, iQMp2 );

		Complex	Q1n  ( rQ1n,  iQ1n );
		Complex	Q1n2 ( rQ1n2, iQ1n2 );
		Complex	Q2n1 ( rQ2n1, iQ2n1 );
		Complex	Q2n2 ( rQ2n2, iQ2n2 );
		Complex	Q3n2 ( rQ3n2, iQ3n2 );
		Complex	Q3n3 ( rQ3n3, iQ3n3 );
		Complex	QMn2 ( rQMn2, iQMn2 );

//		cout << " Q1p  = " << Q1p  << endl;
//		cout << " Q1p2 = " << Q1p2 << endl;
//		cout << " Q2p1 = " << Q2p1 << endl;
//		cout << " Q2p2 = " << Q2p2 << endl;
//		cout << " Q3p2 = " << Q3p2 << endl;
//		cout << " Q3p3 = " << Q3p3 << endl;
//		cout << " QMp2 = " << QMp2 << endl;
//		cout << " wp1  = " << wp1  << endl;
//		cout << " wp2  = " << wp2  << endl;
//		cout << " wp3  = " << wp3  << endl;
//
//		cout << " Q1n  = " << Q1n  << endl;
//		cout << " Q1n2 = " << Q1n2 << endl;
//		cout << " Q2n1 = " << Q2n1 << endl;
//		cout << " Q2n2 = " << Q2n2 << endl;
//		cout << " Q3n2 = " << Q3n2 << endl;
//		cout << " Q3n3 = " << Q3n3 << endl;
//		cout << " QMn2 = " << QMn2 << endl;
//		cout << " wn1  = " << wn1  << endl;
//		cout << " wn2  = " << wn2  << endl;
//		cout << " wn3  = " << wn3  << endl;

		// <(Q_1c)^2>
		hQ1c->Fill( cent, std::norm(Q1p - Q1n) ); //x
		hQ1w->Fill( cent, wp1 + wn1 ); //x
		// <(Q_2)^2>
		hQ2->Fill( cent, std::norm(Q2p1 + Q2n1) ); //x
		hQ2w->Fill( cent, (wp1 + wn1) ); //x
		h2Q2->Fill( cent, std::abs( (Q2p1 + Q2n1)/(wp1+wn1) ) );


		// <cos(i-j)> ++
		hQ1pp->Fill( cent, Q1p2.real() ); //x
		hQ1ppw->Fill( cent, wp2 ); //x
		// <cos(i-j)> --
		hQ1nn->Fill( cent, Q1n2.real() ); //x
		hQ1nnw->Fill( cent, wn2 ); //x
		// <cos(i-j)> +-
		hQ1pn->Fill( cent, (Q1p * std::conj(Q1n)).real() ); //x
		hQ1pnw->Fill( cent, wp1 * wn1 ); //x

		// <cos(2i-2j)> ++
		hQ2pp->Fill( cent, Q2p2.real() ); // x
		hQ2ppw->Fill( cent, wp2 ); // x
		// <cos(2i-2j)> --
		hQ2nn->Fill( cent, Q2n2.real() ); // x
		hQ2nnw->Fill( cent, wn2 ); // x
		// <cos(2i-2j)> +-
		hQ2pn->Fill( cent, (Q2p1 * std::conj(Q2n1)).real() ); // x
		hQ2pnw->Fill( cent, wp1 * wn1 ); // x
		// <cos(2i-2j)> aa
		hQ2aa->Fill( cent, (Q2p1 * std::conj(Q2n1) + Q2n1*std::conj(Q2p1) + Q2p2 + Q2n2).real() ); // x
		hQ2aaw->Fill( cent, 2*wp1*wn1 + wp2 + wn2 ); // x

		// <cos(i+j-2k)> ++a
		hQ3pp->Fill( cent, (Q3p3 + Q3p2*std::conj(Q2n1)).real() ); // x
		hQ3ppw->Fill( cent, wp3 + wp2*wn1 ); // x
		// <cos(i+j-2k)> --a
		hQ3nn->Fill( cent, (Q3n3 + Q3n2*std::conj(Q2p1)).real() ); // x
		hQ3nnw->Fill( cent, wn3 + wn2*wp1 ); // x
		// <cos(i+j-2k)> ++a/--a
		hQ3ss->Fill( cent, (Q3p3 + Q3p2*std::conj(Q2n1) + Q3n3 + Q3n2*std::conj(Q2p1)).real() ); //
		hQ3ssw->Fill( cent, wp3 + wp2*wn1 + wn3 + wn2*wp1 ); //

		// <cos(i+j-2k)> +-a
		hQ3pn->Fill( cent, (QMp2 * Q1n + QMn2 * Q1p).real() ); // x
		hQ3pnw->Fill( cent, wp2 * wn1 + wn2 * wp1); // x
		// S1c qi*qj*cos(i-j)
		Complex S1c = - Q1p * std::conj(Q1n) - Q1n * std::conj(Q1p) + Q1p2 + Q1n2; // x
		// S2 cos(2i-2j)
		Complex S2 = Q2p2 + Q2n2 + Q2p1*std::conj(Q2n1) + Q2n1*std::conj(Q2p1); // x
		// S3c qi*qj*cos(i+j-2k)
		Complex S3c = Q3p3 + Q3p2*std::conj(Q2n1) - 2.*QMp2*Q1n - 2.*QMn2*Q1p + Q3n2*std::conj(Q2p1) + Q3n3; // x
		// hQ3Sc
		double Nch = wp1 + wn1;
		hQ3Sc->Fill( cent, (Nch + 2 * S1c.real() + S2.real() + S3c.real()) / ( (Nch + S1c.real()) * sqrt(Nch + S2.real()) ) );

		// DeltaPhi
		double Dphi = fabs(std::arg( (Q1p - Q1n) * std::conj(Q2p1 + Q2n1) ));
		if ( Dphi > TMath::Pi()/2 ) Dphi = TMath::Pi() - Dphi;
		hDPhi->Fill(cent, Dphi);
	}

	TFile * fwrite = new TFile(Form("%s/output.root", ftxt[s1]), "recreate");

	hQ1c  ->Write();
	hQ1w  ->Write();
	hQ2   ->Write();
	h2Q2  ->Write();
	hQ2w  ->Write();
	hQ1pp ->Write();
	hQ1nn ->Write();
	hQ1pn ->Write();
	hQ1ppw->Write();
	hQ1nnw->Write();
	hQ1pnw->Write();
	hQ2pp ->Write();
	hQ2nn ->Write();
	hQ2pn ->Write();
	hQ2aa ->Write();
	hQ2nnw->Write();
	hQ2ppw->Write();
	hQ2pnw->Write();
	hQ2aaw->Write();
	hQ3pp ->Write();
	hQ3nn ->Write();
	hQ3ss ->Write();
	hQ3pn ->Write();
	hQ3ppw->Write();
	hQ3nnw->Write();
	hQ3ssw->Write();
	hQ3pnw->Write();
	hQ3Sc->Write();

	hCent->Write();
	hMult->Write();
	hMultp->Write();
	hMultn->Write();
	hDPhi->Write();
	fwrite->Close();
}
