#include<bits/stdc++.h>
using namespace std;

map<string, int> mp;

bool wordSearch(string s){
	if(mp.find(s) != mp.end()){
		mp[s]++;
		return true;
	}
	return false;
}

bool prefixSerach(string a, string b){
	if(b.size() > a.size()) return false;
	int i=0;
	while(i<b.size()){
		if(a[i] != b[i]) return false;
        i++;
	}
	return true;
}

vector<string> prefixBasedSuggestion(string s, int k){
	int count = 0;
	vector<string> res;
	for(auto it : mp){

        string temp = it.first;
        
        
		if(prefixSerach(temp, s)){
			res.push_back(it.first);
            count++;
		}
       
		if(count == k) break;
	}
	sort(res.begin(), res.end());
	return res;
}

bool addWord(string s){
	if(mp.find(s) != mp.end()){
		return true;
	}
	mp[s] = 1;
	return false;
}



int main(){
	
	while(1){
		cout<<"Enter 1 for Word Search \n";
		cout<<"Enter 2 for prefix Based Suggestion \n";
		cout<<"Enter 3 for Add Word \n";
		cout<<"Enter 4 for exist from searching feature \n\n";
		
		int n;
		
		cout<<"Enter the value of number \n";
		
		cin>>n;
		
		switch(n){
			case 1: {
				string s;
				cout<<"Enter the word you want to search : ";
				cin>>s;
				if(wordSearch(s)){
					cout<<"Found\n";
				}
				else{
					cout<<"Not Found\n";
				}
				
				break;
			}
			case 2:{
				
				string s;
                int k;
                cout<<"Enter string s for prefix-Based Suggestion \n";
                cin>>s;
                cout<<"Enter the value of k for prefix-Based Suggestion \n";
				cin>>k;
				vector<string> res = prefixBasedSuggestion(s, k);
				if(res.size() == 0){
					cout<<"No suggestion will be availabe for given prefix string";
				}
				else{
					for(auto r : res){
						cout<<r<<", ";
					}
					cout<<"\n";
				}
				break;
			}
			
			case 3:{
				string s;
				cout<<"Enter the word you want to add in dictionary : ";
				cin>>s;
				if(addWord(s)){
					cout<<"already exist\n";
				}
				break;
			}
			
			case 4:{
				exit(0);
			
			}
		}
		
		cout<<"\n\n";
		
		
		
		
	}
	return 0;
}
