#include <TMultiGraph.h>

void errors(){
  const char *dirname="/home/emil/NNStudies/ROCS/multiROC/DFRead";
  const char *ext=".root";
  TFile *filearray[4] = {};
  TSystemDirectory dir(dirname, dirname);
  TList *files = dir.GetListOfFiles();
  ///home/emil/NNStudies/10XTrainingStudies/10XTrainingsPlot/DeepFlavour10Xon94X.root
  TFile * letsgo = TFile::Open("/home/emil/NNStudies/10XTrainingStudies/10XTrainingsPlot/DeepFlavour10Xon10X.root");
  TGraph * one = (TGraph*)letsgo->Get("roccurve_0");
  TGraph * two = (TGraph*)letsgo->Get("roccurve_1");
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
  TGraph * graphlvsb[4] = {};
  TGraph * graphcvsb[4] = {};
  for(int z = 0; z < 4; z++){
    graphlvsb[z] = (TGraph*)filearray[z]->Get("roccurve_0");
    graphcvsb[z] = (TGraph*)filearray[z]->Get("roccurve_1");
  }
  auto mg1  = new TMultiGraph();
  auto mg2  = new TMultiGraph();
  for(int z = 0; z < 4; z++){
    mg1->Add(graphlvsb[z]);
    mg2->Add(graphcvsb[z]);
  }
  const int points = 200;
  double mean1[points] = {};
  double stdsum1[points] = {};
  double std1[points] = {};
  double std12[points] = {};
  double mean2[points] = {};
  double stdsum2[points] = {};
  double std2[points] = {};
  double std22[points] = {};
  double x[points] = {};
  for(int n = 0; n < points; n++){
    x[n] = n/(points - 1.0);
  }
  double size = 4.0;
  TList* grlist1;
  grlist1 = mg1->GetListOfGraphs();
  TIter next(grlist1);
  TObject *obj1;
  TGraph *gr1;
  int l = 0;
  while ((obj1 = next())) {
    gr1=(TGraph*)obj1;
    for(int n = 0; n < points; n++){
      double z = n/(points - 1.0);
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
    for(int n = 0; n < points; n++){
      double z = n/(points - 1.0);
      mean2[n] = mean2[n] + gr2->Eval(z)/(size);
    }
  }
  TIter next2(grlist2);
  TObject *obj3;
  TGraph *gr3;
  while ((obj3 = next2())) {
    gr3=(TGraph*)obj3;
    for(int n = 0; n < points; n++){
      double z = n/(points - 1.0);
      stdsum2[n] = stdsum2[n] + (gr3->Eval(z)-mean2[n] )*(gr3->Eval(z)-mean2[n] )/(size);
    }
  }
  for(int n = 0; n < points; n++){
    std2[n] = sqrt(stdsum2[n]);
    std22[n] = std2[n]*2.0;
  }

  TIter next3(grlist1);
  TObject *obj4;
  TGraph *gr4;
  while ((obj4 = next3())) {
    gr4=(TGraph*)obj4;
    for(int n = 0; n < points; n++){
      double z = n/(points - 1.0);
      stdsum1[n] = stdsum1[n] + (gr4->Eval(z)-mean1[n] )*(gr4->Eval(z)-mean1[n] )/(size);
    }
  }
  for(int n = 0; n < points; n++){
    std1[n] = sqrt(stdsum1[n]);
    std12[n] = std1[n]*2.0;
  }
  
  TCanvas *c1 = new TCanvas("c1", "ROCS",50,50,1500,800);
  c1->SetGrid();
  double zero[points] = {};
  TGraphErrors* ge = new TGraphErrors(points, x, mean1, zero, std1);
  ge->SetTitle("DeepFlavour Sensitivity to Initialization of Weights");
  ge->SetFillColor(kBlue+2);
  ge->SetFillStyle(1001);
  ge->Draw("a C 3");
  ge->GetXaxis()->SetRangeUser(0,1);
  ge->GetXaxis()->SetTitle("b-jet efficiency");
  ge->GetYaxis()->SetTitle("misid. probability");
  ge->GetYaxis()->SetRangeUser(0.0005,1);
  TGraphErrors* ge1 = new TGraphErrors(points, x, mean1, zero, std12);
  ge1->SetTitle("DeepFlavour spread due to initialization");
  ge1->SetFillColor(kBlue);
  ge1->SetFillStyle(3001);
  ge1->Draw("C 3 same");

  TGraphErrors* ge2 = new TGraphErrors(points, x, mean2, zero, std2);
  ge2->SetFillColor(kRed+2);
  ge2->SetFillStyle(1001);
  ge2->Draw("3 C same");
 // mg1->Draw("AC");
 // mg2->Draw("C");
  c1->SetLogy();
  c1->Update();
  TGraphErrors* ge3 = new TGraphErrors(points, x, mean2, zero, std22);
  ge3->SetTitle("");
  //ge3->SetFillColorAlpha(kRed,0.0);
  ge3->SetFillColor(kRed);
  ge3->SetFillStyle(3001);
  ge3->Draw("C 3 same");
  //one->Draw("same");
  //two->Draw("same");
  one->SetLineColor(kGreen+2);
  two->SetLineColor(kGreen+2);

  /*
  blDeepCSV->Draw("same");
  blDeepCSV->SetLineColor(kBlack);
  cbDeepCSV->Draw("same");
  cbDeepCSV->SetLineColor(kBlack);
  */
  double val = 0.0;
  double y = 0.0;
  double yc = 0.0;
  double wp[3] = {0.001,0.01,0.1};
  double lvsbwp[3] = {};
  double cvsbwp[3] = {};

    y = 0.0;
    yc = 0.0;
    for(int n = 0; n<points; n++){
      val = n*(1.0/(points - 1.0));
      y = ge1->Eval(val);
      yc = ge2->Eval(val);
      if( std::abs(y-0.1) < 0.002){
	lvsbwp[0] = std1[n];
      }
      if( std::abs(y-0.01) < 0.001){
	lvsbwp[1] = std1[n];
      }
      if( std::abs(y-0.001) < 0.001){
	lvsbwp[2] = std1[n];
      }
      if( std::abs(yc-0.1) < 0.002){
	cvsbwp[0] = std2[n];
      }
      if( std::abs(yc-0.01) < 0.001){
	cvsbwp[1] = std2[n];
      }
      if( std::abs(yc-0.001) < 0.001){
	cvsbwp[2] = std2[n];
      }      

    }
  

  auto legend = new TLegend(0.28,0.65,0.48,0.8);
  legend->AddEntry(ge,"udsg 1#sigma","f");
  legend->AddEntry(ge1,"udsg 2#sigma","f");
  legend->AddEntry(ge2,"c 1#sigma","f");
  legend->AddEntry(ge3,"c 2#sigma","f");

  legend->Draw();
}
