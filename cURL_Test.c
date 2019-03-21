#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>


using namespace std;

int main(){

	cout << "Testing" << endl;

	curl_global_init( CURL_GLOBAL_ALL );


	CURL * myHandle;
	CURLcode result; // We’ll store the result of CURL’s webpage retrieval, for simple error checking.
	myHandle = curl_easy_init ( ) ;
	// Notice the lack of major error-checking, for brevity


	curl_easy_setopt( myHandle, CURLOPT_URL, "http://www.shodan.io");
	result = curl_easy_perform( myHandle ); 
	curl_easy_cleanup( myHandle );

	return 0;
}

