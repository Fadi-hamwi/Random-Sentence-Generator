# Random-Sentence-Generator

## Table of Contents
[Description](#Description) | A detailed-Description about this project
-------------------------------  | --------------------------------------------------
[Prerequisites](#Prerequisites)  |  Things you need to have before running the files
[Installation](#Installation) | How to install this program
[Usage](#Usage) | How to use this program
[Examples](#Examples) | See a live example of how this program works



## Description
The Random Sentence Generator is a handy and marvelous piece of technology to create
random sentences from a structure known as context-free grammar. A grammar is a
template that describes the various combinations of words that can be used to form
valid sentences. There are profoundly useful grammars available to generate extension
requests, generic Star Trek plots, your average James Bond movie, "Dear John" letters,
and more. You can even create your own grammar! Fun for the whole family! Let’s
show you the value of this practical and wonderful tool:

• Tactic #1: Wear down the proffesor patience.

  I need an extension because I had to go to an alligator wrestling meet, and then, just when
  my mojo was getting back on its feet, I just didn't feel like working, and, well I'm a little
  embarrassed about this, but I had to practice for the Winter Olympics, and on top of that
  my roommate ate my disk, and right about then well, it's all a haze, and then my dorm
  burned down, and just then I had tons of midterms and tons of papers, and right about then I
  lost a lot of money on the four-square semi-finals, oh, and then I had recurring dreams
  about my notes, and just then I forgot how to write, and right about then my dog ate my
  dreams, and just then I had to practice for an intramural monster truck meet, oh, and then
  the bookstore was out of erasers, and on top of that my roommate ate my sense of purpose,
  and then get this, the programming language was inadequately abstract.

. Tactic #2: Plead innocence.
I need an extension because I forgot it would require work and then I didn’t know I was in
this class.

. Tactic #3: Honesty.
I need an extension because I just didn't feel like working.

The Grammar we are using is called out-of-context grammar(**CFG**).

Here is an example of this type of grammar :
```
The Poem grammar

{

<start>
  
The <object> <verb> tonight. ;

}

{

<object>
  
waves ;

big yellow flowers ;

slugs ;

}

{

<verb>
  
sigh <adverb> ;

portend like <object> ;

die <adverb> ;

}

{

<adverb>
  
warily ;

grumpily ;
}
```

each string in brackets is known as a **non-terminal**. A non-terminal is a
placeholder that will expand to another sequence of words when generating a poem. In
contrast, a terminal is a normal word that is not changed to anything else when
expanding the grammar. The name terminal is supposed to conjure up the image that
it’s something of a dead end, that no further expansion is possible.

A **definition consists** of a **non-terminal** and its set of **productions** (or expansions), each
of which is terminated by a semi-colon (';'). There will always be at least one and
potentially several productions for each non-terminal. A production is just a sequence of
words, some of which themselves may be non-terminals. A production can be empty
(i.e. just consist of the terminating semi-colon) which makes it possible for a non-terminal to evaporate into nothingness. The entire definition is enclosed in curly braces
'{' '}'. The following definition of <verb> has three productions:
```{
<verb>
sigh <adverb> ;
portend like <object> ;
die <adverb> ;
}
```
Comments and other irrelevant text may be outside the curly braces and should be
ignored. All the components of the input file—braces, words, and semi-colons—will be
separated from each other by some sort of white space (spaces, tabs, newlines), so that
we’re able to treat them as delimiters when parsing the grammar.

## Prerequisites
You must have make and g++ in order to run the files of this project.
You can check if they exist by typing : 
``` bash
g++ --version
```
``` bash
make --version
```

## Installation
```bash
git clone https://github.com/Fadi-hamwi/Random-Sentence-Generator
```

## Usage
cd to the src directory of the project and run make in it.
Now you should be able to see the **rsg** executable.
``` bash
./rsg <Grammar_file_from the accompanied grammar directory>
```

## Examples
```bash
./rsg ../grammars/excuse.g
```
This gives an excuse for not doing the homework.
and I leave the other grammar files to you to check what they do.

Thanks for Your Time :)
