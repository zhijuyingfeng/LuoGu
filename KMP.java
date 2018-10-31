public class Main
{
    public static int[]Next;

    public static void getNext(final String P)
    {
        int i=0,j=-1;
        Next[0]=-1;
        while(i<P.length()-1)
        {
            if(j==-1||P.charAt(i)==P.charAt(j))
            {
                i++;
                j++;
                Next[i]=j;
            }
            else
            {
                j=Next[j];
            }

        }
    }

    public static int KMP(final String S,final String P)
    {
        int i=0,j=0;
        while(i<S.length()&&j<P.length())
        {
            if(j==-1||S.charAt(i)==P.charAt(j))
            {
                i++;j++;
            }
            else
            {
                j=Next[j];
            }
            if(j==P.length())
            {
                return i-j;
            }
        }
        return -1;
    }

    public static void main(String[] args)
    {
        String P="ABCDABD";
        String S="BBC ABCDAB ABCDABCDABD";
        Next=new int[P.length()];
        getNext(P);
        System.out.println(KMP(S,P));
    }
}
