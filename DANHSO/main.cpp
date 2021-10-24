#include<bits/stdc++.h>
using namespace std;
void Sochuso(int n){

        int dem=0;
        int k=n;
        while(n!=0){
                dem++;

                n=n/10;

        }

        int i=dem;

        int p=(k-pow(10,i-1)+1)*i;

        int m=0;

        for(int j=i-1;j>0;j--){

                m=m+(pow(10,j)-pow(10,j-1))*j;

        }

        int S=m+p;

        cout<<S;

}



int main(){
	 int n;

        cin>>n;
    Sochuso(n);
}
