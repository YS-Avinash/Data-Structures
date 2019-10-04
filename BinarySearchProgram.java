import java.io.*;
import java.util.*;
class BinarySearchProgram
{
	static int arr[];
	public static void main(String[] args)throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter elements seperated by commas:");
		StringTokenizer str = new StringTokenizer(br.readLine(),",");
		arr = new int[str.countTokens()];
		int i=str.countTokens();
		int loc=0;
		while(str.hasMoreTokens()){
			arr[loc]=Integer.parseInt(str.nextToken());
			loc++;
		}
		Arrays.sort(arr); 
		System.out.println("The elements in sorted order is ");
		for(int x:arr)
			System.out.print(x+" ");
		System.out.println("\n");
		System.out.print("Enter a key to search:");
		loc = binarySearch(Integer.parseInt(br.readLine()),i-1);
		if(loc>=0)
			System.out.println("Element found at "+(loc+1));
		else 
			System.out.println("Element Not Found.");
	}
	public static int binarySearch(int key,int n){
		return search(0,n,key);
	}
	public static int search(int first,int last,int key){
		int mid = (first+last)/2;
		if(first<=last)
		{
			if(arr[mid]>key)
				return search(0,mid-1,key);
			else if(arr[mid]<key)
				return search(mid+1,last,key);
			else
				return mid;
		}
		else 
			return -1;
	}
}