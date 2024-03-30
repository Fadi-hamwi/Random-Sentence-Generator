#include "test.h"
#include "stddef.h"
// Helpers
static void readGrammar(ifstream& infile, map<string, Definition>& grammar)
{
  while (true) {
    string uselessText;
    getline(infile, uselessText, '{');
    if (infile.eof()) return;  // true? we encountered EOF before we saw a '{': no more productions!
    infile.putback('{');
    Definition def(infile);
    grammar[def.getNonterminal()] = def;
  }
}



void testPrintDefNamesOfAGrammar(map<string, Definition> grammar) {
    for(auto def : grammar) {
        cout << def.first << " ";
    }
    cout << endl;
}


