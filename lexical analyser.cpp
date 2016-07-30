#include <iostream>
#include <string>
using namespace std;
string getToken(string s)
{
         //Check for Comment
         if(s[0]=='{')
         {
                  for(int i=1; i<s.length(); i++)
                  {
                           if(s[i]=='{')
                                  return "Error";
                           else if(s[i]=='}')
                                  return "Comment";
                           else
                              ;   
                  }
             return "Comment"; // if user forgets to end the comment 
         }
    
     //Check for ID
         if((static_cast<int>(s[0])>=65 && static_cast<int>(s[0])<=90) || (static_cast<int>(s[0])>=97 && static_cast<int>(s[0])<=122))
         {
                  for(int i=1; i<s.length(); i++)
                  {
                           if((static_cast<int>(s[i])>=65 && static_cast<int>(s[i])<=90) || (static_cast<int>(s[i])>=97 && static_cast<int>(s[i])<=122))
                                  return "ID";
                           else if(static_cast<int>(s[i])>=48 && static_cast<int>(s[i])<=57)
                                  return "ID";
                                 
                  }
             return "ID";  
         }
    
    	//Check for Num
    if(static_cast<int>(s[0])>=48 && static_cast<int>(s[0])<=57)
    {
           for(int i=1; i<s.length(); i++)
                  {
                            if(static_cast<int>(s[i])>=48 && static_cast<int>(s[i])<=57)
                                  ;
                           else if((s[i])=='.')
                           {
                               if(static_cast<int>(s[s.length()-1])>=48 && static_cast<int>(s[s.length()-1])<=57)
                               { 
                                   i++;
                                   if(static_cast<int>(s[i])>=48 && static_cast<int>(s[i])<=57)
                                   {
                               for(int j=i; j<s.length(); j++)
                               {
                                   if(static_cast<int>(s[j])>=48 && static_cast<int>(s[j])<=57)
                                    ;
                                  
                               }
                           }
        else if(s[i]=='E')
        {
             if(static_cast<int>(s[s.length()-1])>=48 && static_cast<int>(s[s.length()-1])<=57)
             {
                 i++;
                     if(s[i]=='+'||s[i]=='-'||(static_cast<int>(s[i])>=48 && static_cast<int>(s[i])<=57))
                     {
                         i++;
                          for(int j=i; j<s.length(); j++)
                               {
                                   if(static_cast<int>(s[j])>=48 && static_cast<int>(s[j])<=57)
                                    ;
                                   else
                                       return "Error";
                               }
                     }
             }    
                 else
                     return "error";
        }
         
                      else
                          return "Error";
                           }
                  }
        else if(s[i]=='E')
        {
             if(static_cast<int>(s[s.length()-1])>=48 && static_cast<int>(s[s.length()-1])<=57)
             {
                 i++;
                     if(s[i]=='+'||s[i]=='-'||(static_cast<int>(s[i])>=48 && static_cast<int>(s[i])<=57))
                     {
                         i++;
                          for(int j=i; j<s.length(); j++)
                               {
                                   if(static_cast<int>(s[j])>=48 && static_cast<int>(s[j])<=57)
                                    ;
                                   else
                                       return "Error";
                               }
                     }
             }    
                 else
                     return "error";
        }
                      else
                          return "Error";
                  }
        return "num";
    }                            
         //Check for Relational op
     if(s=="="||s=="<>"||s==">"||s=="<"||s=="<="||s==">=")
     {
       return "Relational_op";
     }
         //Check for Add op
    if(s=="+"||s=="-"||s=="OR")
     {
       return "Add_op";
     }
        //Check for Multiply op
    if(s=="*"||s=="/"||s=="div"||s=="mod"||s=="AND")
     {
       return "Mul_op";
     }
       //Check for Assign op
    if(s==":=")
     {
       return "Assign_op";
     }
}

int main()
{
string input;
string token;
cout<<"Please enter the string to be analyzed."<<endl;
cin>>input;
while(input!="-1")
{
          token=getToken(input);
          cout<<"You have entered "<<token<<endl;
          cin>>input;
}
return 0;
}