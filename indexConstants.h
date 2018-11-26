#ifndef INDEXCONSTANTS_H
#define INDEXCONSTANTS_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
// Special constants controlling the indexing program

extern const int PAGE_THRESHOLD;
extern const int MAX_LINES_PER_PAGE;

struct CountedWords {
  std::string word;
  int count;

  CountedWords (std::string wrd, int cnt);

};

std::string reduceWords (std::string word);
int addInOrder (std::vector<CountedWords>& v, CountedWords value);
int binarySearch(std::vector<CountedWords>& list, std::string searchItem);
void histogram(const int MaxWords, std::istream& input, std::ostream& output);


#endif
