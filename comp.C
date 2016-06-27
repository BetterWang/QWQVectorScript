#include "label.h"
#include "noff.h"
#include "../../style.h"
#include "ALICE.h"


void comp(int s1 = 7, int s2 = 18, TString str1 = "|#eta| < 2.4", TString str2 = "|#eta| < 0.8") {
//	bool bAlice = false;
	bool bAlice = true;

	SetStyle();
	if ( bAlice ) ALICE();
	TFile * f1 = new TFile(Form("%s/out_rebin.root", ftxt[s1]));
	TFile * f2 = new TFile(Form("%s/out_rebin.root", ftxt[s2]));


	TH1D * h3PartSS_Cent1 = (TH1D*) f1->Get("h3PartSS_Cent");
	TH1D * h3PartOS_Cent1 = (TH1D*) f1->Get("h3PartOS_Cent");

	TH1D * h3PartSS_Cent2 = (TH1D*) f2->Get("h3PartSS_Cent");
	TH1D * h3PartOS_Cent2 = (TH1D*) f2->Get("h3PartOS_Cent");

	TCanvas * c1 = MakeCanvas("c1", "c1", 500, 400);
	TH2D * hframe_3part = new TH2D("hframe_3part", "hframe_3part", 1, 0, 200, 1, -0.001, 0.002);
	InitHist(hframe_3part, "Centrality Bin", "cos(#phi_{#alpha}+#phi_{#beta}-2#Psi_{2})");
	hframe_3part->Draw();

	TLine * zero = new TLine(0, 0, 200, 0);
	zero->Draw();

	h3PartSS_Cent1->SetMarkerStyle(kFullCircle);
	h3PartOS_Cent1->SetMarkerStyle(kFullCircle);
	h3PartSS_Cent1->SetMarkerColor(kRed);
	h3PartOS_Cent1->SetMarkerColor(kBlue);
	h3PartSS_Cent1->SetLineColor(kRed);
	h3PartOS_Cent1->SetLineColor(kBlue);

	h3PartSS_Cent2->SetMarkerStyle(kFullSquare);
	h3PartOS_Cent2->SetMarkerStyle(kFullSquare);
	h3PartSS_Cent2->SetMarkerColor(kRed);
	h3PartOS_Cent2->SetMarkerColor(kBlue);
	h3PartSS_Cent2->SetLineColor(kRed);
	h3PartOS_Cent2->SetLineColor(kBlue);


	h3PartSS_Cent1->Draw("same");
	h3PartOS_Cent1->Draw("same");
	h3PartSS_Cent2->Draw("same");
	h3PartOS_Cent2->Draw("same");

	if ( bAlice ) gr_ALICE_3part_tpccumu_os->Draw("psame");
	if ( bAlice ) gr_ALICE_3part_tpccumu_ss->Draw("psame");

	TLegend * leg1 = new TLegend(0.2, 0.5, 0.5, 0.9);
	leg1->SetFillColor(kWhite);
	leg1->SetTextFont(42);
	leg1->SetTextSize(0.06);
	leg1->SetBorderSize(0);

	leg1->AddEntry(h3PartSS_Cent1, Form("SS %s", str1.Data()), "p");
	leg1->AddEntry(h3PartOS_Cent1, Form("OS %s", str1.Data()), "p");
	leg1->AddEntry(h3PartSS_Cent2, Form("SS %s", str2.Data()), "p");
	leg1->AddEntry(h3PartOS_Cent2, Form("OS %s", str2.Data()), "p");

	if ( bAlice ) leg1->AddEntry(gr_ALICE_3part_tpccumu_ss, "ALICE SS", "p");
	else leg1->AddEntry(gr_ALICE_3part_tpccumu_ss, " ", "");
	if ( bAlice ) leg1->AddEntry(gr_ALICE_3part_tpccumu_os, "ALICE OS", "p");
	else leg1->AddEntry(gr_ALICE_3part_tpccumu_os, " ", "");

	leg1->Draw();

	///////////
	TCanvas * c2 = MakeCanvas("c2", "c2", 500, 400);
	TH2D * hframe_2part = new TH2D("hframe_2part", "hframe_2part", 1, 0, 200, 1, -0.01, 0.03);
	InitHist(hframe_2part, "Centrality Bin", "#LTcos(#phi_{#alpha}-#phi_{#beta})#GT");

	TH1D * hQ1pp_Cent1 = (TH1D*) f1->Get("hQ1pp_Cent");
	TH1D * hQ1nn_Cent1 = (TH1D*) f1->Get("hQ1nn_Cent");
	TH1D * hQ1pn_Cent1 = (TH1D*) f1->Get("hQ1pn_Cent");
	TH1D * hQ1ppw_Cent1= (TH1D*) f1->Get("hQ1ppw_Cent");
	TH1D * hQ1nnw_Cent1= (TH1D*) f1->Get("hQ1nnw_Cent");
	TH1D * hQ1pnw_Cent1= (TH1D*) f1->Get("hQ1pnw_Cent");

	TH1D * hQ1pp_Cent2 = (TH1D*) f2->Get("hQ1pp_Cent");
	TH1D * hQ1nn_Cent2 = (TH1D*) f2->Get("hQ1nn_Cent");
	TH1D * hQ1pn_Cent2 = (TH1D*) f2->Get("hQ1pn_Cent");
	TH1D * hQ1ppw_Cent2= (TH1D*) f2->Get("hQ1ppw_Cent");
	TH1D * hQ1nnw_Cent2= (TH1D*) f2->Get("hQ1nnw_Cent");
	TH1D * hQ1pnw_Cent2= (TH1D*) f2->Get("hQ1pnw_Cent");

	hQ1pp_Cent1->Add(hQ1nn_Cent1);
	hQ1ppw_Cent1->Add(hQ1nnw_Cent1);
	hQ1pp_Cent2->Add(hQ1nn_Cent2);
	hQ1ppw_Cent2->Add(hQ1nnw_Cent2);

	hQ1pp_Cent1->Divide(hQ1ppw_Cent1);
	hQ1pp_Cent2->Divide(hQ1ppw_Cent2);
	hQ1pn_Cent1->Divide(hQ1pnw_Cent1);
	hQ1pn_Cent2->Divide(hQ1pnw_Cent2);


	hQ1pp_Cent1->SetMarkerStyle(kFullCircle);
	hQ1pn_Cent1->SetMarkerStyle(kFullCircle);
	hQ1pp_Cent1->SetMarkerColor(kRed);
	hQ1pn_Cent1->SetMarkerColor(kBlue);
	hQ1pp_Cent1->SetLineColor(kRed);
	hQ1pn_Cent1->SetLineColor(kBlue);

	hQ1pp_Cent2->SetMarkerStyle(kFullSquare);
	hQ1pn_Cent2->SetMarkerStyle(kFullSquare);
	hQ1pp_Cent2->SetMarkerColor(kRed);
	hQ1pn_Cent2->SetMarkerColor(kBlue);
	hQ1pp_Cent2->SetLineColor(kRed);
	hQ1pn_Cent2->SetLineColor(kBlue);


	hframe_2part->Draw();
	zero->Draw();
	hQ1pp_Cent1->Draw("same");
	hQ1pn_Cent1->Draw("same");
	hQ1pp_Cent2->Draw("same");
	hQ1pn_Cent2->Draw("same");
	if ( bAlice ) gr_ALICE_2part_tpccumu_os->Draw("psame");
	if ( bAlice ) gr_ALICE_2part_tpccumu_ss->Draw("psame");

	TLegend * leg2 = new TLegend(0.2, 0.5, 0.5, 0.9);
	leg2->SetFillColor(kWhite);
	leg2->SetTextFont(42);
	leg2->SetTextSize(0.06);
	leg2->SetBorderSize(0);

	leg2->AddEntry(hQ1pp_Cent1, Form("SS %s", str1.Data()), "p");
	leg2->AddEntry(hQ1pn_Cent1, Form("OS %s", str1.Data()), "p");
	leg2->AddEntry(hQ1pp_Cent2, Form("SS %s", str2.Data()), "p");
	leg2->AddEntry(hQ1pn_Cent2, Form("OS %s", str2.Data()), "p");

	if ( bAlice ) leg2->AddEntry(gr_ALICE_2part_tpccumu_ss, "ALICE SS", "p");
	else leg2->AddEntry(gr_ALICE_2part_tpccumu_ss, " ", "");
	if ( bAlice ) leg2->AddEntry(gr_ALICE_2part_tpccumu_os, "ALICE OS", "p");
	else leg2->AddEntry(gr_ALICE_2part_tpccumu_os, " ", "");

	leg2->Draw();


	///////////////
	TH1D * hCC_SS1 = (TH1D*)hQ1pp_Cent1->Clone("hCC_SS1");
	TH1D * hCC_OS1 = (TH1D*)hQ1pn_Cent1->Clone("hCC_OS1");
	TH1D * hCC_SS2 = (TH1D*)hQ1pp_Cent2->Clone("hCC_SS2");
	TH1D * hCC_OS2 = (TH1D*)hQ1pn_Cent2->Clone("hCC_OS2");

	hCC_SS1->Add(h3PartSS_Cent1);
	hCC_SS1->Scale(0.5);
	hCC_OS1->Add(h3PartOS_Cent1);
	hCC_OS1->Scale(0.5);
	hCC_SS2->Add(h3PartSS_Cent2);
	hCC_SS2->Scale(0.5);
	hCC_OS2->Add(h3PartOS_Cent2);
	hCC_OS2->Scale(0.5);

	TH1D * hSS_SS1 = (TH1D*)hQ1pp_Cent1->Clone("hSS_SS1");
	TH1D * hSS_OS1 = (TH1D*)hQ1pn_Cent1->Clone("hSS_OS1");
	TH1D * hSS_SS2 = (TH1D*)hQ1pp_Cent2->Clone("hSS_SS2");
	TH1D * hSS_OS2 = (TH1D*)hQ1pn_Cent2->Clone("hSS_OS2");

	hSS_SS1->Add(h3PartSS_Cent1, -1);
	hSS_SS1->Scale(0.5);
	hSS_OS1->Add(h3PartOS_Cent1, -1);
	hSS_OS1->Scale(0.5);
	hSS_SS2->Add(h3PartSS_Cent2, -1);
	hSS_SS2->Scale(0.5);
	hSS_OS2->Add(h3PartOS_Cent2, -1);
	hSS_OS2->Scale(0.5);


	////
	TCanvas * c3 = MakeCanvas("c3", "c3", 500, 400);
	TH2D * hframe_cos = new TH2D("hframe_cos", "hframe_cos", 1, 0, 200, 1, -0.01, 0.02);
	InitHist(hframe_cos, "Centrality Bin", "#LTcos(#Delta#phi_{#alpha})cos(#Delta#phi_{#beta})");

	hframe_cos->Draw();
	zero->Draw();

	hCC_SS1->Draw("same");
	hCC_SS2->Draw("same");
	hCC_OS1->Draw("same");
	hCC_OS2->Draw("same");

	if ( bAlice ) gr_ALICE_coscos_ss->Draw("psame");
	if ( bAlice ) gr_ALICE_coscos_os->Draw("psame");

	TLegend * leg_cos = new TLegend(0.2, 0.5, 0.5, 0.9);
	leg_cos->SetFillColor(kWhite);
	leg_cos->SetTextFont(42);
	leg_cos->SetTextSize(0.06);
	leg_cos->SetBorderSize(0);

	leg_cos->AddEntry(hCC_SS1, Form("SS %s", str1.Data()), "p");
	leg_cos->AddEntry(hCC_OS1, Form("OS %s", str1.Data()), "p");
	leg_cos->AddEntry(hCC_SS2, Form("SS %s", str2.Data()), "p");
	leg_cos->AddEntry(hCC_OS2, Form("OS %s", str2.Data()), "p");

	if ( bAlice ) leg_cos->AddEntry(gr_ALICE_coscos_ss, "ALICE SS", "p");
	else leg_cos->AddEntry(gr_ALICE_coscos_ss, " ", "");
	if ( bAlice ) leg_cos->AddEntry(gr_ALICE_coscos_os, "ALICE OS", "p");
	else leg_cos->AddEntry(gr_ALICE_coscos_os, " ", "");

	leg_cos->Draw();


	///
	TCanvas * c4 = MakeCanvas("c4", "c4", 500, 400);
	TH2D * hframe_sin = new TH2D("hframe_sin", "hframe_sin", 1, 0, 200, 1, -0.01, 0.02);
	InitHist(hframe_sin, "Centrality Bin", "#LTsin(#Delta#phi_{#alpha})sin(#Delta#phi_{#beta})");

	hframe_sin->Draw();
	zero->Draw();

	hSS_SS1->Draw("same");
	hSS_SS2->Draw("same");
	hSS_OS1->Draw("same");
	hSS_OS2->Draw("same");

	if ( bAlice ) gr_ALICE_sinsin_ss->Draw("psame");
	if ( bAlice ) gr_ALICE_sinsin_os->Draw("psame");

	TLegend * leg_sin = new TLegend(0.2, 0.5, 0.5, 0.9);
	leg_sin->SetFillColor(kWhite);
	leg_sin->SetTextFont(42);
	leg_sin->SetTextSize(0.06);
	leg_sin->SetBorderSize(0);

	leg_sin->AddEntry(hSS_SS1, Form("SS %s", str1.Data()), "p");
	leg_sin->AddEntry(hSS_OS1, Form("OS %s", str1.Data()), "p");
	leg_sin->AddEntry(hSS_SS2, Form("SS %s", str2.Data()), "p");
	leg_sin->AddEntry(hSS_OS2, Form("OS %s", str2.Data()), "p");

	if ( bAlice ) leg_sin->AddEntry(gr_ALICE_sinsin_ss, "ALICE SS", "p");
	else leg_sin->AddEntry(gr_ALICE_sinsin_ss, " ", "");
	if ( bAlice ) leg_sin->AddEntry(gr_ALICE_sinsin_os, "ALICE OS", "p");
	else leg_sin->AddEntry(gr_ALICE_sinsin_os, " ", "");

	leg_sin->Draw();




	c1->SaveAs(Form("3part%s_%i_%i.pdf", bAlice?"_Alice":"", s1, s2));
	c2->SaveAs(Form("2part%s_%i_%i.pdf", bAlice?"_Alice":"", s1, s2));
	c3->SaveAs(Form("coscos%s_%i_%i.pdf", bAlice?"_Alice":"", s1, s2));
	c4->SaveAs(Form("sinsin%s_%i_%i.pdf", bAlice?"_Alice":"", s1, s2));


}
