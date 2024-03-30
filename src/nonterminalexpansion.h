/**
 * File: nonterminalexpansion.h
 * defines the abstraction of expanding the non-terminals, and 
 * generating text based on the provided grammar.
*/

#include <iostream>
#include <map>
#include <vector>
#include "definition.h"
#include "production.h"

using namespace std;

class nonterminalexpansion {
public:
    nonterminalexpansion();
    nonterminalexpansion(map<string, Definition>);
    
    /**
     * This function loads the grammar so that methods in this class can make use 
     * of the grammar without passing the grammar as a second argument to every function.
    */
    void loadGrammar(map<string, Definition> grammar) {
        this->grammar = grammar;
    }

    /**
     * Generates a random text from the given grammar by expanding first of all
     * the start non-terminal because all grammars must start with '<start>' non terminal
     * and it returns the generated text in a vector to be ready for printing.
    */
    void generateRandomTextBasedOnGrammar() {
        for(int i=0; i < 3; i++)
            expandNonTerminal(grammar["<start>"]);
    }

    /**
     * We expand the nonTerminals in this function recursively until there are no non_terminals left in the grammar provided.
     * in a nutshell this function subtitutes all the non_terminals recursively.
    */
    void expandNonTerminal(Definition def) {
        Production prod = def.getRandomProduction();
        for(auto curr = prod.begin(); curr != prod.end(); ++curr) {
            if(nonterminalexpansion::isNonTerminal(*curr)) {
                expandNonTerminal(this->grammar[*curr]);

            }else {
                this->generatedText.push_back(*curr);
            }
        }
    }

    void printGeneratedText() {
        for(auto word : this->generatedText) {
            if(word[word.length()-1] == '.') {
                cout << word << "\n";
            }else {
                cout << word << " ";
            }
        }
    }

    static bool isNonTerminal(string word) {
        return word[0] == '<';
    }

    void clearGeneratedText() {
        generatedText.clear();
    }

private:
    map<string, Definition> grammar;
    vector<string> generatedText;
};

