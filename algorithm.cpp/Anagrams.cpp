#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s1 ,string s2){
     int l1=s1.length(),l2=s2.length();
     int alphaArr[26]={0};
     if(l1!=l2){
          return false;
     }
     for(int i=0;i<l1;i++){
        if(isalpha(s1[i])&& isalpha(s2[i])){
            tolower(s1[i]);
            tolower(s2[i]);
            alphaArr[s1[i]-'a']++;
            alphaArr[s2[i]-'a']--;
        }
     }
     for(int i=0;i<26;i++){
        if(alphaArr[i]!=0){return false;}
     }
     return true;

}
int main(){
    string s1="Listen",s2="Silent";
    cout<<isAnagram(s1,s2)<<endl;

}