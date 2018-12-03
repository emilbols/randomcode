#include <TMultiGraph.h>

void script(){
  const char *dirname="/home/emil/NNStudies/ROCS/multiROC/ReadDir";
  const char *ext=".root";
  TFile *filearray[12] = {};
  TSystemDirectory dir(dirname, dirname);
  TList *files = dir.GetListOfFiles();
  int c = 0;
  if (files) {
    TSystemFile *file;
    TString fname;
    TIter next(files);
    while ((file=(TSystemFile*)next())) {
      fname = file->GetName();
      if (!file->IsDirectory() && fname.EndsWith(ext)) {
	cout << fname.Data() << endl;
	filearray[c] = TFile::Open(fname);
	c++;
      }
    }
  }
  TGraph * graphlvsb[12] = {};
  TGraph * graphcvsb[12] = {};
  for(int z = 0; z < 12; z++){
    graphlvsb[z] = (TGraph*)filearray[z]->Get("roccurve_0");
    graphcvsb[z] = (TGraph*)filearray[z]->Get("roccurve_1");
  }
  auto mg1  = new TMultiGraph();
  auto mg2  = new TMultiGraph();
  for(int z = 0; z < 12; z++){
    mg1->Add(graphlvsb[z]);
    mg2->Add(graphcvsb[z]);
  }
  TFile *hfile13 = TFile::Open("../orgROC.root");  
  TGraph * blDeepCSV = (TGraph*)hfile13->Get("roccurve_0");
  TGraph * cbDeepCSV = (TGraph*)hfile13->Get("roccurve_1");
 
  
  /*
  TFile *hfile1 = TFile::Open("ROC1.root");  
  TFile *hfile2 = TFile::Open("ROC2.root");  
  TFile *hfile3 = TFile::Open("ROC3.root");  
  TFile *hfile4 = TFile::Open("ROC4.root");  
  TFile *hfile5 = TFile::Open("ROC5.root");  
  TFile *hfile6 = TFile::Open("ROC6.root");  
  TFile *hfile7 = TFile::Open("ROC7.root");  
  TFile *hfile8 = TFile::Open("ROC8.root");  
  TFile *hfile9 = TFile::Open("ROC9.root");  
  TFile *hfile10 = TFile::Open("ROC10.root");  
  TFile *hfile11 = TFile::Open("ROC11.root");  
  TFile *hfile12 = TFile::Open("ROC12.root");  
  TGraph * bl1 = (TGraph*)hfile1->Get("roccurve_0");
  TGraph * bl2 = (TGraph*)hfile2->Get("roccurve_0");  
  TGraph * bl3 = (TGraph*)hfile3->Get("roccurve_0");
  TGraph * bl4 = (TGraph*)hfile4->Get("roccurve_0");
  TGraph * bl5 = (TGraph*)hfile5->Get("roccurve_0");
  TGraph * bl6 = (TGraph*)hfile6->Get("roccurve_0");
  TGraph * bl7 = (TGraph*)hfile7->Get("roccurve_0");
  TGraph * bl8 = (TGraph*)hfile8->Get("roccurve_0");
  TGraph * bl9 = (TGraph*)hfile9->Get("roccurve_0");
  TGraph * bl10 = (TGraph*)hfile10->Get("roccurve_0");
  TGraph * bl11 = (TGraph*)hfile11->Get("roccurve_0");
  TGraph * bl12 = (TGraph*)hfile12->Get("roccurve_0");
  TGraph * cb1 = (TGraph*)hfile1->Get("roccurve_1");
  TGraph * cb2 = (TGraph*)hfile2->Get("roccurve_1");  
  TGraph * cb3 = (TGraph*)hfile3->Get("roccurve_1");
  TGraph * cb4 = (TGraph*)hfile4->Get("roccurve_1");
  TGraph * cb5 = (TGraph*)hfile5->Get("roccurve_1");
  TGraph * cb6 = (TGraph*)hfile6->Get("roccurve_1");
  TGraph * cb7 = (TGraph*)hfile7->Get("roccurve_1");
  TGraph * cb8 = (TGraph*)hfile8->Get("roccurve_1");
  TGraph * cb9 = (TGraph*)hfile9->Get("roccurve_1");
  TGraph * cb10 = (TGraph*)hfile10->Get("roccurve_1");
  TGraph * cb11 = (TGraph*)hfile11->Get("roccurve_1");
  TGraph * cb12 = (TGraph*)hfile12->Get("roccurve_1");
  
  TGraph * blDeepCSV = (TGraph*)hfile13->Get("roccurve_0");
  TGraph * cbDeepCSV = (TGraph*)hfile13->Get("roccurve_1");
  auto mg1  = new TMultiGraph();
  auto mg2  = new TMultiGraph();
  mg1->Add(bl1);
  mg1->Add(bl2);
  mg1->Add(bl3);
  mg1->Add(bl4);
  mg1->Add(bl5);
  mg1->Add(bl6);
  mg1->Add(bl7);
  mg1->Add(bl8);
  mg1->Add(bl9);
  mg1->Add(bl10);
  mg1->Add(bl11);
  mg1->Add(bl12);
  mg2->Add(cb1);
  mg2->Add(cb2);
  mg2->Add(cb3);
  mg2->Add(cb4);
  mg2->Add(cb5);
  mg2->Add(cb6);
  mg2->Add(cb7);
  mg2->Add(cb8);
  mg2->Add(cb9);
  mg2->Add(cb10);
  mg2->Add(cb11);
  mg2->Add(cb12);
  */
  double mean1[100] = {};
  double stdsum1[100] = {};
  double std1[100] = {};
  double std12[100] = {};
  double mean2[100] = {};
  double stdsum2[100] = {};
  double std2[100] = {};
  double std22[100] = {};
  double x[100] = {};
  for(int n = 0; n < 100; n++){
    x[n] = n/99.0;
  }
  double size = 12.0;
  TList* grlist1;
  grlist1 = mg1->GetListOfGraphs();
  TIter next(grlist1);
  TObject *obj1;
  TGraph *gr1;
  int l = 0;
  while ((obj1 = next())) {
    gr1=(TGraph*)obj1;
    for(int n = 0; n < 100; n++){
      double z = n/99.0;
      mean1[n] = mean1[n] + gr1->Eval(z)/(size);
    }
  }
  cout << mean1[53] << endl;
  cout << l << endl;
  TList* grlist2;
  grlist2 = mg2->GetListOfGraphs();
  TIter next1(grlist2);
  TObject *obj2;
  TGraph *gr2;
  while ((obj2 = next1())) {
    gr2=(TGraph*)obj2;
    for(int n = 0; n < 100; n++){
      double z = n/99.0;
      mean2[n] = mean2[n] + gr2->Eval(z)/(size);
    }
  }
  TIter next2(grlist2);
  TObject *obj3;
  TGraph *gr3;
  while ((obj3 = next2())) {
    gr3=(TGraph*)obj3;
    for(int n = 0; n < 100; n++){
      double z = n/99.0;
      stdsum2[n] = stdsum2[n] + (gr3->Eval(z)-mean2[n] )*(gr3->Eval(z)-mean2[n] )/(size);
    }
  }
  for(int n = 0; n < 100; n++){
    std2[n] = sqrt(stdsum2[n]);
    std22[n] = std2[n]*2.0;
  }

  TIter next3(grlist1);
  TObject *obj4;
  TGraph *gr4;
  while ((obj4 = next3())) {
    gr4=(TGraph*)obj4;
    for(int n = 0; n < 100; n++){
      double z = n/99.0;
      stdsum1[n] = stdsum1[n] + (gr4->Eval(z)-mean1[n] )*(gr4->Eval(z)-mean1[n] )/(size);
    }
  }
  for(int n = 0; n < 100; n++){
    std1[n] = sqrt(stdsum1[n]);
    std12[n] = std1[n]*2.0;
  }
  
  TCanvas *c1 = new TCanvas("c1", "ROCS",50,50,1500,800);
  c1->SetGrid();
  double zero[100] = {};
  TGraphErrors* ge = new TGraphErrors(100, x, mean1, zero, std1);
  ge->SetTitle("Roc Curve Error band");
  ge->SetFillColor(4);
  ge->SetFillStyle(1001);
  ge->Draw("a C 3");
  ge->GetXaxis()->SetRangeUser(0,1);
  ge->GetYaxis()->SetRangeUser(0.0005,1);
  TGraphErrors* ge1 = new TGraphErrors(100, x, mean1, zero, std12);
  ge1->SetTitle("Roc Curve Error band");
  ge1->SetFillColor(4);
  ge1->SetFillStyle(3001);
  ge1->Draw("C 3 same");

  TGraphErrors* ge2 = new TGraphErrors(100, x, mean2, zero, std2);
  ge2->SetFillColor(2);
  ge2->SetFillStyle(1001);
  ge2->Draw("3 C same");
  //mg1->Draw("C");
  // mg2->Draw("C");
  c1->SetLogy();
  c1->Update();
  TGraphErrors* ge3 = new TGraphErrors(100, x, mean2, zero, std22);
  ge3->SetTitle("Roc Curve Error band");
  ge3->SetFillColorAlpha(kRed,0.0);
  ge3->SetFillStyle(3001);
  ge3->Draw("C 3 same");
  blDeepCSV->Draw("same");
  blDeepCSV->SetLineColor(kBlack);
  cbDeepCSV->Draw("same");
  cbDeepCSV->SetLineColor(kBlack);
   auto legend = new TLegend(0.28,0.7,0.48,0.8);
   legend->AddEntry(ge,"udsg vs b","f");
   legend->AddEntry(ge2,"c vs b","f");
   legend->Draw();
  /*
    for(auto graph = mg2->begin(); graph != mg2->end(); graph++){
      mean2[n] = mean2[n] + graph.eval(n/(100.0*size));
    }
  }
  for(double n = 0; n < 100; n++){ 
    for(auto graph = mg1->begin(); graph != mg1->end(); graph++){
      stdsum1[n] = stdsum1[n] + (graph.eval(n/(100.0)-mean1[n]) );
    }
    for(auto graph = mg2->begin(); graph != mg2->end(); graph++){
      stdsum2[n] = stdsum2[n] + (graph.eval(n/(100.0)-mean2[n]) );
    }
  }
  for(double n = 0; n < 100; n++){
    std1[n] = sqrt(stdsum1[n]*stdsum1[n]/(size-1));
    std2[n] = sqrt(stdsum2[n]*stdsum2[n]/(size-1));
  } 
    */
    /* 
  TCanvas *c1 = new TCanvas("c1", "ROCS",50,50,1500,800);
  c1->SetGrid();
  bl1->Draw();
  bl1->SetTitle("Multi ROCS");
  bl1->GetXaxis()->SetRangeUser(0,1);
  bl1->GetYaxis()->SetRangeUser(0.0003,1);
  bl2->Draw("same");
  bl3->Draw("same");
  bl4->Draw("same");
  bl5->Draw("same");
  bl6->Draw("same");
  bl7->Draw("same");
  bl8->Draw("same");
  bl9->Draw("same");
  bl10->Draw("same");
  bl11->Draw("same");
  bl12->Draw("same");
  cb1->Draw("same");
  cb2->Draw("same");
  cb3->Draw("same");
  cb4->Draw("same");
  cb5->Draw("same");
  cb6->Draw("same");
  cb7->Draw("same");
  cb8->Draw("same");
  cb9->Draw("same");
  cb10->Draw("same");
  cb11->Draw("same");
  cb12->Draw("same");
  c1->SetLogy();
    */
}
