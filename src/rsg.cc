/**
 * File: rsg.cc
 * ------------
 * Provides the implementation of the full RSG application, which
 * relies on the services of the built-in string, ifstream, vector,
 * and map classes as well as the custom Production and Definition
 * classes provided.
 */
 
#include <map>
#include <fstream>
#include "definition.h"
#include "production.h"
#include "nonterminalexpansion.h"
#include "test.h"

using namespace std;

/**
 * Takes a reference to a legitimate infile (one that's been set up
 * to layer over a file) and populates the grammar map with the
 * collection of definitions that are spelled out in the referenced
 * file.  The function is written under the assumption that the
 * referenced data file is really a grammar file that's properly
 * formatted.  You may assume that all grammars are in fact properly
 * formatted.
 *
 * @param infile a valid reference to a flat text file storing the grammar.
 * @param grammar a reference to the STL map, which maps nonterminal strings
 *                to their definitions.
 */

static void readGrammar(ifstream& infile, map<string, Definition>& grammar) {
  while (true) {
    string uselessText;
    getline(infile, uselessText, '{');
    if (infile.eof()) return;  // true? we encountered EOF before we saw a '{': no more productions!
    infile.putback('{');
    Definition def(infile);
    grammar[def.getNonterminal()] = def;
  }
}

// static bool isNonTerminal(string word) {
//   return word[0] == '<';
// }

// static void printGeneratedText(vector<string> text) {
//   for(auto word : text) {
//     if(word[word.length()-1] == '.') cout << word << "\n\n";
//     else 
//       cout << word << " ";
//   }
//   cout << "\n";
// }

// static vector<string> expandNonTerminal(map<string, Definition> grammar, Definition nonTerminalDef) {
//   vector<string> generatedText;
//   Production prod = nonTerminalDef.getRandomProduction();
//   for(auto curr = prod.begin(); curr != prod.end(); ++curr) {
//     if(isNonTerminal(*curr)) {
//       vector<string> expandedNonTerminal = expandNonTerminal(grammar, grammar[*curr]);
//       generatedText.insert(generatedText.end(), expandedNonTerminal.begin(), expandedNonTerminal.end()); // appended expandedNonTerminal vector to generatedText
//     }else {
//       generatedText.push_back(*curr);
//     }
//   }

//   return generatedText;
// }

// /**
//  * Generates a random text from the given grammar by expanding first of all
//  * the start non-terminal because all grammars must start with '<start>' non terminal
//  * and it returns the generated text in a vector to be ready for printing.
// */
// static void generateARandomTextBasedOn(map<string, Definition> grammar) {
//   vector<string> generatedText = expandNonTerminal(grammar, grammar["<start>"]);
//   printGeneratedText(generatedText);
// }

/**
 * Performs the rudimentary error checking needed to confirm that
 * the client provided a grammar file.  It then continues to
 * open the file, read the grammar into a map<string, Definition>,
 * and then print out the total number of Definitions that were read
 * in.
 * @param argc the number of tokens making up the command that invoked
 *             the RSG executable.  There must be at least two arguments,
 *             and only the first two are used.
 * @param argv the sequence of tokens making up the command, where each
 *             token is represented as a '\0'-terminated C string.
 */

int main(int argc, char *argv[]) {
  if (argc == 1) {
    cerr << "You need to specify the name of a grammar file." << endl;
    cerr << "Usage: rsg <path to grammar text file>" << endl;
    return 1; // non-zero return value means something bad happened 
  }
  
  ifstream grammarFile(argv[1]);
  if (grammarFile.fail()) {
    cerr << "Failed to open the file named \"" << argv[1] << "\".  Check to ensure the file exists. " << endl;
    return 2; // each bad thing has its own bad return value
  }
  
  // things are looking good...
  map<string, Definition> grammar;
  readGrammar(grammarFile, grammar);
  nonterminalexpansion expand(grammar) ;
  expand.generateRandomTextBasedOnGrammar();
  expand.printGeneratedText();
  return 0;
}

