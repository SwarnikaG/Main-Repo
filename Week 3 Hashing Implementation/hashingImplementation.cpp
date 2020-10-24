#include<iostream>
using namespace std;

class node {
    public:
        string key;
        int value;
        node* next;

        node(string key, int value){
            this->key=key;
            this->value=value;
            next = NULL; //never leave your pointers as it is, make them NULL.
        }
};

//jo hashmap h wo array type ka h aur hr bucket ek address ko hold krne ki capability rkh rhi h wo b node type ka
//toh jo b array banne wla h uska data type node* hoga
//q ki ye dynamic hone wla h isliye apko apne bucket ya array k naam k aage double star lagana pad rha h 
//ek star bta rha h ki wo pointer h q ki dynamically allocate krna hoga
//new keyword hamesha address la kr deta h heap se
//agla star h wo bta rha ki wo node* type ka h jo address hold krne ki capability rkh rha h 

class hashMap{
    private: //keeping my hash function in private so that no one can manipulate it from outside the class
        int hashfn(string key){
            int index=0;
            int mult=13;
            for(int i=0;i<key.length();i++){
                index+=mult*key[i];
                mult*=13;

                index%=ms;
                mult%=ms;
            }
            return index;
        }

        void rehash(){
            node** oldbucket = bucket; //storing oldbucket 
            int oldsize=ms;
            ms*=2; //doubling the size
            bucket=new node*[ms];

            for(int i=0;i<oldsize;i++){ //copying from oldbucket to newbucket
                if(oldbucket[i]){
                    node* head=oldbucket[i];
                    while(head){
                        insert(head->key,head->value);
                        head=head->next;
                    }
                    delete oldbucket[i]; //keep deleting the node after you are done copying
                }
            }
            delete []oldbucket; //delete the whole bucket
        }

    public:
        node** bucket; //iss bucket ka size double ho jayega jb ye 70% bhar jayegi
        int cs; //current size; also cannot initialize here cs with cs=0, because it is a class (which is just a blueprint)
        int ms; //maximum size

        hashMap(int n){
            bucket = new node*[n]; //saari bucket node* type ki chahye jaise int *arr = new int[n] krte h
            cs = 0;
            ms=n;

            for(int i=0;i<n;i++){
                bucket[i]=NULL;
            }
        }

        void insert(string key, int value){
            //kaunse bucket pr ja kr ise store krna h 
            //uss k liye index chahye, aur index nikaalne ka kaam hta h hashfunction ka
            int index=hashfn(key);
            node* temp = bucket[index];
            int flag=0;
            while(temp){ //see in main how apple is used twice but while printing it just prints once because we are skipping it
                if(temp->key==key){
                    flag=1;
                    break;
                }
                temp=temp->next;
            }
            
            if(flag!=1){ //this portion is to avoid insertion of same keys
                node* n = new node(key,value);

                if(bucket[index]==NULL){
                    bucket[index]=n;
                }else{
                    n->next=bucket[index];
                    bucket[index]=n;
                }
                cs++;
            }

            float loadFactor = cs/(ms*1.0);
            if(loadFactor>0.7){
                rehash();
            }
        }

        void print(){
            for(int i=0;i<ms;i++){
                if(bucket[i]){
                    node* head=bucket[i];
                    while(head){
                        cout<<head->key<<" "<<head->value<<" ";
                        head=head->next;
                    }
                    cout<<endl;
                }
            }
        }

        node* searchKey(string key){
            int index=hashfn(key);
            if(bucket[index]){
                node* head=bucket[index];
                while(head){
                    if(head->key==key)
                    return head;
                    head=head->next;
                }
                return NULL;
            }
        }
};

int main(){
    hashMap mp(5);
    mp.insert("apple",100);
    mp.insert("orange",250);
    mp.insert("cherry",500);
    mp.insert("banana",50);
    mp.insert("apple",400);

    mp.print();

    // cout<<endl;
    // cout<<"Search Result : "<<mp.searchKey("orange");

    return 0;
}