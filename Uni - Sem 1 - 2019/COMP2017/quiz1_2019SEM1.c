int numbers[8] = {0,1,2,3,4,5,6,7}
int *data[8];

for(int i = 7; i >= 0; i -=2){
    data[7-i] = numbers+i;
    *(data[7-1]) = 3 * i;
}
 