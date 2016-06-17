#include "label.h"
#include <TH1D.h>

void ana(int s1 = 1)
{
	TFile * f = new TFile(Form("%s/output.root", ftxt[s1]));
	TH1D *	hQ1c   = (TH1D*) f->Get("hQ1c");
	TH1D *	hQ1w   = (TH1D*) f->Get("hQ1w");
	TH1D *	hQ2    = (TH1D*) f->Get("hQ2");
	TH1D *	hQ2w   = (TH1D*) f->Get("hQ2w");

	TH1D *	hQ1pp  = (TH1D*) f->Get("hQ1pp");
	TH1D *	hQ1nn  = (TH1D*) f->Get("hQ1nn");
	TH1D *	hQ1pn  = (TH1D*) f->Get("hQ1pn");
	TH1D *	hQ1ppw = (TH1D*) f->Get("hQ1ppw");
	TH1D *	hQ1nnw = (TH1D*) f->Get("hQ1nnw");
	TH1D *	hQ1pnw = (TH1D*) f->Get("hQ1pnw");

	TH1D *	hQ2pp  = (TH1D*) f->Get("hQ2pp");
	TH1D *	hQ2nn  = (TH1D*) f->Get("hQ2nn");
	TH1D *	hQ2pn  = (TH1D*) f->Get("hQ2pn");
	TH1D *	hQ2aa  = (TH1D*) f->Get("hQ2aa");
	TH1D *	hQ2nnw = (TH1D*) f->Get("hQ2nnw");
	TH1D *	hQ2ppw = (TH1D*) f->Get("hQ2ppw");
	TH1D *	hQ2pnw = (TH1D*) f->Get("hQ2pnw");
	TH1D *	hQ2aaw = (TH1D*) f->Get("hQ2aaw");

	TH1D *	hQ3pp  = (TH1D*) f->Get("hQ3pp");
	TH1D *	hQ3nn  = (TH1D*) f->Get("hQ3nn");
	TH1D *	hQ3ss  = (TH1D*) f->Get("hQ3ss");
	TH1D *	hQ3pn  = (TH1D*) f->Get("hQ3pn");
	TH1D *	hQ3ppw = (TH1D*) f->Get("hQ3ppw");
	TH1D *	hQ3nnw = (TH1D*) f->Get("hQ3nnw");
	TH1D *	hQ3ssw = (TH1D*) f->Get("hQ3ssw");
	TH1D *	hQ3pnw = (TH1D*) f->Get("hQ3pnw");

	TH1D *	hQ3Sc  = (TH1D*) f->Get("hQ3Sc");

	TH1D * hCent   = (TH1D*) f->Get("hCent");
	TH1D * hMult   = (TH1D*) f->Get("hMult");
	TH1D * hMultp  = (TH1D*) f->Get("hMultp");
	TH1D * hMultn  = (TH1D*) f->Get("hMultn");

	TH2D * hDPhi = (TH2D*) f->Get("hDPhi");

	TH1D * hv2aa = (TH1D*) hQ2aa->Clone("hv2aa");
	TH1D * hv2pp = (TH1D*) hQ2pp->Clone("hv2pp");
	TH1D * hv2nn = (TH1D*) hQ2nn->Clone("hv2nn");
	TH1D * hv2pn = (TH1D*) hQ2pn->Clone("hv2pn");


	hv2aa->Divide(hQ2aaw);
	hv2pp->Divide(hQ2ppw);
	hv2nn->Divide(hQ2nnw);
	hv2pn->Divide(hQ2pnw);

	hv2pp->SetLineColor(kRed);
	hv2nn->SetLineColor(kBlue);
	hv2pn->SetLineColor(kGreen);
	hv2pp->SetMarkerColor(kRed);
	hv2nn->SetMarkerColor(kBlue);
	hv2pn->SetMarkerColor(kGreen);


	for ( int c = 0; c < 200; c++ ) {
		hv2aa->SetBinContent(c+1, hv2aa->GetBinContent(c+1)>0?sqrt(hv2aa->GetBinContent(c+1)):-1);
		hv2pp->SetBinContent(c+1, hv2pp->GetBinContent(c+1)>0?sqrt(hv2pp->GetBinContent(c+1)):-1);
		hv2nn->SetBinContent(c+1, hv2nn->GetBinContent(c+1)>0?sqrt(hv2nn->GetBinContent(c+1)):-1);
		hv2pn->SetBinContent(c+1, hv2pn->GetBinContent(c+1)>0?sqrt(hv2pn->GetBinContent(c+1)):-1);
	}

	TCanvas * c1 = new TCanvas();
	hv2aa->GetYaxis()->SetRangeUser(0, 0.4);
	hv2aa->SetTitle(";Centrality;v_{2}");
	hv2aa->Draw();
	hv2pp->Draw("same");
	hv2nn->Draw("same");
	hv2pn->Draw("same");

	TCanvas * c2 = new TCanvas();

	TH1D * h3PartSS = (TH1D*) hQ3ss->Clone("h3PartSS");
	TH1D * h3PartOS = (TH1D*) hQ3pn->Clone("h3PartOS");
	h3PartSS->Divide(hQ3ssw);
	h3PartOS->Divide(hQ3pnw);

	h3PartSS->Divide(hv2aa);
	h3PartOS->Divide(hv2aa);

	h3PartOS->SetLineColor(kRed);
	h3PartOS->SetMarkerColor(kRed);

	h3PartSS->GetYaxis()->SetRangeUser(-0.01, 0.01);
	h3PartSS->SetTitle(";Centrality;cos(#phi_{i}+#phi_{j}-2#phi_{k})");

	h3PartSS->Draw();
	h3PartOS->Draw("same");

	TCanvas * c3 = new TCanvas();
	hQ3Sc->Divide(hCent);

	hQ3Sc->GetYaxis()->SetRangeUser(0, 0.8);
	hQ3Sc->SetTitle(";Centrality;cos(2#Delta#Psi)");
	hQ3Sc->Draw();

	TCanvas * c4 = new TCanvas();
	hMultp->SetMarkerColor(kRed);
	hMultp->SetLineColor(kRed);
	hMultn->SetMarkerColor(kBlue);
	hMultn->SetLineColor(kBlue);

	hMultp->Divide(hMultn);
	hMultp->GetYaxis()->SetRangeUser(0.99, 1.05);

	hMultp->SetTitle(";Centrality;Mult Pos/Neg");
	hMultp->Draw();

	TCanvas * c5 = new TCanvas();

	hQ1c->Draw();

	c1->SaveAs(Form("%s/v2.pdf", ftxt[s1]));
	c2->SaveAs(Form("%s/cos3part.pdf", ftxt[s1]));
	c3->SaveAs(Form("%s/DPsi.pdf", ftxt[s1]));
	c4->SaveAs(Form("%s/Qratio.pdf", ftxt[s1]));

	TFile * fsave = new TFile(Form("%s/ana.root", ftxt[s1]), "recreate");
	hQ3Sc->Write();
	h3PartSS->Write();
	h3PartOS->Write();
}
