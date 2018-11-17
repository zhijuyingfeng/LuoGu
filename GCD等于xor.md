#Qusetion
输入正整数n（1$\leq$n$\leq$3$\times$10$^7$），问有多少对整数（a,b）满足：1$\leq$b$\leq$a$\leq$n，且gcd(a,b)=a XOR b。如n=7时，有4对：(3,2),(5,4),(6,4),(7,6)。

#分析
异或有一条性质：若a xor b=c, 则 a xor c= b,所以可以枚举a和c，然后计算a xor c = b，最后验证一下是否有gcd(a,b)=c。因为对每一个a，要从1开始遍历c，所以时间复杂度为n/n+(n-1)/n+……+2/n+1/n=O(nlogn)。再加上gcd的时间复杂度为O(logn)，所以总的时间复杂度为O(n(logn)$^2$)。

这个算法还可以改进。注意到满足gcd(a,b)=a xor b=c的a、b、c，满足c=a-b。
证明如下：
在二进制下比较减法与异或不难发现a-b$\leq$a xor b,
且由于c=gcd(a,b)，$\therefore$不妨设a=k<sub>1</sub>c,b=k<sub>2</sub>c;(k<sub>1</sub>>k<sub>2</sub>)
$\therefore$a-b=(k<sub>1</sub>-k<sub>2</sub>)c,
又$\because$k<sub>1</sub>-k<sub>2</sub>$\geq$1
$\therefore$a-b$\geq$c

假设$\exist$c使c$\lt$a-b,
则c$\lt$a-b$\leq$a xor b,
与c=a xor b 矛盾。

有了上述结论，沿用上述算法，枚举a和c，计算b=a-c，则gcd(a,b)=gcd(a,a-c)=c,因此只需验证是否有c=a xor b,时间复杂度降为O(nlogn)。