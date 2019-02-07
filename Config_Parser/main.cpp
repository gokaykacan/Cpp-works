/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gokay
 *
 * Created on February 5, 2019, 2:49 PM
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

/*
 * return [addr, *value]
 */


typedef enum{
    PVR = 14,
    OSD_SELECT = 11,
    KEYPAD = 12,
    CANAL_DIGITAL = 60,
}Address_Value;

typedef enum{
    c01 = 1,
    c02 = 2,
    c03 = 3,
}Line_Value;


string ReadNthLine(const string& filename, int N)
{
   ifstream in(filename.c_str());

   string s;
   //for performance
   s.reserve(255);    
   for(int i = 0; i < N; ++i)
       getline(in, s);

   vector<char> line;//char temp_line[255] = {0};
   getline(in,s);
   for(unsigned int i=0; i<s.size(); i++){
       line.push_back(s[i]);
   }

   return s; 
}

vector< vector<int> > ReadConfigValues (string& line){
    const char seperation = ',';
    const char end_line = '#';
    const char start_value = ':';
    char FileCharacter =0;
    vector<char> temp_line;
    
    string address;
    string address3;
    vector<int> address2;
    vector<char> KeyBuffer;
    vector<char> KeyBuffer2;
    vector< vector<int> > Result;
    
    unsigned int k=0;
    unsigned int l=1;

    //copy line to the vector
    for(unsigned int i=0; i<line.size(); i++){
       temp_line.push_back(line[i]);
       //cout << temp_line[i];
    }
    //cout << "Size: " << temp_line.size() << endl;
    
    for(unsigned int j=0; j<temp_line.size(); j++){
        if(temp_line[j] != end_line){
            FileCharacter = temp_line[j];
            if(FileCharacter != seperation)
            {
                if(k>0 && k==l){
                    if(FileCharacter != start_value ){
                            KeyBuffer.push_back(FileCharacter);
                            //cout << KeyBuffer.back();
                            
                    }
                    else{
                        //assign char character to string for use it as address value
                        for(unsigned int i=0; i<KeyBuffer.size(); i++){
                            address = address + KeyBuffer[i];
                        }
                        //
                        //convert string to int and push it to new vector
                        address2.push_back(stoi(address));
                        //add address values to the rows
                        Result.push_back(address2);
                        //debug prints
                        //for(unsigned int i=0; i<address2.size(); i++){
                        //    cout << address2[i] << "->";
                        //}
                        
                        int temp_p=j;//keep it for previous loop
                        
                        //another loop for seperate setting values
                        j=j+1;                        
                        for(;j<temp_line.size(); j++){
                            if(FileCharacter != seperation){
                                FileCharacter = temp_line[j];
                                KeyBuffer2.push_back(FileCharacter);
                            }
                            else
                                break;
                        }
                        //
                        //assign buffer to a string
                        for(unsigned int i=0; i<KeyBuffer2.size(); i++){
                            address3 = address3 + KeyBuffer2[i];
                        }
                        //
                        //add setting values to the vector
                        Result[l-1].push_back(stoi(address3));
                        //cout << "k value: " << k << endl;
                        l++;
                        //clear buffers for next loop
                        address = "";
                        address2.clear();
                        KeyBuffer.clear();
                        address3 = "";
                        KeyBuffer2.clear();
                        //
                        j=temp_p; // turn back to previous place for loop
                    } 
                }
            }
            else{
                k=k+1;//for skip first value at the line
            }
        }
    }
    return Result;
}

int main(int argc, char** argv) {

    string filename = "config_o4.bin";
    
    FILE *pfile;
    pfile = fopen(filename.c_str(), "rb");
    if(pfile == NULL){
        cout << "Could not open file!" << endl;
    }
    else{
        //cout << "File Open SUCCESS !" << endl;
        string line2 =  ReadNthLine(filename,3);
        cout << line2 << endl;
        //cout << line2 << endl;

        vector< vector<int> > res = ReadConfigValues(line2);
        for(int row = 0; row < res.size(); row++)
        {
            for(int colm = 0; colm < res[row].size(); colm++)
            {
                //cout << row << "," << colm << ":";
                cout << res[row][colm] << " ";
            }
            cout << endl;
        }
        fclose(pfile);
    }
 

    
    return 0;
}

