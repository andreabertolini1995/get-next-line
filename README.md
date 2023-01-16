# get-next-line
The *get_next_line* function reads the text file pointed by the file descriptor and returns it, one line at the time.
This function can be called multiple times to return as many lines from the text file.
The size of the buffer can be dynamically changed by adding the following flag *-D BUFFER-SIZE=n* during compilation, where *n* specifies the size of the buffer. 
