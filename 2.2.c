#include <stdio.h>

struct SqList{
    int data[100000];
    int length;
};

        

//2.2-1
int Del_Min(SqList &L,int &e){
    if(L.length == 0);
    return false;
int k = 0;
k = L.data[0];
int flag = 0;
    for (int i = 0, i <length, i++){
        if(L.data[i]<k)
        {
            k=L.data[i];
            flag = i;
        }
    }
L.data[flag] = L.data[L.length-1];
L.length--;
e = L.data[flag];
return true;


//2.2-2
int Back(SqList &L){
    int i,flag;
    if(L.length%2==0)                        //答案并没有给出分类讨论
        for (i =0, i <=L.length/2  ,i++){
            flag = L.data[i];
            L.data[i]=L.data[L.length-i-1];
            L.data[L.length-i-1]=flag;
        }
    else
        for(i = 0,i<=(L.length-1)/2,i++){
          flag = L.data[i];
            L.data[i]=L.data[L.length-i-1];
            L.data[L.length-i-1]=flag;
        }
}


//2.2-3
int Del_X(SqList &L,int x){
    for(int i =0,i<L.length,i++){            //这个思路有点问题，如果按照这样进行下去的话数组元素会发生改变
        if(L.data[i]==x){
            L.data[i]=L.data[i+1];
            i--;
            L.length--;
        }
    }
}


//2.2-3-改
int Del_X(SqList &L,int x){
    int i,k=0;
    for(i = 0,i<L.length,i++){
        if(L.data[i]!=x){
            L.data[k]=L.data[i];
            k++;
        }
    }
    L.length = k;
}


//2.2-4
bool Del_ST(SqList &L,int min,int max){
    if(min>=max||L.length == 0){
        return false;
    }
    else{
    int i,k=0;
    for(i = 0,i<L.length,i++){
        if(L.data[i]<min&&L.data[i]>max){        //注意：此题中的顺序表是有序的，故若要删除就要删除连续的一整片，故可不用上题中的方法。
            L.data[k]=L.data[i];
            k++;
        }
    }
    L.length = k;
    return true;
    }
}

//2.2-4-for部分修改
    for(i=0;i<L.length&&L.data[i]<min;i++){
        if(i>=L.length){
            return false;
        }
    }
    for(j = i;j<L.length&&L.data[j]<=max;j++){
    }
    for(;j<L.length;j++){                            //Very Important
        L.data[i] = L.data[j];
        i++;
    }
    L.length =i;
    return true;
    
     
//2.2-5
bool Del_ST(SqList &L,int min,int max){
    if(min>=max||L.length == 0){
        return false;
    }
    else{
    int i,k=0;
    for(i = 0,i<L.length,i++){
        if(L.data[i]<min&&L.data[i]>max){        //注意：此题中的顺序表是有序的，故若要删除就要删除连续的一整片，故可不用上题中的方法。
            L.data[k]=L.data[i];
            k++;
        }
    }
    L.length = k;
    return true;
    }
}


//2.2-6
int Del_Repeat(SqList &L){
    int i,flag,k;
        for(i = 0,i<L.length,i++){
            if(L.data[i]!=L.data[i+1]){
                L.data[k]=L.data[i];
                k++;
            }  
        }
        L.length = k;
}


//2.2-7
void ComplexAB(SqList A,SqList B,SqList &C){
    int i,k,flag,j=0;
    for(i = 0,i<A.length,i++){                                //这里出错：应该是让i<A.length并且j<B.length
          if(A.data[i]<=B.data[j]){
              C.data[k]=A.data[i];
              k++;
          }  
          else{
              C.data[k] = B.data[j];
              j++;
              k++;
          }
        }    
}


//2.2-7-改
void ComplexAB(SqList A,SqList B,SqList &C){
    int i=0,k,flag,j=0;
    while(i<A.length&&j<B.length){                            //Error Correct Start
          if(A.data[i]<=B.data[j]){
              C.data[k++]=A.data[i++];                            //This kind of code style can reduce the use of space. 
          }  
          else{
              C.data[k++] = B.data[j++];
          }
        }
    while(i<A.length){
        C.data[k++]=A.data[i++];
        }
    while(j<B.length){
        C.data[k++]=B.data[j++];
        }
}


//2.2-8                    
//This Program is a little difficault, so I immediately search the answer. The way of the answer is very useful.Suggest to have a look.

//Central Thought:Exchange all of them at first,then exchange first n then last m.
void Reverse(int A[],int left, int right,int Size){
    if(left>=right||right>=Size){
        return ;
    }
    int mid = (left+right)/2;
    for(int i = 0; i<=mid-left ;i++){
        int t = A[i+left];
        A[i+left] = A[right-i];
        A[right-i]=t;
    }
}
void Exchange(int A[],int left,int right,int Size){
    Reverse(A,0,m+n-1,Size);
    Reverse(A,0,n-1,Size);
    Reverse(A,n,n+m-1,Size);
}


//2.2-9
int Find_X(SqList &L,int x){
    int i,f,k;
    for(i = 0,i<L.length,i++){
        if(L.data[i]<x){
            
        }
    }
}


//2.2-9-改
//此题使用折半查找法，最大限度节省时间。
void SearchExchangeInsert(int L[], int x){
    int low = 0,high = n-1,mid,t;
    while(low<=high){
        mind = (high+low)/2;
        if(A[mid] == x) break;
        else if(A[mid]<x) low = mid+1;
        else(A[mid]>x) high = mid-1;
    }
    if(A[mid]==x&&mid!=n-1){
        t=A[mid];
        A[mid] = A[mid+1];
        A[mid+1] = t;
    }
    if(low>high){
        for(i = n-1;i>high;i--) A[i+1]=A[i];
        A[i+1]=x;    
    }
}


//2.2-10
//This code is simple with 2.2-8.Suggest to complete this two code.
void Reverse(int R[],int from,int to){
    int i,t;
    for(i = 0; i<(to-from+1)/2 ;i++){
        t = A[from+i];
        A[from+i] = A[to-i];
        A[to-i]=t;
    }
}
void Exchange(int R[],int from,int to){
    Reverse(R,0,p-1);
    Reverse(R,p,n-1);
    Reverse(R,0,n-1);
}


//2.2-11
//我的基本思想：先把两个数组合并在一起，然后找这个大数组的中位数。此时算法的时间复杂度为O(n)，空间复杂度为O(n)。
//答案的基本思想：先比较这两个中位数，若相等，则说明这个就是合并后的中位数，若不等，则两个数组各舍弃一半。此时算法的时间复杂度为O(log2(n))，空间复杂度为O(1)
//此处直接给答案的做法
int Middle(int A[],int B[],int n){
    int s1=0,d1=n-1,m1,s2=0,d2=n-1,m2;
    while(s1!=d1||s2!=d2){
        m1=(s1+d1)/2;
        m2=(s2+d2)/2;
        if(A[m1]==B[m2]){
            return A[m1];
        }
        if(A[m1]<B[m2]){
            if((s1+d1)%2==0){            //Waring:这才是奇数的情况，例如：(0+2)%2=0，此时有三个数0.1.2
            s1=m1;
            d2=m2;    
            }
            else{
            s1=m1+1;                            //m1+1是为了让两个数组的元素个数相等，在int中，若有小数，则小数部分直接被截断，故在有偶数个数的时候会出现一点问题。
            d2=m2;
            }
        }
        else{
            if((s1+d1)%2==0){
            d1=m1;
            s2=m2;    
            }
            else{
            d1=m1;
            s2=m2+1;
            }
        }
    }
    return A[s1]<B[s2]? A[s1]:B[s2];        //⚠️注意返回值的格式
}


//2.2-12
//"次优算法"：在真正考试的时候一定不可能想到最优算法，此时只要用次优算法来完成要求即可。
//本题次优算法：用空间换时间：开辟一个B数组专门用来保存A数组每个元素出现的次数，然后扫描一遍B数组即可获得答案，此时T(n)=O(n),S(n)=O(n)
int MainElm(int A[],int n){
    int i,B[];
    for(i=0;i<n;i++){
        B[A[i]]++;    
    }
      for(i=0;i<n;i++){
        B[i]>n/2;
        return i;    
    }
    return -1;          
}

//"次优算法"真实可运行代码（结果无误）
#include <stdio.h> 
#include <stdlib.h>

int MainElm(int A[],int n){
    int i,B[10],f=0;
    memset(B,0,sizeof(B));            //千万别忘了重置B数组，否则就会报错
    for(i=0;i<n;i++){
        f=A[i];
        B[f]++;
    }
      for(i=0;i<n;i++){
        if(B[i]>n/2){
         return i;   
        }
             
    }
    return -1;          
}

int main(){
    int A[8]={0,5,5,3,5,1,5,7};
    //MainElm(A,8);
    int a = MainElm(A,8);
    printf("%d\n",a);
return 0;
}


//2.2-13
//我的思想：空间换时间，开辟一个B数组，专门用来存某一位的整数是否出现过，然后扫描B数组即可。
//答案给出两个需要及其注意的细节，此处直接说答案。
int FindMissMin(int A[],int n){
    int i,B*;
    B=(int *)malloc(sizeof (int)*n);            //注意B数组动态分配空间以及初始化的过程，很重要！！！
    memset(B,0,sizeof(int)*n);
    for(i=0;i<n;i++){
        if(A[i]>0&&A[i]<=n){
            B[A[i]-1]=1;
        }
    }
    for(i=0,i<n;i++){
        if(B[i]==0)  break;
    }
    return i+1;
}
