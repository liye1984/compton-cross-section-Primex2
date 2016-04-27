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
#include "TMultiGraph.h"
#include "TGraphErrors.h"
#include "TChain.h"
using namespace std;


void flux()

{
  gStyle->SetOptStat(1);
  //  gStyle->SetOptFit(1);
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
  float Dyield[181],MCyield[181],Ecounter[181],Nor_MCyield[181];
  float Ec[20],flux_eid[181],flux_Bin[18],input_Bin[18];
  float Energy[18],Ecross[18],Rcross[18],ratio[200],Acc[180],Nor_Acc[18];
  float NEid[18],Binwidth[18];
  float MC_E[18],MC_cross[18];
  float cross_error[18],Acc_error[180],Acc_error_plot[180],flux_total[180];
  float flux_Bin1[18],flux_Bin2[18],flux_Bin3[18],flux_Bin4[18],flux_Bin5[18],flux_Bin6[18],flux_Bin7[18],flux_Bin8[18],flux_Bin9[18];
  float E_channel[180];  
  float Acc_Bin[18],Acc_bin_sum[18];

  float flux_total_empty = 0;
  float flux_total_data = 0;	
  const float Na =  6.02214e+23;
  const float Ne = (2.1236)*Na/2.0 ; 

  //===========  E-counter energy ======================//
  
  Energy[0]= 5.281;	Energy[1]= 5.241;	Energy[2]= 5.195;
  Energy[3]= 5.145;	Energy[4]= 5.093;	Energy[5]= 5.041;
  Energy[6]= 4.988;	Energy[7]= 4.937;	Energy[8]= 4.883;
  Energy[9]= 4.827;	Energy[10]= 4.774;	Energy[11]= 4.726;
  Energy[12]= 4.673;	Energy[13]= 4.609;	Energy[14]= 4.554;
  Energy[15]= 4.503;	Energy[16]= 4.459;	Energy[17]= 4.400;

  



  Binwidth[0] = 0.03904;	Binwidth[1] = 0.04032;	Binwidth[2] = 0.04889;
  Binwidth[3] = 0.05197;	Binwidth[4] = 0.05209;	Binwidth[5] = 0.05153;
  Binwidth[6] = 0.05387;	Binwidth[7] = 0.05119;	Binwidth[8] = 0.05647;
  Binwidth[9] = 0.05566;	Binwidth[10]= 0.05242;	Binwidth[11]= 0.04564;
  Binwidth[12]= 0.02215;	Binwidth[13]= 0.05520;	Binwidth[14]= 0.05663;
  Binwidth[15]= 0.05357;	Binwidth[16]= 0.04049;	Binwidth[17]= 0.05416;


  MC_E[0]= 5.2864;	MC_E[1]= 5.2399;	MC_E[2]= 5.1977;
  MC_E[3]= 5.1484;	MC_E[4]= 5.0959;	MC_E[5]= 5.0451;
  MC_E[6]= 4.9920;	MC_E[7]= 4.9377;	MC_E[8]= 4.8826;
  MC_E[9]= 4.8308;	MC_E[10]= 4.7775;	MC_E[11]= 4.7214;
  MC_E[12]= 4.6676;	MC_E[13]= 4.6115;	MC_E[14]= 4.5565;
  MC_E[15]= 4.5003;	MC_E[16]= 4.4473;	MC_E[17]= 4.3925;
  
  MC_cross[0]= 0.26040;		MC_cross[1]= 0.26245;	MC_cross[2]= 0.26434;
  MC_cross[3]= 0.26659;		MC_cross[4]= 0.26905;	MC_cross[5]= 0.27158;
  MC_cross[6]= 0.27412;		MC_cross[7]= 0.27677;	MC_cross[8]= 0.27957;
  MC_cross[9]= 0.28228;		MC_cross[10]= 0.28503;	MC_cross[11]= 0.28807;
  MC_cross[12]= 0.29104;	MC_cross[13]= 0.29428;	MC_cross[14]= 0.29763;
  MC_cross[15]= 0.30072;	MC_cross[16]= 0.30394;	MC_cross[17]= 0.30728;

for (int i=0;i<180;i++){ E_channel[i] = i;}
for (int i=0;i<180;i++){ Acc[i] = 0;
 			 Acc_error[i] = 0;  Acc_error_plot[i] = 0;
                       }
 
 
  vector <int> gEEid;
  vector <float> gEinput;
  vector <float> gEEflux1;
  vector <float> gEEflux2;
  vector <float> gEEflux3;
  vector <float> gEEflux4;
  vector <float> gEEflux5;
  vector <float> gEEflux6;
  vector <float> gEEflux7;
  vector <float> gEEflux8;
  vector <float> gEEflux9;

  TH1F *h_eid_mc = new TH1F("h_eid_mc","Eid_MC",200,-10,190);


  //  ifstream INPUT_file;
  //   INPUT_file.open(Form("/home/mepmsu/Desktop/premex-2/analysis/flux/eflux_%05d.dat",prun));
  //  if( !INPUT_file)cout<<"ERROR!!!! CAN'T OPEN input file for run "<<prun<<endl;
 


  ifstream INPUT_fileb;
  //INPUT_fileb.open("/home/mepmsu/Desktop/premex-2/analysis/mcinput/MCinput_sum50.txt");
  INPUT_fileb.open("/home/mepmsu/Desktop/premex-2/analysis/mcinput/ge10001.hbk.estat");

  if( !INPUT_fileb)cout<<"ERROR!!!! CAN'T OPEN input  mcinput file for run "<<endl;

  char strline1[2561];
  int m=0;
  float inputN;

  while(!INPUT_fileb.eof())
    {
      INPUT_fileb>>inputN;
      INPUT_fileb.getline(strline1,2560);
     
      gEinput.push_back(inputN);
	

      //	cout<<"eflux="<<eflux<<"; "<<endl;
      m++;
    }
   
  //   for(int i=0;i<180;i++) cout<<gEinput[i]<<" =="<< i <<endl;
 
  for(int k=0;k<18;k++)
    { 
      input_Bin[k]=0;
      for (int kk=0;kk<10;kk++)
	{ 
	  int kkk = kk + 10*k;
	  input_Bin[k] = input_Bin[k]+ gEinput[kkk];

	  //	  cout << gEEflux[kkk] <<"  " << kkk << endl;
	}
  
      //    cout << input_Bin[k] <<"  " << k << endl;

    }
  


  ifstream INPUT_file1;
  ifstream INPUT_file2;
  ifstream INPUT_file3;
  ifstream INPUT_file4;
  ifstream INPUT_file5;
  ifstream INPUT_file6;
  ifstream INPUT_file7;
  ifstream INPUT_file8;
  ifstream INPUT_file9;

  INPUT_file1.open("/home/mepmsu/Desktop/premex-2/analysis/flux/eflux_64876.dat");
  INPUT_file2.open("/home/mepmsu/Desktop/premex-2/analysis/flux/eflux_64877.dat");
  INPUT_file3.open("/home/mepmsu/Desktop/premex-2/analysis/flux/eflux_64878.dat");
  INPUT_file4.open("/home/mepmsu/Desktop/premex-2/analysis/flux/eflux_64879.dat");
  INPUT_file5.open("/home/mepmsu/Desktop/premex-2/analysis/flux/eflux_64880.dat");
  INPUT_file6.open("/home/mepmsu/Desktop/premex-2/analysis/flux/eflux_64881.dat");
  INPUT_file7.open("/home/mepmsu/Desktop/premex-2/analysis/flux/eflux_64882.dat");
  INPUT_file8.open("/home/mepmsu/Desktop/premex-2/analysis/flux/eflux_64883.dat");
  INPUT_file9.open("/home/mepmsu/Desktop/premex-2/analysis/flux/eflux_64885.dat");



  char strline[2561];
  int n=0, runnumber,eid;
  float eflux;

  while(!INPUT_file1.eof())
    {
      INPUT_file1>>runnumber>>eid>>eflux;
      INPUT_file1.getline(strline,2560);
     
      gEEid.push_back(eid);
      gEEflux1.push_back(eflux);

      n++;
    }
   
  
  for(int k=0;k<18;k++)
    { 
      flux_Bin1[k]=0;
      for (int kk=0;kk<10;kk++)
	{ 
	  int kkk = kk + 10*k;
	  flux_Bin1[k] = flux_Bin1[k]+ gEEflux1[kkk];

	  //	  cout << gEEflux[kkk] <<"  " << kkk << endl;
	}
  
      //   cout << flux_Bin[k] <<"  " << k << endl;

    }
  

  while(!INPUT_file2.eof())
    {
      INPUT_file2>>runnumber>>eid>>eflux;
      INPUT_file2.getline(strline,2560);
     
      gEEflux2.push_back(eflux);

    }
   
  
  for(int k=0;k<18;k++)
    { 
      flux_Bin2[k]=0;
      for (int kk=0;kk<10;kk++)
	{ 
	  int kkk = kk + 10*k;
	  flux_Bin2[k] = flux_Bin2[k]+ gEEflux2[kkk];
	
	}
 
    }
  

  while(!INPUT_file3.eof())
    {
      INPUT_file3>>runnumber>>eid>>eflux;
      INPUT_file3.getline(strline,2560);
     
      gEEflux3.push_back(eflux);

    }
   
  
  for(int k=0;k<18;k++)
    { 
      flux_Bin3[k]=0;
      for (int kk=0;kk<10;kk++)
	{ 
	  int kkk = kk + 10*k;
	  flux_Bin3[k] = flux_Bin3[k]+ gEEflux3[kkk];
	
	}
 
    }
  

  while(!INPUT_file4.eof())
    {
      INPUT_file4>>runnumber>>eid>>eflux;
      INPUT_file4.getline(strline,2560);
     
      gEEflux4.push_back(eflux);

    }
   
  
  for(int k=0;k<18;k++)
    { 
      flux_Bin4[k]=0;
      for (int kk=0;kk<10;kk++)
	{ 
	  int kkk = kk + 10*k;
	  flux_Bin4[k] = flux_Bin4[k]+ gEEflux4[kkk];
	
	}
 
    }
  

  while(!INPUT_file5.eof())
    {
      INPUT_file5>>runnumber>>eid>>eflux;
      INPUT_file5.getline(strline,2560);
     
      gEEflux5.push_back(eflux);

    }
   
  
  for(int k=0;k<18;k++)
    { 
      flux_Bin5[k]=0;
      for (int kk=0;kk<10;kk++)
	{ 
	  int kkk = kk + 10*k;
	  flux_Bin5[k] = flux_Bin5[k]+ gEEflux5[kkk];
	
	}
 
    }
  

  while(!INPUT_file6.eof())
    {
      INPUT_file6>>runnumber>>eid>>eflux;
      INPUT_file6.getline(strline,2560);
     
      gEEflux6.push_back(eflux);

    }
   
  
  for(int k=0;k<18;k++)
    { 
      flux_Bin6[k]=0;
      for (int kk=0;kk<10;kk++)
	{ 
	  int kkk = kk + 10*k;
	  flux_Bin6[k] = flux_Bin6[k]+ gEEflux6[kkk];
	
	}
 
    }
  
  while(!INPUT_file7.eof())
    {
      INPUT_file7>>runnumber>>eid>>eflux;
      INPUT_file7.getline(strline,2560);
     
      gEEflux7.push_back(eflux);

    }
   
  
  for(int k=0;k<18;k++)
    { 
      flux_Bin7[k]=0;
      for (int kk=0;kk<10;kk++)
	{ 
	  int kkk = kk + 10*k;
	  flux_Bin7[k] = flux_Bin7[k]+ gEEflux7[kkk];
	
	}
 
    }
  

  while(!INPUT_file8.eof())
    {
      INPUT_file8>>runnumber>>eid>>eflux;
      INPUT_file8.getline(strline,2560);
     
      gEEflux8.push_back(eflux);

    }
   
  
  for(int k=0;k<18;k++)
    { 
      flux_Bin8[k]=0;
      for (int kk=0;kk<10;kk++)
	{ 
	  int kkk = kk + 10*k;
	  flux_Bin8[k] = flux_Bin8[k]+ gEEflux8[kkk];
	
	}
 
    }
  
  while(!INPUT_file9.eof())
    {
      INPUT_file9>>runnumber>>eid>>eflux;
      INPUT_file9.getline(strline,2560);
     
      gEEflux9.push_back(eflux);

    }
   
  
  for(int k=0;k<18;k++)
    { 
      flux_Bin9[k]=0;
      for (int kk=0;kk<10;kk++)
	{ 
	  int kkk = kk + 10*k;
	  flux_Bin9[k] = flux_Bin9[k]+ gEEflux9[kkk];
	
	}
 
    }
  /*  
      for (int i =0;i<181;i++)
      {
      Ecounter[i] = i+1 ;
      ratio[i] = gEinput[i]/gEEflux2[i]/240000;
      }
  */


  TH1F *mc_Ecounter[18];   
  char hName[255],hTitle[255];
  for(int ii=0;ii<18;ii++) 
    {	
      sprintf(hName,"mc_Ecounter%02d",ii);
      sprintf(hTitle,"mc_Ecounter%02d",ii);
      mc_Ecounter[ii] = new TH1F(hName,hTitle,200,-2,2);  
    }

 //TFile *f2 = new TFile("/home/mepmsu/Desktop/premex-2/analysis/data/MC64877_50M_nocut.root","r");
  TFile *f2 = new TFile("/home/mepmsu/Desktop/premex-2/analysis/data/sidata/cookMC65078_e1_5_z200.root","r");
  
  if (!f2) cout << " erro " << endl;
 
  //h_eid_data = (TH1F*)f1->Get("h_eid");
  h_eid_mc = (TH1F*)f2->Get("h_eid");

  mc_Ecounter[0]  = (TH1F*)f2->Get("h_Ecounter01");
  mc_Ecounter[1]  = (TH1F*)f2->Get("h_Ecounter02");	
  mc_Ecounter[2]  = (TH1F*)f2->Get("h_Ecounter03");
  mc_Ecounter[3]  = (TH1F*)f2->Get("h_Ecounter04");	
  mc_Ecounter[4]  = (TH1F*)f2->Get("h_Ecounter05");	
  mc_Ecounter[5]  = (TH1F*)f2->Get("h_Ecounter06");	
  mc_Ecounter[6]  = (TH1F*)f2->Get("h_Ecounter07");	
  mc_Ecounter[7]  = (TH1F*)f2->Get("h_Ecounter08");	
  mc_Ecounter[8]  = (TH1F*)f2->Get("h_Ecounter09");	
  mc_Ecounter[9]  = (TH1F*)f2->Get("h_Ecounter10");	
  mc_Ecounter[10] = (TH1F*)f2->Get("h_Ecounter11");	
  mc_Ecounter[11] = (TH1F*)f2->Get("h_Ecounter12");	
  mc_Ecounter[12] = (TH1F*)f2->Get("h_Ecounter13");	
  mc_Ecounter[13] = (TH1F*)f2->Get("h_Ecounter14");	
  mc_Ecounter[14] = (TH1F*)f2->Get("h_Ecounter15");	
  mc_Ecounter[15] = (TH1F*)f2->Get("h_Ecounter16");	
  mc_Ecounter[16] = (TH1F*)f2->Get("h_Ecounter17");	
  mc_Ecounter[17] = (TH1F*)f2->Get("h_Ecounter18");	
  	

for (int i =0;i<18;i++)
    { 
      flux_total[i] = flux_Bin1[i]+flux_Bin2[i]+flux_Bin3[i]+flux_Bin4[i]+flux_Bin5[i]+flux_Bin6[i]+flux_Bin7[i]+flux_Bin8[i]; 
      flux_total_empty = flux_Bin9[i]+flux_total_empty;
   
      ratio[i] = input_Bin[i]/flux_Bin2[i]/10e5;

    }


  for (int i =0;i<180;i++)
    {  
            
      MCyield[i] = h_eid_mc->GetBinContent(i+1);
     if (MCyield[i] == 0) Acc[i]= Acc_error[i] = 0;
     else { 

            Acc[i] = (MCyield[i]+0.00000001)/(gEinput[i]+0.1);
            Acc_error[i] = 1.0/sqrt(MCyield[i]);
            
           }
       

     }


 for (int i =0;i<180;i++) 
	  {
	    flux_total_data = flux_total[i]+flux_total_data;
	    //cout<< setprecision(10) << "flux_total = "<< flux_total_data<<" -- "<<flux_total[i] << " = " << i << " = " << flux_Bin2[i]<<"  ;"<<"empty ="<<flux_total_empty<<" -- " << flux_Bin9[i]<< endl;
	   
	//cout << " Acc_error ~~ "     <<Acc_error[i] << endl ;
	//cout << " Acc_error_plot ~~ "<<Acc_error_plot[i]<<endl;
       // cout << "Acc= ~~  "<<Acc[i]<<endl;
	// cout << MCyield[i]<<endl;
	  }





	for (int i =0;i<180;i++)
    { 
      Acc_error_plot[i]	= Acc_error[i] * Acc[i];
    
//cout << " Acc_error_plot ~~ "<<Acc_error_plot[i]<<endl;
  

    }

float Bin_num[18],MCyield_bin_sum[18],Acc_Bin_error[18];

for(int k=0;k<18;k++)
    { 
      Acc_Bin[k]=0;Acc_bin_sum[k]=0;Bin_num[k]=0;MCyield_bin_sum[k]=0;
      for (int kk=0;kk<10;kk++)
	{ 
	  int kkk = kk + 10*k;
          if ( Acc[kkk] > 0.05 ) Bin_num[k]++ ;	 
	 Acc_bin_sum[k] = Acc_bin_sum[k]+ Acc[kkk];
	MCyield_bin_sum[k] = MCyield_bin_sum[k]+ MCyield[kkk];	


	}
 	Acc_Bin[k] = (Acc_bin_sum[k])/Bin_num[k];
	Acc_Bin_error[k] = 1.0*(Acc_Bin[k])/sqrt(MCyield_bin_sum[k]);
	cout << Acc_Bin[k]<<" ~~" << Bin_num[k]<<endl;
    }



////////////////////////////////////////////////////////
/* 
ofstream fout("MC_yield_Ech180_withcut.txt");
   for (int i =0;i<180;i++)
     {
       fout<<MCyield[i]<<endl;
       
     }
   fout.close();
*/
/////////////////////////////////////////////////////////
      //==========================================================================






      TMultiGraph *mg = new TMultiGraph("mg","Si target MC Acceptance (with cuts 1M) ");
      //TGraphErrors *g1 = new TGraphErrors(18,Energy,Acc_Bin,0,Acc_Bin_error);
      TGraphErrors *g1 = new TGraphErrors(180,E_channel,Acc,0,Acc_error_plot);	
      //TF1 * gli = new TF1("gli", "0.77437 -0.151152*x+0.0102022*x*x", 4.2,5.4);

      TCanvas *c11 = new TCanvas("c11","counts vs T",600,300);
      //  TCanvas *c22 = new TCanvas("c22","XY position",800,800);
      gStyle->SetPalette(0,0);
      // c11->Divide(1,2);
      c11->cd();

 
      //  g1->Draw("A*");
      g1->SetName("g1");
      g1->SetTitle("");  
      g1->SetMarkerStyle(20);
      g1->SetMarkerColor(4);
      g1->SetMarkerSize(0.5);
      g1->SetDrawOption("AP");
      g1->SetLineColor(1);
      g1->SetLineWidth(0);
      g1->SetFillStyle(0);
      g1->GetYaxis()->SetTitle("");
      g1->GetXaxis()->SetTitle("");
   

      mg->Add(g1);
      //  mg->Add(g2);
      //mg->Add(gli);	

      mg->Draw("AP");
      mg->GetXaxis()->SetTitle("E-channel  ");
      mg->GetYaxis()->SetTitle("   Accceptance = N-yield/N-input  ");
      gPad->Modified();
    //  mg->GetXaxis()->SetLimits(4.3,5.4);
      mg->SetMinimum(0.11);
      mg->SetMaximum(0.20);
      // gli->Draw("same");

      // TLegend *leg = new TLegend(0.1,0.7,0.48,0.9);
      // leg->AddEntry("g1","#64876-64883 data (way1)");
      // leg->AddEntry("gli","Theory");
      // leg->Draw();
  	
      //  c11->cd(2);







    }













