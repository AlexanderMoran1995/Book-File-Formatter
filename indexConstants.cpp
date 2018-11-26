#include "indexConstants.h"


extern const int PAGE_THRESHOLD = 25;
extern const int MAX_LINES_PER_PAGE = 75;


using namespace std;

CountedWords::CountedWords (std::string wrd, int cnt)
  : word(wrd), count(cnt)
{}

// Strips all punctuation (except hyphens) from a word and
// changes any upper-case characters to lower-case. Note that
// if a word has nothing except punctuation, this may reduce
// it to the empty string.
string reduceWords (string word)
{
  string result;
  for (int i = 0; i < word.size(); ++i)
    {
      char c = word[i];
      if (c == '-')
	result += c;
      else if (c >= 'a' && c <= 'z')
	result += c;
      else if (c >= 'A' && c <= 'Z')
	result += (c - 'A' + 'a'); // converts to lower-case
      //else if (sizeof(c) == 1)
    //result =- c;
    }
  return result;
}






// Assume the elements of the array are already in order
// Find the position where value could be added to keep
//    everything in order, and insert it there.
// Return the position where it was inserted
//  - Assumes that we have a separate integer (size) indicating how
//     many elements are in the array
//  - and that the "true" size of the array is at least one larger
//      than the current value of that counter

int addInOrder (vector<CountedWords>& v, CountedWords value)
{
  // Make room for the insertion
  int toBeMoved = v.size() - 1;
  v.push_back(value);
  while (toBeMoved >= 0 && value.word < v[toBeMoved].word) {
    v[toBeMoved+1] = v[toBeMoved];
    --toBeMoved;
  }
  // Insert the new value
  v[toBeMoved+1] = value;
  return toBeMoved+1;
}



// Search an ordered array for a given value, returning the index where
//    found or -1 if not found.
int binarySearch(vector<CountedWords>& list, string searchItem)
{
    int first = 0;
    int last = list.size() - 1;
    int mid;

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;

        if (list[mid].word == searchItem)
            found = true;
        else
            if (searchItem < list[mid].word)
                last = mid - 1;
            else
                first = mid + 1;
    }

    if (found)
        return mid;
    else
        return -1;
}




// Read words from the provided input stream, reducing each word and counting
// how many times each word appears. Write the resulting words and counts (in
// alphabetic order by word) in CSV format to the output stream.
// - Assume that the input contains a maximum of MaxWords distinct words
//   (after reduction). If more distinct words than this are actually
//   encountered, write nothing to the output stream but print an error
//   message on the standard error stream.
void histogram(const int MaxWords, istream& input, ostream& output)
{
  vector<CountedWords> countedWords;

  string word;
  while (input >> word)
    {
      word = reduceWords(word);
      if (word != "")
	{
	  int index = binarySearch(countedWords, word);
	  if (index >= 0)
	    {
	      ++countedWords[index].count;
	    }
	  else
	    {
	      if (countedWords.size() >= MaxWords)
		{
		  cerr << "Input file contains more than "
		       << MaxWords << " words." << endl;
		  exit (1);
		}
	      CountedWords wc = CountedWords(word, 1);
	      addInOrder(countedWords, wc);
	    }
	}
    }


  for (int i = 0; i < countedWords.size(); ++i)
    {
    if (countedWords[i].count <= 10)
        {

    output << '"' << countedWords[i].word
	   <<  "\"," << countedWords[i].count << endl;
        }
  }
}
