#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int main()
{
	vector<int>index;	//for index	
	vector<int>founded_at;	//for reference
	vector<string>str;	//stores string in table
	vector<char>ch;	//for decoding through table
	string s1;	//input string
	cout<<"\n Enter the string:";
	cin>>s1;
	int i=0,ind=0,k=1,flag1=0;
	cout<<"\n\t ENCODER \t\t INDEX \t\tENTRY";
	while(i<s1.length())
	{
		int temp_index=0;
		string temp,sub;
		cout<<"\n";
		for(k=1;k<=index.size();k++)	//check for all the available characters
		{
			sub=s1.substr(i,str.at(k-1).length());	//take length as string[at table]
			if(sub==str.at(k-1))	//match found in table
			{
				temp_index=k;
				temp=sub;
			}
		}
		if(temp_index!=0)	//match found
		{
			if(i+(str.at(temp_index-1).length())<s1.length())	//if it is in s1.length
			{
				temp+=s1.at(i+str.at(temp_index-1).length());	
			}
			else	//if last portion is already available in table
			{
				flag1=1;
				temp='\0';
			}
		}
		else	//match not found
		{
			if(i<s1.length())	//if is in range
			{
				temp+=s1.at(i);
			}
			else	//if exceeds string.length() ->maybe this case is not possible
			{
				flag1=1;
				temp='\0';
			}
		}
		founded_at.push_back(temp_index);
		ind+=1;
		if(flag1==0)	//if match is not found at end
		{
			str.push_back(temp);
			index.push_back(ind);
			i+=temp.length();
			ch.push_back(temp.at(temp.length()-1));
			cout<<"\t< "<<temp_index<<" , "<<temp.at(temp.length()-1)<<" > "<<"\t\t "<<ind<<"\t\t"<<temp;	
		}
		else	//if match is found, put '-' as ending symbol
		{
			str.push_back("-");
			index.push_back(ind);
			i+=temp.length();
			ch.push_back('-');
			cout<<"\t< "<<temp_index<<" , "<<"-"<<" > "<<"\t\t "<<ind<<"\t\t"<<temp;			
			break;
		}
	}
	i=0;
	vector<string>decode_karisu;	//decoding_string_vector_in_table
	string final_decoding_string;	//string as decoding result
	while(i<ch.size())
	{
		if(ch.at(i)!='-')	//if it is not end
		{
			if(founded_at.at(i)==0)	//if it is not available in table
			{
				string abcd;
				abcd+=ch.at(i);
				decode_karisu.push_back(abcd);
				final_decoding_string+=abcd;			
			}
			else	//else take reference of table 
			{
				string abcd;
				abcd+=decode_karisu.at(founded_at.at(i)-1);
				abcd+=ch.at(i);
				decode_karisu.push_back(abcd);
				final_decoding_string+=abcd;
			}		
		}
		else	//ending portion is present in table 
		{
			string abcd=decode_karisu.at(founded_at.at(i)-1);
			final_decoding_string+=abcd;
		}
		i++;
	}
	cout<<"\n decoded string:"<<final_decoding_string;
	return 0;	
}
