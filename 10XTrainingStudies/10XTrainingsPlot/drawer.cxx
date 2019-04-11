#include <TMultiGraph.h>
#include "tdrstyle.C"
#include "CMS_lumi.C"
void CMS_LABEL(Double_t x,Double_t y){
    TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
    l.SetNDC();
    l.SetTextFont(72);
    l.SetTextColor(kBlack);
    l.SetTextSize(0.05);
    l.DrawLatex(x,y,"#bf{Preliminary}");
}
void TT_LABEL(Double_t x,Double_t y){
    TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
    l.SetNDC();
    l.SetTextFont(42);
    l.SetTextColor(kBlack);
    l.SetTextSize(0.04);
    l.DrawLatex(x,y,"t#bar{t} events ");
}
void PT_LABEL_30(Double_t x,Double_t y){
    TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
    l.SetNDC();
    l.SetTextFont(42);
    l.SetTextColor(kBlack);
    l.SetTextSize(0.04);
    l.DrawLatex(x,y,"AK4jets (p_{T} > 30 GeV) ");
}
void PT_LABEL_90(Double_t x,Double_t y){
    TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
    l.SetNDC();
    l.SetTextFont(42);
    l.SetTextColor(kBlack);
    l.SetTextSize(0.04);
    l.DrawLatex(x,y,"AK4jets (p_{T} > 90 GeV) ");
}
void PT_LABEL_200(Double_t x,Double_t y){
    TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
    l.SetNDC();
    l.SetTextFont(42);
    l.SetTextColor(kBlack);
    l.SetTextSize(0.04);
    l.DrawLatex(x,y,"AK4jets (p_{T} > 200 GeV) ");
}
void PT_LABEL_300(Double_t x,Double_t y){
    TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
    l.SetNDC();
    l.SetTextFont(42);
    l.SetTextColor(kBlack);
    l.SetTextSize(0.04);
    l.DrawLatex(x,y,"AK4jets (p_{T} > 300 GeV) ");
}

