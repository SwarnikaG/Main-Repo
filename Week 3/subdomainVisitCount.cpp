class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string,int> data;
        for(int i=0;i<cpdomains.size();i++){
            string eachValue = cpdomains[i];
            //cout<<"cpdomains["<<i<<"]: "<<eachValue<<endl;
            int space = eachValue.find(" ");
            //cout<<"space :"<<space<<endl;
            int number = stoi(eachValue.substr(0,space-0+1));
            //cout<<"number : "<<number<<endl;
            string rest = eachValue.substr(space+1);
            
            int current = rest.find(".");
            
            while(current!=string::npos){//string::npos is a constant (probably -1) representing a non-position
                data[rest]+=number;
                rest = rest.substr(++current);
                current = rest.find(".");
            }
            data[rest] += number;
        }
        vector<string> result;
        for(const auto elem:data){
            string toAdd = to_string(elem.second)+" "+elem.first;
            result.push_back(toAdd);
        }
        return result;
    }
};