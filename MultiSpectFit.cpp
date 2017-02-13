#include "MultiSpectFit.h"

int main()
{
    double min = 10.02, max = 11.375; //Min and Max Ex for the fit
    std::vector<double> vEx, vWidths, vWidthsSigma; //Information for defining the parameters
    
    //Read input files
    
    //Get histograms
    //For now doing this with just one file
    TFile *finTemp = TFile::Open("/home/padsley/data/19Fpp/Analysis/Alpha0CoincidenceSpectra.root");
    TH1F *hExAlpha0 = (TH1F*)finTemp->FindObjectAny("hExAlpha0");
    NumberOfHistos++;
    
    histos = new TH1F*[NumberOfHistos];
    histos[0] = hExAlpha0;
    
    //Get state information
    vEx.push_back(9.820);  vWidths.push_back(0.3e-3); vWidthsSigma.push_back(0.05e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(9.8343);  vWidths.push_back(1e-3); vWidthsSigma.push_back(2e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(9.874);  vWidths.push_back(1e-3); vWidthsSigma.push_back(0); vNarrow.push_back(true); vFixWidth.push_back(false);
    vEx.push_back(9.887);  vWidths.push_back(25e-3); vWidthsSigma.push_back(2e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(9.895);  vWidths.push_back(1e-3); vWidthsSigma.push_back(2e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(9.926);  vWidths.push_back(0.3e-3); vWidthsSigma.push_back(0.05e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.057); vWidths.push_back(1e-3); vWidthsSigma.push_back(1e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.088); vWidths.push_back(1.5e-3); vWidthsSigma.push_back(1e3); vNarrow.push_back(true); vFixWidth.push_back(false);
    vEx.push_back(10.1);   vWidths.push_back(200e-3); vWidthsSigma.push_back(100e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.137); vWidths.push_back(4.3e-3); vWidthsSigma.push_back(6e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.162); vWidths.push_back(31e-3); vWidthsSigma.push_back(10e-3); vNarrow.push_back(false); vFixWidth.push_back(true);
    vEx.push_back(10.19); vWidths.push_back(1e-3); vWidthsSigma.push_back(3e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.232); vWidths.push_back(1e-3); vWidthsSigma.push_back(1e3); vNarrow.push_back(true); vFixWidth.push_back(false);
    vEx.push_back(10.254); vWidths.push_back(22e-3); vWidthsSigma.push_back(1e2); vNarrow.push_back(false); vFixWidth.push_back(true);
    vEx.push_back(10.308); vWidths.push_back(9.2e-3); vWidthsSigma.push_back(3e-3); vNarrow.push_back(false); vFixWidth.push_back(true);
    vEx.push_back(10.356); vWidths.push_back(1e-3); vWidthsSigma.push_back(3e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.365); vWidths.push_back(3.0e-3); vWidthsSigma.push_back(1.5e-3); vNarrow.push_back(true); vFixWidth.push_back(false);
    vEx.push_back(10.392); vWidths.push_back(1.5e-3); vWidthsSigma.push_back(1e3); vNarrow.push_back(true); vFixWidth.push_back(false);
    vEx.push_back(10.411); vWidths.push_back(1.5e-3); vWidthsSigma.push_back(1e3); vNarrow.push_back(true); vFixWidth.push_back(false);
    vEx.push_back(10.45); vWidths.push_back(1e-3); vWidthsSigma.push_back(3e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.469); vWidths.push_back(11e-3); vWidthsSigma.push_back(1.2e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.488); vWidths.push_back(4.8e-3); vWidthsSigma.push_back(0.8e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.4963); vWidths.push_back(5.7e-3); vWidthsSigma.push_back(0.6e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.521); vWidths.push_back(14e-3); vWidthsSigma.push_back(2e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.5423); vWidths.push_back(2.5e-3); vWidthsSigma.push_back(0.2e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.555); vWidths.push_back(4.0e-3); vWidthsSigma.push_back(1.2e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.5647); vWidths.push_back(4.6e-3); vWidthsSigma.push_back(0.7e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.581); vWidths.push_back(22e-3); vWidthsSigma.push_back(3e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
//     vEx.push_back(10.590); vWidths.push_back(1e-3); vWidthsSigma.push_back(1e3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.6143); vWidths.push_back(4.7e-3); vWidthsSigma.push_back(0.5e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.673); vWidths.push_back(1e-3); vWidthsSigma.push_back(1e3); vNarrow.push_back(true); vFixWidth.push_back(false);
    vEx.push_back(10.73); vWidths.push_back(1e-3); vWidthsSigma.push_back(1e3); vNarrow.push_back(true); vFixWidth.push_back(false);
    vEx.push_back(10.7633); vWidths.push_back(6e-3); vWidthsSigma.push_back(3e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.795); vWidths.push_back(6e-3); vWidthsSigma.push_back(3e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.821); vWidths.push_back(6e-3); vWidthsSigma.push_back(3e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
//     vEx.push_back(10.8597); vWidths.push_back(240.0e-3); vWidthsSigma.push_back(0.15e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.867); vWidths.push_back(6e-3); vWidthsSigma.push_back(3e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.9); vWidths.push_back(6e-3); vWidthsSigma.push_back(3e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.927); vWidths.push_back(6e-3); vWidthsSigma.push_back(3e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.975); vWidths.push_back(14e-3); vWidthsSigma.push_back(2e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(10.989); vWidths.push_back(7e-3); vWidthsSigma.push_back(2e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(11.044); vWidths.push_back(5e-3); vWidthsSigma.push_back(4e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(11.072); vWidths.push_back(35e-3); vWidthsSigma.push_back(4e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(11.106); vWidths.push_back(35e-3); vWidthsSigma.push_back(4e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(11.188); vWidths.push_back(17e-3); vWidthsSigma.push_back(4e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(11.235); vWidths.push_back(15e-3); vWidthsSigma.push_back(4e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(11.273); vWidths.push_back(7e-3); vWidthsSigma.push_back(2e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(11.286); vWidths.push_back(22e-3); vWidthsSigma.push_back(5e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(11.307); vWidths.push_back(22e-3); vWidthsSigma.push_back(5e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    vEx.push_back(11.350); vWidths.push_back(27e-3); vWidthsSigma.push_back(31e-3); vNarrow.push_back(false); vFixWidth.push_back(false);
    
    nstates = vEx.size();
    //Setup TMinuit2
    TMinuit *gMinuit = new TMinuit(2*NumberOfHistos+1+2*nstates+nstates*NumberOfHistos);
    gMinuit->SetFCN(LogLikelihood);
    
    int *ParameterFlags = new int[2*NumberOfHistos+1+2*nstates+nstates*NumberOfHistos];
    gMinuit->mnparm(0,"Constant Background",0,1e-4,0,0,ParameterFlags[0]);
    gMinuit->mnparm(1,"Linear Background",0,1e-4,0,0,ParameterFlags[1]);
    
    
    //Set Parameters
    for(unsigned int i=0;i<NumberOfHistos;i++)
    {
    for(unsigned int j=0;j<vEx.size();j++)
    {
//         fitSingles->SetParameter(3+3*i,vEx.at(i));
        char buffer[256];
        sprintf(buffer,"Energy of state %d",j);
        gMinuit->mnparm(2*NumberOfHistos+1+j,buffer,vEx.at(j),1e-6,vEx.at(j)-0.005,vEx.at(j)+0.005,ParameterFlags[2*NumberOfHistos+1+j]);

        sprintf(buffer,"Amplitude of state %d in histogram %d",j,i);
        gMinuit->mnparm(2*NumberOfHistos+1+2*nstates+j+NumberOfHistos*i,buffer,histos[i]->GetBinContent(histos[i]->FindBin(vEx.at(j))),1e-4,0,1e5,ParameterFlags[2*NumberOfHistos+1+2*nstates+j+NumberOfHistos*i]);
        
        sprintf(buffer,"Width of state %d",j);
        if(vNarrow.at(i))
        {
            gMinuit->mnparm(2*NumberOfHistos+nstates+j,buffer,0,1e-4,0,0,ParameterFlags[2*NumberOfHistos+nstates+j]);
        }
        else
        {
            if(vFixWidth.at(i))
            {
                gMinuit->mnparm(2*NumberOfHistos+nstates+j,buffer,vWidths.at(j),1e-4,vWidths.at(j),vWidths.at(j),ParameterFlags[2*NumberOfHistos+nstates+j]);
            }
            else
            {
                gMinuit->mnparm(2*NumberOfHistos+nstates+j,buffer,vWidths.at(j),1e-4,0,1,ParameterFlags[2*NumberOfHistos+nstates+j]);
            }
        }
    }
    }
    
    //Pray (and/or do the minimisation)
    int ierflg = 0;
    gMinuit->SetPrintLevel(0);
    gMinuit->mnexcm("MIGRAD",0,0,ierflg);

    //Save the information to the output file
    TFile *fout = new TFile("output.root","RECREATE");
    for(unsigned int i=0;i<NumberOfHistos;i++)histos[i]->Write();
    fout->Close();
    
 return 0;
}

// void LogLikelihood(double *pars, TH1F **histos)
void LogLikelihood(int &npar, double *gin, double &result, double *pars, int iflag)
{
 //Work out number of histograms and loop over them   
//  double result = 0;
     
 for(unsigned int i=0;i<NumberOfHistos;i++)
 {
  for(int j=0;j<histos[i]->GetNbinsX();j++)
  {
      double *x = new double[1];
      x[0] = histos[i]->GetBinCenter(j);
      if(x[0]>=10.02 && x[0]<=11.375)result += -2 * log(PoissonianProbability(FitFunction(x,pars,i),histos[i]->GetBinContent(j)));
  }
     
 }
//    return result; 
}

double PoissonianProbability(double mean, int counts)
{
    double result = exp(-mean) * pow(mean,counts) / TMath::Factorial(counts);
    return result;
}

double FitFunction(double *x, double *pars,int HistoIndex) //Depending on what fitting you're trying to do, this function might need to change. Currently it's implemented for narrow Gaussian peaks and broad peaks with FIXED widths - i.e. Voigt functions
{
    double result = 0;
    
    result += pars[2*HistoIndex] + pars[2*HistoIndex+1] * (x[0]-10);
    
    //Gaussian is parameter 2
    
    //3+3*i is the mean of the ith state
    //4+3*i is the width of the ith state
    //5+3*i is the amplitude of the ith state
    
    for(unsigned int i=0;i<nstates;i++)
    {
        if(vNarrow.at(i))
        {
            result += pars[2*NumberOfHistos+1+2*nstates+HistoIndex*nstates+i] * sqrt(2*TMath::Pi()) * pars[2] * TMath::Gaus(x[0], pars[2*NumberOfHistos+1+i], pars[2], kTRUE);
        }
        else if(!vNarrow.at(i))
        {
            result += pars[2*NumberOfHistos+1+nstates+i]*pars[2]*pow(2*TMath::Pi(),1.5)/4.*pars[2*NumberOfHistos+1+2*nstates+HistoIndex*nstates+i] * TMath::Voigt(x[0] - pars[2*NumberOfHistos+1+i], pars[2], pars[2*NumberOfHistos+1+nstates+i]);
        }
        else
        {
            std::cout << "Um?" << std::endl;
        }
    }
    return result;
}