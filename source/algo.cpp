// Feras al Sabaa 
//mtr.nr 118921

#include<iostream>
#include <math.h> 
#include <sstream>
#include <vector>

double hash(std::string word)     //bekommt das Wort
{
     unsigned int count = 0;     //zahl der Buchstaben
     double hash=0;
     for (unsigned int i = 0;i < word.size();i++)  //zahl der Buchstaben
    {
        count++;
    }
    for(unsigned int i=0;i<count;i++)   
    {
      hash += double(word[i]) * pow(34,count-(i+1));  //Karp-Rabin
    }
    return fmod(hash,97);                         // mod %
  
}
bool test (std::string pattern,std::string text_word)  //testen ob in diesem Wort diese Pattern existiert
{
    bool result = false;
    int word_letter = text_word.length();      //grosse dieses wort, das wir testen wollen
    int i=0;
    int j=0;
    std::string temp="";
    int k = pattern.size();
    while(i<word_letter)          //  testen von erste position bis letzte
    {
       while(j<k)                 // nimm nur die grosse von pattern nicht mehr oder weniger
       {
           temp += text_word[j];
           j++;
       }
       if(hash(temp)==hash(pattern))   //wenn sie die gleiche hash haben
       {
           if(temp.compare(pattern)==0)  // test ob sie die gleiche buchstaben haben
           {
               result=true;      // schon gefunden 
           }
       }
           i++;   //nachste buchstabe von word
           j=i;   // nochmal gleiche position wie i
           k++;   // damit immer grosse von pattern.size()
           temp=""; //nochmal leer
    }
    return result;
}


int main()
{
    std::string text1;
    std::cout<<"enter your text please : " <<"\n";
    std::getline(std::cin,text1);
    std::string pattern;
    std::cout<<"enter your word please : " <<"\n";
    std::cin>>pattern;
    std::stringstream text(text1);
    int count=0;                       // wie viel mal kommt dieses Wort
    int pos=0;                         //im wlchen positionwort kommt dieses Wort
    std::vector <int> position;

std::string temp;
    while(getline(text,temp,' '))
    {   pos++;  
        if(pattern.length()<=temp.length())
        {   if(test(pattern,temp)==true)
           {
                count ++;
                position.push_back(pos);
           }
        }
    }
    std::cout<<"this Word occures in the whole text "<< count<<" times\n";
    for(auto a:position)
    {
        std::cout<<"in the: "<<a<<".word"<<"\n";
    }



   // suchen(a,ss);

    return 0;
}