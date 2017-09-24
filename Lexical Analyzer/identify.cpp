// This identifies all the identifiers in an input c program.


/*
	The code assumes a lot of things.
	Most importantly it assumes that there is a space between each keyword and identifies=r and literal of the input file.

	e.g. c = a + b;
	and not c=a+b; which will be read as one word the program.
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	/* code */

	ifstream in("hello.c");
	string word;

	while(in>>word){

		if(word.substr(0,2)=="//"){
			char c;
			in.get(c);
			while(c!='\n'){
				in.get(c);
			}
			continue;
		}

		if(word.substr(0,2)=="/*"){
			in>>word;
			while(word.substr(0,2)!="*/" && word.substr(word.length()-2,1)!="*/"){
				in>>word;
			}
			continue;
		}

		if(word!="auto" && word!="double" && word!="int" && word!="struct" && 
			word!="break" && word!="else" && word!="long" && word!="switch" && 
			word!="case" && word!="enum" && word!="register" && word!="typedef" && 
			word!="char" && word!="extern" && word!="return" && word!="union" && 
			word!="continue" && word!="for" && word!="signed" && word!="void" && 
			word!="do" && word!="if" && word!="static" && word!="while" && 
			word!="default" && word!="goto" && word!="sizeof" && word!="volatile" && 
			word!="const" && word!="float" && word!="short" && word!="unsigned"){


				// The read word is not a keyword.

				if(word.substr(0,7)=="printf(" || word.substr(0,6)=="scanf("){
					char c;
					while(1){
						in.get(c);
						if(c==';')
							break;
					}
					continue;
				}
				else{

					// It's is neither printf() nor scanf().

					// If the read word is a number.
					if(word[0]>='0' && word[0]<='9'){
						cout<<word.substr(0,word.length()-1)<<endl;
					}

					// If it is a function name.
					else if((word[word.length()-2]==')' && word[word.length()-1]==';') ||
					 (word[word.length()-1]=='{'  && word[word.length()-2]==')')){
						char c = word[0];
						int i = 0;
						while(word[i]!='('){
							cout<<word[i];
							i++;
						}
						cout<<endl;
					}
					else{
						// It is a varaible name.

						/*
						NOTE:- According to the assumptions, a variable is found.
								If there is scope of any improvement, please do.
						*/
						if((word[0]>='a' && word[0]<='z') || (word[0]>='A' && word[0]<='Z') || word[0]=='_'){

							if(word[word.length()-1]==';')
								cout<<word.substr(0,word.length()-1)<<endl;
							else{
								cout<<word<<endl;
							}
						}
					}
					
				}
			}
		}
	return 0;
}