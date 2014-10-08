import java.util.*;
class p6
{
    int numUnique(int a,int b,int c)
    {
        int i=0;
        if((a-b)!0)
        i++;
        if((a-c)!0)
            i++;
        if((b-c)!0)
            i++;
        return i;
    }
    public static void main(String ar[])
    {
        int a,b,c;
        Scanner s=new Scanner(System.in);
        System.out.println("Enter 3 numbers");
        a=s.nextInt();
        b=s.nextInt();
        c=s.nextInt();
        p6 p=new p6();
        System.out.println("The number of unique elements is"+p.numUnique(a,b,c));
    }
};
