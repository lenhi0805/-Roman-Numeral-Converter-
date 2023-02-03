#include <iostream>
#include<fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cstdlib>
#include <algorithm>

using namespace std;
const string roman_char = "IVXLCDM"; 
bool check_number(string str) {
  if (str[0] == '0') str.erase(str.begin(),str.begin() + 1); 
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false) 
      return false;
      return true; 
} 


bool check_roman(string str){
  for (int i = 0; i < str.length(); i++){
    string temp = "";
    temp+=str[i];
    if (roman_char.find(temp) >= str.length()) return false;
  }
  return true;
}
int string_to_int(string s){
  int num = atoi(s.c_str());
  return num;
} 
int check_type (string s) {
  if (check_number(s))return 1; //integer
  else if (check_roman(s)) return -1; // roman
  else
  return ' '; //invalid
}
string Convert_to_roman(int n){
  string s ="";
   while (n >= 1000) {s += "M"; n -= 1000;}
   if (n >= 900) {s += "CM"; n -= 900;}
   if (n >= 500) {s += "D"; n -= 500;}
   if (n >= 400) {s += "CD"; n -= 400;}
   while (n >= 100) {s += "C"; n -= 100;}
   if (n >= 90) {s += "XC"; n -= 90;}
   if (n >= 50) {s += "L"; n -= 50;}
   if (n >= 40) {s += "XL"; n -= 40;}
   while (n >= 10) {s += "X"; n -= 10;}
   if (n >= 9) {s += "IX"; n -= 9;}
   if (n >= 5) {s += "V"; n -= 5;}
   if (n >= 4) {s += "IV"; n -= 4;}
   while (n >= 1) {s += "I"; n -= 1;}
  return s;
}

string Convert_to_int(string roman){
  vector<int>a;
  for (int i = 0; i < roman.length(); i++) {        
      if (roman[i] == 'I')
          a.push_back(1);
      else if (roman[i] == 'V')
          a.push_back(5);
      else if (roman[i] == 'X')
          a.push_back(10);
      else if (roman[i] == 'L')
          a.push_back(50);
      else if (roman[i] == 'C')
          a.push_back(100);
      else if (roman[i] == 'D')
          a.push_back(500);
      else if (roman[i] == 'M')
          a.push_back(1000);
  }
  int k = a[a.size() - 1];
  for (int j = (int)a.size()-1; j > 0; j--) {
      if (a[j] > a[j - 1])
          k = k - a[j - 1];
      else if (a[j] == a[j - 1] || a[j] < a[j - 1])
          k = k + a[j - 1];
  }
  string s = to_string(k);
  return s;        
}



int main(){

/* ################  DO NOT MODIFY CODE IN THIS BLOCK ###################### */
   string temp;  //variable for database filename
   string batch; //variable for batch filename

   cout<<"Enter File Name: ";
   cin>>temp;

   ifstream infile(temp, ios::binary);
   ofstream outfile( "numbers.tx", ios::binary);
   string line;
   if (infile)
        while (infile.good())
        {
            getline(infile, line);
            if (line != "")
                outfile << line << "\n";
        }

   infile.close();
   outfile.close();

   //Nhi Le
   //ntl200000
    ifstream filein(temp, ios::binary);
    ofstream fileout( "numbers.txt", ios::binary);
    vector <string> roman_number;
    
    if (filein) {
       while(!filein.eof()) {
            string roman= "";
            getline(filein,roman); 
            roman.erase(std::remove(roman.begin(), roman.end(), ' '), roman.end()); 
            roman_number.push_back(roman);
       }
    }
    
      for(int i = 0; i < (int)roman_number.size(); i++){ 
            string roman = "";
            string integer = "";
            int type = check_type(roman_number[i]); // check [i] / invalid
            if(type == 1) //int
            { 
              integer += roman_number[i];
              int k = string_to_int(integer); 
              roman += Convert_to_roman(k);
            }
            else if (type == -1) //roman
            {
              roman += roman_number[i];
              integer += Convert_to_int(roman);
            }
            fileout << setw(16) << left << roman;
            fileout << setw(4) << left << integer << endl;
        }
    filein.close();
    fileout.close();
}
