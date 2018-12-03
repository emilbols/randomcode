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
  lumi_sqrtS = "#sqrt{s} = 13 TeV";
  TFile * files[29] = {};
  files[0] = TFile::Open("DeepFlavour10Xon10X.root");
  files[1] = TFile::Open("DeepFlavour10Xon94X.root"); //DeepFlavour210Xon10XTTBar
  files[2] = TFile::Open("DeepFlavour94Xon94X.root");
  files[3] = TFile::Open("DeepFlavour94Xon10X.root");
  files[4] = TFile::Open("DeepFlavour94Xon94XLept.root");
  files[5] = TFile::Open("DeepFlavour10Xon94XLept.root");
  files[6] = TFile::Open("DeepFlavour10XNoPuppi.root");
  files[7] = TFile::Open("DeepFlavour10XQCD.root");
  files[8] = TFile::Open("DeepFlavour94XQCD.root");
  files[9] = TFile::Open("DeepFlavour10Xon10XQCD700Pt.root");
  files[10] = TFile::Open("DeepFlavour94Xon10XQCD700Pt.root"); //DeepFlavour210Xon10XQCDHighPT
//DeepFlavour10XQCDHighPT
  //DeepFlavour94XQCDHighPT.root
  files[11] = TFile::Open("DeepCSV10XTestTTBar.root");
  files[12] = TFile::Open("DeepCSV94x.root"); // DeepCSV94x.root
  files[13] = TFile::Open("DeepFlavour94XttBarHighPT.root"); //DeepFlavour210Xon10XTTBarHighPt.root
  files[14] = TFile::Open("DeepFlavour10XttBarHighPT.root");
  files[15] = TFile::Open("DeepFlavour94Xon10XTTBar400Pt.root");
  files[16] = TFile::Open("DeepFlavour10Xon10XTTBar400Pt.root");
  files[17] = TFile::Open("DeepFlavour210Xon10XTTBar400Pt.root");
  
  files[18] = TFile::Open("DeepFlavour94XNoLeptTTBarFinal.root");
  files[19] = TFile::Open("DeepFlavour94XNoLeptReallyEarlyTTBar200PT.root");

  files[20] = TFile::Open("DeepFlavour210Xon10XTTBar.root");
  
  files[21] = TFile::Open("DeepFlavour94XNoLeptQCD360.root");
  files[22] = TFile::Open("DeepCSV8XTT30GeVClean.root");
  files[23] = TFile::Open("DeepCSV8XTT90GeVClean.root");
  files[24] = TFile::Open("DeepCSV94XTTBar90GeV.root");
  files[25] = TFile::Open("DeepFlavour10XTTbar90GeV.root");
  files[26] = TFile::Open("DeepCSV8XTT200GeV.root");
  files[27] = TFile::Open("DeepCSV94XTTBar200GeV.root");
  files[28] = TFile::Open("DeepFlavour10XTTbar200GeV.root ");



  TGraph * graphlvsb[29] = {};
  TGraph * graphcvsb[29] = {};
  auto mg1  = new TMultiGraph();
  auto mg2  = new TMultiGraph();
  for(int z = 0; z < 29; z++){
    graphlvsb[z] = (TGraph*)files[z]->Get("roccurve_0");
    graphlvsb[z]->SetLineColor(kRed+z);
    graphcvsb[z] = (TGraph*)files[z]->Get("roccurve_1");
    graphcvsb[z]->SetLineColor(kRed+z);
    graphcvsb[z]->SetLineStyle(7); 
  }
  TCanvas *c1 = new TCanvas("c1", "ROCS",50,50,1500,800);
  c1->SetGrid();
  graphlvsb[1]->SetLineColor(kBlue);
  graphcvsb[1]->SetLineColor(kBlue);
  graphlvsb[2]->SetLineColor(kGreen);
  graphcvsb[2]->SetLineColor(kGreen);
  graphlvsb[3]->SetLineColor(kOrange);
  graphcvsb[3]->SetLineColor(kOrange);
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
  graphlvsb[1]->Draw("same");
  graphcvsb[0]->Draw("same");
  graphcvsb[1]->Draw("same");
  graphlvsb[2]->Draw("same");
  graphcvsb[2]->Draw("same");
  graphlvsb[3]->Draw("same");
  graphcvsb[3]->Draw("same");
  //   graphlvsb[18]->Draw("same");
  // graphcvsb[18]->Draw("same"); 
  auto legend = new TLegend(0.28,0.65,0.48,0.8);
  legend->AddEntry(graphcvsb[0],"10X training on 10X","l");
  legend->AddEntry(graphcvsb[1],"10X training on 94X","l");
  legend->AddEntry(graphcvsb[2],"94X training on 94X","l");
  legend->AddEntry(graphcvsb[3],"94X training on 10X","l");
  //legend->AddEntry(graphcvsb[18],"94X no lept training on 10X","l");
  legend->Draw();

  TCanvas *c2 = new TCanvas("c2", "ROCS",50,50,1500,800);
  c2->SetGrid();
  graphlvsb[4]->Draw();
  graphlvsb[4]->GetXaxis()->SetTitle("b-jet efficiency");
  graphlvsb[4]->GetYaxis()->SetTitle("mistag rate");  
  graphlvsb[4]->SetTitle("DeepFlavour evaluated on tt-bar leptonic MC");
  graphcvsb[4]->Draw("same"); 
  graphcvsb[4]->SetLineStyle(9); 
  graphlvsb[5]->Draw("same");
  graphcvsb[5]->Draw("same");
  graphcvsb[5]->SetLineStyle(9);
  auto legend1 = new TLegend(0.28,0.65,0.48,0.8);
  legend1->AddEntry(graphlvsb[4],"94X training","l");
  legend1->AddEntry(graphlvsb[5],"10X training","l");
  legend1->Draw(); 

  TCanvas *c3 = new TCanvas("c3", "ROCS",50,50,1500,800);
  c3->SetGrid();
  graphlvsb[0]->Draw();
  graphcvsb[0]->Draw("same"); 
  graphlvsb[6]->Draw("same");
  graphcvsb[6]->Draw("same");

  auto legend2 = new TLegend(0.28,0.65,0.48,0.8);
  legend2->AddEntry(graphcvsb[0],"10X training with puppi weights","l");
  legend2->AddEntry(graphcvsb[6],"10X training without puppi weights","l");
  legend2->Draw(); 

  TCanvas *c4 = new TCanvas("c4", "ROCS",50,50,1500,800);
  c4->SetGrid();
  graphlvsb[7]->Draw();
  graphlvsb[7]->SetTitle("Comparison on 94X QCD 120 to 170 GeV");
  graphcvsb[7]->Draw("same"); 
  graphlvsb[8]->Draw("same");
  graphcvsb[8]->Draw("same");

  auto legend3 = new TLegend(0.28,0.65,0.48,0.8);
  legend3->AddEntry(graphcvsb[7],"10X training on 94X QCD 120 to 170 GeV","l");
  legend3->AddEntry(graphcvsb[8],"94X training on 94X QCD 120 to 170 GeV","l");
  legend3->Draw();

  TCanvas *c5 = new TCanvas("c5", "ROCS",50,50,1500,800);
  c5->SetGrid();
  graphlvsb[9]->Draw();
  graphlvsb[9]->SetTitle("Comparison on 10X QCD pt > 700GeV");
  graphcvsb[9]->Draw("same"); 
  graphlvsb[10]->Draw("same");
  graphcvsb[10]->Draw("same"); 
 // graphlvsb[21]->Draw("same");
 // graphcvsb[21]->Draw("same");

  auto legend4 = new TLegend(0.28,0.65,0.48,0.8);
  legend4->AddEntry(graphcvsb[9],"10X training on 10X QCD pt > 700GeV","l");
  legend4->AddEntry(graphcvsb[10],"94X training on 10X QCD pt > 700GeV","l");
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
  graphlvsb[22]->Draw("same");
  graphcvsb[22]->Draw("same");
  graphcvsb[22]->SetLineWidth(2);
  graphlvsb[22]->SetLineWidth(2);      
  graphlvsb[12]->SetLineColor(kRed);
  graphcvsb[12]->SetLineColor(kRed);
  graphlvsb[1]->SetLineColor(kBlue);
  graphcvsb[1]->SetLineColor(kBlue);
  graphlvsb[22]->SetLineColor(kGreen+3);
  graphcvsb[22]->SetLineColor(kGreen+3);
  graphlvsb[12]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphlvsb[12]->GetYaxis()->SetRangeUser(0.00085,1);
  c9->SetLogy();
  CMS_lumi( c9, 0, 11 );
  CMS_LABEL(0.535,0.822);
  TT_LABEL(0.14,0.772);
  PT_LABEL_30(0.14,0.722);
  auto legend9 = new TLegend(0.1419,0.5384,0.4044,0.6877);
  legend9->AddEntry(graphlvsb[1],"DeepFlavour phase 1","l");
  legend9->AddEntry(graphlvsb[12],"DeepCSV phase 1","l");
  legend9->AddEntry(graphlvsb[22],"DeepCSV phase 0","l");
  legend9->Draw();  
  auto legend8 = new TLegend(0.1419,0.354,0.3422,0.451);
  legend8->AddEntry(graphlvsb[18],"udsg","l");
  legend8->AddEntry(graphcvsb[21],"c","l");
  legend8->Draw();  
  c9->Update();
  //c9->SaveAs("PT30GeV.C");
  TCanvas *c10 = new TCanvas("c10", "ROCS",50,50,1200,900);
  c10->SetGrid();
  graphlvsb[24]->Draw("CA");
  graphcvsb[24]->Draw("same");
  graphlvsb[24]->SetTitle(""); 
  graphlvsb[24]->GetXaxis()->SetTitle("b jet efficiency");
  graphlvsb[24]->GetYaxis()->SetTitle("misid. probability"); 
  graphlvsb[23]->Draw("same");
  graphcvsb[23]->Draw("same");
  graphlvsb[25]->Draw("same");
  graphcvsb[25]->Draw("same");
  graphcvsb[23]->SetLineWidth(2);
  graphlvsb[23]->SetLineWidth(2);      
  graphlvsb[24]->SetLineColor(kRed);
  graphcvsb[24]->SetLineColor(kRed);
  graphlvsb[25]->SetLineColor(kBlue);
  graphcvsb[25]->SetLineColor(kBlue);
  graphlvsb[23]->SetLineColor(kGreen+3);
  graphcvsb[23]->SetLineColor(kGreen+3);
  graphlvsb[24]->GetXaxis()->SetRangeUser(0.0,1.0);
  graphlvsb[24]->GetYaxis()->SetRangeUser(0.00085,1);
  c10->SetLogy();
  CMS_lumi( c10, 0, 11 );
  CMS_LABEL(0.535,0.822);
  TT_LABEL(0.14,0.772);
  PT_LABEL_90(0.14,0.722);
  auto legend10 = new TLegend(0.1419,0.5384,0.4044,0.6877);
  legend10->AddEntry(graphlvsb[25],"DeepFlavour phase 1","l");
  legend10->AddEntry(graphlvsb[24],"DeepCSV phase 1","l");
  legend10->AddEntry(graphlvsb[23],"DeepCSV phase 0","l");
  legend10->Draw();  
  auto legend11 = new TLegend(0.1419,0.354,0.3422,0.451); //0.712,0.1308,0.8906,0.2273
  legend11->AddEntry(graphlvsb[18],"udsg","l");
  legend11->AddEntry(graphcvsb[21],"c","l");
  legend11->Draw();
  c10->Update();
  // c10->SaveAs("PT90GeV.C");
  TCanvas *c11 = new TCanvas("c11", "ROCS",50,50,1200,900);
  c11->SetGrid();
  graphlvsb[27]->Draw("CA");
  graphcvsb[27]->Draw("same");
  graphlvsb[27]->SetTitle(""); 
  graphlvsb[27]->GetXaxis()->SetTitle("b jet efficiency");
  graphlvsb[27]->GetYaxis()->SetTitle("misid. probability"); 
  graphlvsb[26]->Draw("same");
  graphcvsb[26]->Draw("same");
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
  CMS_LABEL(0.535,0.822);
  TT_LABEL(0.14,0.772);
  PT_LABEL_200(0.14,0.722);
  auto legend12 = new TLegend(0.1419,0.5384,0.4044,0.6877);
  legend12->AddEntry(graphlvsb[28],"DeepFlavour phase 1","l");
  legend12->AddEntry(graphlvsb[27],"DeepCSV phase 1","l");
  legend12->AddEntry(graphlvsb[26],"DeepCSV phase 0","l");
  legend12->Draw();  
  auto legend13 = new TLegend(0.1419,0.354,0.3422,0.451);
  legend13->AddEntry(graphlvsb[18],"udsg","l");
  legend13->AddEntry(graphcvsb[21],"c","l");
  legend13->Draw();   
  
}
