#include <iostream> 			//@author: Bilguun
using namespace std;			//Ceaser chiper

string encryption(string text, int key);
string decryption(string text, int key);

int main(){
	string plaintext, encryptedtext, decryptedtext;
	int num;
	
	cout << "Please input plain text: ";
	getline(cin, plaintext);   //input line
	cout << "Key: ";
	cin >> num;
	
	encryptedtext = encryption(plaintext, num); //encrypt
	
	for(int i=1; i<27; i++){	//decrypt key 1 - 26
		decryptedtext = decryption(encryptedtext, i);
		cout << "Decrypted text (key:" << i << "): " << decryptedtext << endl;
	}
	
	return 0;
}

string encryption(string text, int key){
	string enc="";
	for(int i=0; i<text.length(); i++){
		if( isalpha(text[i]) ){		
        	if(isupper(text[i])){
        		enc+=((((text[i]-65)+key) % 26) + 65);		//lower case letter ascii 97 - 122
			}
			
			else{											//upper case letter ascii 65 - 90
				enc+=(((text[i]-97)+key) % 26) + 97;		//((letter ascii - 97) + key) + 97
			}
			
			continue;										//isalpha(text[i]) == false
    	}
    	
    	enc+=text[i];										//
	}
	
	return enc;
}

string decryption(string text, int key){
	string enc="";
	for(int i=0; i<text.length(); i++){
		if( isalpha(text[i]) ){
        	if(isupper(text[i])){	//lower case letter ascii 97 - 122
        		enc+=((((text[i]-65)-key) % 26) + 65);  //((letter ascii - 97) - key) + 97
			}
			
			else{					//upper case letter ascii 65 - 90
				enc+=(((text[i]-97)-key) % 26) + 97; 
			}
			
			continue;	//isalpha(text[i]) == false
    	}
    	
    	enc+=text[i];	//decryptedtext + text[i]
	}
	
	return enc;
}
