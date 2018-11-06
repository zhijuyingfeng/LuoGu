public class Main
{
    //reverse elements in array from index L to index R(L and R included)
    public static  void reverse(int[]arr,int L,int R)
    {
        int temp;
        for(int i=0;i<(R-L+1)/2;i++)
        {
            temp=arr[L+i];
            arr[L+i]=arr[R-i];
            arr[R-i]=temp;
        }
    }

    /*
    three steps:
    1. reverse the whole array
    2. reverse the front k elements
    3. reverse the rear n-k elements
     */
    public static void move(int[]arr,int k)
    {
        reverse(arr,0,arr.length-1);
        reverse(arr,0,k-1);
        reverse(arr,k,arr.length-1);
    }

    //Find the greatest common divisor
    public static int GCD(int a,int b)
    {
        int temp;
        while(a%b>0)
        {
            temp=a%b;
            a=b;
            b=temp;
        }
        return b;
    }

    //数组循环右移
    public static void loop(int[]arr,int k)
    {
        int n=arr.length;
        for(int i=0;i<GCD(n,k);i++)
        {
            int temp=arr[n-i-1];
            int j=n-1-i-k;
            while(j!=n-1-i)
            {
                arr[(j+k)%n]=arr[j];
                j=(j-k+n)%n;
            }
            arr[(j+k)%n]=temp;
        }
    }

    public static void ShowArray(int []arr)
    {
        for(int i=0;i<arr.length;i++)
        {
            System.out.printf("%d ",arr[i]);
        }
        System.out.println();
    }

    public static void compare(int n,int k)
    {
        int[]A=new int[n];
        int[]B=new int[n];
        for(int i=0;i<n;i++)
        {
            A[i]=i;
            B[i]=i;
        }
        loop(A,k);
        System.out.print("Loop:");
        ShowArray(A);
        move(B,k);
        System.out.print("Move:");
        ShowArray(B);
    }

    public static void main(String[]args)
    {
        compare(11,4);
    }
}
