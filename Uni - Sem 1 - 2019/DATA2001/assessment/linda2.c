int writeoffset = -1;
	if(numfiles == 0){ //No existing files in table
		writeoffset = 0;
	}
	//Case: Only 1 file
	if(numfiles == 1){
		if(length < sortedbyoffset[0].offset){
			writeoffset = 0;
		} else {
            //okay yeah i get this now soz
			writeoffset = sortedbyoffset[0].offset + sortedbyoffset[0].len;
		}
	}
	if(numfiles > 0){
		//if numfiles == 1, this will skip over
        //so i can compare to i-1

        //
		for(int i = 0; i < numfiles-1; i++){   //for loop starts here
			int curroffset = sortedbyoffset[i].offset;
			int currlen = sortedbyoffset[i].len;
			int nextoffset = sortedbyoffset[i+1].offset;
			int nextlen = sortedbyoffset[i+1].len;
            //Below should actually check before the first file (not last)
			if(i == 0){
				if(length < sortedbyoffset[i].offset){ //if there's enough space
					writeoffset = 0;
					break;
				}
			}
			if(curroffset - (prevoffset + prevlen) > length){ //If there's space in between
				writeoffset = prevoffset + prevlen;
				break;
			}
            //Here it should check if there's space after the last file
			if(i == (numfiles - 2)){ //on last file
				if(totallength - (nextoffset + nextlen) > length){//If there's enough space after
					writeoffset = (nextoffset + nextlen);
					break;
				} else {
					//No contiguous space, time to repack
					repack(helper);
					create_file(filename, length, helper);
				}				
			}
		}
	}

	if(writeoffset == -1){
		printf("Write is still at -1!!\n"); //This gets printed right before last table prints

	}

    //After marking:
    //prints file at beginning 
    //numfiles = 3, repacks, calls create_file again
    
    //prints file at beginning again (files look repacked)
    //numfiles = 3
    //finds space after last offset, writeoffset = 37
    //prints file at end

    //then skips for loop completely
    //prints "write is still at -1!!"
    //numfiles = 3
    //prints file at end




    void aidan_create_file_check_space(){

        	//checking if we need to repack
	        int largest_gap = 0;
	        int curr = 0;
	        //Iterate through our array of files and find the largest space
	        for(int i = 0; i < (disk2Size/72)- 1; i++){
	        	curr = abs((master->directory_array[i].offset + 
	        				master->directory_array[i].length) - 
	        			    master->directory_array[i + 1].offset);
	        	if(curr > largest_gap){
	        		largest_gap = curr;
	        	}
	        }

	        //Only repack if we dont have enough space
	        if(largest_gap < length){
	        	repack(helper);
	        }

    }