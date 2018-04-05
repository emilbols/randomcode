void readDeepCSV(){
      TFile *ntfile = new TFile("CutPaIP3p0MereData.root","READ");
  //TFile *ntfile = new TFile("CutPaIP1p9.root","READ");

  //TFile *ntfile = new TFile("QCDandOldDeepCSVTaggerDef.root","READ");
    	TTree *data = (TTree*)ntfile->Get("btagana/ttree");

   	TH1F *h_lightdisc = new TH1F("h_lightdisc","h_lightdisc",100,-1,1);
   	TH1F *h_lightdiscSymmetry = new TH1F("h_lightdiscSymmetry","h_lightdiscSymmetry",100,-1,1);
	TH1F *h_lightdiscN = new TH1F("h_lightdiscN","h_lightdiscN",100,-1,1);
   	TH1F *h3 = new TH1F("h3","Pos Tagger b",100,-1,1);
   	TH1F *h4 = new TH1F("h4","Neg Tagger b",100,-1,1);
   	TH1F *h5 = new TH1F("h5","Pos Tagger c",100,-1,1);
   	TH1F *h6 = new TH1F("h6","Neg Tagger c",100,-1,1);


   	TH1F *h7 = new TH1F("h7","trackSip3dSigLight",100,-20,55);
   	TH1F *h8 = new TH1F("h8","trackSip3dSigB",100,-20,55);
   	TH1F *h9 = new TH1F("h9","trackSip3dSigC",100,-20,55);

	float DeepFlavourBDisc[1000];
	float DeepFlavourBDiscN[1000];
	int Jet_hadronFlavour[1000];
	float TagVarCSV_trackSip3dSig[5000];
	int Jet_nFirstTrkTagVarCSV[1000];
	int Jet_nLastTrkTagVarCSV[1000];
	int nJet;
	data->SetBranchAddress("Jet_DeepCSVBDisc",&DeepFlavourBDisc);	
	data->SetBranchAddress("Jet_DeepCSVBDiscN",&DeepFlavourBDiscN);
	data->SetBranchAddress("Jet_hadronFlavour",&Jet_hadronFlavour);
	data->SetBranchAddress("Jet_nFirstTrkTagVarCSV",&Jet_nFirstTrkTagVarCSV);
	data->SetBranchAddress("Jet_nLastTrkTagVarCSV",&Jet_nLastTrkTagVarCSV);
	data->SetBranchAddress("nJet",&nJet);
	data->SetBranchAddress("TagVarCSV_trackSip3dSig",&TagVarCSV_trackSip3dSig);
	Int_t nentries = data->GetEntries();
	int lights = 0;
	int bs = 0;
	for (Int_t i=0;i<nentries;i++) {
		data->GetEntry(i);
		for(int n=0; n<nJet; n++){
		  if(Jet_hadronFlavour[n] == 0){
		    lights++;
		    h_lightdisc->Fill(DeepFlavourBDisc[n]);
		    h_lightdiscSymmetry->Fill(DeepFlavourBDiscN[n]);
		    h_lightdiscN->Fill(-DeepFlavourBDiscN[n]);
		    for(int z=Jet_nFirstTrkTagVarCSV[n]; z<Jet_nLastTrkTagVarCSV[n]; z++){
			h7->Fill(TagVarCSV_trackSip3dSig[z]);
		    }
		  }
		  
		  if(Jet_hadronFlavour[n] == 5){
		    bs++;
		    h3->Fill(DeepFlavourBDisc[n]);
		    h4->Fill(-DeepFlavourBDiscN[n]);
		    for(int z=Jet_nFirstTrkTagVarCSV[n]; z<Jet_nLastTrkTagVarCSV[n]; z++){
			h8->Fill(TagVarCSV_trackSip3dSig[z]);
		    }
		  }
		  if(Jet_hadronFlavour[n] == 4){
		    h5->Fill(DeepFlavourBDisc[n]);
		    h6->Fill(-DeepFlavourBDiscN[n]);
		    for(int z=Jet_nFirstTrkTagVarCSV[n]; z<Jet_nLastTrkTagVarCSV[n]; z++){
			h9->Fill(TagVarCSV_trackSip3dSig[z]);
		    }
		  }
		}
	}
	int bin1 = h_lightdisc->GetXaxis()->FindBin(0.6);
	int bin2 = h_lightdiscN->GetXaxis()->FindBin(-0.6);
	int bin3 = h4->GetXaxis()->FindBin(-0.6);
	cout << "Light jets in true tagger = " << h_lightdisc->Integral(bin1,100)/lights  << endl;
	cout << "fraction of light jets remaining in negative tagger = " << h_lightdiscN->Integral(1,bin2)/h_lightdisc->Integral(bin1,100)  << endl;
	cout << " fraction of b jets remaining in negative tagger = " << h4->Integral(1,bin3)/bs  << endl;

	h_lightdisc->SetFillColor(kBlue);
	h_lightdiscN->SetFillColor(kCyan);
	h7->SetFillColor(kBlue);
	h3->SetFillColor(kRed);
	h4->SetFillColor(kRed);
	h8->SetFillColor(kRed);
	h5->SetFillColor(kGreen);
	h6->SetFillColor(kGreen);
	h9->SetFillColor(kGreen);
	TCanvas *cd = new TCanvas("cd","cd",10,10,1300,800);
	
   	THStack *hs = new THStack("hs","");
	hs->Add(h_lightdisc);
	hs->Add(h_lightdiscN);
	hs->Add(h3);
	hs->Add(h4);
	hs->Add(h5);
	hs->Add(h6);
	hs->Draw();
	cd->SetLogy();
	cd->Update();
	TCanvas *cd1 = new TCanvas("cd1","cd1",10,10,1300,800);
	THStack *hs1 = new THStack("hs1","");
	hs1->Add(h7);
	hs1->Add(h8);
	hs1->Add(h9);
	hs1->Draw();
	cd1->Update();
	TCanvas *cd3 = new TCanvas("cd3","cd3",10,10,1300,800);
	h_lightdiscSymmetry->Divide(h_lightdisc);
	h_lightdiscSymmetry->Draw();
	h_lightdiscSymmetry->GetXaxis()->SetRangeUser(0,1);
	cd3->Update();	
}
