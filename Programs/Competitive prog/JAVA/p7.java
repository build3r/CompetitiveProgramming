import java.util.Scanner;
class p7
{
    void smallestLargest()
    {
        int n,i=0,j,t,a[]=new int[100];
        Scanner s=new Scanner(System.in);
        System.out.println("Enter number of numbers");
        n=s.nextInt();
        while((i)<n)
            a[i++]=s.nextInt();
        for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
        {
            if(a[i]>a[i+1])
            {
             t=a[i];
             a[i]=a[i+1];
             a[i+1]=a[i];
            }
        }
         System.out.println("Smallest number="+a[0]);
         System.out.println("Largest number="+a[n-1]);
    }
    public static void main(String ar[])
    {
       p7 d=new p7();
        d.smallestLargest();
    }
};
