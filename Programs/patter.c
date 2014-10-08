int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d", &n);
		n = (1<<n);
		int x, y, i;
		for (y = n - 1; y >= 0; y--, putchar('\n')){
			for (i = 0; i < y; i++)
			       	putchar(' ');
			for (x = 0; x + y <n; x++)
				printf((x & y) ? "  " : "* ");
		}
	}
	return 0;
}
