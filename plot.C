#include "label.h"
#include "noff.h"
#include "../../style.h"
#include "ALICE.h"


void plot(int s1 = 7)
{
	bool bAlice = true;

	TFile * f = new TFile(Form("%s/out_rebin.root", ftxt[s1]));
	SetStyle();

	if ( bAlice ) ALICE();

	TH1D * hQ1c_Cent  = (TH1D*) f->Get("hQ1c_Cent");
	TH1D * hQ1w_Cent  = (TH1D*) f->Get("hQ1w_Cent");
	TH1D * hQ2_Cent   = (TH1D*) f->Get("hQ2_Cent");
	TH1D * hQ2w_Cent  = (TH1D*) f->Get("hQ2w_Cent");

	TH1D * hQ1pp_Cent = (TH1D*) f->Get("hQ1pp_Cent");
	TH1D * hQ1nn_Cent = (TH1D*) f->Get("hQ1nn_Cent");
	TH1D * hQ1pn_Cent = (TH1D*) f->Get("hQ1pn_Cent");
	TH1D * hQ1ppw_Cent= (TH1D*) f->Get("hQ1ppw_Cent");
	TH1D * hQ1nnw_Cent= (TH1D*) f->Get("hQ1nnw_Cent");
	TH1D * hQ1pnw_Cent= (TH1D*) f->Get("hQ1pnw_Cent");

	TH1D * hQ2pp_Cent = (TH1D*) f->Get("hQ2pp_Cent");
	TH1D * hQ2nn_Cent = (TH1D*) f->Get("hQ2nn_Cent");
	TH1D * hQ2pn_Cent = (TH1D*) f->Get("hQ2pn_Cent");
	TH1D * hQ2aa_Cent = (TH1D*) f->Get("hQ2aa_Cent");
	TH1D * hQ2nnw_Cent= (TH1D*) f->Get("hQ2nnw_Cent");
	TH1D * hQ2ppw_Cent= (TH1D*) f->Get("hQ2ppw_Cent");
	TH1D * hQ2pnw_Cent= (TH1D*) f->Get("hQ2pnw_Cent");
	TH1D * hQ2aaw_Cent= (TH1D*) f->Get("hQ2aaw_Cent");

	TH1D * hQ3pp_Cent = (TH1D*) f->Get("hQ3pp_Cent");
	TH1D * hQ3nn_Cent = (TH1D*) f->Get("hQ3nn_Cent");
	TH1D * hQ3ss_Cent = (TH1D*) f->Get("hQ3ss_Cent");
	TH1D * hQ3pn_Cent = (TH1D*) f->Get("hQ3pn_Cent");
	TH1D * hQ3ppw_Cent= (TH1D*) f->Get("hQ3ppw_Cent");
	TH1D * hQ3nnw_Cent= (TH1D*) f->Get("hQ3nnw_Cent");
	TH1D * hQ3ssw_Cent= (TH1D*) f->Get("hQ3ssw_Cent");
	TH1D * hQ3pnw_Cent= (TH1D*) f->Get("hQ3pnw_Cent");

	TH1D * hQ3Sc_Cent = (TH1D*) f->Get("hQ3Sc_Cent");

	TH1D * hCent_Cent = (TH1D*) f->Get("hCent_Cent");
	TH1D * hMult_Cent = (TH1D*) f->Get("hMult_Cent");
	TH1D * hMultp_Cent= (TH1D*) f->Get("hMultp_Cent");
	TH1D * hMultn_Cent= (TH1D*) f->Get("hMultn_Cent");

	TH1D * hv2aa_Cent = (TH1D*) f->Get("hv2aa_Cent");
	TH1D * hv2pp_Cent = (TH1D*) f->Get("hv2pp_Cent");
	TH1D * hv2nn_Cent = (TH1D*) f->Get("hv2nn_Cent");
	TH1D * hv2pn_Cent = (TH1D*) f->Get("hv2pn_Cent");

	TH1D * h3PartSS_Cent = (TH1D*) f->Get("h3PartSS_Cent");
	TH1D * h3PartOS_Cent = (TH1D*) f->Get("h3PartOS_Cent");

	TCanvas * c1 = MakeCanvas("c1", "c1", 500, 400);
	TH2D * hframe_v2 = new TH2D("hframe_v2", "hframe_v2", 1, 0, 200, 1, 0., 0.4);
	InitHist(hframe_v2, "Centrality Bin", "v_{2}");
	hframe_v2->Draw();

	hv2pp_Cent->SetMarkerColor(kRed);
	hv2nn_Cent->SetMarkerColor(kBlue);
	hv2pn_Cent->SetMarkerColor(kGreen);

	hv2pp_Cent->SetLineColor(kRed);
	hv2nn_Cent->SetLineColor(kBlue);
	hv2pn_Cent->SetLineColor(kGreen);


	hv2aa_Cent->Draw("same");
	hv2pp_Cent->Draw("same");
	hv2nn_Cent->Draw("same");
	hv2pn_Cent->Draw("same");


	TCanvas * c2 = MakeCanvas("c2", "c2", 500, 400);
	TH2D * hframe_3part = new TH2D("hframe_3part", "hframe_3part", 1, 0, 200, 1, -0.002, 0.002);
	InitHist(hframe_3part, "Centrality Bin", "cos(#phi_{i}+#phi_{j}-2#Psi_{2})");
	hframe_3part->Draw();

	TLine * zero = new TLine(0, 0, 200, 0);
	zero->Draw();

	h3PartSS_Cent->SetMarkerColor(kRed);
	h3PartOS_Cent->SetMarkerColor(kBlue);
	h3PartSS_Cent->SetLineColor(kRed);
	h3PartOS_Cent->SetLineColor(kBlue);

	h3PartSS_Cent->Draw("same");
	h3PartOS_Cent->Draw("same");
	if ( bAlice ) gr_ALICE_3part_tpccumu_os->Draw("psame");
	if ( bAlice ) gr_ALICE_3part_tpccumu_ss->Draw("psame");

	TCanvas * c3 = MakeCanvas("c3", "c3", 500, 400);
	TH2D * hframe_Q3Sc = new TH2D("hframe_Q3Sc", "hframe_Q3Sc", 1, 0, 200, 1, .0, 1.0);
	InitHist(hframe_Q3Sc, "Centrality Bin", "#LTcos(2#Delta#Psi)#GT");
	hframe_Q3Sc->Draw();

	hQ3Sc_Cent->Draw("same");

	TCanvas * c4 = MakeCanvas("c4", "c4", 500, 400);
	TH2D * hframe_Q1c = new TH2D("hframe_Q1c", "hframe_Q1c", 1, 0, 200, 1, 0.00, 2.);
	InitHist(hframe_Q1c, "Centrality Bin", "Q_{1}^{c}");

	hframe_Q1c->Draw();
	hQ1c_Cent->Divide(hQ1w_Cent);
	hQ1c_Cent->Draw("same");

	TCanvas * c5 = MakeCanvas("c5", "c5", 500, 400);
	TH2D * hframe_2part = new TH2D("hframe_2part", "hframe_2part", 1, 0, 200, 1, -0.09, 0.04);
	InitHist(hframe_2part, "Centrality Bin", "#LTcos(#phi_{i}-#phi_{j})#GT");

	hframe_2part->Draw();
	zero->Draw();
	hQ1pp_Cent->Divide(hQ1ppw_Cent);
	hQ1nn_Cent->Divide(hQ1nnw_Cent);
	hQ1pn_Cent->Divide(hQ1pnw_Cent);

	hQ1pp_Cent->SetMarkerColor(kRed);
	hQ1pp_Cent->SetLineColor(kRed);
	hQ1nn_Cent->SetMarkerColor(kBlue);
	hQ1nn_Cent->SetLineColor(kBlue);
	hQ1pn_Cent->SetMarkerColor(kBlack);
	hQ1pn_Cent->SetLineColor(kBlack);

	hQ1pp_Cent->Draw("same");
	hQ1nn_Cent->Draw("same");
	hQ1pn_Cent->Draw("same");

	if ( bAlice ) gr_ALICE_2part_tpccumu_os->Draw("psame");
	if ( bAlice ) gr_ALICE_2part_tpccumu_ss->Draw("psame");

	c1->SaveAs(Form("%s/v22.pdf", ftxt[s1]));
	c2->SaveAs(Form("%s/3part.pdf", ftxt[s1]));
	c3->SaveAs(Form("%s/hQ3Sc.pdf", ftxt[s1]));
	c4->SaveAs(Form("%s/hQ1c.pdf", ftxt[s1]));
	c5->SaveAs(Form("%s/2part.pdf", ftxt[s1]));

}
