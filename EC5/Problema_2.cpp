#include <iostream>
#include <vector>
using namespace std;


class HashNode{
    public:
    int key;
    string name;

    HashNode(int key,string name){
        this->key=key;
        this->name=name;
    }
};


class HashTable{
    private:
    HashNode** data;
    int size;

    int HashFunction(int key){
        return key%size;
    }

    public:
    HashTable(int size){
        this->size=size;
        data=new HashNode* [size];
        for (int i = 0; i < size; i++){
            data[i]=NULL;
        }
    }

    void Display(){
        for (int i = 0; i < size; i++){
            if (data[i]!=NULL){
                cout<<"Index: "<<i
                <<" Key: "<<data[i]->key
                <<" Name: "<<data[i]->name
                <<endl;
            }
        }
    }

    void Insert(HashNode* item){
        int key= item->key;
        int hash= HashFunction(key);
        while (data[hash]!=NULL)
        {
            ++hash;
            hash %= size;
        }
        data[hash]=item;
    }

    //Buaca elemento por clave
    HashNode* Find(int key){
        int hash= HashFunction(key);
        while (data[hash]!=NULL)
        {
            if (data[hash]->key==key)
            {
                return data[hash];
            }
            hash++;
            hash=hash%size;
        }
        return NULL;        
    }
};


class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int conbinaciones=0;
        HashTable hasht(10);
        int id=0;
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < nums.size(); j++){
                if (i!=j && nums[i]+nums[j] == target){
                    //Guardamos los pares ordenados
                    string a=to_string(i);
                    string b=to_string(j);
                    HashNode nodo(id,"(" + a + "," + b + ")");
                    hasht.Insert(&nodo);
                    id++;
                } 
            }  
        }
        //Buscamos en la tabla hash las coordenadas guardadas
        for (int i = 0; i < id; i++){
            HashNode* r=hasht.Find(i);
            conbinaciones++;
        }
        return conbinaciones;      
    }

       
};

int main(){
    vector<string> v={"777","7","77","77"};
    string target="7777";

    Solution solution;
    int s=solution.numOfPairs(v,target);
    cout<<s<<endl;    
    
    vector<string> v2={"123","4","12","34"};
    string ta="1234";
    Solution sol;
    int s1=sol.numOfPairs(v2,ta);
    cout<<s1<<endl; 

    vector<string> v3={"1","1","1"};
    string tar="11";
    Solution solu;
    int s2=solu.numOfPairs(v3,tar);
    cout<<s2<<endl;   
}