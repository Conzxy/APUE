#include <fmt/format.h>
#include <sys/stat.h>

using namespace fmt;

int main(int argc,char* argv[])
{
	struct stat buf;
	char const* ptr;
	{}
	for(int i=1;i<argc;++i)
	{
		print("{}: ",argv[i]);
		if(lstat(argv[i],&buf)<0)
		{
			print(stderr,"lstat error");
			continue;
		}

		if(S_ISREG(buf.st_mode))
			ptr="regular file";
		else if(S_ISDIR(buf.st_mode))
			ptr="directory file";
		else if(S_ISCHR(buf.st_mode))
			ptr="charater file";
		else if(S_ISBLK(buf.st_mode))
			ptr="block file";
		else if(S_ISLNK(buf.st_mode))
			ptr="symbolic file";
		else if(S_ISSOCK(buf.st_mode))
			ptr="socket";
		else if(S_ISFIFO(buf.st_mode))
			ptr="FIFO or pipe";
		else
			ptr="** unknown mode **";
		print("{}\n",ptr);
	}

	return 0;
}
