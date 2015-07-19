#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char*argv[])
{
	struct stat buf;
	int a;
	if (argc != 2)
	{
	printf("No filename\n");
	exit(-1);
	}
	if ((a = stat(argv[1], &buf)) == -1)
	{
	printf("Can't create structure\n");
	exit(-1);
	}
	printf("User id : %d\n", buf.st_uid);
	printf("Group id : %d\n", buf.st_gid);
	printf("Block size : %d\n", buf.st_blksize);
	printf("Blocks allocated : %d\n", buf.st_blocks);
	printf("Inode no. : %d\n", buf.st_ino);
	printf("Last accessed : %s", ctime(&(buf.st_atime)));
	printf("Last modified : %s", ctime(&(buf.st_mtime)));
	printf("File size : %d bytes\n", buf.st_size);
	printf("No. of links : %d\n", buf.st_nlink);
	printf("Permissions : ");
	printf( (S_ISDIR(buf.st_mode)) ? "d" : "-");
	printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
	printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
	printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
	printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
	printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
	printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
	printf( (buf.st_mode & S_IROTH) ? "r" : "-");
	printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
	printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n");
	if(buf.st_mode & S_IFREG)
	printf("File type : Regular\n");
	if(buf.st_mode & S_IFDIR)
	printf("File type : Directory \n");
}





