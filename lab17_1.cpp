//Write your code here
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;

string upper(string x){
    int i = 0;
    while(x[i]){
        x[i] = toupper(x[i]);
        i++;
    }
    return x;
}

string upper(string );

int main(){
    vector<string> name;
    vector<string> grade;
    int num1,num2,num3,Gradenum;
    string Gd;
    char Name[100];
    ifstream n("name_score.txt");
    string N;
    while(getline(n,N)){
        sscanf(N.c_str(),"%[^:]:%d %d %d",Name,&num1,&num2,&num3);
        name.push_back(Name);
        Gradenum = 0;
        Gradenum = num1+num2+num3;
        if(Gradenum >= 80) Gd = "A";
        else if(Gradenum >=70 && Gradenum <= 79) Gd = "B";
        else if(Gradenum >=60 && Gradenum <= 69) Gd = "C";
        else if(Gradenum >=50 && Gradenum <= 59) Gd = "D";
        else if(Gradenum < 50 ) Gd = "F";
        grade.push_back(Gd);
        
    }
      
    while(1){
        string s;
        cout << "Please input your command :";
        getline(cin,s);
        int idx = s.find_first_of(" ");
        string s1 = upper(s.substr(0,idx));
        string s2 = upper(s.substr(idx+1,s.size()));
        if(s1 == "NAME"){
            cout << "---------------------------------" << "\n";
            int n=0;
            for(int i=0;i<s.size();i++){
                
                if(s2 == upper(name[i])){
                    cout << name[i] << "'s grade = " << grade[i] << "\n";
                    n++;
                }
            }
            if(n == 0) cout << "Cannot found." << "\n" ;
            cout << "---------------------------------" << "\n";
        }else if(s1 == "GRADE"){
            cout << "---------------------------------" << "\n";
            for(int i=0;i<grade.size();i++){
                if(s2 == upper(grade[i])) cout << name[i] << "\n";
            }
            cout << "---------------------------------" << "\n";
        }else if(s1 == "EXIT"){
            break;
        }else{ cout << "Invalid command" << "\n";}
    }
}

   