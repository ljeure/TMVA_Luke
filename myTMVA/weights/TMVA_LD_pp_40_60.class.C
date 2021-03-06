// Class: ReadLD
// Automatically generated by MethodBase::MakeClass
//

/* configuration options =====================================================

#GEN -*-*-*-*-*-*-*-*-*-*-*- general info -*-*-*-*-*-*-*-*-*-*-*-

Method         : LD::LD
TMVA Release   : 4.2.0         [262656]
ROOT Release   : 6.02/13       [393741]
Creator        : leure
Date           : Tue Jun  6 19:51:04 2017
Host           : Linux vocms029.cern.ch 2.6.32-504.12.2.el6.x86_64 #1 SMP Thu Mar 12 07:33:00 CET 2015 x86_64 x86_64 x86_64 GNU/Linux
Dir            : /data/leure/TMVA_Luke/myTMVA
Training events: 6651
Analysis type  : [Classification]


#OPT -*-*-*-*-*-*-*-*-*-*-*-*- options -*-*-*-*-*-*-*-*-*-*-*-*-

# Set by User:
V: "False" [Verbose output (short form of "VerbosityLevel" below - overrides the latter one)]
VarTransform: "None" [List of variable transformations performed before training, e.g., "D_Background,P_Signal,G,N_AllClasses" for: "Decorrelation, PCA-transformation, Gaussianisation, Normalisation, each for the given class of events ('AllClasses' denotes all events of all classes, if no class indication is given, 'All' is assumed)"]
H: "True" [Print method-specific help message]
CreateMVAPdfs: "True" [Create PDFs for classifier outputs (signal and background)]
# Default:
VerbosityLevel: "Default" [Verbosity level]
IgnoreNegWeightsInTraining: "False" [Events with negative weights are ignored in the training (but are included for testing and performance evaluation)]
##


#VAR -*-*-*-*-*-*-*-*-*-*-*-* variables *-*-*-*-*-*-*-*-*-*-*-*-

NVar 10
Dtrk1Pt                       Dtrk1Pt                       Dtrk1Pt                       Dtrk1Pt                                                         'F'    [0.501860499382,51.7713851929]
DRestrk1Pt                    DRestrk1Pt                    DRestrk1Pt                    DRestrk1Pt                                                      'F'    [0.693660438061,56.3495254517]
DRestrk2Pt                    DRestrk2Pt                    DRestrk2Pt                    DRestrk2Pt                                                      'F'    [0.501416265965,50.7236557007]
DtktkRespt                    DtktkRespt                    DtktkRespt                    DtktkRespt                                                      'F'    [8.00832366943,58.8731307983]
Dchi2cl                       Dchi2cl                       Dchi2cl                       Dchi2cl                                                         'F'    [0.0501119084656,0.999967932701]
DtktkRes_chi2cl               DtktkRes_chi2cl               DtktkRes_chi2cl               DtktkRes_chi2cl                                                 'F'    [0.0501329638064,0.999576151371]
Dalpha                        Dalpha                        Dalpha                        Dalpha                                                          'F'    [2.90316274913e-05,0.199643790722]
DtktkRes_alpha                DtktkRes_alpha                DtktkRes_alpha                DtktkRes_alpha                                                  'F'    [7.98378823674e-05,0.199953570962]
DsvpvDistance/DsvpvDisErr     DsvpvDistance_D_DsvpvDisErr   DsvpvDistance/DsvpvDisErr     DsvpvDistance/DsvpvDisErr                                       'F'    [2.0015206337,587.856567383]
DtktkRes_svpvDistance/DtktkRes_svpvDisErr   DtktkRes_svpvDistance_D_DtktkRes_svpvDisErr DtktkRes_svpvDistance/DtktkRes_svpvDisErr   DtktkRes_svpvDistance/DtktkRes_svpvDisErr                                                   'F'    [2.010004282,503.130828857]
NSpec 0


============================================================================ */

#include <vector>
#include <cmath>
#include <string>
#include <iostream>

#ifndef IClassifierReader__def
#define IClassifierReader__def

class IClassifierReader {

 public:

   // constructor
   IClassifierReader() : fStatusIsClean( true ) {}
   virtual ~IClassifierReader() {}

   // return classifier response
   virtual double GetMvaValue( const std::vector<double>& inputValues ) const = 0;

   // returns classifier status
   bool IsStatusClean() const { return fStatusIsClean; }

 protected:

   bool fStatusIsClean;
};

#endif

class ReadLD : public IClassifierReader {

 public:

