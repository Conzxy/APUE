#include <stdio.h>
#include <iostream>

int main()
{
	char buf[4];
	char buf2[4];
	std::cout<<snprintf(buf, 4, "133j121")<<std::endl;
	std::cout<<snprintf(buf2, 3, "11")<<std::endl;
	printf("%s\n", buf);
	printf("%s\n", buf2);
}
