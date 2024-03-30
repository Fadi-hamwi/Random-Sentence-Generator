#include "nonterminalexpansion.h"

nonterminalexpansion::nonterminalexpansion() {
}

nonterminalexpansion::nonterminalexpansion(map<string, Definition> gr) : grammar{gr} {
        clearGeneratedText();
}


