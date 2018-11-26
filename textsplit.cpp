#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>



#include "textsplit.h"
#include "indexConstants.h"

using namespace std;


// default constructor
TextSplit::TextSplit(string FileName, int numberOfLinesForEachFile) {

	// sanity check
	if (numberOfLinesForEachFile < 1)
		numberOfLinesForEachFile = DEF_NUMLINES;

	// set local 'textsplit' class variables
	numLinesForEachFile = numberOfLinesForEachFile;
	numLinesForEachFileConst = numLinesForEachFile;
	// if a full path is used to specify the filename, discard the path...
	myFileName = FileName.substr(FileName.find_last_of("\\") + 1, FileName.size());
	// open file (check if file exists)
	ifstream fin(FileName.c_str());
	if (!fin) {
		cerr << "Error: Cannot open file for input." << endl;
		exit(1);
	}
	// Invoke CountLines function.
	CountLines(fin);

}

// count number of lines in file (private)
void TextSplit::CountLines(ifstream &fin) {
		long counter = 0;
		string Tmp_Currentline;
		while (getline(fin, Tmp_Currentline, '\n')) {
			line.push_back(Tmp_Currentline);
			counter++;

		}
		TotalLines = counter;
}








void TextSplit::CreateOutputFiles() {
	// Determine how many output files to create.
	if ((TotalLines % numLinesForEachFile) == 0)
			numFiles = TotalLines / numLinesForEachFile;
	else
		numFiles = TotalLines / numLinesForEachFile + 1;
	// initialise currentLine to 0 (i.e. the first line of input file
	long currentLine = 0;

	long numLinesLastFile = TotalLines - ((numFiles-1)*numLinesForEachFile);

	// create 'numFiles' amount of output files....
	for (long i=1,N=1,P = -1;   i <= numFiles; i++) {

        N++;
        P++;


    if(i == numFiles)
         numLinesForEachFile = currentLine + numLinesLastFile;





		/* Convert integer to string using stringstreams.
		   String variable temp_i is the number of the sub_file */
		stringstream ss;
		ss.width(4);
		string temp_i;
		ss << setfill('0') << i;
		ss >> temp_i;

		stringstream sn;
		sn.width(4);
		string temp_iN;
		sn << setfill('0') << N;
		sn >> temp_iN;

		stringstream sp;
		sp.width(4);
		string temp_iP;
		sp << setfill('0') << P ;
		sp >> temp_iP;



		string outputfiles;
		string Noutputfiles;
		string Poutputfiles;
        int pageNum = i;
        string BookTitle = TextSplit::myFileName.substr(0, TextSplit::myFileName.size()-4);


      outputfiles = "page" + temp_i + ".html";
      Noutputfiles = "page" + temp_iN + ".html";
      Poutputfiles = "page" + temp_iP + ".html";




		ofstream fout(outputfiles.c_str());
        fout <<  "<html>" << endl;
        fout << "<head>" << endl;




        fout <<   "<title>" << BookTitle + " page" + temp_i << "</title>" << endl;
        fout << "</head>" << endl;
        fout <<  "<body>" << endl;
        fout <<  "<p>" << endl;

       if( pageNum == 1){
        fout << "<a href="<< Noutputfiles << ">" << "Next" << "</a>" << endl;
        fout << "<a href=index.html>" << "Index" << "</a>" << endl;
        }
        else if ((pageNum > 1) && (numFiles > pageNum)){

        fout << "<a href="<< Poutputfiles << ">" << "Prev" << "</a>" << endl;
        fout << "<a href="<< Noutputfiles << ">" << "Next" << "</a>" << endl;
        fout << "<a href=index.html>" << "Index" << "</a>" << endl;
        }
        else if (pageNum == numFiles){
        fout << "<a href="<< Poutputfiles << ">" << "Prev" << "</a>" << endl;
        fout << "<a href=index.html>" << "Index" << "</a>" << endl;
        }
        fout <<  "</p>" << endl;
        fout <<  "<hr/>" << endl;
		fout <<  "<PRE>" << endl;

		// move each line to the newly created output file.
		for (int j = currentLine; j < numLinesForEachFile; j++) {
			fout << line[j] << endl;
		}

		fout <<  "</PRE>" << endl;
		fout << "</body>" << endl;
        fout << "</html>" << endl;




		// set Currentline to the max number of lines it should take
		currentLine = numLinesForEachFile;
		// increase numLinesForEachFile with original number of lines value --
		numLinesForEachFile = numLinesForEachFile + numLinesForEachFileConst;
		cout << "Successfully created " << outputfiles << endl;

	}

}
void TextSplit::Index(){

   string indexOutput = "index.html";

   ofstream fout(indexOutput.c_str());





        fout <<  "<html>" << endl;
        fout << "<head>" << endl;
        fout <<   "<title>" "BookTitle" "</title>" << endl;
        fout << "</head>" << endl;
        fout << "       " << endl;
        fout <<  "<body>" << endl;
        fout <<  "<p>" << endl;

        fout << "<a href=page0001.html>" << "First" << "</a>" << endl;
        fout <<  "</p>" << endl;
        fout <<  "<hr/>" << endl;


        fout <<  "<p>" << endl;
        fout <<  "<a href=#A>A</a>" << endl;
        fout <<  "<a href=#B>B</a>" << endl;
        fout <<  "<a href=#C>C</a>" << endl;
        fout <<  "<a href=#D>D</a>" << endl;
        fout <<  "<a href=#E>E</a>" << endl;
        fout <<  "<a href=#F>F</a>" << endl;
        fout <<  "<a href=#G>G</a>" << endl;
        fout <<  "<a href=#H>H</a>" << endl;
        fout <<  "<a href=#I>I</a>" << endl;
        fout <<  "<a href=#J>J</a>" << endl;
        fout <<  "<a href=#K>K</a>" << endl;
        fout <<  "<a href=#L>L</a>" << endl;
        fout <<  "<a href=#M>M</a>" << endl;
        fout <<  "<a href=#N>N</a>" << endl;
        fout <<  "<a href=#O>O</a>" << endl;
        fout <<  "<a href=#P>P</a>" << endl;
        fout <<  "<a href=#Q>Q</a>" << endl;
        fout <<  "<a href=#R>R</a>" << endl;
        fout <<  "<a href=#S>S</a>" << endl;
        fout <<  "<a href=#T>T</a>" << endl;
        fout <<  "<a href=#U>U</a>" << endl;
        fout <<  "<a href=#V>V</a>" << endl;
        fout <<  "<a href=#W>W</a>" << endl;
        fout <<  "<a href=#X>X</a>" << endl;
        fout <<  "<a href=#Y>Y</a>" << endl;
        fout <<  "<a href=#Z>Z</a>" << endl;

        fout <<  "</p>" << endl;
        fout <<  "<hr/>" << endl;
        fout << "<h1>Index</h1>" << endl;


        fout << "<h2 id=""A"">A</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;


        fout << "<h2 id=""B"">B</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""C"">C</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""D"">D</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""E"">E</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""F"">F</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""G"">G</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""H"">H</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""I"">I</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""J"">J</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""K"">K</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""L"">L</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""M"">M</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""N"">N</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""O"">O</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""P"">P</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""Q"">Q</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""R"">R</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""S"">S</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""T"">T</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""U"">U</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""V"">V</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""W"">W</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""X"">X</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""Y"">Y</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;

        fout << "<h2 id=""Z"">Z</h2>" << endl;
        fout << "<ul>" << endl;
        fout << "</ul>" << endl;


		fout << "</body>" << endl;
        fout << "</html>" << endl;




       cout << "Successfully created " << "index.html" << endl;
}
