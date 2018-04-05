void printcor(Double_t x){
    TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
    l.SetNDC();
    l.SetTextFont(72);
    l.SetTextColor(kBlack);
    l.SetTextSize(0.035);
    std::string str = std::to_string(x);
    l.DrawLatex(0.15,0.91,("correlation factor = " + str).c_str());
}

void ComReader(){

  //TFile *ntfile = new TFile("ntuple1000.root","READ");
  //TFile *ntfile = new TFile("nomatching.root","READ");
        TChain *data = new TChain("tree");
        data->Add("JetTree_mc_249.root ");
	



	TH1F *h_trackEtaRel= new TH1F("trackEtaRel","trackEtaRel", 100,0,10);
	TH1F *h_trackPtRel= new TH1F("trackPtRel","trackPtRel", 100,0,10);
	TH1F *h_trackDeltaR= new TH1F("trackDeltaR","trackDeltaR", 100,0,0.5);
	TH1F *h_trackSip3dSig= new TH1F("trackSip3dSig","trackSip3dSig", 100,-7,7);
	TH1F *h_trackSip2dSig= new TH1F("trackSip2dSig","trackSip2dSig", 100,-7,7);
	TH1F *h_trackJetDistVal= new TH1F("trackJetDistVal","trackJetDistVal", 100,-0.1,0);
	TH1F *h_trackDecayLenVal= new TH1F("trackDecayLenVal","trackDecayLenVal", 100,0,2.5);


	float OnDeepCSVProbb; //!
	float DeepCSVProbb; //!
	float DeepCSVProbbb; //!
	float OnDeepCSVProbc; //!                     
	float DeepCSVProbc; //!
	float OnCSVProbb; //!                                                                                                                       
	float CSVProbb; //!
	float OnDeepCSVProbudsg; //!
	float DeepCSVProbudsg; //!
	TH1F *h_WMCnPV= new TH1F("h_WMCnPV","h_WMCnPV", 100,0,100);
	TH1F *h_MCnPV= new TH1F("h_MCnPV","h_MCnPV", 100,0,100);
	TH1F *h_DATAnPV= new TH1F("h_DATAnPV","h_DATAnPV", 100,0,100);
	TH1F *h_MCJetPT = new TH1F("h_MCJetPT","h_MCJetPT", 100,0,500);
	TH1F *h_WMCJetPT = new TH1F("h_WMCJetPT","h_WMCJetPT", 100,0,500);
	TH1F *h_DATAJetPT = new TH1F("h_DATAJetPT","h_DATAJetPT", 100,0,500);

	TH1F *h_vertexMass= new TH1F("vertexMass","vertexMass", 100,0,20);
	TH1F *h_vertexNTracks= new TH1F("vertexNTracks","vertexNTracks", 16,0.5,16.5);
	TH1F *h_vertexEnergyRatio= new TH1F("vertexEnergyRatio","vertexEnergyRatio", 100,0,1.2);
	TH1F *h_vertexJetDeltaR= new TH1F("vertexJetDeltaR","vertexJetDeltaR", 100,0,0.3);
	TH1F *h_flightDistance2dVal= new TH1F("flightDistance2dVal","flightDistance2dVal", 100,0,2.5);
	TH1F *h_flightDistance3dVal= new TH1F("flightDistance3dVal","flightDistance3dVal", 100,0,2.5);
	TH1F *h_flightDistance2dSig= new TH1F("flightDistance2dSig","flightDistance2dSig", 100,0,20);
	TH1F *h_flightDistance3dSig= new TH1F("flightDistance3dSig","flightDistance3dSig", 100,0,20);

	TH2F *h_vertexMassOffVsOn= new TH2F("vertexMassOffVsOn","vertexMassOffVsOn", 12,0,20,12,0,20);
	TH2F *h_vertexNTracksOffVsOn= new TH2F("vertexNTracksOffVsOn","vertexNTracksOffVsOn", 16,0.5,16.5,16,0.5,16.5);
	TH2F *h_vertexJetDeltaROffVsOn= new TH2F("vertexJetDeltaROffVsOn","vertexJetDeltaROffVsOn", 12,0,0.3,12,0,0.3);
	TH2F *h_vertexEnergyRatioOffVsOn= new TH2F("vertexEnergyRatioOffVsOn","vertexEnergyRatioOffVsOn", 12,0,1.2,12,0,1.2);

	TH2F *h_flightDistance2dValOffVsOn= new TH2F("flightDistance2dValOffVsOn","flightDistance2dValOffVsOn", 12,0,2.5,12,0,2.5);	
	TH2F *h_flightDistance3dValOffVsOn= new TH2F("flightDistance3dValOffVsOn","flightDistance3dValOffVsOn", 12,0,2.5,12,0,2.5);
	TH2F *h_flightDistance2dSigOffVsOn= new TH2F("flightDistance2dSigOffVsOn","flightDistance2dSigOffVsOn", 12,0,20,12,0,20);
	TH2F *h_flightDistance3dSigOffVsOn= new TH2F("flightDistance3dSigOffVsOn","flightDistance3dSigOffVsOn", 12,0,20,12,0,20);

	float eff[10] = {};
	float pass[10] = {};
	float fail[10] = {};
	float ueff[10] = {};
	float trackJetPt, jetNTracks, TagVarCSV_jetNSecondaryVertices, TagVarCSV_trackSip3dValAboveCharm,TagVarCSV_trackSip2dValAboveCharm,TagVarCSV_trackSip3dSigAboveCharm,TagVarCSV_trackSip2dSigAboveCharm;

	UInt_t OnNStoredVertices,NStoredVertices;

	float TagVarCSV_jetNSelectedTracks;
	float trackSumJetDeltaR, vertexCategory, trackSumJetETRatio, jetNTracksEtaRel, OnjetNTracksEtaRel;

	float OntrackSumJetDeltaR, OnvertexCategory, OntrackSumJetETRatio;

	UInt_t n_jetNSelectedTracks_;
	UInt_t Onn_jetNSelectedTracks_;
	float OntrackJetPt, OnjetNTracks, OnTagVarCSV_jetNSecondaryVertices,OnTagVarCSV_jetNSelectedTracks, OnTagVarCSV_trackSip3dValAboveCharm,OnTagVarCSV_trackSip2dValAboveCharm,OnTagVarCSV_trackSip3dSigAboveCharm,OnTagVarCSV_trackSip2dSigAboveCharm;
	
	float OntrackEtaRel[100] = {};
	float trackEtaRel[100] = {};
	float TagVarCSVTrk_trackPtRel[100] = {};
	float TagVarCSVTrk_trackDeltaR[100] = {};
	float TagVarCSVTrk_trackPtRatio[100] = {};
	float TagVarCSVTrk_trackSip3dSig[100] = {};
	float TagVarCSVTrk_trackSip2dSig[100] = {};
	float TagVarCSVTrk_trackDecayLenVal[100] = {};
	float TagVarCSVTrk_trackJetDistVal[100] = {};
	
	float OnTagVarCSVTrk_trackPtRel[100] = {};
	float OnTagVarCSVTrk_trackDeltaR[100] = {};
	float OnTagVarCSVTrk_trackPtRatio[100] = {};
	float OnTagVarCSVTrk_trackSip3dSig[100] = {};
	float OnTagVarCSVTrk_trackSip2dSig[100] = {};
	float OnTagVarCSVTrk_trackDecayLenVal[100] = {};
	float OnTagVarCSVTrk_trackJetDistVal[100] = {};

	float TagVarCSV_vertexMass[10] = {}; 
	float TagVarCSV_vertexNTracks[10] = {};
	float TagVarCSV_vertexJetDeltaR[10] = {};
	float TagVarCSV_vertexEnergyRatio[10] = {};
	float TagVarCSV_flightDistance2dVal[10] = {};
	float TagVarCSV_flightDistance3dVal[10] = {};
	float TagVarCSV_flightDistance2dSig[10] = {};
	float TagVarCSV_flightDistance3dSig[10] = {};

	float OnTagVarCSV_vertexMass[10] = {}; 
	float OnTagVarCSV_vertexNTracks[10] = {};
	float OnTagVarCSV_vertexJetDeltaR[10] = {};
	float OnTagVarCSV_vertexEnergyRatio[10] = {};
	float OnTagVarCSV_flightDistance2dVal[10] = {};
	float OnTagVarCSV_flightDistance3dVal[10] = {};
	float OnTagVarCSV_flightDistance2dSig[10] = {};
	float OnTagVarCSV_flightDistance3dSig[10] = {};

	float Jet_pt;
	float weightXS;
	float WeightPU;
	int nPV;
	data->SetBranchAddress("Jet_pt",&Jet_pt);	
	data->SetBranchAddress("nPV",&nPV);
	data->SetBranchAddress("weightXS",&weightXS);
	data->SetBranchAddress("WeightPU",&WeightPU);


	data->SetBranchAddress("TagVarCSV_vertexMass",&TagVarCSV_vertexMass);
	data->SetBranchAddress("TagVarCSV_vertexNTracks",&TagVarCSV_vertexNTracks);
	data->SetBranchAddress("TagVarCSV_vertexJetDeltaR",&TagVarCSV_vertexJetDeltaR);
	data->SetBranchAddress("TagVarCSV_vertexEnergyRatio",&TagVarCSV_vertexEnergyRatio);
	data->SetBranchAddress("TagVarCSV_flightDistance2dVal",&TagVarCSV_flightDistance2dVal);
	data->SetBranchAddress("TagVarCSV_flightDistance3dVal",&TagVarCSV_flightDistance3dVal);
	data->SetBranchAddress("TagVarCSV_flightDistance2dSig",&TagVarCSV_flightDistance2dSig);
	data->SetBranchAddress("TagVarCSV_flightDistance3dSig",&TagVarCSV_flightDistance3dSig);

	
	data->SetBranchAddress("n_TagVarCSV_jetNSelectedTracks",&n_jetNSelectedTracks_);
	data->SetBranchAddress("trackJetPt",&trackJetPt);
	data->SetBranchAddress("jetNTracks",&jetNTracks);
	data->SetBranchAddress("n_StoredVertices",&NStoredVertices);
	data->SetBranchAddress("TagVarCSV_jetNSecondaryVertices",&TagVarCSV_jetNSecondaryVertices);

	data->SetBranchAddress("TagVarCSV_jetNSelectedTracks",&TagVarCSV_jetNSelectedTracks);
	data->SetBranchAddress("TagVarCSV_trackSip3dValAboveCharm",&TagVarCSV_trackSip3dValAboveCharm);
	data->SetBranchAddress("TagVarCSV_trackSip2dValAboveCharm",&TagVarCSV_trackSip2dValAboveCharm);

	data->SetBranchAddress("TagVarCSV_trackSip3dSigAboveCharm",&TagVarCSV_trackSip3dSigAboveCharm);

	data->SetBranchAddress("TagVarCSV_trackSip2dSigAboveCharm",&TagVarCSV_trackSip2dSigAboveCharm);
	data->SetBranchAddress("TagVarCSV_vertexCategory",&vertexCategory);
	data->SetBranchAddress("TagVarCSV_trackSumJetEtRatio",&trackSumJetETRatio);
	data->SetBranchAddress("TagVarCSV_jetNTracksEtaRel",&jetNTracksEtaRel);

	data->SetBranchAddress("TagVarCSV_trackSumJetDeltaR",&trackSumJetDeltaR);
	data->SetBranchAddress("TagVarCSV_trackEtaRel",&trackEtaRel);
	data->SetBranchAddress("TagVarCSVTrk_trackDeltaR",&TagVarCSVTrk_trackDeltaR);
	data->SetBranchAddress("TagVarCSVTrk_trackPtRatio",&TagVarCSVTrk_trackPtRatio);
	data->SetBranchAddress("TagVarCSVTrk_trackSip3dSig",&TagVarCSVTrk_trackSip3dSig);
	data->SetBranchAddress("TagVarCSVTrk_trackSip2dSig",&TagVarCSVTrk_trackSip2dSig);
	data->SetBranchAddress("TagVarCSVTrk_trackDecayLenVal",&TagVarCSVTrk_trackDecayLenVal);
	data->SetBranchAddress("TagVarCSVTrk_trackJetDistVal",&TagVarCSVTrk_trackJetDistVal);
	data->SetBranchAddress("TagVarCSVTrk_trackPtRel",&TagVarCSVTrk_trackPtRel);

	
	double bestx = 0.0;
	double besty = 0.0;
	float wp = 0.0;
	bool isMC = true;
	float wp1[10] = {};
	float null[10] = {};
	Int_t nentries = data->GetEntries();
	for (Int_t i=0;i<nentries;i++) {
		data->GetEntry(i);
		if(weightXS == (-1)){
			isMC = false;
			weightXS = 1;
			WeightPU = 1;
		}
		if(isMC){
			h_WMCnPV->Fill(nPV,weightXS*WeightPU);
			h_MCnPV->Fill(nPV);
			h_WMCJetPT->Fill(Jet_pt,weightXS*WeightPU);
			h_MCJetPT->Fill(Jet_pt);
		}
		else{
			h_DATAnPV->Fill(nPV);
			h_DATAJetPT->Fill(Jet_pt);				
		}
		float lal = n_jetNSelectedTracks_;
		for(int n = 0; n < jetNTracksEtaRel; n++){
			h_trackEtaRel->Fill(trackEtaRel[n]);
		}
		for(int n = 0; n < n_jetNSelectedTracks_; n++){
			//cout << "Number " << n << "Value =" <<	TagVarCSVTrk_trackPtRel[n] << " " << TagVarCSVTrk_trackDeltaR[n] << " " << TagVarCSVTrk_trackSip3dSig[n] << " " << TagVarCSVTrk_trackSip2dSig[n] << " " << TagVarCSVTrk_trackDecayLenVal[n] << " " << TagVarCSVTrk_trackJetDistVal[n] << endl;
			h_trackPtRel->Fill(TagVarCSVTrk_trackPtRel[n]);
			h_trackDeltaR->Fill(TagVarCSVTrk_trackDeltaR[n]);
			h_trackSip3dSig->Fill(TagVarCSVTrk_trackSip3dSig[n]);
			h_trackSip2dSig->Fill(TagVarCSVTrk_trackSip2dSig[n]);
			h_trackDecayLenVal->Fill(TagVarCSVTrk_trackDecayLenVal[n]);
			h_trackJetDistVal->Fill(TagVarCSVTrk_trackJetDistVal[n]);		
		}
		if(nSV
		for(int n = Jet_nFirstSV; n < (Jet_nLastSV+1); n++){
		  h_vertexMass->Fill(TagVarCSV_vertexMass[n]);
		  h_vertexNTracks->Fill(TagVarCSV_vertexNTracks[n]);
		  h_vertexEnergyRatio->Fill(TagVarCSV_vertexEnergyRatio[n]);
		  h_vertexJetDeltaR->Fill(TagVarCSV_vertexJetDeltaR[n]);
		  h_flightDistance2dVal->Fill(TagVarCSV_flightDistance2dVal[n]);
		  h_flightDistance3dVal->Fill(TagVarCSV_flightDistance3dVal[n]);
		  h_flightDistance2dSig->Fill(TagVarCSV_flightDistance2dSig[n]);
		  h_flightDistance3dSig->Fill(TagVarCSV_flightDistance3dSig[n]);
		}
	}

	
	TCanvas *cd1 = new TCanvas("cd1", "trackPtRelOffvsOn",50,50,1000,800);
	/*
	float scale1 = h_DATAnPV->Integral(1,100);
	h_DATAnPV->Draw("E0");
	h_DATAnPV->Scale(1/scale1);
	h_DATAnPV->SetFillColor(2);
	cout << h_DATAnPV->Integral(1,100) << endl;
	*/
	float scale2 = h_WMCnPV->Integral(1,100);
	h_WMCnPV->Draw("E0 same");
	h_WMCnPV->Scale(1/scale2);	
	h_WMCnPV->SetMarkerStyle(20);
	cout << h_WMCnPV->Integral(1,100) << endl;

	TCanvas *cd2 = new TCanvas("cd2", "pt",50,50,1000,800);
 	/*
	float scale3 = h_DATAJetPT->Integral(1,100);
	h_DATAJetPT->Draw("E0");
	h_DATAJetPT->Scale(1/scale1);
	h_DATAJetPT->SetFillColor(2);
	cout << h_DATAJetPT->Integral(1,100) << endl;
	*/
	float scale4 = h_WMCJetPT->Integral(1,100);
	h_WMCJetPT->Draw("E0 same");
	h_WMCJetPT->Scale(1/scale2);	
	h_WMCJetPT->SetMarkerStyle(20);
	cout << h_WMCJetPT->Integral(1,100) << endl;

	TCanvas *cd3 = new TCanvas("cd3", "pt",50,50,1000,800);
	h_flightDistance2dSig->Draw("E0");
	cd3->Update();

}
