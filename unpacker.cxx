void unpacker(){
  TFile *ntfile = new TFile("RocsFromBtagAna/JetTree_mc.root","READ");
  TTree *data = (TTree*)ntfile->Get("btagana/ttree");
  float DeepFlavourBDisc[1000];
  float DeepFlavourPrunedBDisc[1000];
  float Jet_pt[1000];
  int Jet_hadronFlavour[1000];
  float Jet_eta[1000];
  float DeepFlavourBDisc_single;
  float DeepFlavourPrunedBDisc_single;
  float Jet_pt_single;
  float Jet_eta_single;
  int Jet_hadronFlavour_single;
  int nJet;
  data->SetBranchStatus("*", 0);
  data->SetBranchStatus("Jet_DeepFlavourBDisc", 1);
  data->SetBranchAddress("Jet_DeepFlavourBDisc",&DeepFlavourBDisc);
  data->SetBranchStatus("Jet_DeepFlavourPrunedBDisc", 1);
  data->SetBranchAddress("Jet_DeepFlavourPrunedBDisc",&DeepFlavourPrunedBDisc);
  data->SetBranchStatus("nJet", 1);
  data->SetBranchAddress("nJet",&nJet);
  data->SetBranchStatus("Jet_pt", 1);
  data->SetBranchAddress("Jet_pt",&Jet_pt);
  data->SetBranchStatus("Jet_hadronFlavour", 1);
  data->SetBranchAddress("Jet_hadronFlavour",&Jet_hadronFlavour);
  data->SetBranchStatus("Jet_eta", 1);
  data->SetBranchAddress("Jet_eta",&Jet_eta);
  TFile *f = new TFile("RocsFromBtagAna/PrunedDFNoPuppi.root","RECREATE");
  TTree *t2;
  t2 = new TTree("t2","t2");
  t2->Branch("Jet_DeepFlavourBDisc", &DeepFlavourBDisc_single, "Jet_DeepFlavourBDisc/F");
  t2->Branch("Jet_DeepFlavourPrunedBDisc", &DeepFlavourPrunedBDisc_single, "Jet_DeepFlavourPrunedBDisc/F");
  t2->Branch("Jet_pt",&Jet_pt_single, "Jet_pt/F");
  t2->Branch("Jet_eta",&Jet_eta_single, "Jet_eta/F");
  t2->Branch("Jet_hadronFlavour",&Jet_hadronFlavour_single, "Jet_hadronFlavour/I");
  Int_t nentries = data->GetEntries();
  for (Int_t i=0;i<nentries;i++) {
	data->GetEntry(i);
	for(int n=0; n<nJet; n++){
	   DeepFlavourBDisc_single = DeepFlavourBDisc[n];
	   DeepFlavourPrunedBDisc_single = DeepFlavourPrunedBDisc[n];
	   Jet_hadronFlavour_single = Jet_hadronFlavour[n];
	   Jet_eta_single = Jet_eta[n];
	   Jet_pt_single = Jet_pt[n];
	   t2->Fill();
	}
  }
  t2->Write(); 
}
