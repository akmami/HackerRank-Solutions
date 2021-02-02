#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
   string str;
   cin >> str;
   int q, n, length=(int)str.length(), arr[26], count=str[0]-96, i;
   cin >> q;
   for(i=0; i<26; i++) {
       arr[i]=0;
   }
   for(i=1; i<length; i++) {
       if(str[i]==str[i-1]) {
           count=count+str[i-1]-96;
       } else {
           if(arr[str[i-1]-97]<count)
               arr[str[i-1]-97]=count;
           count=str[i]-96;
       }
   }
   if(length==i) {
       if(str[i-1]==str[i-2])
           count=count+str[i-1]-96;
       else
           count=str[i-1]-96;
       if(arr[str[i-1]-97]<count)
           arr[str[i-1]-97]=count;
   }
   while(q--) {
       cin >> n;
       bool res=false;
       for(i=0; !res && i<26; i++) {
           if(arr[i]>=n && n%(i+1)==0)
               res=true;
       }
       if(res) {
           cout << "Yes" << endl;
       } else {
           cout << "No" << endl;
       }
   }
   return 0;
}

