#include "label.h"
#include "noff.h"

void sqrthist(TH1D* h)
{
	for ( int c = 0; c < h->GetNbinsX(); c++ ) {
		double val = h->GetBinContent(c+1);
		double err = h->GetBinError(c+1);
		if ( val > 0 ) {
			h->SetBinContent(c+1, sqrt(val));
			h->SetBinError(c+1, err/sqrt(val)/2.);
		} else {
			h->SetBinContent(c+1, -1.);
			h->SetBinError(c+1, -1.);
		}
	}
}



void rebin(int s1 = 7)
{
	TFile * f = new TFile(Form("%s/output.root", ftxt[s1]));
	TH1D *	hQ1c   = (TH1D*) f->Get("hQ1c");
	TH1D *	hQ1w   = (TH1D*) f->Get("hQ1w");
	TH1D *	hQ2    = (TH1D*) f->Get("hQ2");
	TH1D *	hQ2w   = (TH1D*) f->Get("hQ2w");
	TH2D *	h2Q2   = (TH2D*) f->Get("h2Q2");

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

	TH1D *	hQ3pHFpp  = (TH1D*) f->Get("hQ3pHFpp");
	TH1D *	hQ3pHFnn  = (TH1D*) f->Get("hQ3pHFnn");
	TH1D *	hQ3pHFss  = (TH1D*) f->Get("hQ3pHFss");
	TH1D *	hQ3pHFpn  = (TH1D*) f->Get("hQ3pHFpn");
	TH1D *	hQ3pHFppw = (TH1D*) f->Get("hQ3pHFppw");
	TH1D *	hQ3pHFnnw = (TH1D*) f->Get("hQ3pHFnnw");
	TH1D *	hQ3pHFssw = (TH1D*) f->Get("hQ3pHFssw");
	TH1D *	hQ3pHFpnw = (TH1D*) f->Get("hQ3pHFpnw");

	TH1D *	hQ3nHFpp  = (TH1D*) f->Get("hQ3nHFpp");
	TH1D *	hQ3nHFnn  = (TH1D*) f->Get("hQ3nHFnn");
	TH1D *	hQ3nHFss  = (TH1D*) f->Get("hQ3nHFss");
	TH1D *	hQ3nHFpn  = (TH1D*) f->Get("hQ3nHFpn");
	TH1D *	hQ3nHFppw = (TH1D*) f->Get("hQ3nHFppw");
	TH1D *	hQ3nHFnnw = (TH1D*) f->Get("hQ3nHFnnw");
	TH1D *	hQ3nHFssw = (TH1D*) f->Get("hQ3nHFssw");
	TH1D *	hQ3nHFpnw = (TH1D*) f->Get("hQ3nHFpnw");

	TH1D *	hQpHF2 = (TH1D*) f->Get("hQpHF2");
	TH1D *	hQnHF2 = (TH1D*) f->Get("hQnHF2");

	TH1D *	hQ3Sc  = (TH1D*) f->Get("hQ3Sc");

	TH2D *	hDPhi  = (TH2D*) f->Get("hDPhi");

	TH1D *	hCent  = (TH1D*) f->Get("hCent");
	TH1D *	hMult  = (TH1D*) f->Get("hMult");
	TH1D *	hMultp = (TH1D*) f->Get("hMultp");
	TH1D *	hMultn = (TH1D*) f->Get("hMultn");


	// rebin

	TH1D *	hQ1c_Cent   = (TH1D*) hQ1c   ->Rebin(NCent, "hQ1c_Cent", Cent);
	TH1D *	hQ1w_Cent   = (TH1D*) hQ1w   ->Rebin(NCent, "hQ1w_Cent", Cent);
	TH1D *	hQ2_Cent    = (TH1D*) hQ2    ->Rebin(NCent, "hQ2_Cent", Cent);
	TH1D *	hQ2w_Cent   = (TH1D*) hQ2w   ->Rebin(NCent, "hQ2w_Cent", Cent);

	TH1D *  hQ1pp_Cent  =  (TH1D*)  hQ1pp   ->Rebin(NCent,  "hQ1pp_Cent",   Cent);
	TH1D *  hQ1nn_Cent  =  (TH1D*)  hQ1nn   ->Rebin(NCent,  "hQ1nn_Cent",   Cent);
	TH1D *  hQ1pn_Cent  =  (TH1D*)  hQ1pn   ->Rebin(NCent,  "hQ1pn_Cent",   Cent);
	TH1D *  hQ1ppw_Cent =  (TH1D*)  hQ1ppw  ->Rebin(NCent,  "hQ1ppw_Cent",  Cent);
	TH1D *  hQ1nnw_Cent =  (TH1D*)  hQ1nnw  ->Rebin(NCent,  "hQ1nnw_Cent",  Cent);
	TH1D *  hQ1pnw_Cent =  (TH1D*)  hQ1pnw  ->Rebin(NCent,  "hQ1pnw_Cent",  Cent);

	TH1D *	hQ2pp_Cent  = (TH1D*) hQ2pp  ->Rebin(NCent, "hQ2pp_Cent", Cent);
	TH1D *	hQ2nn_Cent  = (TH1D*) hQ2nn  ->Rebin(NCent, "hQ2nn_Cent", Cent);
	TH1D *	hQ2pn_Cent  = (TH1D*) hQ2pn  ->Rebin(NCent, "hQ2pn_Cent", Cent);
	TH1D *	hQ2aa_Cent  = (TH1D*) hQ2aa  ->Rebin(NCent, "hQ2aa_Cent", Cent);
	TH1D *	hQ2nnw_Cent = (TH1D*) hQ2nnw ->Rebin(NCent, "hQ2nnw_Cent", Cent);
	TH1D *	hQ2ppw_Cent = (TH1D*) hQ2ppw ->Rebin(NCent, "hQ2ppw_Cent", Cent);
	TH1D *	hQ2pnw_Cent = (TH1D*) hQ2pnw ->Rebin(NCent, "hQ2pnw_Cent", Cent);
	TH1D *	hQ2aaw_Cent = (TH1D*) hQ2aaw ->Rebin(NCent, "hQ2aaw_Cent", Cent);

	TH1D *	hQ3pp_Cent  = (TH1D*) hQ3pp  ->Rebin(NCent, "hQ3pp_Cent", Cent);
	TH1D *	hQ3nn_Cent  = (TH1D*) hQ3nn  ->Rebin(NCent, "hQ3nn_Cent", Cent);
	TH1D *	hQ3ss_Cent  = (TH1D*) hQ3ss  ->Rebin(NCent, "hQ3ss_Cent", Cent);
	TH1D *	hQ3pn_Cent  = (TH1D*) hQ3pn  ->Rebin(NCent, "hQ3pn_Cent", Cent);
	TH1D *	hQ3ppw_Cent = (TH1D*) hQ3ppw ->Rebin(NCent, "hQ3ppw_Cent", Cent);
	TH1D *	hQ3nnw_Cent = (TH1D*) hQ3nnw ->Rebin(NCent, "hQ3nnw_Cent", Cent);
	TH1D *	hQ3ssw_Cent = (TH1D*) hQ3ssw ->Rebin(NCent, "hQ3ssw_Cent", Cent);
	TH1D *	hQ3pnw_Cent = (TH1D*) hQ3pnw ->Rebin(NCent, "hQ3pnw_Cent", Cent);

	TH1D *	hQ3pHFpp_Cent  = (TH1D*) hQ3pHFpp  ->Rebin(NCent, "hQ3pHFpp_Cent", Cent);
	TH1D *	hQ3pHFnn_Cent  = (TH1D*) hQ3pHFnn  ->Rebin(NCent, "hQ3pHFnn_Cent", Cent);
	TH1D *	hQ3pHFss_Cent  = (TH1D*) hQ3pHFss  ->Rebin(NCent, "hQ3pHFss_Cent", Cent);
	TH1D *	hQ3pHFpn_Cent  = (TH1D*) hQ3pHFpn  ->Rebin(NCent, "hQ3pHFpn_Cent", Cent);
	TH1D *	hQ3pHFppw_Cent = (TH1D*) hQ3pHFppw ->Rebin(NCent, "hQ3pHFppw_Cent", Cent);
	TH1D *	hQ3pHFnnw_Cent = (TH1D*) hQ3pHFnnw ->Rebin(NCent, "hQ3pHFnnw_Cent", Cent);
	TH1D *	hQ3pHFssw_Cent = (TH1D*) hQ3pHFssw ->Rebin(NCent, "hQ3pHFssw_Cent", Cent);
	TH1D *	hQ3pHFpnw_Cent = (TH1D*) hQ3pHFpnw ->Rebin(NCent, "hQ3pHFpnw_Cent", Cent);

	TH1D *	hQ3nHFpp_Cent  = (TH1D*) hQ3nHFpp  ->Rebin(NCent, "hQ3nHFpp_Cent", Cent);
	TH1D *	hQ3nHFnn_Cent  = (TH1D*) hQ3nHFnn  ->Rebin(NCent, "hQ3nHFnn_Cent", Cent);
	TH1D *	hQ3nHFss_Cent  = (TH1D*) hQ3nHFss  ->Rebin(NCent, "hQ3nHFss_Cent", Cent);
	TH1D *	hQ3nHFpn_Cent  = (TH1D*) hQ3nHFpn  ->Rebin(NCent, "hQ3nHFpn_Cent", Cent);
	TH1D *	hQ3nHFppw_Cent = (TH1D*) hQ3nHFppw ->Rebin(NCent, "hQ3nHFppw_Cent", Cent);
	TH1D *	hQ3nHFnnw_Cent = (TH1D*) hQ3nHFnnw ->Rebin(NCent, "hQ3nHFnnw_Cent", Cent);
	TH1D *	hQ3nHFssw_Cent = (TH1D*) hQ3nHFssw ->Rebin(NCent, "hQ3nHFssw_Cent", Cent);
	TH1D *	hQ3nHFpnw_Cent = (TH1D*) hQ3nHFpnw ->Rebin(NCent, "hQ3nHFpnw_Cent", Cent);

	TH1D *	hQpHF2_Cent  = (TH1D*) hQpHF2  ->Rebin(NCent, "hQpHF2_Cent", Cent);
	TH1D *	hQnHF2_Cent  = (TH1D*) hQnHF2  ->Rebin(NCent, "hQnHF2_Cent", Cent);

	TH1D *	hQ3Sc_Cent  = (TH1D*) hQ3Sc  ->Rebin(NCent, "hQ3Sc_Cent", Cent);

	TH1D *	hCent_Cent  = (TH1D*) hCent  ->Rebin(NCent, "hCent_Cent", Cent);
	TH1D *	hMult_Cent  = (TH1D*) hMult  ->Rebin(NCent, "hMult_Cent", Cent);
	TH1D *	hMultp_Cent = (TH1D*) hMultp ->Rebin(NCent, "hMultp_Cent", Cent);
	TH1D *	hMultn_Cent = (TH1D*) hMultn ->Rebin(NCent, "hMultn_Cent", Cent);

	// done rebin

	// v2
	TH1D * hv2aa = (TH1D*) hQ2aa_Cent->Clone("hv2aa_Cent");
	TH1D * hv2pp = (TH1D*) hQ2pp_Cent->Clone("hv2pp_Cent");
	TH1D * hv2nn = (TH1D*) hQ2nn_Cent->Clone("hv2nn_Cent");
	TH1D * hv2pn = (TH1D*) hQ2pn_Cent->Clone("hv2pn_Cent");

	hv2aa->Divide(hQ2aaw_Cent);
	hv2pp->Divide(hQ2ppw_Cent);
	hv2nn->Divide(hQ2nnw_Cent);
	hv2pn->Divide(hQ2pnw_Cent);

	sqrthist(hv2aa);
	sqrthist(hv2pp);
	sqrthist(hv2nn);
	sqrthist(hv2pn);

	// 3part
	TH1D * h3PartSS = (TH1D*) hQ3ss_Cent->Clone("h3PartSS_Cent");
	TH1D * h3PartOS = (TH1D*) hQ3pn_Cent->Clone("h3PartOS_Cent");
	h3PartSS->Divide(hQ3ssw_Cent);
	h3PartOS->Divide(hQ3pnw_Cent);

	TH1D * h3PartSS_raw = (TH1D*) h3PartSS->Clone("h3PartSS_raw");
	TH1D * h3PartOS_raw = (TH1D*) h3PartOS->Clone("h3PartOS_raw");

	h3PartSS->Divide(hv2aa);
	h3PartOS->Divide(hv2aa);

	TH1D * h3PartSSpHF = (TH1D*) hQ3pHFss_Cent->Clone("h3PartSSpHF_Cent");
	TH1D * h3PartOSpHF = (TH1D*) hQ3pHFpn_Cent->Clone("h3PartOSpHF_Cent");
	h3PartSSpHF->Divide(hQ3pHFssw_Cent);
	h3PartOSpHF->Divide(hQ3pHFpnw_Cent);

	TH1D * h3PartSSnHF = (TH1D*) hQ3nHFss_Cent->Clone("h3PartSSnHF_Cent");
	TH1D * h3PartOSnHF = (TH1D*) hQ3nHFpn_Cent->Clone("h3PartOSnHF_Cent");
	h3PartSSnHF->Divide(hQ3nHFssw_Cent);
	h3PartOSnHF->Divide(hQ3nHFpnw_Cent);

	TH1D * h3PartSSpHF_raw = (TH1D*) h3PartSSpHF->Clone("h3PartSSpHF_raw");
	TH1D * h3PartOSpHF_raw = (TH1D*) h3PartOSpHF->Clone("h3PartOSpHF_raw");

	TH1D * h3PartSSnHF_raw = (TH1D*) h3PartSSnHF->Clone("h3PartSSnHF_raw");
	TH1D * h3PartOSnHF_raw = (TH1D*) h3PartOSnHF->Clone("h3PartOSnHF_raw");

	// Q3Sc
	hQ3Sc_Cent->Divide(hCent_Cent);

	// Th2D
	TH1D * h2Q2_Cent[NCent];
	TH1D * hDPhi_Cent[NCent];
	for ( int c = 0; c < NCent; c++ ) {
		h2Q2_Cent[c]  = h2Q2->ProjectionY(Form("h2Q2_Cent_%i", c), Cent[c]+1, Cent[c+1], "e");
		hDPhi_Cent[c] = hDPhi->ProjectionY(Form("hDPhi_Cent_%i", c), Cent[c]+1, Cent[c+1], "e");
	}

	// 
	// saving
	TFile * fsave = new TFile(Form("%s/out_rebin.root", ftxt[s1]), "recreate");
	hQ1c_Cent  ->Write();
	hQ1w_Cent  ->Write();
	hQ2_Cent   ->Write();
	hQ2w_Cent  ->Write();

	hQ1pp_Cent ->Write();
	hQ1nn_Cent ->Write();
	hQ1pn_Cent ->Write();
	hQ1ppw_Cent->Write();
	hQ1nnw_Cent->Write();
	hQ1pnw_Cent->Write();

	hQ2pp_Cent ->Write();
	hQ2nn_Cent ->Write();
	hQ2pn_Cent ->Write();
	hQ2aa_Cent ->Write();
	hQ2nnw_Cent->Write();
	hQ2ppw_Cent->Write();
	hQ2pnw_Cent->Write();
	hQ2aaw_Cent->Write();

	hQ3pp_Cent ->Write();
	hQ3nn_Cent ->Write();
	hQ3ss_Cent ->Write();
	hQ3pn_Cent ->Write();
	hQ3ppw_Cent->Write();
	hQ3nnw_Cent->Write();
	hQ3ssw_Cent->Write();
	hQ3pnw_Cent->Write();

	hQ3pHFpp_Cent ->Write();
	hQ3pHFnn_Cent ->Write();
	hQ3pHFss_Cent ->Write();
	hQ3pHFpn_Cent ->Write();
	hQ3pHFppw_Cent->Write();
	hQ3pHFnnw_Cent->Write();
	hQ3pHFssw_Cent->Write();
	hQ3pHFpnw_Cent->Write();

	hQ3nHFpp_Cent ->Write();
	hQ3nHFnn_Cent ->Write();
	hQ3nHFss_Cent ->Write();
	hQ3nHFpn_Cent ->Write();
	hQ3nHFppw_Cent->Write();
	hQ3nHFnnw_Cent->Write();
	hQ3nHFssw_Cent->Write();
	hQ3nHFpnw_Cent->Write();

	hQpHF2_Cent->Write();
	hQnHF2_Cent->Write();

	hQ3Sc_Cent ->Write();

	hCent_Cent ->Write();
	hMult_Cent ->Write();
	hMultp_Cent->Write();
	hMultn_Cent->Write();

	hv2aa      ->Write();
	hv2pp      ->Write();
	hv2nn      ->Write();
	hv2pn      ->Write();

	h3PartSS_raw->Write();
	h3PartOS_raw->Write();
	h3PartSS   ->Write();
	h3PartOS   ->Write();

	h3PartSSpHF_raw->Write();
	h3PartOSpHF_raw->Write();
	h3PartSSnHF_raw->Write();
	h3PartOSnHF_raw->Write();

	for ( int c = 0; c < NCent; c++ ) {
		h2Q2_Cent[c]->Write();
		hDPhi_Cent[c]->Write();
	}
}
