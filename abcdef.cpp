#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 
  

int findit(int val,int *array2,int c2)
{
	int count=0;
	int pos=search(val,array2,0,c2);
	if(pos!=-1)
	{
	//	cout<<"inside";
		int i;
		i=pos;
		while(i>=0&&array2[i]==val)
			i--;
		count+=pos-i;
		i=pos+1;
		while(i<=c2&&array2[i]==val)
			i++;
		count+=i-pos-1;
		return count;
	}
	else
		return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	int array1[10000];
	int array2[10000];
	int c1,c2;
	c1=c2=-1;
	int i;
	int ans=0;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int j,k;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				array1[++c1]=arr[i]*arr[j]+arr[k];
				if(arr[i])
					array2[++c2]=arr[i]*(arr[j]+arr[k]);
			}
		}
	}

	sort(array1,array1+c1+1);
	sort(array2,array2+c2+1);

	i=0;
	while(i<=c1)
	{
		j=i;
		while(j<=c1&&array1[j]==array1[i])
			j++;
		ans+=(j-i)*findit(array1[i],array2,c2);
		i=j-1;
		i++;
	}
	printf("%d\n",ans);
	return 0;
}
