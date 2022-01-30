/*
    Author: 
        Team DARr:
            Dev Vora
            Atharva Verma
            Richa Monserate
    Project: Cyber-Cypher Elementary
    Start Date:29-01-2022
    End Date:30-01-2022
*/
#include <string>
#include <bits/stdc++.h>
using namespace std;

class encryption
{
    public:
        //Function used to shift the characters of the inputted string.
        string shift(string before_shift,int sc)
        {
            string after_shift="";
            char ch;
            int len=before_shift.length();
            if(len>10)
            {
                sc=len;        
            }
            for (int i=0;i<len;i++)
                {
                    ch=before_shift.at(i);
                    if ((char)(ch+sc)>'Z')
                        after_shift += (char)((ch+sc-1)-'Z'+'A');
                    else
                        after_shift += (char)(ch+sc);
                }    
            return after_shift;
        }
        
        //Function used to encrypt the string
        string encrypt(string unencrypt_word, int s)
        {
            string encrpyt_word = "";
            int len=unencrypt_word.length();
            if(s%26==0)
            {
                s=26;
            }
            else
            {
                s%=26;
            }
            if((len<11)&&(s<=26))
            {
                encrpyt_word=shift(unencrypt_word,s);
                while(encrpyt_word.length()<=10)
                {
                    encrpyt_word+='0';
                }
                encrpyt_word+=(char)('a'+s-1);
            }
            else if(len==11)
            {
                encrpyt_word=shift(unencrypt_word,s);
                encrpyt_word+="/";
            }    
            else
            {
                encrpyt_word=shift(unencrypt_word,s);
            }
            return encrpyt_word;
        }
        
        //Function used for accepting a sentence word by word and the shift value for each word;then encrypting it gradually.
        void encrypt_end_result()
        {
            string word,encrpt_result="",original_statment="";
            int shift=0;
            //To stop the process of encrypting data.
            cout<<endl<<"Enter STOPSTOPSTOP to stop encrypting"<<endl;
            while(true)
            {
                cout<<"Enter word: ";
                cin>>word;
                if(word.compare("STOPSTOPSTOP")==0)
                {
                    break;
                }
                else
                {
                    original_statment+=word+" ";
                }
                if(word.length()<11)
                {
                    cout<<"Enter shift: ";
                    cin>>shift;
                }
                encrpt_result+=encrypt(word,shift)+" ";
                cout<<"Encryption until now: "<<encrpt_result<<endl<<endl;
                
            }
            cout<<endl<<"Original String: "<<original_statment<<endl
                <<endl<<"Encrpted String: "<<encrpt_result<<endl;
        }
    
};

class decryption
{
    public:
    
        string decrypt(string encryted_word)
        {
            int len = encryted_word.length(),shift,i=0;
            char ch;
            string decrypted_word,str="";//"str" will store the part that is needed to decrypted.
        
            if (encryted_word[len - 1] >= 'a' && encryted_word[len - 1] <= 'z')
            {
                int b = encryted_word[len - 1];
                shift = int(b) - 96;
            }
            else if (encryted_word[len - 1] == '/')
            {
                shift = 11;
            }
            else
            {
                shift = len;
            }
        
            //To ignore the trash values at the end of a string and consider the main alphabetic part.
            for(i=0;i<len;i++)
            {
                if((encryted_word[i]=='0')||(encryted_word[i]=='/'))
                {
                    break;
                }
                str+=encryted_word[i];
            }
            
            for (i = 0; i < str.length(); i++)
            {
                ch=str.at(i);
                if ((char)(ch-shift)<'A')
                    decrypted_word += (char)((ch-shift+1)-'A'+'Z');
                else
                    decrypted_word += (char)(ch-shift);
            }
            return decrypted_word;
        }
        
        //Function used for accepting a sentence then decrypting it.
        void decrpyt_end_result()
        {
            string encrypt_str,separated_word,decrypt_result;
            cin.ignore();
            cout<<"Enter the Encrypted Message: ";
            getline(cin,encrypt_str);
            encrypt_str+=" ";
            for(int i=0;i<encrypt_str.length();i++)
            {
                if(encrypt_str[i]==' ')
                {
                    decrypt_result+=decrypt(separated_word)+" ";
                    separated_word="";
                }
                else
                {
                    //To separated words and decrpyting them indivially.
                    separated_word+=encrypt_str[i];
                }
            }
            cout<<"The decrypted message is : "<<decrypt_result<<endl;
        }
    
};

int main()
{
    encryption obj1; //Creation of Object "obj1" for Encryption.
    decryption obj2; //Creation of Object "obj2" for Decrpytion.
    string id,password,tran;
    char ch;
    while(true)
    {
        Credentials://"Credentials" Label for a goto used.
        cout<<"Enter I.D."<<endl
            <<"Enter EXIT to exit. "<<endl
            <<"Enter: ";
        //Ideal ID for the Spies is "admin".
        cin>>id;
        if(id.compare("EXIT")==0)
        {
            return 0;
        }
        cout<<"Enter Password: ";//Ideal Password for the Spies is "CYBERCYPHER".
        cin>>password;
        cout<<endl;
        if((id.compare("admin")==0)&&(password.compare("CYBERCYPHER")==0))
        {
            //For accepting the choice of conversion required by the spy
            cout<<"Enter E/e for Encryption"<<endl
                <<"Enter D/d for Decryption"<<endl
                <<"Enter Your Choice: ";
            cin>>ch;
            
            //Message to the user as all the Encryption and Decryption is be done for Capital Characters
            cout<<endl<<"TURN CAPSLOCK ON"<<endl;
            while((ch!='e')&&(ch!='E')&&(ch!='d')&&(ch!='D'))
            {
                cout<<"Enter a Valid Choice (e/E/d/D): ";
                cin>>ch;
            }
            if(ch=='E'||ch=='e')
            {
                obj1.encrypt_end_result();     
            }
            else if(ch=='D'||ch=='d')
            {
                cout<<endl;
                obj2.decrpyt_end_result();    
            }
            
        }
        else if(id.compare("admin")==0)
        {
            cout<<endl<<"Enter Correct Credentials:"<<endl;
            //To goto label "Credentials" if the spies has enter a wrong password by mistake
            goto Credentials;
        }
        else
        {
            //To make the Transaction procedure look more realistic.
            cout<<"Please Enter Transaction I.d.:";
            cin>>tran;
            cout<<"Transaction Id:"<<tran<<" has been successfully added.";
        }
        cout<<endl;
    }
    return 0;
}
