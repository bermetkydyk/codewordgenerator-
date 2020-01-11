//Bermet Kydykova
// CodewordGenerator.hpp
// our generator will create only codewords that match a given pattern 
// December 1, 2019 


#include "CodewordGenerator.hpp"
#include <iostream>
#include <queue>
#include <regex>
#include <string>
#include <stack>
#include <vector>

using namespace std;
// takes a string pattern and returns the shortest string that matches the 
// pattern exploring the space of all possible alphabet permutations
// in breadth first search order
string CodewordGenerator::generateShortestWord(string pattern)
{

    // any upper case letter [:upper:]
    // regex re("[A-Z]+");
  	regex re(pattern);
    // we will use all upper case letters 
  	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // push empty string on the stack
    queue<string> myqueue;
  
  	myqueue.push("");
    
    //store eveything in a vector 
  	vector<string> result;
  
  	int n = 10;

    while(!myqueue.empty())
    {
        string current_string = myqueue.front();
      
      	// stop when a matching string is about to be added to the list
        // to check if it matches the pattern 
      	if (regex_match(current_string,re))
          	return current_string;
      
      	// pops and adds to result 
      	myqueue.pop();	
        result.push_back(current_string);

        // checks if the current size is less than the maxsize 
        if(current_string.size() < n)
        {
          	char ch;
              //loops through every character in alpahbet 
            for(int i = 0; i < alphabet.size(); i++)
            {
              	ch = alphabet[i];
                //append ch to current_string and push it  
                myqueue.push(current_string + ch);
               
            }
        }
       

    }
  
  
  	// if no matching string
  	
    return "";



}

//depth first search order 
//takes a string pattern and an integer n anf returns a string length n
//that matches the pattern exploring the space of all possible alphabet permutations in DFS


string CodewordGenerator::generateLengthWord(string pattern, int length)
{
    
    int n  = length;
  
    regex re(pattern);
    // all uppercase letters in the alphabet 
  	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // a new empty stack 
    stack<string> mystack;
  
  	mystack.push("");
  
  	vector<string> result;
  
    while(!mystack.empty())
    {
        //let current string pop and add to result  
        string current_string = mystack.top();
        mystack.pop();
      	result.push_back(current_string);
      		
        // if the strinf less than size 
        if(current_string.size() < n)
        {
          	char ch;
            // every character in alphabet 
            for (int i = 0; i < alphabet.size(); i++)
            {
              	ch = alphabet[i];
              	//append ch to current_string and push it 
                mystack.push(current_string + ch);
               
            }
        }
      	else	// if the desired string length is gotten to
        {
           	// stop when a matching string is about to be added to the list
      	 	if (regex_match(current_string,re))
           		return current_string;
        }

    } 
  	// if no matching string
  	return "";
    
}
