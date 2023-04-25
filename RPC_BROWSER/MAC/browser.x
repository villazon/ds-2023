struct fileinfo{
	string filename<256>;
	string fullpath<256>;
	int size;
	string nextfile<256>;
};
program DSFILEBROWSER { 
 version DSVER { 
 fileinfo GETFILEINFO(string) = 1; 
 } = 2020; 
} = 0x20940216; 
