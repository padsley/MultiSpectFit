#include <TMath.h>
#include <TROOT.h>
#include <TH1.h>
#include <TF1.h>
#include <TTree.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TMinuit.h>
#include <iostream>
#include <vector>

double PoissonianProbability(double mean, int counts);
// double LogLikelihood(double *x, double *pars, TH1F **histos);
void LogLikelihood(int &npar, double *gin, double &result, double *par, int iflag);
double FitFunction(double *x, double *pars, int HistoIndex);

TH1F **histos;

unsigned int nstates = 0; //Number of states for the fit - global because I need it everywhere!
unsigned int NumberOfHistos = 0;
std::vector<bool> vNarrow, vFixWidth; //Whether peaks are narrow or if the width has been fixed - also needed for the fitting globally