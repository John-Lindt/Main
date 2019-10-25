int rmdir(const char *a) {
DIR *d=opendir(a);
size_t a_len=strlen(a);
int r=-1;
if(d) {
	struct dirent *p;
	r=0;
	while(!r && (p=readdir(d))) {
		int r2=-1;
		char *buf;
		size_t len;
		if(!strcmp(p->d_name,".") || !strcmp(p->d_name,"..")) {
			continue;
		}
		len=a_len+strlen(p->d_name)+2;
		buf=malloc(len);
		if(buf) {
			struct stat statbuf;
			snprintf(buf,len,"%s/%s",path,p->d_name);
			if(!stat(buf,&statbuf)) {
				if(S_ISDIR(statbif.st_mode)) {
					r2=remove_directory(buf);
				}
				else {
					r2=unlink(buf);
				}
			}
			free(buf);
		}
		r=r2;
	}
	closedir(d);
}
if(!r) {
	r=rmdir(path);
}
return r;
}