   // constructor
   ReadLD( std::vector<std::string>& theInputVars ) 
      : IClassifierReader(),
        fClassName( "ReadLD" ),
        fNvars( 10 ),
        fIsNormalised( false )
   {      
      // the training input variables
      const char* inputVars[] = { "Dtrk1Pt", "DRestrk1Pt", "DRestrk2Pt", "DtktkRespt", "Dchi2cl", "DtktkRes_chi2cl", "Dalpha", "DtktkRes_alpha", "DsvpvDistance/DsvpvDisErr", "DtktkRes_svpvDistance/DtktkRes_svpvDisErr" };

      // sanity checks
      if (theInputVars.size() <= 0) {
         std::cout << "Problem in class \"" << fClassName << "\": empty input vector" << std::endl;
         fStatusIsClean = false;
      }

      if (theInputVars.size() != fNvars) {
         std::cout << "Problem in class \"" << fClassName << "\": mismatch in number of input values: "
                   << theInputVars.size() << " != " << fNvars << std::endl;
         fStatusIsClean = false;
      }

      // validate input variables
      for (size_t ivar = 0; ivar < theInputVars.size(); ivar++) {
         if (theInputVars[ivar] != inputVars[ivar]) {
            std::cout << "Problem in class \"" << fClassName << "\": mismatch in input variable names" << std::endl
                      << " for variable [" << ivar << "]: " << theInputVars[ivar].c_str() << " != " << inputVars[ivar] << std::endl;
            fStatusIsClean = false;
         }
      }

      // initialize min and max vectors (for normalisation)
      fVmin[0] = 0;
      fVmax[0] = 0;
      fVmin[1] = 0;
      fVmax[1] = 0;
      fVmin[2] = 0;
      fVmax[2] = 0;
      fVmin[3] = 0;
      fVmax[3] = 0;
      fVmin[4] = 0;
      fVmax[4] = 0;
      fVmin[5] = 0;
      fVmax[5] = 0;
      fVmin[6] = 0;
      fVmax[6] = 0;
      fVmin[7] = 0;
      fVmax[7] = 0;
      fVmin[8] = 0;
      fVmax[8] = 0;
      fVmin[9] = 0;
      fVmax[9] = 0;

      // initialize input variable types
      fType[0] = 'F';
      fType[1] = 'F';
      fType[2] = 'F';
      fType[3] = 'F';
      fType[4] = 'F';
      fType[5] = 'F';
      fType[6] = 'F';
      fType[7] = 'F';
      fType[8] = 'F';
      fType[9] = 'F';

      // initialize constants
      Initialize();

   }

   // destructor
   virtual ~ReadLD() {
      Clear(); // method-specific
   }

   // the classifier response
   // "inputValues" is a vector of input values in the same order as the 
   // variables given to the constructor
   double GetMvaValue( const std::vector<double>& inputValues ) const;

 private:

   // method-specific destructor
   void Clear();

   // common member variables
   const char* fClassName;

   const size_t fNvars;
   size_t GetNvar()           const { return fNvars; }
   char   GetType( int ivar ) const { return fType[ivar]; }

   // normalisation of input variables
   const bool fIsNormalised;
   bool IsNormalised() const { return fIsNormalised; }
   double fVmin[10];
   double fVmax[10];
   double NormVariable( double x, double xmin, double xmax ) const {
      // normalise to output range: [-1, 1]
      return 2*(x - xmin)/(xmax - xmin) - 1.0;
   }

   // type of input variable: 'F' or 'I'
   char   fType[10];

   // initialize internal variables
   void Initialize();
   double GetMvaValue__( const std::vector<double>& inputValues ) const;

   // private members (method specific)
   std::vector<double> fLDCoefficients;
};

inline void ReadLD::Initialize() 
{
   fLDCoefficients.push_back( 0.0290908824733 );
   fLDCoefficients.push_back( -0.000222475880323 );
   fLDCoefficients.push_back( 0.0151318216029 );
   fLDCoefficients.push_back( 0.0146609652211 );
   fLDCoefficients.push_back( -0.0163843491751 );
   fLDCoefficients.push_back( 0.00297922906984 );
   fLDCoefficients.push_back( 0.00387567501742 );
   fLDCoefficients.push_back( -0.386482831307 );
   fLDCoefficients.push_back( -0.198414866201 );
   fLDCoefficients.push_back( 5.12117922034e-05 );
   fLDCoefficients.push_back( -5.08044044298e-05 );

   // sanity check
   if (fLDCoefficients.size() != fNvars+1) {
      std::cout << "Problem in class \"" << fClassName << "\"::Initialize: mismatch in number of input values"
                << fLDCoefficients.size() << " != " << fNvars+1 << std::endl;
      fStatusIsClean = false;
   }         
}

inline double ReadLD::GetMvaValue__( const std::vector<double>& inputValues ) const
{
   double retval = fLDCoefficients[0];
   for (size_t ivar = 1; ivar < fNvars+1; ivar++) {
      retval += fLDCoefficients[ivar]*inputValues[ivar-1];
   }

   return retval;
}

// Clean up
inline void ReadLD::Clear() 
{
   // clear coefficients
   fLDCoefficients.clear(); 
}
   inline double ReadLD::GetMvaValue( const std::vector<double>& inputValues ) const
   {
      // classifier response value
      double retval = 0;

      // classifier response, sanity check first
      if (!IsStatusClean()) {
         std::cout << "Problem in class \"" << fClassName << "\": cannot return classifier response"
                   << " because status is dirty" << std::endl;
         retval = 0;
      }
      else {
         if (IsNormalised()) {
            // normalise variables
            std::vector<double> iV;
            iV.reserve(inputValues.size());
            int ivar = 0;
            for (std::vector<double>::const_iterator varIt = inputValues.begin();
                 varIt != inputValues.end(); varIt++, ivar++) {
               iV.push_back(NormVariable( *varIt, fVmin[ivar], fVmax[ivar] ));
            }
            retval = GetMvaValue__( iV );
         }
         else {
            retval = GetMvaValue__( inputValues );
         }
      }

      return retval;
   }
