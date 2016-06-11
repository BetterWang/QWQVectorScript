
void comp() {
	TFile * f1 = new TFile("txt/HIMB3_v1/ana.root");
	TFile * f2 = new TFile("txt/HIMB3_randq_v1/ana.root");

	TH1D * hQ3Sc1 = (TH1D*) f1->Get("hQ3Sc");
	TH1D * hQ3Sc2 = (TH1D*) f2->Get("hQ3Sc");

	hQ3Sc1->SetMarkerColor(kRed);
	hQ3Sc2->SetMarkerColor(kBlue);
	hQ3Sc1->SetLineColor(kRed);
	hQ3Sc2->SetLineColor(kBlue);

	hQ3Sc1->Add(hQ3Sc2, -1);
	hQ3Sc1->Draw();
//	hQ3Sc2->Draw("same");
}
