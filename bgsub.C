#include "label.h"
#include "noff.h"
#include "../../style.h"


void bgsub(int s1 = 7, int s2 = 13)
{
	SetStyle();
	TFile * f1 = new TFile(Form("%s/out_rebin.root", ftxt[s1]));
	TFile * f2 = new TFile(Form("%s/out_rebin.root", ftxt[s2]));

	TH1D * hQ3Sc1_Cent = (TH1D*) f1->Get("hQ3Sc_Cent");
	TH1D * hQ3Sc2_Cent = (TH1D*) f2->Get("hQ3Sc_Cent");

	hQ3Sc1_Cent->SetMarkerColor(kRed);
	hQ3Sc1_Cent->SetLineColor(kRed);
	hQ3Sc2_Cent->SetMarkerColor(kBlue);
	hQ3Sc2_Cent->SetLineColor(kBlue);

	TLine * zero = new TLine(0, 0, 200, 0);

	TCanvas * c1 = MakeCanvas("c1", "c1", 500, 400);
	TH2D * hframe_Q3Sc = new TH2D("hframe_Q3Sc", "hframe_Q3Sc", 1, 0, 200, 1, -0.02, 0.41);
	InitHist(hframe_Q3Sc, "Centrality Bin", "#LTcos(2#Delta#Psi)#GT");

	hframe_Q3Sc->Draw();
	zero->Draw();
	hQ3Sc1_Cent->Draw("same");
	hQ3Sc2_Cent->Draw("same");

	TCanvas * c2 = MakeCanvas("c2", "c2", 500, 400);
	TH2D * hframe_Q3ScDiff = new TH2D("hframe_Q3ScDiff", "hframe_Q3ScDiff", 1, 0, 200, 1, -0.02, 0.01);
	InitHist(hframe_Q3ScDiff, "Centrality Bin", "#LTcos(2#Delta#Psi)#GT");

	hframe_Q3ScDiff->Draw();
	zero->Draw();

	TH1D * hQ3Sc1_Diff = (TH1D*) hQ3Sc1_Cent->Clone("hQ3Sc1_Diff");
	hQ3Sc1_Diff->Add(hQ3Sc2_Cent, -1);

	hQ3Sc1_Diff->SetMarkerColor(kBlack);
	hQ3Sc1_Diff->SetLineColor(kBlack);

	hQ3Sc1_Diff->Draw("same");

	TH1D * hDPhi_Cent1[NCent];
	TH1D * hDPhi_Cent2[NCent];
	for ( int c = 0; c < NCent; c++ ) {
		hDPhi_Cent1[c] = (TH1D*) f1->Get(Form("hDPhi_Cent_%i", c));
		hDPhi_Cent2[c] = (TH1D*) f2->Get(Form("hDPhi_Cent_%i", c));

		hDPhi_Cent1[c]->Add(hDPhi_Cent2[c], -1);
	}


	TCanvas * cT = MakeCanvas("cT", "cT", 1000, 500);
        makeMultiPanelCanvas(cT, 5, 4, 0.0, 0., 0.2, 0.2, 0.01);
	TH2D * hframe_DPhi = new TH2D("hframe_DPhi", "hframe_DPhi", 1, 0, 1.6, 1, -1., 1.);
	InitHist(hframe_DPhi, "#Dleta#Phi", "");
	for ( int c = 0; c < NCent; c++ ) {
		cT->cd(c+1);
//		hframe_DPhi->Draw();
		hDPhi_Cent1[c]->Draw();
	}

	c1->SaveAs(Form("Q3Sc_%i_%i.pdf", s1, s2));
	c2->SaveAs(Form("Q3Sc_%i_%i_Diff.pdf", s1, s2));

}
