#include <TMath.h>
#include <TROOT.h>
#include <TH1.h>
#include <TF1.h>
#include <TTree.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TMinuit.h>


double PoissonianProbability(double mean, int counts);
double LogLikelihood(double *x, double *pars, TH1F **histos);