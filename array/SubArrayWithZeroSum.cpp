#include<iostream>
#include<map>
using namespace std;

// the function takes array and checks whether a subarray with sum as 0 
//exits within array or not 
bool checkSubArray(int arr[],int n){

  //the below code works on time complexity of  O(N^2)  and space complexity of   O(N)
   // if(arr[0]==0)
   //      return true;
   //      int sum;
   //      for(int i=0;i<n;i++){
   //          sum=0;
   //          for(int j=i;j<n;j++){
   //              sum+=arr[j];
   //              if(sum==0)
   //              return true;
   //          }
   //      }
   //      return false;


  // the better approach which works on time complexity of  O(N) is as follows 
  // but it takes space complexity of O(N)
   int sum=0;
map<int,bool> mp;
  for(int i=0;i<n;i++){
    sum+=arr[i];
    if(sum==0)
      return true;
    if(mp[sum]==true)
      return true;
    else
      mp[sum]=true;
}
return false;

}

int main(){
int n;
cout<<"enter the size of array"<<endl;
cin>>n;
int arr[n];
  cout<<"enter the elements of array"<<endl;
for(int i=0;i<n;i++){
cin>>arr[i];
}

if(checkSubArray(arr,n))
cout<<"true";
else
cout<<"false";

return 0;
}
