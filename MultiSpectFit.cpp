#include <MultiSpectFit.h>



int main()
{
    //Read input files
    
    //Get histograms
    //For now doing this with just one file
    TFile *finTemp = TFile::Open("/home/padsley/data/19Fpp/Analysis/Alpha0CoincidenceSpectra.root");
    
    //Get state information
    
    //Setup TMinuit2
    
    //Pray (and/or do the minimisation)
    

    //Save the information to the output file
    
 return 0;
}

double LogLikelihood(double *x, double *pars, TH1F **histos)
{
 //Work out number of histograms and loop over them   
 double result = 0;
    
    
    
    
}

double PoissonianProbability(double mean, int counts)
{
    double result = exp(-mean) * pow(mean,counts) / TMath::Factorial(counts);
    return result;
}
