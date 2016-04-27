#include <iostream>
#include <fstream>
#include <iomanip>

//using namespace std;

#include "TCanvas.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TProfile.h"
#include "TBenchmark.h"
#include "TStyle.h"
#include "TPaveText.h"
#include "TFrame.h"
#include "TF1.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TInterpreter.h"
#include "TStyle.h"
#include "TH1.h"
#include "TH2.h"
#include "TMath.h"
#include "TTree.h"
#include "TH1F.h"


#include "TChain.h"
using namespace std;


void tdiff(int prun)

{
gStyle->SetOptStat(0);
gStyle->SetOptFit(1);
gStyle->SetStatH(0.3);

//TChain *event = new TChain("event","");
//event->Add("./data/prim_ana6487?t.root/tagger/cmpt_ntuple");

/*

int main(int argc, char** argv)
{
  int run = atoi(argv[1]);
  TFile *f1 = new TFile(Form("/home/mepmsu/Desktop/premex-2/analysis/data/prim_ana%dt.root",run),"r");

 */
  
  const int kMax = 1000;

  float run, evn;

  float Eid;
  float tid;      // Tcounter channel ID
  float tdiff;   //time difference between Hycal and Tcounter 
  float eg;      // incoming photon energy
  float e1;      // cluster 1 energy
  float x1;      // cluster 1 x position
  float y1;      // cluster 1 y position
  float e0;     
  float e2;      // cluster 2 energy
  float x2;      // cluster 2 x position
  float y2;      // cluster 2 y position

  /*
  float  id1, id2, type1, type2;
  float invm[kMax], angle[kMax];
  */
  float PI=3.1415927;	
  

  TFile *f1 = new TFile(Form("./data/prim_ana%dt.root",prun),"r");
  TDirectory *dd = (TDirectory*)f1->Get("tagger");
  TNtuple *event = (TNtuple*) dd->Get("cmpt_ntuple");
 
  

  //TDirectory *dd = (TDirectory*)f1->Get("tagger");
  // TNtuple *event = (TNtuple*) dd->Get("cmpt_ntuple");

  //    event->SetBranchStatus("run",0);
  	
  event->SetBranchAddress("run", &run);
  event->SetBranchAddress("evn", &evn);
  event->SetBranchAddress("tdiff", &tdiff);
  event->SetBranchAddress("tid", &tid);
 // event->SetBranchAddress("Eid", &Eid);
  event->SetBranchAddress("eg",&eg);
  //event->SetBranchAddress("id1",&id1);
  //event->SetBranchAddress("id2",&id2);
  //  event->SetBranchAddress("type1",type1);
  //  event->SetBranchAddress("type2",type2);
  event->SetBranchAddress("x1",&x1);
  event->SetBranchAddress("y1",&y1);
  event->SetBranchAddress("x2",&x2);
  event->SetBranchAddress("y2",&y2);
  event->SetBranchAddress("e1",&e1);
  event->SetBranchAddress("e2",&e2);
 // event->SetBranchAddress("e0",&e0);


  TH1F *h_E = new TH1F("h_E","E0 = eg - e1 -e2",1300,-2,5);
  TH1F *h_x = new TH1F("h_x","X position",60,-30,30);
  TH1F *h_sep = new TH1F("h_sep","Cluster Separation",500,-50,50);
  TH1F *h_angle = new TH1F("h_angle","Azimuthal Angle Difference",600,-240,240);
  TH1F *h_z = new TH1F("h_z","Z position",600,-30,1200);

  TH1F *h_tdiff[18];
  char hName[255],hTitle[255];
for(int i=0;i<18;i++) 
{
	sprintf(hName,"tdiff%02d",i);
	sprintf(hTitle,"tdiff%02d",i);
	h_tdiff[i] = new TH1F(hName,hTitle,140,-8,6);  
}

	
  TH2F *h_x_y_1 = new TH2F("h_x_y_1"," XY position for cluster1", 200,-20,20,500,-20,20);
  TH2F *h_x_y_2 = new TH2F("h_x_y_2"," XY position for cluster2", 200,-20,20,500,-20,20);
  TH2F *h_sep_2d = new TH2F("h_sep_2d"," Cluster Separation", 200,-40,40,200,-40,40);
  TH1F *h_cosphi = new TH1F("h_cosphi","cosphi",600,0,4);


	 

  int nevents = event->GetEntries();
  //	  int nevents = 300;
  cout<<"number of events: "<<nevents<<endl;
  for(int i=1;i<=nevents;i++) {
    // if(i%100000==0)cout<<i<<endl;
    //Progress bar
    Double_t  entries=nevents;
    Double_t ratio = i/(Double_t)entries;
    cout<<setw(8)<<(int)(ratio*100)<<"%\r"<<flush;
    event->GetEntry(i);
   

 float angle_diff=0,  angle1_a=0 , angle2_a=0, sep=0, sep_x=0, sep_y=0 ;
	
    float r1=0,r2=0;
	
    float e0 =0;
    //========== Z position reconstruction ==========//	
    double z;
    double a = 1.0 - (0.5109989e-3*eg)/e1/e2;
    double b = (x1*x1*x2*x2 + x1*x1*y2*y2 + y1*y1*x2*x2 + y1*y1*y2*y2);
    double c = (x1*x1 + y1*y1 + x2*x2 + y2*y2);
    double d = (x1*x1*x2*x2 + y1*y1*y2*y2 + 2*x1*x2*y1*y2);
    double e = x1*x2 + y1*y2;
    double A = a*a - 1;
    double B = a*a*c - 2*e;
    double C = a*a*b - d;
    double t = (- B - sqrt(B*B - 4*A*C))/2./A;
    if (t >= 0) {
      z = sqrt(t);
    } else {
      z = -100.;}

    if ( x1 >0 ) {  angle1_a = atan(y1/x1)*180.0/PI;  }
    if ( x1 <0 ) {  angle1_a = atan(y1/x1)*180.0/PI + 180.0 ; }
    if ( x2 >0 ) {  angle2_a = atan(y2/x2)*180.0/PI; } 
    if ( x2 <0 ) {  angle2_a = atan(y2/x2)*180.0/PI + 180.0 ; }

    float angle_diff0 = angle1_a - angle2_a;
    if ( angle_diff0 > 0 ) { angle_diff = angle_diff0;}
    if ( angle_diff0 <= 0 ) { angle_diff = -angle_diff0;} 


    sep_x = x1-x2 ;
    sep_y = y1-y2 ;
    sep = sqrt(sep_x*sep_x + sep_y*sep_y);
    e0 = eg -e1 -e2 ;	
   
 //============= Tdiff alienment =============//
   
    if (tid > 36 ) continue;
    if (abs(x1)< 4.154 && abs(y1)< 4.154) continue;
    if (abs(x1)> 32.2 && abs(y1)>32.2) continue;
    if (abs(x2)< 4.154 && abs(y2)< 4.154) continue;	
    if (abs(x2)> 32.2 && abs(y2)> 32.2) continue;
    if (e1 < 0.5 || e2 <0.5 ) continue;
    if (e1+e2 <=2.5 ) continue;

    //  if (Tdiff_a < -6.0 || Tdiff_a > 4.0) continue;
    if (angle_diff < 140.0 || angle_diff > 220.0 ) continue;  
        
    if (sep < 18.0 ) continue;
    if (e0 > 1.0 || e0 < -1.0 ) continue;

     
   	int idx=int((tid-1)/2);
	if(idx<18) h_tdiff[idx]->Fill(tdiff);
  }
	
	double mean, sigma, xmin=0, xmax=0;
	TF1 *gaus=0;
	TCanvas *c1 = new TCanvas("c1","XY position",1200,800);
	c1->Divide(4,5);
	for(int i=0;i<18;i++)
	{
	  	c1->cd(i+1);
	   	xmin=-6.0, xmax=2.0;
	  	h_tdiff[i]->Draw();
		h_tdiff[i]->Fit("gaus","QR","",xmin,xmax);
		gaus = (TF1*) h_tdiff[i]->GetListOfFunctions()->FindObject("gaus");
		mean = gaus->GetParameter(1);
		sigma = gaus->GetParameter(2);
		xmin = mean - 2.5*sigma;
		xmax = mean + 2.5*sigma;
		h_tdiff[i]->Fit("gaus","R","",xmin,xmax);
		gaus = (TF1*) h_tdiff[i]->GetListOfFunctions()->FindObject("gaus");
		mean = gaus->GetParameter(1);
		sigma = gaus->GetParameter(2);
//cout <<prun<<" "<< "Tid= "<<i<< "mean= "<<mean<<endl;		

 
	}
	c1->cd(0);
	c1->Draw();

//c1->SaveAs(Form("tdiff_alignment_r%d.png",prun));
}













