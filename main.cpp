#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

struct posdec{
	int word;
	int letter;
};
void decryptposdec(vector<string> passage, vector<posdec> encrypt, vector<posdec> separate, vector<string>& output);

int main(){
	vector<string> passage;
	vector<posdec> encrypt;
	vector<posdec> separate;
	vector<string> output;

	ifstream infile, infile2, infile3 ;
	ofstream outfile ;

	string infilename1;
	string infilename2;
	string infilename3;

	cout << "Please enter the name of the text" << endl;
	cin >> infilename1 ;

	infile . open ( infilename1 . c_str ( ) ) ;

	 if ( ! infile . is_open ( ) ) {
	 cout << "could not open input file" << endl ;
	 exit ( EXIT_FAILURE ) ;
	 }
	 else{
		 string words;
		 while(infile >> words){
			 passage.push_back(words);
		 }
	 }

	 cout << "Please enter the file name of the separators" << endl;
	 	cin >> infilename2 ;

	 	infile2 . open ( infilename2 . c_str ( ) ) ;

	 	 if ( ! infile2 . is_open ( ) ) {
	 	 cout << "could not open input file" << endl ;
	 	 exit ( EXIT_FAILURE ) ;
	 	 }
	 	 else{
	 		 posdec separated;
	 		 while(infile2 >> separated.word >> separated.letter){
	 			 separate.push_back(separated);
	 		 }
	 	 }

	 	cout << "Please enter the file name of the encrypted message" << endl;
	 		 	cin >> infilename3;

	 		 	infile3 . open ( infilename3 . c_str ( ) ) ;

	 		 	 if ( ! infile3 . is_open ( ) ) {
	 		 	 cout << "could not open input file" << endl ;
	 		 	 exit ( EXIT_FAILURE ) ;
	 		 	 }
	 		 	 else{
	 		 		 posdec encrypted;
	 		 		 while(infile3 >> encrypted.word >> encrypted.letter){
	 		 			 encrypt.push_back(encrypted);
	 		 		 }
	 		 	 }
	 		 	 decryptposdec(passage, encrypt, separate, output);

	 		 	 for(int q = 0; q < output.size(); q++){
	 		 		 cout << output[q] << " ";
	 		 	 }
	}

void decryptposdec(vector<string> passage, vector<posdec> encrypt, vector<posdec> separate, vector<string>& output){
	bool checkseparate(vector<string> passage, vector<posdec> encrypt,vector<posdec> separate, unsigned int i);
	string word;
	for(int i = 0; i < encrypt.size(); i++){
		if(checkseparate(passage, encrypt, separate, i)){
			word = word + passage[(encrypt[i].word)-1][(encrypt[i].letter)-1];
		}

		if(!(checkseparate(passage, encrypt, separate, i))){
			output.push_back(word);
			word = "";
		}

		if( i == (encrypt.size() - 1)){
			output.push_back(word);
		}
	}
}

bool checkseparate(vector<string> passage, vector<posdec> encrypt,vector<posdec> separate,unsigned int i){
	   for( int j = 0; j < separate.size(); j++){
		if((encrypt[i].word == separate[j].word) && ((encrypt[i].letter == separate[j].letter))){
		return false;
		}
	}
	return true;
}
