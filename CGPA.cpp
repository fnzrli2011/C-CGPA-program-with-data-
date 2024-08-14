#include <cstddef>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  cout<<"Balinizi Hesablaymaq ucun 1 e basin ,  Baliniza baxmaq ucun 2 e basin : ";
  int choice;
  cin>>choice;
  if(choice==1){
    ofstream dosya("Data.txt",ios::app);
    int NumOfCourse;
    double Point , Sum;
    string Name , Surname;
    cout<<"Adinizi Daxil Edin : ";
    cin>>Name;
    cout<<"Soyadinizi Daxil Edin : ";
    cin>>Surname;
    cout<<"Nece dene Kursda Istirak etmisiniz : ";
    cin>>NumOfCourse;
    for(int i=0;i<NumOfCourse;i++)
    {
        cout<<i+1<<"-ci Kursdaki Balinizi Daxil Edin : ";
        cin>>Point;
        Sum+=Point;
    }
    double Averge_Point = Sum/NumOfCourse;
    cout<<Name<<" "<<Surname<<" "<<"Ortalama Baliniz : "<<Averge_Point<<"-dir";
    dosya<<Name<<" "<<Surname<<" Ortalama Bal : "<<Averge_Point<<endl;
    dosya.close();
  }
  else {
    ifstream data("Data.txt");
    string line;
    bool found = false;
    string name,surname;
    cout<<"Adinizi Daxil Edin : ";
    cin>>name;
    cout<<"Soyadinizi Daxil Edin : ";
    cin>>surname;
    string search = name + " " + surname;
    while(getline(data,line))
    {
      if(line.find(search)==0)
      {
        cout<<line<<endl;
        found = true;
      }
    }
    if(found==false)
    {
      cout<<"Bele istifadeci tapilmadi"<<endl;
    }
  }
}
