#include <iostream>
#include <string>
#include <fstream>

#include "textsplit.h"
#include "indexConstants.h"


using namespace std;

int main(int argc, char *argv[])
{


   int howMany;
	string fileName;
	ofstream outStream;
    ifstream input (argv[1]);


   if (argc ==2){

    fileName = (argv[1]);

    howMany = MAX_LINES_PER_PAGE;

    TextSplit R(fileName, howMany);
	R.CreateOutputFiles();

	int MaxWords = 999999;

      ofstream out ("counter.txt");
      histogram (MaxWords, input, out);


	R.Index();

   }
   else if (argc!=2) {
        cout << "ERROR: no input file detected" << endl;
   }

}
