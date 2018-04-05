void read(){


  //          TFile *ntfile = new TFile("MakeNegativeTaggersGreatAgain.root","READ");
  //	TFile *ntfile = new TFile("QCDShouldBeGreatButLooksWeird.root","READ");
  
  //      TFile *ntfile = new TFile("NoExtVerticesCutat10IP.root","READ");
  //TFile *ntfile = new TFile("NoExtVerticesCutat0IP.root","READ");
  //TFile *ntfile = new TFile("AllVerticesRemade_mc.root","READ");
  //  TFile *ntfile = new TFile("NoExtVerticesForNegTaggerWithDeepFlavour.root","READ");
  //  TFile *ntfile = new TFile("NegativeVertexCollectionDeepFlavour2000Events.root","READ");
  //            TFile *ntfile = new TFile("AllVerticesRemadeMoreData.root","READ");
    

 // ALL OF THESE ARE BUG FILLED

  //  TFile *ntfile = new TFile("QCDNoCutsAllFixes.root","READ");
            //     TFile *ntfile = new TFile("NoBugsIPCutatZero.root","READ");
  //            TFile *ntfile = new TFile("ShouldBeCompletelyBugFreeIpCut10p0.root","READ");
  //    TFile *ntfile = new TFile("GodLikeDefCut10ip.root","READ");   

    //       TFile *ntfile = new TFile("WrongCharmTag.root","READ");
  //            TFile *ntfile = new TFile("FixedCharmandipcut4p0.root","READ");
  //     TFile *ntfile = new TFile("FixedEverythingIpCutat10p0.root","READ");
  //  TFile *ntfile = new TFile("PRProduced.root","READ");
  TFile *ntfile = new TFile("JetTree_mc.root","READ");

	  //       TFile *ntfile = new TFile("CutPaIP1p9.root","READ");

  //TFile *ntfile = new TFile("NoCutsEverythingFlipped.root","READ");
		            // TFile *ntfile = new TFile("ShittyTagDef.root","READ");
    
	 TTree *data = (TTree*)ntfile->Get("btagana/ttree");

   	TH1F *h_lightdisc = new TH1F("h_lightdisc","h_lightdisc",100,-1,1);
   	TH1F *h_lightdiscSymmetry = new TH1F("h_lightdiscSymmetry","h_lightdiscSymmetry",100,-1,1);
   	TH1F *h_lightdiscSymmetry1 = new TH1F("h_lightdiscSymmetry1","h_lightdiscSymmetry1",100,-1,1);
	TH1F *h_lightdiscN = new TH1F("h_lightdiscN","h_lightdiscN",100,-1,1);
	h_lightdisc->Sumw2();
	h_lightdiscN->Sumw2();
	h_lightdiscSymmetry->Sumw2();
	h_lightdiscSymmetry1->Sumw2();
   	TH1F *h3 = new TH1F("h3","Pos Tagger b",100,-1,1);
   	TH1F *h4 = new TH1F("h4","Neg Tagger b",100,-1,1);
   	TH1F *h5 = new TH1F("h5","Pos Tagger c",100,-1,1);
   	TH1F *h6 = new TH1F("h6","Neg Tagger c",100,-1,1);


   	TH1F *b1 = new TH1F("b1","AboveCharmVal2d",20,-1.1,1.1);
   	TH1F *b2 = new TH1F("b2","NegAboveCharmVal2d",20,-1.1,1.1);

   	TH1F *b3 = new TH1F("b3","AboveCharmVal3d",20,-1.1,1.1);
   	TH1F *b4 = new TH1F("b4","NegAboveCharmVal3d",20,-1.1,1.1);

	TH1F *b5 = new TH1F("b5","AboveCharmSig2d",50,-2,2);
   	TH1F *b6 = new TH1F("b6","NegAboveCharmSig2d",50,-2,2);

	TH1F *b7 = new TH1F("b7","AboveCharmSig3d",50,-6,6);
   	TH1F *b8 = new TH1F("b8","NegAboveCharmSig3d",50,-6,6);

	
   	TH1F *h7 = new TH1F("h7","trackSip3dSigLight",100,-20,55);
   	TH1F *h8 = new TH1F("h8","trackSip3dSigB",100,-20,55);
   	TH1F *h9 = new TH1F("h9","trackSip3dSigC",100,-20,55);

	TH1F *sym1 = new TH1F("sym1","sym1",50,0,40);
	TH1F *sym2 = new TH1F("sym2","sym2",50,0,40);
	sym1->Sumw2();
	sym2->Sumw2();
   	TH1F *h10 = new TH1F("h10","flightDist3dSigLight",100,0,10);
   	TH1F *h11 = new TH1F("h11","flightDist3dSigB",100,0,10);
   	TH1F *h12 = new TH1F("h12","flightDist3dSigC",100,0,10);

  	TH1F *h13 = new TH1F("h13","fractionOfNegPos",10,0,1.1);
	TH1F *h14 = new TH1F("h14","DeepCSVTest",30,0,1.0);
	TH1F *h15 = new TH1F("h15","DeepCSVTest",30,0,1.0);

	TH1F *h16 = new TH1F("h16","DeepCSVL",100,-1.0,1.0);
	TH1F *h17 = new TH1F("h17","DeepCSVB",100,-1.0,1.0);
	TH1F *h18 = new TH1F("h18","DeepCSVC",100,-1.0,1.0);		

	TH1F *h19 = new TH1F("h19","DeepCSVLN",100,-1.0,1.0);
	TH1F *h20 = new TH1F("h20","DeepCSVBN",100,-1.0,1.0);
	TH1F *h21 = new TH1F("h21","DeepCSVCN",100,-1.0,1.0);


	TH1F *hh16 = new TH1F("hh16","DeepCSVCvsLL",100,-1.0,1.0);
	TH1F *hh17 = new TH1F("hh17","DeepCSVCvsLB",100,-1.0,1.0);
	TH1F *hh18 = new TH1F("hh18","DeepCSVCvsLC",100,-1.0,1.0);		

	TH1F *hh19 = new TH1F("hh19","DeepCSVCvsLLN",100,-1.0,1.0);
	TH1F *hh20 = new TH1F("hh20","DeepCSVCvsLBN",100,-1.0,1.0);
	TH1F *hh21 = new TH1F("hh21","DeepCSVCvsLCN",100,-1.0,1.0);

	TH1F *h22 = new TH1F("h22","Vertex Category",3,-0.5,2.5);
	

	TH1F *h_jetNSecondaryVertices= new TH1F("jetNSecondaryVertices","jetNSecondaryVertices", 5,-0.5,4.5);
	TH1F *h_NegjetNSecondaryVertices= new TH1F("NegjetNSecondaryVertices","NegjetNSecondaryVertices", 5,-0.5,4.5);

	TH1F *h_vertexMass= new TH1F("vertexMass","vertexMass", 100,0,20);
	TH1F *h_vertexNTracks= new TH1F("vertexNTracks","vertexNTracks", 16,0.5,16.5);
	TH1F *h_vertexEnergyRatio= new TH1F("vertexEnergyRatio","vertexEnergyRatio", 100,0,1.2);
	TH1F *h_NegvertexEnergyRatio= new TH1F("NegvertexEnergyRatio","NegvertexEnergyRatio", 100,0,1.2);

	TH1F *h_vertexJetDeltaR= new TH1F("vertexJetDeltaR","vertexJetDeltaR", 100,0,20.4);
	TH1F *h_NegvertexJetDeltaR= new TH1F("NegvertexJetDeltaR","NegvertexJetDeltaR", 100,0,20.4);
	TH1F *h_NegTrackJetDeltaR= new TH1F("NegTrackJetDeltaR","NegTrackJetDeltaR", 100,0,0.4);
	TH1F *h_flightDistance2dVal= new TH1F("flightDistance2dVal","flightDistance2dVal", 20,0,2.5);
	TH1F *h_flightDistance3dVal= new TH1F("flightDistance3dVal","flightDistance3dVal", 20,0,2.5);
	TH1F *h_flightDistance2dSig= new TH1F("flightDistance2dSig","flightDistance2dSig", 100,0,10);
	TH1F *h_flightDistance3dSig= new TH1F("flightDistance3dSig","flightDistance3dSig", 100,0,10);
	TH1F *h_etaRel= new TH1F("etaRel","etaRel", 30,-8,8);

	float DeepFlavourBDisc[1000];
	float DeepFlavourBDiscN[1000];
	float TagVarCSV_trackSip2dValAboveCharm[1000];
	float TagVarCSV_NegtrackSip2dValAboveCharm[1000];
	float TagVarCSV_trackSip3dValAboveCharm[1000];
	float TagVarCSV_NegtrackSip3dValAboveCharm[1000];
	float TagVarCSV_trackSip2dSigAboveCharm[1000];
	float TagVarCSV_NegtrackSip2dSigAboveCharm[1000];
	float TagVarCSV_trackSip3dSigAboveCharm[1000];
	float TagVarCSV_NegtrackSip3dSigAboveCharm[1000];
	float TagVarCSV_NegvertexCategory[1000];
	float TagVarCSV_vertexCategory[1000];
	float DeepCSVBDisc[1000];
	float DeepCSVBDiscN[1000];
	float DeepCSVCvsLDisc[1000];
	float DeepCSVCvsLDiscN[1000];
	int Jet_hadronFlavour[1000];
	float TagVarCSV_trackSip3dSig[5000];
	float TagVarCSV_flightDistance3dSig[1000];
	int Jet_nFirstTrkTagVarCSV[1000];
	int Jet_nLastTrkTagVarCSV[1000];


	float TagVarCSV_NegvertexMass[1000] = {}; 
	float TagVarCSV_NegvertexNTracks[1000] = {};
	float TagVarCSV_NegvertexJetDeltaR[1000] = {};
	float TagVarCSV_vertexJetDeltaR[1000] = {};
	float TagVarCSV_NegvertexEnergyRatio[1000] = {};
	float TagVarCSV_vertexEnergyRatio[1000] = {};
	float TagVarCSV_NegflightDistance2dVal[1000] = {};
	float TagVarCSV_NegflightDistance3dVal[1000] = {};
	float TagVarCSV_NegflightDistance2dSig[1000] = {};
	float TagVarCSV_NegflightDistance3dSig[1000] = {};
	float TagVarCSV_NegjetNSecondaryVertices[1000] = {};
	float TagVarCSV_jetNSecondaryVertices[1000] = {};
	float TagVarCSV_NegtrackEtaRel[5000] = {};
	float Jet_NegnFirstTrkEtaRelTagVarCSV[1000] = {};
	float Jet_NegnLastTrkEtaRelTagVarCSV[1000] = {};
	int nJet;

	data->SetBranchAddress("TagVarCSV_NegvertexMass",&TagVarCSV_NegvertexMass);
	data->SetBranchAddress("TagVarCSV_NegvertexNTracks",&TagVarCSV_NegvertexNTracks);
	data->SetBranchAddress("TagVarCSV_NegvertexJetDeltaR",&TagVarCSV_NegvertexJetDeltaR);
	data->SetBranchAddress("TagVarCSV_vertexJetDeltaR",&TagVarCSV_vertexJetDeltaR);
	data->SetBranchAddress("TagVarCSV_NegvertexEnergyRatio",&TagVarCSV_NegvertexEnergyRatio);
	data->SetBranchAddress("TagVarCSV_NegflightDistance2dVal",&TagVarCSV_NegflightDistance2dVal);
	data->SetBranchAddress("TagVarCSV_NegflightDistance3dVal",&TagVarCSV_NegflightDistance3dVal);
	data->SetBranchAddress("TagVarCSV_NegflightDistance2dSig",&TagVarCSV_NegflightDistance2dSig);
	data->SetBranchAddress("TagVarCSV_NegflightDistance3dSig",&TagVarCSV_NegflightDistance3dSig);
       	data->SetBranchAddress("TagVarCSV_vertexEnergyRatio",&TagVarCSV_vertexEnergyRatio);

	data->SetBranchAddress("TagVarCSV_jetNSecondaryVertices",&TagVarCSV_jetNSecondaryVertices);	
	data->SetBranchAddress("TagVarCSV_NegjetNSecondaryVertices",&TagVarCSV_NegjetNSecondaryVertices);
	data->SetBranchAddress("TagVarCSV_trackSip2dSigAboveCharm",&TagVarCSV_trackSip2dSigAboveCharm);	
	data->SetBranchAddress("TagVarCSV_NegtrackSip2dSigAboveCharm",&TagVarCSV_NegtrackSip2dSigAboveCharm);
	data->SetBranchAddress("TagVarCSV_trackSip3dSigAboveCharm",&TagVarCSV_trackSip3dSigAboveCharm);	
	data->SetBranchAddress("TagVarCSV_NegtrackSip3dSigAboveCharm",&TagVarCSV_NegtrackSip3dSigAboveCharm);
	data->SetBranchAddress("TagVarCSV_trackSip2dValAboveCharm",&TagVarCSV_trackSip2dValAboveCharm);	
	data->SetBranchAddress("TagVarCSV_NegtrackSip2dValAboveCharm",&TagVarCSV_NegtrackSip2dValAboveCharm);
	data->SetBranchAddress("TagVarCSV_trackSip3dValAboveCharm",&TagVarCSV_trackSip3dValAboveCharm);	
	data->SetBranchAddress("TagVarCSV_NegtrackSip3dValAboveCharm",&TagVarCSV_NegtrackSip3dValAboveCharm);
	data->SetBranchAddress("TagVarCSV_vertexCategory",&TagVarCSV_vertexCategory);
	data->SetBranchAddress("TagVarCSV_NegvertexCategory",&TagVarCSV_NegvertexCategory);
	data->SetBranchAddress("Jet_DeepFlavourBDisc",&DeepFlavourBDisc);	
	data->SetBranchAddress("Jet_DeepFlavourBDiscN",&DeepFlavourBDiscN);
	data->SetBranchAddress("Jet_DeepCSVBDisc",&DeepCSVBDisc);	
	data->SetBranchAddress("Jet_DeepCSVBDiscN",&DeepCSVBDiscN);
	data->SetBranchAddress("Jet_DeepCSVCvsLDisc",&DeepCSVCvsLDisc);	
	data->SetBranchAddress("Jet_DeepCSVCvsLDiscN",&DeepCSVCvsLDiscN);
	data->SetBranchAddress("Jet_hadronFlavour",&Jet_hadronFlavour);
	data->SetBranchAddress("Jet_nFirstTrkTagVarCSV",&Jet_nFirstTrkTagVarCSV);
	data->SetBranchAddress("Jet_nLastTrkTagVarCSV",&Jet_nLastTrkTagVarCSV);
	data->SetBranchAddress("nJet",&nJet);
	data->SetBranchAddress("TagVarCSV_trackSip3dSig",&TagVarCSV_trackSip3dSig);
	data->SetBranchAddress("TagVarCSV_flightDistance3dSig",&TagVarCSV_flightDistance3dSig);
	data->SetBranchAddress("Jet_NegnFirstTrkEtaRelTagVarCSV",&Jet_NegnFirstTrkEtaRelTagVarCSV);
	data->SetBranchAddress("Jet_NegnLastTrkEtaRelTagVarCSV",&Jet_NegnLastTrkEtaRelTagVarCSV);
	data->SetBranchAddress("TagVarCSV_NegtrackEtaRel",&TagVarCSV_NegtrackEtaRel);
	
	Int_t nentries = data->GetEntries();
	int lights = 0;
	int bs = 0;
	float uniformtracks = 0;
	float tottracks = 0;
	float blab = 0;
	float vertices = 0;
	float negvertices = 0;
	for (Int_t i=0;i<nentries;i++) {
		data->GetEntry(i);
		for(int n=0; n<nJet; n++){
		  b1->Fill(TagVarCSV_trackSip2dValAboveCharm[n]);
		  b2->Fill(TagVarCSV_NegtrackSip2dValAboveCharm[n]);
		  b3->Fill(TagVarCSV_trackSip3dValAboveCharm[n]);
		  b4->Fill(TagVarCSV_NegtrackSip3dValAboveCharm[n]);
		  b5->Fill(TagVarCSV_trackSip2dSigAboveCharm[n]);
		  b6->Fill(TagVarCSV_NegtrackSip2dSigAboveCharm[n]);
		  b7->Fill(TagVarCSV_trackSip3dSigAboveCharm[n]);
		  b8->Fill(TagVarCSV_NegtrackSip3dSigAboveCharm[n]);
		  h22->Fill(TagVarCSV_NegvertexCategory[n]);
		  //  if(TagVarCSV_NegflightDistance2dSig[n] < 2.5){continue;}
		  h_vertexMass->Fill(TagVarCSV_NegvertexMass[n]);
		  h_vertexNTracks->Fill(TagVarCSV_NegvertexNTracks[n]);
		  h_flightDistance2dVal->Fill(TagVarCSV_NegflightDistance2dVal[n]);
		  h_flightDistance3dVal->Fill(TagVarCSV_NegflightDistance3dVal[n]);
		  h_flightDistance2dSig->Fill(TagVarCSV_NegflightDistance2dSig[n]);
		  h_flightDistance3dSig->Fill(TagVarCSV_NegflightDistance3dSig[n]);
		  for(int l = Jet_NegnFirstTrkEtaRelTagVarCSV[n]; l < Jet_NegnLastTrkEtaRelTagVarCSV[n]; l++){
			h_etaRel->Fill(TagVarCSV_NegtrackEtaRel[l]);
		  }
		  if(Jet_hadronFlavour[n] == 0){
		    lights++;
		    float pos = 0;
		    float tracks = 0;
		    h_NegvertexEnergyRatio->Fill(TagVarCSV_NegvertexEnergyRatio[n]);
		    h_vertexEnergyRatio->Fill(TagVarCSV_vertexEnergyRatio[n]);
		    h_vertexJetDeltaR->Fill(TagVarCSV_vertexJetDeltaR[n]);
		    h_NegvertexJetDeltaR->Fill(TagVarCSV_NegvertexJetDeltaR[n]);
		    h_NegjetNSecondaryVertices->Fill(TagVarCSV_NegjetNSecondaryVertices[n]);
		    h_jetNSecondaryVertices->Fill(TagVarCSV_jetNSecondaryVertices[n]);
		    h_lightdisc->Fill(DeepFlavourBDisc[n]);
		    h16->Fill(DeepCSVBDisc[n]);
		    h19->Fill(-DeepCSVBDiscN[n]);
		    if(DeepCSVCvsLDisc[n] > 0){
		    	hh16->Fill(DeepCSVCvsLDisc[n]);
		    }
		    if(DeepCSVCvsLDiscN[n] > 0){
		    	hh19->Fill(-DeepCSVCvsLDiscN[n]);
		    }
		    h_lightdiscSymmetry->Fill(DeepFlavourBDiscN[n]);
		    h_lightdiscSymmetry1->Fill(DeepCSVBDiscN[n]);
		    h_lightdiscN->Fill(-DeepFlavourBDiscN[n]);
		    h10->Fill(TagVarCSV_flightDistance3dSig[n]);
		    for(int z=Jet_nFirstTrkTagVarCSV[n]; z<Jet_nLastTrkTagVarCSV[n]; z++){
		      if(TagVarCSV_trackSip3dSig[z] > 0){
			pos++;
			sym1->Fill(TagVarCSV_trackSip3dSig[z]);
		      }
		      else{
			sym2->Fill(-TagVarCSV_trackSip3dSig[z]);
		      }
		      tracks++;
		      h7->Fill(TagVarCSV_trackSip3dSig[z]);
		    }
		    if(tracks > 0){
			    if((pos/tracks) < 0.01 | (pos/tracks) > 0.99){
			      uniformtracks++;
			      h14->Fill(DeepCSVBDisc[n]);
			    }
			    if( ((pos/tracks) > 0.01) && ((pos/tracks) < 0.99)){
				blab++;
			      h15->Fill(DeepCSVBDisc[n]);
			    }
		    	 h13->Fill(pos/tracks);
		    }
		  }
		  
		  if(Jet_hadronFlavour[n] == 5){
		    bs++;
		    h3->Fill(DeepFlavourBDisc[n]);
		    h4->Fill(-DeepFlavourBDiscN[n]);
		    h17->Fill(DeepCSVBDisc[n]);
		    h20->Fill(-DeepCSVBDiscN[n]);
		    if(DeepCSVCvsLDisc[n] > 0){
		    	hh17->Fill(DeepCSVCvsLDisc[n]);
		    }
		    if(DeepCSVCvsLDiscN[n] > 0){
		    	hh20->Fill(-DeepCSVCvsLDiscN[n]);
		    }
		    h11->Fill(TagVarCSV_flightDistance3dSig[n]);
		    for(int z=Jet_nFirstTrkTagVarCSV[n]; z<Jet_nLastTrkTagVarCSV[n]; z++){
			h8->Fill(TagVarCSV_trackSip3dSig[z]);
		    }
		  }
		  if(Jet_hadronFlavour[n] == 4){
		    h5->Fill(DeepFlavourBDisc[n]);
		    h6->Fill(-DeepFlavourBDiscN[n]);
		    h12->Fill(TagVarCSV_flightDistance3dSig[n]);
		    h18->Fill(DeepCSVBDisc[n]);
		    h21->Fill(-DeepCSVBDiscN[n]);
		    if(DeepCSVCvsLDisc[n] > 0){
		    	hh18->Fill(DeepCSVCvsLDisc[n]);
		    }
		    if(DeepCSVCvsLDiscN[n] > 0 ){
		    	hh21->Fill(-DeepCSVCvsLDiscN[n]);
		    }
		    for(int z=Jet_nFirstTrkTagVarCSV[n]; z<Jet_nLastTrkTagVarCSV[n]; z++){
			h9->Fill(TagVarCSV_trackSip3dSig[z]);
		    }
		  }
		}
	}
	int bin1 = h_lightdisc->GetXaxis()->FindBin(0.6);
	int bin2 = h_lightdiscN->GetXaxis()->FindBin(-0.6);
	int bin4 = h3->GetXaxis()->FindBin(0.6);
	int bin3 = h4->GetXaxis()->FindBin(-0.6);
	 
	int bin6 = h17->GetXaxis()->FindBin(0.6);
	int bin5 = h20->GetXaxis()->FindBin(-0.6);

	TCanvas *cd9 = new TCanvas("cd9","cd9",10,10,1300,800);
	b5->Draw();
	b5->SetTitle("Full Tagger: 2d IP Sig of first track above charm mass");
	b5->SetFillColor(kRed);
	b5->SetLineColor(kRed);
	cd9->Update();
 	TCanvas *cd12 = new TCanvas("cd12","cd12",10,10,1300,800);
	b6->Draw();
	b6->SetTitle("Negative Tagger: 2d IP Sig of first track above charm mass");
	b6->SetFillColor(kBlue);
	cd12->Update();

	cout << "Light jets in true tagger = " << h_lightdisc->Integral(bin1,100)/lights  << endl;
	cout << "fraction of light jets remaining in negative tagger = " << h_lightdiscN->Integral(1,bin2)/h_lightdisc->Integral(bin1,100)  << endl;
	cout << " fraction of b jets remaining in negative tagger = " << h4->Integral(1,bin3)/h3->Integral(bin4,100)  << endl;
	cout << "DeepCSV fraction of b jets remaining in negative tagger = " << h20->Integral(1,bin5)/h17->Integral(bin6,100)  << endl;
	cout << "fraction of light jets with all tracks same IP = " << uniformtracks/(blab+uniformtracks) << endl; 
	h_lightdisc->SetFillColor(kBlue);
	h_lightdiscN->SetFillColor(kCyan);
	h7->SetFillColor(kBlue);
	h10->SetFillColor(kBlue);
	h16->SetFillColor(kBlue);
	h19->SetFillColor(kCyan);
	hh16->SetFillColor(kBlue);
	hh19->SetFillColor(kCyan);
	h3->SetFillColor(kRed);
	h4->SetFillColor(kRed);
	h8->SetFillColor(kRed);
	h11->SetFillColor(kRed);
	h17->SetFillColor(kRed);
	h20->SetFillColor(kRed);
	hh17->SetFillColor(kRed);
	hh20->SetFillColor(kRed);
	h5->SetFillColor(kGreen);
	h6->SetFillColor(kGreen);
	h9->SetFillColor(kGreen);
	h12->SetFillColor(kGreen);
	h18->SetFillColor(kGreen);
	hh18->SetFillColor(kGreen);
	h21->SetFillColor(kGreen);
	hh21->SetFillColor(kGreen);
	TCanvas *bd = new TCanvas("bd","bd",10,10,1300,800);
	
   	THStack *hs3 = new THStack("hs3","DeepCSV");
	hs3->Add(h16);
	hs3->Add(h17);
	hs3->Add(h18);
	hs3->Add(h19);
	hs3->Add(h20);
	hs3->Add(h21);
	hs3->Draw();
	bd->SetLogy();
	bd->Update();

	TCanvas *bbd = new TCanvas("bbd","bbd",10,10,1300,800);
	
   	THStack *hhs3 = new THStack("hhs3","DeepCSV CvsL");
	hhs3->Add(hh16);
	hhs3->Add(hh17);
	hhs3->Add(hh18);
	hhs3->Add(hh19);
	hhs3->Add(hh20);
	hhs3->Add(hh21);
	hhs3->Draw();
	bbd->SetLogy();
	bbd->Update();

	TCanvas *cd = new TCanvas("cd","cd",10,10,1300,800);
	
   	THStack *hs = new THStack("hs","DeepFlavour");
	hs->Add(h_lightdisc);
	hs->Add(h_lightdiscN);
	hs->Add(h3);
	hs->Add(h4);
	hs->Add(h5);
	hs->Add(h6);
	hs->Draw("hist");
	hs->GetYaxis()->SetRangeUser(1,10000);
	cd->SetLogy();
	cd->Update();
	TCanvas *cd1 = new TCanvas("cd1","cd1",10,10,1300,800);
	THStack *hs1 = new THStack("hs1","3D Track Impact Parameter Distributions");
	hs1->Add(h7);
	hs1->Add(h8);
	hs1->Add(h9);
	hs1->Draw();
	cd1->Update();	
	TCanvas *cd2 = new TCanvas("cd2","cd2",10,10,1300,800);
	THStack *hs2 = new THStack("hs2","");
	hs2->Add(h10);
	hs2->Add(h11);
	hs2->Add(h12);
	hs2->SetTitle("3d flight distance");
	hs2->Draw();
	cd2->Update();
	TCanvas *cd3 = new TCanvas("cd3","cd3",10,10,1300,800);
	h_lightdiscSymmetry->Divide(h_lightdisc);
	h_lightdiscSymmetry->Draw("E0");
	h_lightdiscSymmetry->SetMarkerStyle(20);
	h_lightdiscSymmetry->GetXaxis()->SetRangeUser(0,1);
	cd3->Update();
	TCanvas *cd4 = new TCanvas("cd4","cd4",10,10,1300,800);
	h13->Draw();
	cd4->Update();
	TCanvas *cd5 = new TCanvas("cd5","cd5",10,10,1300,800);
	h14->Draw("hist");
	h14->Scale(1/uniformtracks);
	h14->SetFillColor(2);
	h15->Draw("E0 same");
	h15->Scale(1/blab);
	h15->SetMarkerStyle(20);
	cd5->Update();
	TCanvas *cd6 = new TCanvas("cd6","cd6",10,10,1300,800);
	h_lightdiscSymmetry1->Divide(h16);
	h_lightdiscSymmetry1->Draw("E0");
	h_lightdiscSymmetry1->GetXaxis()->SetRangeUser(0,1);
	h_lightdiscSymmetry1->SetMarkerStyle(21);	
	cd6->Update();
 	TCanvas *cd7 = new TCanvas("cd7","cd7",10,10,1300,800);
	//b1->Draw();
	b2->Draw("same");
	b1->SetFillColor(kRed);
	b1->SetLineColor(kRed);
	b2->SetFillColor(kBlue);
	cd7->Update();
 	TCanvas *cd8 = new TCanvas("cd8","cd8",10,10,1300,800);
	b3->Draw();
	b4->Draw("same");
	b3->SetFillColor(kRed);
	b3->SetLineColor(kRed);
	b4->SetFillColor(kBlue);
	cd8->Update();

 	TCanvas *cd10 = new TCanvas("cd10","cd10",10,10,1300,800);
	b7->Draw();
	b8->Draw("same");
	b7->SetFillColor(kRed);
	b7->SetLineColor(kRed);
	b8->SetFillColor(16);
	b8->SetFillStyle(3001);
	cd10->Update();
 	TCanvas *cd11 = new TCanvas("cd11","cd11",10,10,1300,800);
	h22->Draw();
	cd11->Update();


	TCanvas *cd20 = new TCanvas("cd20", "vertexNTracksOffvsOn",50,50,1000,800);
	h_vertexNTracks->SetTitle("Number of Vertex Tracks");
	h_vertexNTracks->Draw("hist");
	h_vertexNTracks->SetFillColor(2);
	h_vertexNTracks->GetYaxis()->SetTitle("Event Count");
	h_vertexNTracks->GetXaxis()->SetTitle("Number of Vertex Tracks");
	cd20->SetLogy();
	cd20->Update();
	TCanvas *cd21 = new TCanvas("cd21", "vertexEnergyRatioOffvsOn",50,50,1000,800);
	h_vertexEnergyRatio->Rebin(5);	
	h_vertexEnergyRatio->Draw("hist");
	h_vertexEnergyRatio->SetFillColor(2);
	h_NegvertexEnergyRatio->Rebin(5);	
	h_NegvertexEnergyRatio->Draw("E0 same");
	h_NegvertexEnergyRatio->SetMarkerStyle(20);
	cd21->SetLogy();
	cd21->Update();
	TCanvas *cd22 = new TCanvas("cd22", "vertexJetDeltaROffvsOn",50,50,1000,800);
	h_vertexJetDeltaR->Rebin(5);	
	h_vertexJetDeltaR->Draw("hist");
	h_vertexJetDeltaR->SetFillColor(2);
	h_NegvertexJetDeltaR->Rebin(5);	
	h_NegvertexJetDeltaR->Draw("E0 same");
	h_NegvertexJetDeltaR->SetMarkerStyle(20);	
	cd22->SetLogy();
	cd22->Update();
	TCanvas *cd23 = new TCanvas("cd23", "flightDistance2dValOffvsOn",50,50,1000,800);
	h_flightDistance2dVal->Draw("hist");
	h_flightDistance2dVal->SetFillColor(2);
	cd23->SetLogy();
	cd23->Update();
	TCanvas *cd24 = new TCanvas("cd24", "flightDistance3dValOffvsOn",50,50,1000,800);
	h_flightDistance3dVal->Draw("hist");
	h_flightDistance3dVal->SetFillColor(2);
	cd24->SetLogy();
	cd24->Update();
	TCanvas *cd25 = new TCanvas("cd25", "flightDistance3dSigOffvsOn",50,50,1000,800);
	h_flightDistance3dSig->Draw("hist");
	h_flightDistance3dSig->SetFillColor(2);
	cd25->SetLogy();
	cd25->Update();
	TCanvas *cd26 = new TCanvas("cd26", "flightDistance2dSigOffvsOn",50,50,1000,800);
	h_flightDistance2dSig->Draw("hist");
	h_flightDistance2dSig->SetFillColor(2);
	cd26->SetLogy();
	cd26->Update();
	TCanvas *cd27 = new TCanvas("cd27", "Jet N Secondary vertices",50,50,1000,800);
	h_jetNSecondaryVertices->Draw("hist");
	h_jetNSecondaryVertices->SetFillColor(2);
	h_jetNSecondaryVertices->SetTitle("Number of secondary vertices in negative tagger and full tagger for light jets only");
	h_NegjetNSecondaryVertices->Draw("E0 same");
	h_NegjetNSecondaryVertices->SetMarkerStyle(20);
	cd27->SetLogy();
   	auto legend = new TLegend(0.9,0.7,0.48,0.9);
   	legend->AddEntry(h_jetNSecondaryVertices,"Full Tagger");
   	legend->AddEntry(h_NegjetNSecondaryVertices,"Negative Tagger");
	legend->Draw();
	cd27->Update();
	TCanvas *cd28 = new TCanvas("cd28", "Eta relative to jet axis",50,50,1000,800);
	h_etaRel->Draw("hist");
	h_etaRel->SetTitle("Vertex tracks eta relative to the jet axis - negative tagger");
	h_etaRel->SetFillColor(2);
	cd28->Update();
	TCanvas *canvas = new TCanvas("canvas","canvas",10,10,1300,800);
	sym2->Divide(sym1);
	sym2->Draw("E0");
	sym2->SetMarkerStyle(21);	
	canvas->Update();
}
