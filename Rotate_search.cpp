# include <iostream>
using namespace std;
# include <vector>
int find_pivot(vector<int> v){
    int s=0;
    int ind=-1;
    int e=v.size()-1;
    int mid=(s+e)/2;
    while(s<e){
         if(v[mid]>v[mid+1]){
            return mid;
        }
        if(v[mid-1]>v[mid]){
           return mid-1;
        }
        if(v[s]>v[mid]){
            e=mid-1;
        }
        else if(v[s]<v[mid]){
            s=mid;
        }
       
        mid=(s+e)/2;
    }
    return s;
}
int binary(vector<int> v ,int key,int start,int end){
    int ind=-1;
    int mid=(start+end)/2;
    while(start<=end){
        if(v[mid]==key){
            ind=mid;
            end=mid-1;
        }
        else if(v[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=(start+end)/2;
    }
   return ind;
}

int search_rotate(vector <int> v,int target){
   
   int p=find_pivot(v);
   cout<<"Pivot element :"<<p<<endl;
   int ans=-1;
   if(target>=v[0]&&target<=v[p]){
    ans=binary(v,target,0,p);
    
    return ans;

   }
    if(p<v.size()&&target>=v[p+1]&& target<=v[v.size()-1]){
    ans=binary(v,target,p+1,v.size()-1);
    return ans;
   }
   return -1;


}
 int main(){
    vector<int> c{4,5,6,7,0,1,2};
    int target=2;
    cout<<" Element found at an index :"<<search_rotate(c,target);
 }