void drawer(){
  //gROOT->LoadMacro("tdrstyle.C");
  //setTDRStyle();
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasColor(kWhite);
  gStyle->SetLegendBorderSize(1);
  gStyle->SetLabelColor(1, "XYZ");
  gStyle->SetLabelFont(42, "XYZ");
  gStyle->SetLabelOffset(0.007, "XYZ");
  gStyle->SetLabelSize(0.04, "XYZ");
  gStyle->SetAxisColor(1, "XYZ");
  gStyle->SetStripDecimals(kTRUE);
  gStyle->SetTickLength(0.03, "XYZ");
  gStyle->SetNdivisions(510, "XYZ");
  gStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  gStyle->SetPadTickY(1);
  gStyle->SetTitleColor(1, "XYZ");
  gStyle->SetTitleFont(42, "XYZ");
  gStyle->SetTitleSize(0.045, "XYZ");
  // tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  // tdrStyle->SetTitleYSize(Float_t size = 0.02);
  gStyle->SetTitleXOffset(0.9);
  gStyle->SetTitleYOffset(1.15);
  writeExtraText = false;       // if extra text
  extraText  = "t#bar{t} events";  // default extra text is "Preliminary"
  //lumi_sqrtS = "#sqrt{s} = 13 TeV";
  lumi_sqrtS = "41.9 fb^{-1} (13 TeV, 2017)";
  const int nr = 40;
  TFile * files[nr] = {};
  files[0] = TFile::Open("DeepFlavour10Xon10X.root"); // DFSkimEpoch30.root
  //files[0] = TFile::Open("Underligt_1.root"); // DFSkimEpoch30.root
  files[1] = TFile::Open("DeepFlavour10Xon94X.root"); //DeepFlavour10Xon94X.root PermInv26EpochsAttempt1.root DeepCSV_94X_TTBar_30GeV.root DeepFlavour210Xon10XTTBar DeepFlavour10Xon94X.root
  files[2] = TFile::Open("DeepFlavour94Xon94X.root"); // DFSkimEpoch30.root DFRNN_lrpSkim.root
  files[3] = TFile::Open("Underligt.root"); //DF_Skim_NoPupAss/DF_NoAss_TTBarHad_10X_30GeV.root /home/emil/NNStudies/ROCS/multiROC/NewDFSkim/DF2_Skim_Final_ttBarHad_30.root pruned/DF_final_skim_ttBar30GeV.root DFRNN_lrpSkimV2_cuttracks_v2_ttbarhad_30.root DF_frac0p02_Skim_Final_ttBarHad_30.root DFRNN_lrpSkimV2_cuttracks_v2_ttbarhad_30.root DFRNN_lrpSkimV2_cuttracks_more_ttBar_30Pt.root DFRNN_lrpSkimV2.root DFRNN_lrpSkimV2_cuttracks_more_ttBar_30Pt.root DFRNN_lrpSkimV2_cuttracks_TTBar_10X_30Pt.root NewMiniAODv2.root DeepFlavour94Xon10X.root DFRNN_lrpSkim.root DF_frac0p02_Skim_Final_ttBarHad_30.root
  files[4] = TFile::Open("DF_Skim_NoPupAss/DF_NoAss_TTBarLept_10X_30GeV.root"); //pruned2/DF2_final_skim_TTBar_lep_30GeV.root DFRNN_lrpSkimV2_cuttracks_v2_TTBarLept94X_30.root DeepFlavour_only_reco.root DeepFlavour_reco.root, DeepFlavour_only_reco.root 
  files[5] = TFile::Open("DeepFlavour10Xon94XLept.root"); // DeepFlavour10Xon94XLept.root
  files[6] = TFile::Open("/home/emil/NNStudies/ROCS/multiROC/NewDFSkim/DF2_Skim_Final_ttBarHad_30.root"); // pruned/DF_final_skim_ttBar30GeV.root DeepFlavour10XTTBarNoAss30GeV.root DeepFlavour10XNoPuppi.root
  files[7] = TFile::Open("DeepFlavour10XQCD.root"); // evaluated on 94X 120to170
  files[8] = TFile::Open("DF_Skim_NoPupAss/DF_NoAss_QCD120to170_94X_30GeV.root"); //this is 10X // pruned2/DF2_final_skim_QCD120to170_30GeV.root DFRNN_lrpSkimV2_cuttracks_v2_QCD120to170_30.root
  files[9] = TFile::Open("DF_Original_QCD3200toInf_94X_500GeV.root");
  files[10] = TFile::Open("DF_Skim_NoPupAss/DF_NoAss_QCD3200toInf_94X_500GeV.root"); //pruned2/DF2_final_skim_QCD3200toInf_94X_500GeV.root DFRNN_lrpSkimV2_cuttracks_v2_QCD3200toInf_500.root DFRNN_lrpSkimV2_cuttracks_more_QCD_500Pt.root DFRNN_lrpSkimV2_QCD_500Pt.root DFRNN_lrpSkimV2_cuttracks_QCD_10X_500Pt.pdf DeepFlavour94Xon10XQCD360Pt.root DFRNN_lrpSkimV2_cuttracks_QCD_10X_500Pt.root DFRNN_lrpSkimV2_cuttracks_more_QCD_500Pt.root
//DeepFlavour10XQCDHighPT
  //DeepFlavour94XQCDHighPT.root
  files[11] = TFile::Open("DeepCSV10XTestTTBar.root");
  files[12] = TFile::Open("DeepCSV_94X_TTBar.root"); //DeepCSV_94X_TTBar_30GeV.root DeepCSV_94X_TTBar.root Test94XRocCSV.root DeepCSV94x.root DeepCSV_inNtuples_roc.root DeepCSV_Phase1_roc.root
  files[13] = TFile::Open("DeepFlavour94XttBarHighPT.root"); //DeepFlavour210Xon10XTTBarHighPt.root
  files[14] = TFile::Open("DeepFlavour10XttBarHighPT.root");
  files[15] = TFile::Open("DeepFlavour94Xon10XTTBar400Pt.root");
  files[16] = TFile::Open("DeepFlavour10Xon10XTTBar400Pt.root");
  files[17] = TFile::Open("DeepFlavour210Xon10XTTBar400Pt.root");
  
  files[18] = TFile::Open("DFNoRNN_lrpSkim.root");//DFNoRNN_lrpSkim.root DeepFlavour94XTTBarNoLeptTrain.root DeepFlavour94XNoLeptTTBarFinal.root
  files[19] = TFile::Open("DeepFlavour94XNoLeptReallyEarlyTTBar200PT.root");

  files[20] = TFile::Open("DeepFlavour210Xon10XTTBar.root");
  
  files[21] = TFile::Open("DeepFlavour94XNoLeptQCD360.root");
  files[22] = TFile::Open("DeepCSV8XTT30GeVClean.root");
  files[23] = TFile::Open("DeepCSV8XTT90GeVClean.root");
  files[24] = TFile::Open("DeepCSV_94X_TTBar_90GeV.root"); // DeepCSV_94X_TTBar_90GeV.root -- DeepCSV94XTTBar90GeV.root
  files[25] = TFile::Open("DeepFlavour10XTTbar90GeV.root");
  files[26] = TFile::Open("DeepCSV8XTT200GeV.root");
  files[27] = TFile::Open("DF_Skim_NoPupAss/DF_NoAss_TTBarHad_10X_200GeV.root"); //pruned2/DF2_final_skim_TTBarHad_200GeV.root DFRNN_lrpSkimV2_cuttracks_TTBar_10X_200Pt.root  DFRNN_lrpSkimV2_200Pt.root DeepCSV94XTTBar200GeV.root DFRNN_lrpSkimV2_cuttracks_more_ttBar_200Pt.root
  files[28] = TFile::Open("DeepFlavour10XTTbar200GeV.root ");
  files[29] = TFile::Open("/home/emil/NNStudies/TestOfDF94X/Test94XRoc.root "); ///home/emil/NNStudies/TestOfDF94X/Test94XRoc.root  
  files[30] = TFile::Open("DF_OLDCMSSW.root ");
  files[31] = TFile::Open("DeepCSV_noTrackSelect.root"); //DFNoRNN.root
  files[32] = TFile::Open("DFOriginal_TTBarCTag_30pt.root");
  files[33] = TFile::Open("DF_Skim_NoPupAss/DF_NoAss_TTBarHad_CTag_30GeV.root"); //pruned2/DF2_final_skim_TTBarCTag_30GeV.root DFRNN_lrpSkimV2_TTBarCTag_30pt.root
  files[34] = TFile::Open("DFOriginal_TTBarUDSTag_30pt.root");
  files[35] = TFile::Open("DF_Skim_NoPupAss/DF_NoAss_TTBarHad_UDSTag_30GeV.root"); //pruned2/DF2_final_skim_TTBarUDSTag_30GeV.root DF_lrpskim_TTBarUDSTag_30pt.root
  files[36] = TFile::Open("DF_org_ttBarHad_300GeV.root");
  files[37] = TFile::Open("DeepCSV_94X_TTBar_300GeV.root");
  files[38] = TFile::Open("DF_10X_on_Phase0.root");
  files[39] = TFile::Open("Underligt90.root");
 


  
  TFile * SF_DF_file = TFile::Open("SF_deepFlavour.root");
  //TFile * SF_DF_file = TFile::Open("automated_SF_DeepFlavour_30GeV.root");
  TGraphAsymmErrors * SF_DF_plot_lvsb = (TGraphAsymmErrors*)SF_DF_file->Get("roccurve_0");
  TGraphAsymmErrors * SF_DF_plot_cvsb = (TGraphAsymmErrors*)SF_DF_file->Get("roccurve_1");
  TGraph * SF_DF_plot_lvsb_no_cor = (TGraph*)SF_DF_file->Get("roccurve_0noCor");
  TGraph * SF_DF_plot_cvsb_no_cor = (TGraph*)SF_DF_file->Get("roccurve_1noCor");

  TFile * SF_DCSV_file = TFile::Open("SF_deepCSV_phase1.root");
  TGraphAsymmErrors * SF_DCSV_plot_lvsb = (TGraphAsymmErrors*)SF_DCSV_file->Get("roccurve_0");
  TGraphAsymmErrors * SF_DCSV_plot_cvsb = (TGraphAsymmErrors*)SF_DCSV_file->Get("roccurve_1");
  TGraph * SF_DCSV_plot_lvsb_no_cor = (TGraph*)SF_DCSV_file->Get("roccurve_0noCor");
  TGraph * SF_DCSV_plot_cvsb_no_cor = (TGraph*)SF_DCSV_file->Get("roccurve_1noCor");


  TFile * SF_DF_file_90 = TFile::Open("SF_deepFlavour_90GeV.root");
  TGraphAsymmErrors * SF_DF_plot_lvsb_90 = (TGraphAsymmErrors*)SF_DF_file_90->Get("roccurve_0");
  TGraphAsymmErrors * SF_DF_plot_cvsb_90 = (TGraphAsymmErrors*)SF_DF_file_90->Get("roccurve_1");
  TGraphAsymmErrors * SF_DF_plot_lvsb_90_no_cor = (TGraphAsymmErrors*)SF_DF_file_90->Get("roccurve_0noCor");
  TGraphAsymmErrors * SF_DF_plot_cvsb_90_no_cor = (TGraphAsymmErrors*)SF_DF_file_90->Get("roccurve_1noCor");

  TFile * SF_DCSV_file_90 = TFile::Open("SF_deepCSV_phase1_90GeV.root");
  TGraphAsymmErrors * SF_DCSV_plot_lvsb_90 = (TGraphAsymmErrors*)SF_DCSV_file_90->Get("roccurve_0");
  TGraphAsymmErrors * SF_DCSV_plot_cvsb_90 = (TGraphAsymmErrors*)SF_DCSV_file_90->Get("roccurve_1");
  TGraphAsymmErrors * SF_DCSV_plot_lvsb_90_no_cor = (TGraphAsymmErrors*)SF_DCSV_file_90->Get("roccurve_0noCor");
  TGraphAsymmErrors * SF_DCSV_plot_cvsb_90_no_cor = (TGraphAsymmErrors*)SF_DCSV_file_90->Get("roccurve_1noCor");

  TFile * SF_DF_file_300 = TFile::Open("SF_deepFlavour_300GeV.root");
  TGraphAsymmErrors * SF_DF_plot_lvsb_300 = (TGraphAsymmErrors*)SF_DF_file_300->Get("roccurve_0");
  TGraphAsymmErrors * SF_DF_plot_cvsb_300 = (TGraphAsymmErrors*)SF_DF_file_300->Get("roccurve_1");
  TGraphAsymmErrors * SF_DF_plot_lvsb_300_no_cor = (TGraphAsymmErrors*)SF_DF_file_300->Get("roccurve_0noCor");
  TGraphAsymmErrors * SF_DF_plot_cvsb_300_no_cor = (TGraphAsymmErrors*)SF_DF_file_300->Get("roccurve_1noCor");

  TFile * SF_DCSV_file_300 = TFile::Open("SF_deepCSV_phase1_300GeV.root");
  TGraphAsymmErrors * SF_DCSV_plot_lvsb_300 = (TGraphAsymmErrors*)SF_DCSV_file_300->Get("roccurve_0");
  TGraphAsymmErrors * SF_DCSV_plot_cvsb_300 = (TGraphAsymmErrors*)SF_DCSV_file_300->Get("roccurve_1");
  TGraphAsymmErrors * SF_DCSV_plot_lvsb_300_no_cor = (TGraphAsymmErrors*)SF_DCSV_file_300->Get("roccurve_0noCor");
  TGraphAsymmErrors * SF_DCSV_plot_cvsb_300_no_cor = (TGraphAsymmErrors*)SF_DCSV_file_300->Get("roccurve_1noCor");

  


  
  SF_DF_plot_lvsb->SetMarkerColor(kBlue);
  SF_DF_plot_cvsb->SetMarkerColor(kBlue);
  SF_DCSV_plot_lvsb->SetMarkerColor(kRed);
  SF_DCSV_plot_cvsb->SetMarkerColor(kRed);
  SF_DF_plot_lvsb->SetMarkerSize(2);
  SF_DF_plot_cvsb->SetMarkerSize(2);
  SF_DF_plot_lvsb_no_cor->SetMarkerStyle(20);
  SF_DF_plot_cvsb_no_cor->SetMarkerStyle(24);
  SF_DF_plot_lvsb_no_cor->SetMarkerSize(2);
  SF_DF_plot_cvsb_no_cor->SetMarkerSize(2);

  SF_DCSV_plot_lvsb_no_cor->SetMarkerStyle(20);
  SF_DCSV_plot_cvsb_no_cor->SetMarkerStyle(24);
  SF_DCSV_plot_lvsb_no_cor->SetMarkerSize(2);
  SF_DCSV_plot_cvsb_no_cor->SetMarkerSize(2);

  SF_DF_plot_lvsb_no_cor->SetMarkerColor(kBlue);
  SF_DF_plot_cvsb_no_cor->SetMarkerColor(kBlue);

  SF_DCSV_plot_lvsb_no_cor->SetMarkerColor(kRed);
  SF_DCSV_plot_cvsb_no_cor->SetMarkerColor(kRed);


  SF_DF_plot_lvsb_no_cor->SetLineColor(kBlue);
  SF_DF_plot_cvsb_no_cor->SetLineColor(kBlue);
  SF_DCSV_plot_lvsb_no_cor->SetLineColor(kRed);
  SF_DCSV_plot_cvsb_no_cor->SetLineColor(kRed);

  
  SF_DCSV_plot_lvsb->SetMarkerSize(2);
  SF_DCSV_plot_cvsb->SetMarkerSize(2);
  SF_DF_plot_lvsb->SetLineColor(kBlue);
  SF_DF_plot_cvsb->SetLineColor(kBlue);
  SF_DCSV_plot_lvsb->SetLineColor(kRed);
  SF_DCSV_plot_cvsb->SetLineColor(kRed);

  SF_DF_plot_lvsb->SetMarkerStyle(22);
  SF_DF_plot_cvsb->SetMarkerStyle(26);
  SF_DCSV_plot_lvsb->SetMarkerStyle(22);
  SF_DCSV_plot_cvsb->SetMarkerStyle(26);


  SF_DF_plot_lvsb_90->SetMarkerColor(kBlue);
  SF_DF_plot_cvsb_90->SetMarkerColor(kBlue);
  SF_DCSV_plot_lvsb_90->SetMarkerColor(kRed);
  SF_DCSV_plot_cvsb_90->SetMarkerColor(kRed);
  SF_DF_plot_lvsb_90->SetMarkerSize(2);
  SF_DF_plot_cvsb_90->SetMarkerSize(2);
  SF_DCSV_plot_lvsb_90->SetMarkerSize(2);
  SF_DCSV_plot_cvsb_90->SetMarkerSize(2);
  SF_DF_plot_lvsb_90->SetLineColor(kBlue);
  SF_DF_plot_cvsb_90->SetLineColor(kBlue);
  SF_DCSV_plot_lvsb_90->SetLineColor(kRed);
  SF_DCSV_plot_cvsb_90->SetLineColor(kRed);

  SF_DF_plot_lvsb_90->SetMarkerStyle(22);
  SF_DF_plot_cvsb_90->SetMarkerStyle(26);
  SF_DCSV_plot_lvsb_90->SetMarkerStyle(22);
  SF_DCSV_plot_cvsb_90->SetMarkerStyle(26);

  SF_DF_plot_lvsb_90_no_cor->SetLineColor(kBlue);
  SF_DF_plot_cvsb_90_no_cor->SetLineColor(kBlue);
  SF_DCSV_plot_lvsb_90_no_cor->SetLineColor(kRed);
  SF_DCSV_plot_cvsb_90_no_cor->SetLineColor(kRed);

  
  SF_DF_plot_lvsb_90_no_cor->SetMarkerStyle(20);
  SF_DF_plot_cvsb_90_no_cor->SetMarkerStyle(24);
  SF_DF_plot_lvsb_90_no_cor->SetMarkerSize(2);
  SF_DF_plot_cvsb_90_no_cor->SetMarkerSize(2);

  SF_DF_plot_lvsb_90_no_cor->SetMarkerColor(kBlue);
  SF_DF_plot_cvsb_90_no_cor->SetMarkerColor(kBlue);
  SF_DCSV_plot_lvsb_90_no_cor->SetMarkerStyle(20);
  SF_DCSV_plot_cvsb_90_no_cor->SetMarkerStyle(24);
  SF_DCSV_plot_lvsb_90_no_cor->SetMarkerSize(2);
  SF_DCSV_plot_cvsb_90_no_cor->SetMarkerSize(2);
  SF_DCSV_plot_lvsb_90_no_cor->SetMarkerColor(kRed);
  SF_DCSV_plot_cvsb_90_no_cor->SetMarkerColor(kRed);
  
  SF_DF_plot_lvsb_300->SetMarkerColor(kBlue);
  SF_DF_plot_cvsb_300->SetMarkerColor(kBlue);
  SF_DCSV_plot_lvsb_300->SetMarkerColor(kRed);
  SF_DCSV_plot_cvsb_300->SetMarkerColor(kRed);

  SF_DF_plot_lvsb_300->SetMarkerStyle(22);
  SF_DF_plot_cvsb_300->SetMarkerStyle(26);
  SF_DCSV_plot_lvsb_300->SetMarkerStyle(22);
  SF_DCSV_plot_cvsb_300->SetMarkerStyle(26);

  SF_DF_plot_lvsb_300->SetMarkerSize(2);
  SF_DF_plot_cvsb_300->SetMarkerSize(2);
  SF_DCSV_plot_lvsb_300->SetMarkerSize(2);
  SF_DCSV_plot_cvsb_300->SetMarkerSize(2);
  SF_DF_plot_lvsb_300->SetLineColor(kBlue);
  SF_DF_plot_cvsb_300->SetLineColor(kBlue);
  SF_DCSV_plot_lvsb_300->SetLineColor(kRed);
  SF_DCSV_plot_cvsb_300->SetLineColor(kRed);


  SF_DF_plot_lvsb_300_no_cor->SetMarkerStyle(20);
  SF_DF_plot_cvsb_300_no_cor->SetMarkerStyle(24);
  SF_DF_plot_lvsb_300_no_cor->SetMarkerSize(2);
  SF_DF_plot_cvsb_300_no_cor->SetMarkerSize(2);
  SF_DF_plot_lvsb_300_no_cor->SetMarkerColor(kBlue);
  SF_DF_plot_cvsb_300_no_cor->SetMarkerColor(kBlue);
  SF_DF_plot_lvsb_300_no_cor->SetLineColor(kBlue);
  SF_DF_plot_cvsb_300_no_cor->SetLineColor(kBlue);

  
  SF_DCSV_plot_lvsb_300_no_cor->SetMarkerStyle(20);
  SF_DCSV_plot_cvsb_300_no_cor->SetMarkerStyle(24);
  SF_DCSV_plot_lvsb_300_no_cor->SetMarkerSize(2);
  SF_DCSV_plot_cvsb_300_no_cor->SetMarkerSize(2);
  SF_DCSV_plot_lvsb_300_no_cor->SetMarkerColor(kRed);
  SF_DCSV_plot_cvsb_300_no_cor->SetMarkerColor(kRed);
  SF_DCSV_plot_lvsb_300_no_cor->SetLineColor(kRed);
  SF_DCSV_plot_cvsb_300_no_cor->SetLineColor(kRed);
 
  
  TGraph * graphlvsb[nr] = {};
  TGraph * graphcvsb[nr] = {};
  auto mg1  = new TMultiGraph();
  auto mg2  = new TMultiGraph();
  for(int z = 0; z < nr; z++){
    graphlvsb[z] = (TGraph*)files[z]->Get("roccurve_0");
    graphlvsb[z]->SetLineColor(kRed+z);
    graphcvsb[z] = (TGraph*)files[z]->Get("roccurve_1");
    graphcvsb[z]->SetLineColor(kRed+z);
    graphcvsb[z]->SetLineStyle(7);
    graphlvsb[z]->SetLineWidth(2); 
    graphcvsb[z]->SetLineWidth(2);
  }
  TCanvas *c1 = new TCanvas("c1", "ROCS",50,50,1500,800);
  c1->SetGrid();
  graphlvsb[1]->SetLineColor(kBlue);
  graphcvsb[1]->SetLineColor(kBlue);
  graphlvsb[2]->SetLineColor(kGreen);
  graphcvsb[2]->SetLineColor(kGreen);
  graphlvsb[3]->SetLineColor(kRed);
  graphcvsb[3]->SetLineColor(kRed);
  graphlvsb[4]->SetLineColor(kRed);
  graphcvsb[4]->SetLineColor(kRed);
  graphlvsb[5]->SetLineColor(kBlue);
  graphcvsb[5]->SetLineColor(kBlue);
  graphlvsb[6]->SetLineColor(kBlue);
  graphcvsb[6]->SetLineColor(kBlue);
  graphlvsb[7]->SetLineColor(kBlue);
  graphcvsb[7]->SetLineColor(kBlue);
  graphlvsb[8]->SetLineColor(kRed);
  graphcvsb[8]->SetLineColor(kRed);
  graphlvsb[9]->SetLineColor(kBlue);
  graphcvsb[9]->SetLineColor(kBlue);
  graphlvsb[10]->SetLineColor(kRed);
  graphcvsb[10]->SetLineColor(kRed);
  graphlvsb[11]->SetLineColor(kBlue);
  graphcvsb[11]->SetLineColor(kBlue);
  graphlvsb[12]->SetLineColor(kRed);
  graphcvsb[12]->SetLineColor(kRed);
  graphlvsb[18]->SetLineColor(kBlack);
  graphcvsb[18]->SetLineColor(kBlack);
  graphlvsb[21]->SetLineColor(kBlack);
  graphcvsb[21]->SetLineColor(kBlack);
  graphlvsb[0]->Draw();
  graphlvsb[0]->SetTitle("10X DeepFlavour Training");
  graphcvsb[0]->Draw("same");
  graphlvsb[3]->Draw("same");
  graphcvsb[3]->Draw("same");
  // graphlvsb[18]->Draw("same");
  // graphcvsb[18]->Draw("same"); 
  auto legend = new TLegend(0.28,0.65,0.48,0.8);
  legend->AddEntry(graphlvsb[0],"10X Training Full","l");
  legend->AddEntry(graphlvsb[3],"10X Training Skim","l"); //94X training on 10X
  //legend->AddEntry(graphlvsb[18],"NoRNN Skim","l");
  //legend->AddEntry(graphcvsb[18],"94X no lept training on 10X","l");
  legend->Draw();

  TCanvas *c2 = new TCanvas("c2", "ROCS",50,50,1500,800);
  c2->SetGrid();
  graphcvsb[5]->Draw(); 
  graphlvsb[4]->Draw("same");
  graphcvsb[5]->GetXaxis()->SetTitle("b-jet efficiency");
  graphcvsb[5]->GetYaxis()->SetTitle("mistag rate");  
  graphcvsb[5]->SetTitle("DeepFlavour Skim: evaluated on tt-bar leptonic MC");
  graphcvsb[4]->Draw("same"); 
  graphcvsb[4]->SetLineStyle(9); 
  graphlvsb[5]->Draw("same");
  graphcvsb[5]->SetLineStyle(9);
  // graphlvsb[29]->Draw("same");
  //graphcvsb[29]->Draw("same");
  graphlvsb[29]->SetLineColor(kGreen+3);
  graphcvsb[29]->SetLineColor(kGreen+3);
  graphcvsb[29]->SetLineStyle(9);
  //graphlvsb[30]->Draw("same");
  //graphcvsb[30]->Draw("same");
  graphlvsb[30]->SetLineColor(kBlack);
  graphcvsb[30]->SetLineColor(kBlack);
  graphlvsb[38]->SetLineColor(kBlack);
  graphcvsb[38]->SetLineColor(kBlack);
  graphcvsb[30]->SetLineStyle(9);
  graphlvsb[4]->SetLineWidth(2); 
  graphcvsb[4]->SetLineWidth(2); 
  graphlvsb[5]->SetLineWidth(2);
 graphcvsb[38]->SetLineWidth(2); 	
  graphlvsb[38]->SetLineWidth(2);
  graphcvsb[5]->SetLineWidth(2);
  graphlvsb[29]->SetLineWidth(2);
  graphcvsb[29]->SetLineWidth(2);
  auto legend1 = new TLegend(0.28,0.65,0.48,0.8);
  legend1->AddEntry(graphlvsb[4],"DeepFlavour Skim","l");
  legend1->AddEntry(graphlvsb[5],"DeepFlavour","l");
  //legend1->AddEntry(graphlvsb[29],"Previous Model","l");
  legend1->Draw(); 

  TCanvas *c3 = new TCanvas("c3", "ROCS",50,50,1500,800);
  c3->SetGrid();
  graphlvsb[0]->Draw();
  graphcvsb[0]->Draw("same"); 
  graphlvsb[6]->Draw("same");
  graphcvsb[6]->Draw("same");

  auto legend2 = new TLegend(0.28,0.65,0.48,0.8);
  //legend2->AddEntry(graphcvsb[0],"10X training with puppi weights","l");
  //legend2->AddEntry(graphcvsb[6],"10X training without puppi weights","l");
  legend2->AddEntry(graphcvsb[0],"10X training TTbar had > 30GeV","l");
  legend2->AddEntry(graphcvsb[6],"DeepFlavour skim TTBar had > 30GeV","l");
 
  legend2->Draw(); 

  TCanvas *c4 = new TCanvas("c4", "ROCS",50,50,1500,800);
  c4->SetGrid();
  graphlvsb[7]->Draw();
  graphlvsb[7]->SetTitle("Comparison on 94X QCD 120 to 170 GeV");
  graphcvsb[7]->Draw("same"); 
  graphlvsb[8]->Draw("same");
  graphcvsb[8]->Draw("same");
  graphlvsb[38]->Draw("same");
  graphcvsb[38]->Draw("same");

  auto legend3 = new TLegend(0.28,0.65,0.48,0.8);
  legend3->AddEntry(graphcvsb[7],"10X training on 94X QCD 120 to 170 GeV","l");
  legend3->AddEntry(graphcvsb[8],"10X skimmed training on 94X QCD 120 to 170 GeV","l");
  legend3->Draw();

  TCanvas *c5 = new TCanvas("c5", "ROCS",50,50,1500,800);
  c5->SetGrid();
  graphlvsb[9]->Draw();
  graphlvsb[9]->SetTitle("Comparison on 94X QCD pt > 500GeV");
  graphcvsb[9]->Draw("same"); 
  graphlvsb[10]->Draw("same");
  graphcvsb[10]->Draw("same"); 
 // graphlvsb[21]->Draw("same");
 // graphcvsb[21]->Draw("same");

  auto legend4 = new TLegend(0.28,0.65,0.48,0.8);
  legend4->AddEntry(graphcvsb[9],"10X training on 94X QCD pt > 500GeV","l");
  legend4->AddEntry(graphcvsb[10],"10X training skimmed on 94X QCD pt > 500GeV","l");
  //legend4->AddEntry(graphcvsb[21],"94X with no ttbar leptonic training on 10X QCD pt > 360GeV","l");
  legend4->Draw();  

  TCanvas *c6 = new TCanvas("c6", "ROCS",50,50,1500,800);
  c6->SetGrid();
  graphlvsb[11]->Draw();
  graphlvsb[11]->SetTitle("Comparison of DeepCSV on TTbar");
  graphcvsb[11]->Draw("same"); 
  graphlvsb[12]->Draw("same");
  graphcvsb[12]->Draw("same");

  auto legend5 = new TLegend(0.28,0.65,0.48,0.8);
  legend5->AddEntry(graphcvsb[9],"10X training DeepCSV","l");
  legend5->AddEntry(graphcvsb[10],"94X training DeepCSV","l");
  legend5->Draw();  

  TCanvas *c7 = new TCanvas("c7", "ROCS",50,50,1500,800);
  c7->SetGrid();
  graphlvsb[13]->Draw();
  graphlvsb[13]->SetTitle("TTbar 10X pt > 200 GeV");
  graphcvsb[13]->Draw("same"); 
  graphlvsb[14]->Draw("same");
  graphcvsb[14]->Draw("same");
  //  graphlvsb[19]->Draw("same");
  // graphcvsb[19]->Draw("same");
  graphlvsb[13]->SetLineColor(kRed);
  graphcvsb[13]->SetLineColor(kRed);
  graphlvsb[14]->SetLineColor(kBlue);
  graphcvsb[14]->SetLineColor(kBlue);
  graphlvsb[19]->SetLineColor(kGreen);
  graphcvsb[19]->SetLineColor(kGreen);

  auto legend6 = new TLegend(0.28,0.65,0.48,0.8);
  legend6->AddEntry(graphcvsb[13],"94X training ttBar > 200GeV","l");
  legend6->AddEntry(graphcvsb[14],"10X training ttBar > 200GeV","l");
  legend6->Draw();  

  TCanvas *c8 = new TCanvas("c8", "ROCS",50,50,1500,800);
  c8->SetGrid();
  graphlvsb[15]->Draw();
  graphlvsb[15]->SetTitle("TTbar 10X pt > 400 GeV");
  graphcvsb[15]->Draw("same"); 
  graphlvsb[16]->Draw("same");
  graphcvsb[16]->Draw("same"); 
  graphlvsb[17]->Draw("same");
  graphcvsb[17]->Draw("same");
  graphlvsb[15]->SetLineColor(kRed);
  graphcvsb[15]->SetLineColor(kRed);
  graphlvsb[16]->SetLineColor(kBlue);
  graphcvsb[16]->SetLineColor(kBlue);
  graphlvsb[17]->SetLineColor(kOrange);
  graphcvsb[17]->SetLineColor(kOrange);

  auto legend7 = new TLegend(0.28,0.65,0.48,0.8);
  legend7->AddEntry(graphcvsb[15],"DeepFlavour 94X ttBar HighPT","l");
  legend7->AddEntry(graphcvsb[16],"DeepFlavour 10X ttBar HighPT","l");
  legend7->AddEntry(graphcvsb[17],"DeepFlavour 2 10X ttBar HighPT","l");
  legend7->Draw();  


  TCanvas *c9 = new TCanvas("c9", "ROCS",50,50,1200,900);
  c9->SetGrid();
  graphlvsb[12]->Draw("CA");
  graphcvsb[12]->Draw("same");
  graphlvsb[12]->SetTitle(""); 
  graphlvsb[12]->GetXaxis()->SetTitle("b jet efficiency");
  graphlvsb[12]->GetYaxis()->SetTitle("misid. probability"); 
  graphlvsb[1]->Draw("same");
  graphcvsb[1]->Draw("same");

  graphlvsb[31]->Draw("same");
  graphcvsb[31]->Draw("same");
  graphlvsb[31]->SetLineColor(kGreen);
  graphcvsb[31]->SetLineColor(kGreen);

  SF_DF_plot_lvsb->Draw("P same");
  SF_DF_plot_cvsb->Draw("P same");
  SF_DF_plot_lvsb_no_cor->Draw("P same");
  SF_DF_plot_cvsb_no_cor->Draw("P same");
  
  SF_DCSV_plot_lvsb_no_cor->Draw("P same");
  SF_DCSV_plot_cvsb_no_cor->Draw("P same");

  SF_DCSV_plot_lvsb->Draw("P same");
  SF_DCSV_plot_cvsb->Draw("P same");
  //  graphlvsb[22]->Draw("same");
  //graphcvsb[22]->Draw("same");
  graphcvsb[22]->SetLineWidth(2);
  graphlvsb[22]->SetLineWidth(2);      
  graphlvsb[12]->SetLineColor(kRed);
  graphcvsb[12]->SetLineColor(kRed);
  graphlvsb[1]->SetLineColor(kBlue);
  graphcvsb[1]->SetLineColor(kBlue);
  graphlvsb[22]->SetLineColor(kGreen+3);
  graphcvsb[22]->SetLineColor(kGreen+3);
  graphlvsb[12]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphlvsb[12]->GetYaxis()->SetRangeUser(0.0005,1);
  c9->SetLogy();
  CMS_lumi( c9, 0, 11 );
  CMS_LABEL(0.266,0.812);
  //CMS_LABEL(0.266,0.826);
  TT_LABEL(0.14,0.772);
  PT_LABEL_30(0.14,0.722);
  auto legend9 = new TLegend(0.1419,0.5384,0.4044,0.6877);
  //legend9->AddEntry(graphlvsb[1],"DeepJet","lp");
  //legend9->AddEntry(graphlvsb[12],"DeepCSV","lp");
  legend9->AddEntry(SF_DF_plot_lvsb_no_cor,"DeepJet","lp");
  legend9->AddEntry(SF_DCSV_plot_lvsb_no_cor,"DeepCSV","lp");
  legend9->AddEntry(SF_DF_plot_lvsb,"DeepJet with SF applied","lep");
  legend9->AddEntry(SF_DCSV_plot_lvsb,"DeepCSV with SF applied","lep");

  //legend9->AddEntry(graphlvsb[22],"DeepCSV phase 0","l");
  legend9->Draw();  
  auto legend8 = new TLegend(0.1419,0.354,0.3622,0.5);
  graphlvsb[18]->SetMarkerStyle(22);
  graphcvsb[21]->SetMarkerStyle(26);
  graphlvsb[18]->SetMarkerColor(kBlack);
  graphcvsb[21]->SetMarkerColor(kBlack);
  graphlvsb[18]->SetMarkerSize(2);
  graphcvsb[21]->SetMarkerSize(2);
  legend8->AddEntry(graphlvsb[18],"udsg","l");
  legend8->AddEntry(graphcvsb[21],"c","l");
  legend8->AddEntry(graphlvsb[18],"udsg with SF applied","p");
  legend8->AddEntry(graphcvsb[21],"c with SF applied","p");
  legend8->Draw();  
  c9->Update();
  c9->SaveAs("SF_30GeVUpdate.pdf");
  TCanvas *c10 = new TCanvas("c10", "ROCS",50,50,1200,900);
  c10->SetGrid();
  graphlvsb[24]->Draw("CA");
  graphcvsb[24]->Draw("same");
  graphlvsb[24]->SetTitle(""); 
  graphlvsb[24]->GetXaxis()->SetTitle("b jet efficiency");
  graphlvsb[24]->GetYaxis()->SetTitle("misid. probability"); 
  // graphlvsb[23]->Draw("same");
  //graphcvsb[23]->Draw("same");
  graphlvsb[25]->Draw("same");
  graphcvsb[25]->Draw("same");
  SF_DF_plot_lvsb_90->Draw("P same");
  SF_DF_plot_cvsb_90->Draw("P same");
  SF_DF_plot_lvsb_90_no_cor->Draw("P same");
  SF_DF_plot_cvsb_90_no_cor->Draw("P same");
  SF_DCSV_plot_lvsb_90->Draw("P same");
  SF_DCSV_plot_cvsb_90->Draw("P same");
  SF_DCSV_plot_lvsb_90_no_cor->Draw("P same");
  SF_DCSV_plot_cvsb_90_no_cor->Draw("P same");
  graphcvsb[23]->SetLineWidth(2);
  graphlvsb[23]->SetLineWidth(2);      
  graphlvsb[24]->SetLineColor(kRed);
  graphcvsb[24]->SetLineColor(kRed);
  graphlvsb[25]->SetLineColor(kBlue);
  graphcvsb[25]->SetLineColor(kBlue);
  graphlvsb[23]->SetLineColor(kGreen+3);
  graphcvsb[23]->SetLineColor(kGreen+3);
  graphlvsb[24]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphlvsb[24]->GetYaxis()->SetRangeUser(0.0005,1);
  c10->SetLogy();
  CMS_lumi( c10, 0, 11 );
  CMS_LABEL(0.266,0.812);
  TT_LABEL(0.14,0.772);
  PT_LABEL_90(0.14,0.722);
  auto legend10 = new TLegend(0.1419,0.5384,0.4044,0.6877);
  //legend10->AddEntry(graphlvsb[25],"DeepJet","l");
  //legend10->AddEntry(graphlvsb[24],"DeepCSV","l");
  legend10->AddEntry(SF_DF_plot_lvsb_90_no_cor,"DeepJet","lp");
  legend10->AddEntry(SF_DCSV_plot_lvsb_90_no_cor,"DeepCSV","lp");
  
  legend10->AddEntry(SF_DF_plot_lvsb_90,"DeepJet with SF applied","lep");
  legend10->AddEntry(SF_DCSV_plot_lvsb_90,"DeepCSV with SF applied","lep");
  //  legend10->AddEntry(graphlvsb[23],"DeepCSV phase 0","l");
  legend10->Draw();  
  auto legend11 = new TLegend(0.1419,0.354,0.3422,0.451); //0.712,0.1308,0.8906,0.2273
  legend11->AddEntry(graphlvsb[18],"udsg","l");
  legend11->AddEntry(graphcvsb[21],"c","l");
  // legend11->Draw();
  legend8->Draw();
  c10->Update();
  c10->SaveAs("SF_90GeV.pdf");
  TCanvas *c11 = new TCanvas("c11", "ROCS",50,50,1200,900);
  c11->SetGrid();
  graphlvsb[27]->Draw("CA");
  graphcvsb[27]->Draw("same");
  graphlvsb[27]->SetTitle(""); 
  graphlvsb[27]->GetXaxis()->SetTitle("b jet efficiency");
  graphlvsb[27]->GetYaxis()->SetTitle("misid. probability"); 
  //graphlvsb[26]->Draw("same");
  // graphcvsb[26]->Draw("same");
  graphlvsb[28]->Draw("same");
  graphcvsb[28]->Draw("same");
  graphcvsb[26]->SetLineWidth(2);
  graphlvsb[26]->SetLineWidth(2);      
  graphlvsb[27]->SetLineColor(kRed);
  graphcvsb[27]->SetLineColor(kRed);
  graphlvsb[28]->SetLineColor(kBlue);
  graphcvsb[28]->SetLineColor(kBlue);
  graphlvsb[26]->SetLineColor(kGreen+3);
  graphcvsb[26]->SetLineColor(kGreen+3);
  graphlvsb[27]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphlvsb[27]->GetYaxis()->SetRangeUser(0.00085,1);
  c11->SetLogy();
  CMS_lumi( c11, 0, 11 );
  CMS_LABEL(0.535,0.812);
  TT_LABEL(0.14,0.772);
  PT_LABEL_200(0.14,0.722);
  auto legend12 = new TLegend(0.1419,0.5384,0.4044,0.6877);
  legend12->AddEntry(graphlvsb[28],"DeepFlavour phase 1","l");
  legend12->AddEntry(graphlvsb[27],"DeepFlavour Skim","l"); // DeepFlavour Skim
  //legend12->AddEntry(graphlvsb[26],"DeepCSV phase 0","l");
  legend12->Draw();  
  auto legend13 = new TLegend(0.1419,0.354,0.3422,0.451);
  legend13->AddEntry(graphlvsb[18],"udsg","l");
  legend13->AddEntry(graphcvsb[21],"c","l");
  legend13->Draw();   
  TCanvas *c12 = new TCanvas("c12", "RNN Comp",50,50,1200,900);
  c12->SetGrid();
  graphlvsb[0]->Draw("CA");
  graphcvsb[0]->Draw("same");
  c12->SetLogy();
  auto legend14 = new TLegend(0.1419,0.5384,0.4044,0.6877);
  legend14->AddEntry(graphlvsb[0],"DeepFlavour","l");
  legend14->AddEntry(graphlvsb[31],"DeepFlavour with no RNN","l"); // DeepFlavour Skim
  legend14->Draw();
   TCanvas *c13 = new TCanvas("c13", "ROCS",50,50,1200,900);
  c13->SetGrid();
  graphlvsb[0]->Draw("CA");
  graphcvsb[0]->Draw("same");
  graphlvsb[0]->SetTitle(""); 
  graphlvsb[0]->GetXaxis()->SetTitle("b jet efficiency");
  graphlvsb[0]->GetYaxis()->SetTitle("misid. probability");
  graphlvsb[3]->Draw("same");
  graphcvsb[3]->Draw("same");
  graphlvsb[3]->SetLineColor(kRed);
  graphcvsb[3]->SetLineColor(kRed);
  graphlvsb[0]->SetLineColor(kBlue);
  graphcvsb[0]->SetLineColor(kBlue);
  graphlvsb[0]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphlvsb[0]->GetYaxis()->SetRangeUser(0.00055,1);
  c13->SetLogy();
  CMS_lumi( c13, 0, 11 );
  CMS_LABEL(0.535,0.812);
  TT_LABEL(0.14,0.772);
  PT_LABEL_30(0.14,0.722);
  auto legend15 = new TLegend(0.1419,0.5384,0.4044,0.6877);
  legend15->AddEntry(graphlvsb[0],"DeepFlavour","l");
  legend15->AddEntry(graphlvsb[3],"DeepFlavour Skim","l");
  legend15->Draw();  
  TCanvas *c14 = new TCanvas("c14", "ROCS",50,50,1200,900);
  c14->SetGrid();
  graphlvsb[32]->Draw("CA");
  graphcvsb[32]->Draw("same");
  graphlvsb[32]->SetTitle(""); 
  graphlvsb[32]->GetXaxis()->SetTitle("c jet efficiency");
  graphlvsb[32]->GetYaxis()->SetTitle("misid. probability"); 
  graphlvsb[33]->Draw("same");
  graphcvsb[33]->Draw("same");
  graphlvsb[33]->SetLineColor(kRed);
  graphcvsb[33]->SetLineColor(kRed);
  graphlvsb[32]->SetLineColor(kBlue);
  graphcvsb[32]->SetLineColor(kBlue);
  graphlvsb[32]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphlvsb[32]->GetYaxis()->SetRangeUser(0.00085,1);
  c14->SetLogy();
  CMS_lumi( c14, 0, 11 );
  CMS_LABEL(0.535,0.812);
  TT_LABEL(0.14,0.772);
  PT_LABEL_30(0.14,0.722);
  auto legend16 = new TLegend(0.1419,0.5384,0.4044,0.6877);
  legend16->AddEntry(graphlvsb[0],"DeepFlavour","l");
  legend16->AddEntry(graphlvsb[3],"DeepFlavour Skim","l");
  legend16->Draw();  
  TCanvas *c15 = new TCanvas("c15", "ROCS",50,50,1200,900);
  c15->SetGrid();
  graphlvsb[34]->Draw("CA");
  graphcvsb[34]->Draw("same");
  graphlvsb[34]->SetTitle(""); 
  graphlvsb[34]->GetXaxis()->SetTitle("uds jet efficiency");
  graphlvsb[34]->GetYaxis()->SetTitle("misid. probability"); 
  graphlvsb[35]->Draw("same");
  graphcvsb[35]->Draw("same");
  graphlvsb[35]->SetLineColor(kRed);
  graphcvsb[35]->SetLineColor(kRed);
  graphlvsb[34]->SetLineColor(kBlue);
  graphcvsb[34]->SetLineColor(kBlue);
  graphlvsb[34]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphlvsb[34]->GetYaxis()->SetRangeUser(0.00085,1);
  c15->SetLogy();
  CMS_lumi( c15, 0, 11 );
  CMS_LABEL(0.535,0.812);
  TT_LABEL(0.14,0.772);
  PT_LABEL_30(0.14,0.722);
  auto legend17 = new TLegend(0.1419,0.5384,0.4044,0.6877);
  legend17->AddEntry(graphlvsb[0],"DeepFlavour","l");
  legend17->AddEntry(graphlvsb[3],"DeepFlavour Skim","l");
  legend17->Draw();  



  TCanvas *c16 = new TCanvas("c16", "ROCS",50,50,1200,900);
  c16->SetGrid();
  graphlvsb[37]->Draw("CA");
  graphcvsb[37]->Draw("same");
  graphlvsb[37]->SetTitle(""); 
  graphlvsb[37]->GetXaxis()->SetTitle("b jet efficiency");
  graphlvsb[37]->GetYaxis()->SetTitle("misid. probability"); 
  graphlvsb[36]->Draw("same");
  graphcvsb[36]->Draw("same");


  SF_DF_plot_lvsb_300->Draw("P same");
  SF_DF_plot_cvsb_300->Draw("P same");
  SF_DF_plot_lvsb_300_no_cor->Draw("P same");
  SF_DF_plot_cvsb_300_no_cor->Draw("P same");
  
  SF_DCSV_plot_lvsb_300_no_cor->Draw("P same");
  SF_DCSV_plot_cvsb_300_no_cor->Draw("P same");

  SF_DCSV_plot_lvsb_300->Draw("P same");
  SF_DCSV_plot_cvsb_300->Draw("P same");
  //  graphlvsb[22]->Draw("same");
  //graphcvsb[22]->Draw("same");
  graphlvsb[37]->SetLineColor(kRed);
  graphcvsb[37]->SetLineColor(kRed);
  graphlvsb[36]->SetLineColor(kBlue);
  graphcvsb[36]->SetLineColor(kBlue);
  graphlvsb[37]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphlvsb[37]->GetYaxis()->SetRangeUser(0.005,1);
  c16->SetLogy();
  CMS_lumi( c16, 0, 11 );
  CMS_LABEL(0.266,0.812);
  TT_LABEL(0.14,0.772);
  PT_LABEL_300(0.14,0.722);
  auto legend100 = new TLegend(0.1419,0.5384,0.4044,0.6877);
  legend100->AddEntry(graphlvsb[36],"DeepJet","l");
  legend100->AddEntry(graphlvsb[37],"DeepCSV","l");
  legend100->AddEntry(SF_DF_plot_lvsb_300,"DeepJet with SF applied","lep");
  legend100->AddEntry(SF_DCSV_plot_lvsb_300,"DeepCSV with SF applied","lep");
  legend9->Draw();
  legend8->Draw();  
  //c16->SaveAs("PT_300GeV.pdf");  

  TCanvas *xxx = new TCanvas("xxx", "ROCS",50,50,1500,800);
  xxx->SetGrid();
  graphlvsb[25]->Draw();
  graphlvsb[25]->SetTitle("Comparison on 90GeV perm inv");
  graphcvsb[25]->Draw("same"); 
  graphlvsb[39]->Draw("same");
  graphcvsb[39]->Draw("same");
  graphlvsb[39]->SetLineColor(kRed);
  graphcvsb[39]->SetLineColor(kRed);

}

