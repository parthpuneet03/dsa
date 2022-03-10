#include<stdio.h>
#include<conio.h>
//non-recursive
int lSearch(int* a,int val, int n){
    for(int i=0; i<n; i++){
        if(a[i]==val){
            return i;
            break;
        }
        else{
            continue;
        }
    }
    return -999;
}
//non recursive
void Bsearch(int *a, int val, int size){
    int beg, mid, end;
    beg=0;
    end=size-1;
    while(beg<=end){
        mid=(end+beg)/2;
        if(a[mid]==val){
            printf("element found at postion %d", mid );
            return;
        }
        else if(val >a[mid]){
            beg=mid+1;
        }
        else{
            end=mid-1;
        }
    }

}

int main(){
    int a[10]={1,2,3,4,5,6};
    /*int loc=linearSearch(a,4,6);
    if(loc!=-999){
        printf("element found at %d location",loc);
    }
    else{
        printf("Element not found");
    }*/
    Bsearch(a, 4, 6);
}
