#ifndef H_TEXT_SPLIT
#define H_TEXT_SPLIT

#include<iostream>
#include<string>
#include<vector>


#define DEF_NUMLINES 50

class TextSplit {
public:
	// default constructor
	TextSplit(std::string FileName, int numberOfLinesForEachFile);
	void CreateOutputFiles();
	void Index();

protected:
	void CountLines(std::ifstream &fin);
private:
	long numLinesForEachFile, numLinesForEachFileConst, numFiles, TotalLines;
	std::vector<std::string> line;
	std::string myFileName;

};
#endif


