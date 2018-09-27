#include <bits/stdc++.h>

using namespace std;

int n,t,mt,i,j;
string s;
string author,title,pages,journal,year,volume,pages1,number;

int main() {
    std::ios::sync_with_stdio(false);
    cin>>t;
    while (t--) {
        cin>>n;
        getline(cin,s);
        while (n--) {
            getline(cin,s);
            for (mt=0;mt<8;mt++) {
                getline(cin,s);
                string st="",en="";
                for (i=0;i<s.size();i++)
                    if (s[i] == '=') break; else
                    st+=s[i];
                    int x=2;
                    if (mt == 7) x=1;
                for (j=i+2;j+x<s.size();j++)
                    en+=s[j];
                if (st == "author")
                    author=en;
                
                if (st == "title")
                    title=en;
                if (st == "pages")
                    pages1=en;

                if (st == "journal")
                    journal=en;
                
                if (st == "year")
                    year=en;
                if (st == "volume")
                    volume=en;
                
                if (st == "number")
                    number=en;
            }
            getline(cin,s);
            s=author;
            s+=",";
            string name="",surname="";
            bool ff=0;
            for (i=0;i<s.size();i++) {
                if (s[i] == ',') {
                    cout<<name[0]<<name[1]<<". "<<surname[0];
                    if (i+1 == s.size()) cout<<". "; else
                    cout<<", ";
                    name=surname="";
                    i++;
                    ff=0;
                    continue;
                }
                if (s[i] == ' ') { ff=1; continue; }
                if (ff == 0) name+=s[i]; else surname+=s[i];
            }
            cout<<title<<". "<<journal<<". "<<year<<";"<<volume<<"("<<number<<"):"<<pages1<<"."<<endl;
        }
    }
}