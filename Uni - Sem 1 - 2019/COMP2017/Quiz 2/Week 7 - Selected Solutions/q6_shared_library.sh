

# Your don't necessarily need ranlib
gcc -c q5_rbuf.c -o rbuf.o
ar rcs librbuf.a rbuf.o
gcc q7_test.c -L./ -lrbuf -o rbuf_test

#-L allows for specification of library directory, -l is the linker command, 
#Once constructed we can cutout the -lib- component and specify the component afterwards

