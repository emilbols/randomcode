void CommisionRead(){
      TFile *ntfile = new TFile("JetTree_mc_100.root","READ");
    	TTree *data = (TTree*)ntfile->Get("btagana/ttree");

   	TH1F *h_SVSig2d = new TH1F("SV 2d flight","SV 2d flight",100,0,10);

	int nJet;
	int Jet_nFirstSV[1000];
	int Jet_nLastSV[1000];
	float SV_flight2D[5000];
	float SV_flight2DErr[5000];
	data->SetBranchAddress("nJet",&nJet);
	data->SetBranchAddress("Jet_nFirstSV",&Jet_nFirstSV);	
	data->SetBranchAddress("Jet_nLastSV",&Jet_nLastSV);
	data->SetBranchAddress("SV_flight2DErr",&SV_flight2DErr);
	data->SetBranchAddress("SV_flight2D",&SV_flight2D);
	Int_t nentries = data->GetEntries();
	for (Int_t i=0;i<nentries;i++) {
	  data->GetEntry(i);
	  for(int n=0; n<nJet; n++){
	    for(int z = Jet_nFirstSV[n]; z < Jet_nLastSV[n]; z++){
	      h_SVSig2d->Fill(SV_flight2D[z]/SV_flight2DErr[z]);
	    }
	  }
	}
	TCanvas *cd3 = new TCanvas("cd3","cd3",10,10,1300,800);
	h_SVSig2d->Draw();
	cd3->Update();	
}
